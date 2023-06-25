void setupWiFi(){
  wm.setConfigPortalTimeout(30); // auto close configportal after n seconds
  bool  res;
  res = wm.autoConnect("TERYAQ"); // anonymous ap
  
    if(!res) {
        Serial.println("Failed to connect");
        // ESP.restart();
    } 
    else {
        //if you get here you have connected to the WiFi    
        Serial.println("connected...yeey :)");
    }
    
  //WiFi.begin(ssid, pass);
  /*while (WiFi.status() != WL_CONNECTED) {
     delay(500);
     Serial.print(".");
  } */
  Serial.println("");
  Serial.println("WiFi connected.");
  // Init and get the time
  configTime(gmtOffset_sec, daylightOffset_sec, ntpServer);
  if (getLocalTime(&timeinfo)){
    rtc.setTimeStruct(timeinfo); 
  }

  // Assign the api key (required).
  config.api_key = API_KEY;

  // Assign the RTDB URL (required).
  config.database_url = DATABASE_URL;

  // Sign up.
  Serial.println();
  Serial.println("---------------Sign up");
  Serial.print("Sign up new user... ");
  if (Firebase.signUp(&config, &auth, "", "")){
    Serial.println("ok");
    signupOK = true;
  }
  else{
    Serial.printf("%s\n", config.signer.signupError.message.c_str());
  }
  Serial.println("---------------");
  
  // Assign the callback function for the long running token generation task.
  config.token_status_callback = tokenStatusCallback; //--> see addons/TokenHelper.h
  
  Firebase.begin(&config, &auth);
  Firebase.reconnectWiFi(true);

  getDataFromServer();
  
}


void Wireless_Telemetry(){

  currentWiFiMillis = millis();
  if(currentWiFiMillis-prevWiFiMillis>=millisWiFiInterval){   //Run routine every millisRoutineInterval (ms)
    prevWiFiMillis = currentWiFiMillis;                       //Store previous time
  
    printLocalTime();
  }
  if(settingMode==1 && dataSend==0){
    getDataFromServer();
  }
  else if(dataSend==1){
    sendDataToServer();
    dataSend = 0;
  }
}

void printLocalTime(){
  tm timeinfo = rtc.getTimeStruct();
  Serial.println(rtc.getTime());          //  (String) 15:24:38
  actHour = rtc.getHour(true);
  actMin = rtc.getMinute();
  actSec = rtc.getSecond();
  while(gsmSerial.available()) 
  {
    Serial.write(gsmSerial.read());//Forward what Software Serial received to Serial Port
  }
  
}

void factoryReset(){
  EEPROM.write(0,1);       //STORE: Box1 Hour = 1
  EEPROM.write(1,2);       //STORE: Box2 Hour = 2
  EEPROM.write(2,3);       //STORE: Box3 Hour = 3
  EEPROM.write(3,4);       //STORE: Box4 Hour = 4
  EEPROM.write(4,0);       //STORE: Box1 minutes = 0
  EEPROM.write(5,0);       //STORE: Box2 minutes = 0
  EEPROM.write(6,0);       //STORE: Box3 minutes = 0
  EEPROM.write(7,0);       //STORE: Box4 minutes = 0
  EEPROM.write(8,2);       //STORE: Box1 TakeTimes = 2
  EEPROM.write(9,2);       //STORE: Box2 TakeTimes = 2
  EEPROM.write(10,2);      //STORE: Box3 TakeTimes = 2
  EEPROM.write(11,2);      //STORE: Box4 TakeTimes = 2
  EEPROM.write(12,0);      //STORE: LCD backlight sleep timer (default: 0 = never)
  EEPROM.writeUInt(13,1201290445);
  EEPROM.writeLong(17,7200);
  EEPROM.commit();
  wm.resetSettings();
  loadSettings();
}

                                             //Load saves timings for all boxes
void loadSettings(){
  hour1             = EEPROM.read(0);
  hour2             = EEPROM.read(1);
  hour3             = EEPROM.read(2);
  hour4             = EEPROM.read(3);
  min1              = EEPROM.read(4);
  min2              = EEPROM.read(5);
  min3              = EEPROM.read(6);
  min4              = EEPROM.read(7);
  takeTimes1        = EEPROM.read(8);
  takeTimes2        = EEPROM.read(9);
  takeTimes3        = EEPROM.read(10);
  takeTimes4        = EEPROM.read(11);
  backlightSleepMode= EEPROM.read(12);        // Load saved lcd backlight sleep timer
  phone             = EEPROM.readUInt(13);
  gmtOffset_sec     = EEPROM.readLong(17);
}

void saveSettings(){
  EEPROM.write(0,hour1);
  EEPROM.write(1,hour2);
  EEPROM.write(2,hour3);
  EEPROM.write(3,hour4);
  EEPROM.write(4,min1);
  EEPROM.write(5,min2);
  EEPROM.write(6,min3);
  EEPROM.write(7,min4);
  EEPROM.write(8,takeTimes1);
  EEPROM.write(9,takeTimes2);
  EEPROM.write(10,takeTimes3);
  EEPROM.write(11,takeTimes4);
  EEPROM.write(12,backlightSleepMode); //STORE: LCD backlight sleep timer
  EEPROM.writeUInt(13,phone);
  EEPROM.writeLong(17,gmtOffset_sec);
  EEPROM.commit();
}

void sendDataToServer(){
    if (Firebase.ready() && signupOK ){

    // The process of sending/storing data to the firebase database.
    Serial.println();
    Serial.println("---------------Store Data");
    
    // Write an Int number on the database
    if (Firebase.RTDB.setInt(&fbdo, "/med1/pills",takeTimes1)) 
    if (Firebase.RTDB.setInt(&fbdo, "/med1/time/hours",hour1)) 
    if (Firebase.RTDB.setInt(&fbdo, "/med1/time/minutes",min1)) 
    if (Firebase.RTDB.setInt(&fbdo, "/med2/pills",takeTimes2)) 
    if (Firebase.RTDB.setInt(&fbdo, "/med2/time/hours",hour2)) 
    if (Firebase.RTDB.setInt(&fbdo, "/med2/time/minutes",min2))
    if (Firebase.RTDB.setInt(&fbdo, "/med3/pills",takeTimes3)) 
    if (Firebase.RTDB.setInt(&fbdo, "/med3/time/hours",hour3)) 
    if (Firebase.RTDB.setInt(&fbdo, "/med3/time/minutes",min3))
    if (Firebase.RTDB.setInt(&fbdo, "/med4/pills",takeTimes4)) 
    if (Firebase.RTDB.setInt(&fbdo, "/med4/time/hours",hour4)) 
    if (Firebase.RTDB.setInt(&fbdo, "/med4/time/minutes",min4))
    if (Firebase.RTDB.setInt(&fbdo, "/phone",phone))
    if (Firebase.RTDB.setInt(&fbdo, "/GMT_offset",gmtOffset_sec))
    ; 
  }
}

void getDataFromServer(){
  if (Firebase.ready() && signupOK && (millis() - sendDataPrevMillis >= sendDataIntervalMillis || sendDataPrevMillis == 0)){
    sendDataPrevMillis = millis();

    // The process of reading data from firebase database.
    Serial.println();
    Serial.println("---------------Get Data");
    
    if (Firebase.RTDB.getInt(&fbdo, "/med1/pills")) {takeTimes1 = fbdo.intData();}  
    else {Serial.println(fbdo.errorReason());}
    if (Firebase.RTDB.getInt(&fbdo, "/med1/time/hours")) {hour1 = fbdo.intData();}
    else {Serial.println(fbdo.errorReason());}
    if (Firebase.RTDB.getInt(&fbdo, "/med1/time/minutes")) {min1 = fbdo.intData();}
    if (Firebase.RTDB.getInt(&fbdo, "/med2/pills")) {takeTimes2 = fbdo.intData();}  
    if (Firebase.RTDB.getInt(&fbdo, "/med2/time/hours")) {hour2 = fbdo.intData();}
    if (Firebase.RTDB.getInt(&fbdo, "/med2/time/minutes")) {min2 = fbdo.intData();}
    if (Firebase.RTDB.getInt(&fbdo, "/med3/pills")) {takeTimes3 = fbdo.intData();}  
    if (Firebase.RTDB.getInt(&fbdo, "/med3/time/hours")) {hour3 = fbdo.intData();}
    if (Firebase.RTDB.getInt(&fbdo, "/med3/time/minutes")) {min3 = fbdo.intData();}
    if (Firebase.RTDB.getInt(&fbdo, "/med4/pills")) {takeTimes4 = fbdo.intData();}  
    if (Firebase.RTDB.getInt(&fbdo, "/med4/time/hours")) {hour4 = fbdo.intData();}
    if (Firebase.RTDB.getInt(&fbdo, "/med4/time/minutes")) {min4 = fbdo.intData();}
    if (Firebase.RTDB.getInt(&fbdo, "/phone")) {phone = fbdo.intData();}
    if (Firebase.RTDB.getInt(&fbdo, "/GMT_offset")) {gmtOffset_sec = fbdo.intData();}
    saveSettings();
  }
}

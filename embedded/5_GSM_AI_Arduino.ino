void gsmModule() {
  if(makeCall == 1){
    prevGsmMillis = millis();
    gsmSerial.println("ATD+ +20"+String(phone)+";");              //  Setting country code and phone number to dial
    digitalWrite(speaker,HIGH);
    call = 1;                
    makeCall = 0;
    delay(100);
  }
  currentGsmMillis = millis();
  if(currentGsmMillis-prevGsmMillis>=hangUpInterval && call==1){    //Run routine every millisRoutineInterval (ms)
    gsmSerial.println("ATH"); //hang up
    digitalWrite(speaker,LOW);
    call = 0;
    prevGsmMillis = currentGsmMillis;                               //Store previous time
  } 
}


void AIDetect(){
  while (Serial2.available()) {                                      //Check for data from AI arduino
  AI =Serial2.read();                                                //Read data from AI ardiuno
  Serial.println(AI);
  Serial.println(Serial2.read());
  if(AI=='5'){box = 5;}
  else if(AI=='6'){box = 6;}
  else if(AI=='7'){box = 7;}
  else if(AI=='1'){makeCall = 1;}
  else if(AI=='2'){gsmSerial.println("ATA");}
  }

}

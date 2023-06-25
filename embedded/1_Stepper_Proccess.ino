void Time_Table(){
  if(hour1 == hour2 && min1 == min2){            // Set time offset of 3 minutes between the identical take time
    min2 = min2+3;
  }
  else if(hour2 == hour3 && min2 == min3){
    min3 = min3+3;
  }
  else if(hour3 == hour4 && min3 == min4){
    min4 = min4+3;
  }

  //=================== Box number 1 Settings ==================
  if(takeTimes1 == 1 && settingMode==0){
    if(actHour == hour1 && actMin == min1 && actSec == 0){
      box = 1;
    }
  }
  else if(takeTimes1 == 2 && settingMode==0){
    if(actHour == hour1 && actMin == min1){
      box = 1;
      if(hour1+12 >= 24){
        hour1=hour1-12;
      }
      else{hour1=hour1+12;}
    }
  }
  else if(takeTimes1 == 3 && settingMode==0){
    if(actHour == hour1 && actMin == min1){
      box = 1;
      if(hour1+8 >= 24){
        hour1=hour1-16;
      }
      else{hour1=hour1+8;}
    }
  }
  else if(takeTimes1 == 4 && settingMode==0){
    if(actHour == hour1 && actMin == min1){
      box = 1;
      if(hour1+6 >= 24){
        hour1=hour1-18;
      }
      else{hour1=hour1+6;}
    }
  }

  //=================== Box number 2 Settings ==================
  if(takeTimes2 == 1 && settingMode==0){
    if(actHour == hour2 && actMin == min2 && actSec == 0){
      box = 2;
    }
  }
  else if(takeTimes2 == 2 && settingMode==0){
    if(actHour == hour2 && actMin == min2){
      box = 2;
      if(hour2+12 >= 24){
        hour2=hour2-12;
      }
      else{hour2=hour2+12;}
    }
  }
  else if(takeTimes2 == 3 && settingMode==0){
    if(actHour == hour2 && actMin == min2){
      box = 2;
      if(hour2+8 >= 24){
        hour2=hour2-16;
      }
      else{hour2=hour2+8;}
    }
  }
  else if(takeTimes2 == 4 && settingMode==0){
    if(actHour == hour2 && actMin == min2){
      box = 2;
      if(hour2+6 >= 24){
        hour2=hour2-18;
      }
      else{hour2=hour2+6;}
    }
  }
  
  //=================== Box number 3 Settings ==================
  if(takeTimes3 == 1 && settingMode==0){
    if(actHour == hour3 && actMin == min3 && actSec == 0){
      box = 3;
    }
  }
  else if(takeTimes3 == 2 && settingMode==0){
    if(actHour == hour3 && actMin == min3){
      box = 3;
      if(hour3+12 >= 24){
        hour3=hour3-12;
      }
      else{hour3=hour3+12;}
    }
  }
  else if(takeTimes3 == 3 && settingMode==0){
    if(actHour == hour3 && actMin == min3){
      box = 3;
      if(hour3+8 >= 24){
        hour3=hour3-16;
      }
      else{hour3=hour3+8;}
    }
  }
  else if(takeTimes3 == 4 && settingMode==0){
    if(actHour == hour3 && actMin == min3){
      box = 3;
      if(hour3+6 >= 24){
        hour3=hour3-18;
      }
      else{hour3=hour3+6;}
    }
  }

  //=================== Box number 4 Settings ==================
  if(takeTimes4 == 1 && settingMode==0){
    if(actHour == hour4 && actMin == min4 && actSec == 0){
      box = 4;
    }
  }
  else if(takeTimes4 == 2 && settingMode==0){
    if(actHour == hour4 && actMin == min4){
      box = 4;
      if(hour4+12 >= 24){
        hour4=hour4-12;
      }
      else{hour4=hour4+12;}
    }
  }
  else if(takeTimes4 == 3 && settingMode==0){
    if(actHour == hour4 && actMin == min4){
      box = 4;
      if(hour4+8 >= 24){
        hour4=hour4-16;
      }
      else{hour4=hour4+8;}
    }
  }
  else if(takeTimes4 == 4 && settingMode==0){
    if(actHour == hour4 && actMin == min4){
      box = 4;
      if(hour4+6 >= 24){
        hour4=hour4-18;
      }
      else{hour4=hour4+6;}
    }
  } 
}



//====================== Stepper Motor Angle Configration =====================
void Stepper_Process(){
  
  if(box == 1 && idle == 0){
    digitalWrite(dirPin,HIGH);
    for(angle = 0; angle < 200; angle++) {
    digitalWrite(stepPin,HIGH); 
    delayMicroseconds(1000);    // by changing this time delay between the steps we can change the rotation speed
    digitalWrite(stepPin,LOW); 
    delayMicroseconds(1000); 
    }
    idle = 1;   
    prevResetMillis = millis();    
  }

  else if(box == 2 && idle == 0){
    digitalWrite(dirPin,HIGH);
    for(angle = 0; angle < 400; angle++) {
    digitalWrite(stepPin,HIGH); 
    delayMicroseconds(1000);    // by changing this time delay between the steps we can change the rotation speed
    digitalWrite(stepPin,LOW); 
    delayMicroseconds(1000); 
    }
    idle = 1;   
    prevResetMillis = millis();    
  }
 
  else if(box == 3 && idle == 0){
    digitalWrite(dirPin,HIGH);
    for(angle = 0; angle < 600; angle++) {
    digitalWrite(stepPin,HIGH); 
    delayMicroseconds(1000);    // by changing this time delay between the steps we can change the rotation speed
    digitalWrite(stepPin,LOW); 
    delayMicroseconds(1000); 
    }
    idle = 1;   
    prevResetMillis = millis();    
  }

  else if(box == 4 && idle == 0){
    digitalWrite(dirPin,HIGH);
    for(angle = 0; angle < 800; angle++) {
    digitalWrite(stepPin,HIGH); 
    delayMicroseconds(1000);    // by changing this time delay between the steps we can change the rotation speed
    digitalWrite(stepPin,LOW); 
    delayMicroseconds(1000); 
    }
    idle = 1;   
    prevResetMillis = millis();    
  }

  else if(box == 5 && idle == 0){
    digitalWrite(dirPin,HIGH);
    for(angle = 0; angle < 1000; angle++) {
    digitalWrite(stepPin,HIGH); 
    delayMicroseconds(1000);    // by changing this time delay between the steps we can change the rotation speed
    digitalWrite(stepPin,LOW); 
    delayMicroseconds(1000); 
    }
    idle = 1;   
    prevResetMillis = millis();    
  }

  else if(box == 6 && idle == 0){
    digitalWrite(dirPin,HIGH);
    for(angle = 0; angle < 1200; angle++) {
    digitalWrite(stepPin,HIGH); 
    delayMicroseconds(1000);    // by changing this time delay between the steps we can change the rotation speed
    digitalWrite(stepPin,LOW); 
    delayMicroseconds(1000); 
    }
    idle = 1;   
    prevResetMillis = millis();    
  }

  else if(box == 7 && idle == 0){
    digitalWrite(dirPin,HIGH);
    for(angle = 0; angle < 1400; angle++) {
    digitalWrite(stepPin,HIGH); 
    delayMicroseconds(1000);    // by changing this time delay between the steps we can change the rotation speed
    digitalWrite(stepPin,LOW); 
    delayMicroseconds(1000); 
    }
    idle = 1;   
    prevResetMillis = millis();    
  }

  if(box != 0 && idle == 1){
    Reset_Disk();
  }
}

//====================== Stepper Reset Angle Configration =====================
void Reset_Disk(){  
  if(digitalRead(IR) == HIGH){
    digitalWrite(LED,LOW);
    hand = 2; 
    ledState = 0;
  }
  if(hand == 2){
    prevStepperMillis = millis();
    hand = 1;
  }
  else if(hand == 1){
    currentStepperMillis = millis();
    if(currentStepperMillis-prevStepperMillis>=millisStepperInterval){
      prevStepperMillis = currentStepperMillis;
      digitalWrite(dirPin,LOW);
      for(angle ; angle > 0; angle--) {
        digitalWrite(stepPin,HIGH); 
        delayMicroseconds(1000);
        digitalWrite(stepPin,LOW); 
        delayMicroseconds(1000);
        }
      hand = 0;
      box = 0;
      idle=0;
      angle=0;
    }
  }
  else if(hand == 0){
    currentResetMillis = millis();
    if(currentResetMillis-prevBlinkMillis>=millisBlinkOffDelay && ledState==0){
      digitalWrite(LED,HIGH);
      ledState = 1;
      prevBlinkMillis = currentResetMillis;
    }
    else if(currentResetMillis-prevBlinkMillis>=millisBlinkOnDelay && ledState==1){
      digitalWrite(LED,LOW);
      ledState = 0;
      prevBlinkMillis = currentResetMillis;
    }
    else if(currentResetMillis-prevResetMillis>=millisResetDelay){
      digitalWrite(LED,LOW);
      hand = 2; 
      ledState = 0;
      prevResetMillis = currentResetMillis;
    }
  }
}

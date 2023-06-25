void lcdBacklight_Wake(){
    lcd.setBacklight(HIGH);
    prevLCDBackLMillis = millis();
}
void lcdBacklight(){
  unsigned long backLightInterval;
  if(backlightSleepMode==0){prevLCDBackLMillis = millis();}                 //Set backlight var to sleep never
  else if(backlightSleepMode==1){backLightInterval=10000;}                  //Set backlight var to sleep after 10 seconds without keypress 
  else if(backlightSleepMode==2){backLightInterval=300000;}                 //Set backlight var to sleep after 5 minutes without keypress 
  else if(backlightSleepMode==3){backLightInterval=3600000;}                //Set backlight var to sleep after 1 hour without keypress  
  else if(backlightSleepMode==4){backLightInterval=21600000;}               //Set backlight var to sleep after 6 hours without keypress    
  else if(backlightSleepMode==5){backLightInterval=43200000;}               //Set backlight var to sleep after 12 hours without keypress   
  else if(backlightSleepMode==6){backLightInterval=86400000;}               //Set backlight var to sleep after 1 day without keypress 
  else if(backlightSleepMode==7){backLightInterval=259200000;}              //Set backlight var to sleep after 3 days without keypress 
  else if(backlightSleepMode==8){backLightInterval=604800000;}              //Set backlight var to sleep after 1 week without keypress  
  else if(backlightSleepMode==9){backLightInterval=2419200000;}             //Set backlight var to sleep after 1 month without keypress    

  if(backlightSleepMode>0 && settingMode==0){
    currentLCDBackLMillis = millis();
    if(currentLCDBackLMillis-prevLCDBackLMillis>=backLightInterval){        //Run routine every millisRoutineInterval (ms)
      prevLCDBackLMillis = currentLCDBackLMillis;                           //Store previous time
      lcd.setBacklight(LOW);                                               
    } 
  }  
}
void displayConfig1(){
  tm timelcd = rtc.getTimeStruct();
  lcd.setCursor(0,0);lcd.print(&timelcd," %I:%M:%S  %p  ");    
  lcd.setCursor(0,1);lcd.print(&timelcd," %F %a");
}
void displayConfig2(){
  lcd.setCursor(0,0);lcd.print(" >Box1    Box2  ");
  lcd.setCursor(0,1);lcd.print("  Box3    Box4  ");
}
void displayConfig3(){
  lcd.setCursor(0,0);lcd.print("  Box1   >Box2  ");
  lcd.setCursor(0,1);lcd.print("  Box3    Box4  ");
}
void displayConfig4(){
  lcd.setCursor(0,0);lcd.print("  Box1    Box2  ");
  lcd.setCursor(0,1);lcd.print(" >Box3    Box4  ");
}
void displayConfig5(){
  lcd.setCursor(0,0);lcd.print("  Box1    Box2  ");
  lcd.setCursor(0,1);lcd.print("  Box3   >Box4  ");
}
void displayConfig6(){
  lcd.setCursor(0,0);lcd.print("BACKLIGHT SLEEP ");
  lcd.setCursor(0,1);lcd.print("> PRESS SELECT  ");
}
void displayConfig7(){
  lcd.setCursor(0,0);lcd.print("FACTORY RESET   ");
  lcd.setCursor(0,1);lcd.print("> PRESS SELECT  ");
}


////////////////////////////////////////////  MAIN LCD MENU CODE /////////////////////////////////////////////
void LCD_Menu(){
  int 
  menuPages          = 5,
  subMenuPages       = 3,
  longPressTime      = 2000,
  longPressInterval  = 500,  
  shortPressInterval = 200;

  //SETTINGS MENU
  if(settingMode==1){

    

    //BUTTON KEYPRESS
    if(setMenuPage==0){
      if(digitalRead(buttonRight)==1){menuPage++;}
      if(digitalRead(buttonLeft)==1) {menuPage--;}
      if(digitalRead(buttonBack)==1) {settingMode=0;menuPage=0;lcd.clear();}  //bool engage, main menu int page
      if(digitalRead(buttonSelect)==1){setMenuPage=1;subMenuPage=0;lcd.clear();} //enter sub menu settings - bool engage 
      lcdBacklight_Wake();
      while(digitalRead(buttonRight)==1||digitalRead(buttonLeft)==1    
      ||digitalRead(buttonBack)==1||digitalRead(buttonSelect)==1){}
    }
    //MENU PAGE CYCLING
    if(menuPage>menuPages){menuPage=0;}                     
    else if(menuPage<0){menuPage=menuPages;}

    if(menuPage==0 && setMenuPage==0){displayConfig2();}
    else if(menuPage==1 && setMenuPage==0){displayConfig3();}
    else if(menuPage==2 && setMenuPage==0){displayConfig4();}
    else if(menuPage==3 && setMenuPage==0){displayConfig5();}
    else if(menuPage==4 && setMenuPage==0){displayConfig6();}
    else if(menuPage==5 && setMenuPage==0){displayConfig7();}

    //--------------------------- SETTINGS MENU PAGES: ---------------------------// 
    ///// SETTINGS MENU Time Adjustment /////
    // BOX NO1 SETTINGS
    if(menuPage==0 && setMenuPage==1){
      lcd.setCursor(0,0);lcd.print("BOX no1   ");
      lcd.setCursor(0,1);lcd.print(" >");

      //SET MENU - FLOATTYPE
      if(subMenuPage==0){
        lcd.setCursor(10,0);lcd.print(" Hour ");
        lcd.setCursor(2,1);lcd.print(hour1);lcd.print("           ");
        if(digitalRead(buttonBack)==1){while(digitalRead(buttonBack)==1){}subMenuPage=0;menuPage=0;settingMode=1;setMenuPage=0;} 
        if(digitalRead(buttonSelect)==1){while(digitalRead(buttonSelect)==1){}subMenuPage=1;}     
        if(digitalRead(buttonRight)==1){                                                    //Right button press (increments setting values)
          while(digitalRead(buttonRight)==1){
            hour1 += 1;                                                    //Increment by 1
            hour1 = constrain(hour1,0,23); //Limit settings values to a range
            lcd.setCursor(2,1);lcd.print(hour1);delay(shortPressInterval);  //Display settings data                            
          }
        }
        else if(digitalRead(buttonLeft)==1){                                                //Left button press (decrements setting values)
          while(digitalRead(buttonLeft)==1){
            hour1 -= 1;                                                    //decrement by 1
            hour1 =  constrain(hour1,0,23); //Limit settings values to a range
            lcd.setCursor(2,1);lcd.print(hour1);delay(shortPressInterval);   //Display settings data                                        
          }
        }
      }
      if(subMenuPage==1){
        lcd.setCursor(10,0);lcd.print(" min  ");
        lcd.setCursor(2,1);lcd.print(min1);lcd.print("           ");
        if(digitalRead(buttonBack)==1){while(digitalRead(buttonBack)==1){}subMenuPage=0;} 
        if(digitalRead(buttonSelect)==1){while(digitalRead(buttonSelect)==1){}subMenuPage=2;}     
        currentMenuSetMillis = millis();
        if(digitalRead(buttonRight)==1){                                                    //Right button press (increments setting values)
          while(digitalRead(buttonRight)==1){
            if(millis()-currentMenuSetMillis>longPressTime){                                //Long Press     
              min1 += 5;                                                    //Increment by 5
              min1 = constrain(min1,0,59); //Limit settings values to a range
              lcd.setCursor(2,1);lcd.print(min1);delay(longPressInterval);   //Display settings data                               
            }
            else{                                                                           //Short Press  
              min1 += 1;                                                    //Increment by 1
              min1 = constrain(min1,0,59); //Limit settings values to a range
              lcd.setCursor(2,1);lcd.print(min1);delay(shortPressInterval);  //Display settings data                            
            } 
          }
        }
        else if(digitalRead(buttonLeft)==1){                                                //Left button press (decrements setting values)
          while(digitalRead(buttonLeft)==1){
            if(millis()-currentMenuSetMillis>longPressTime){                                //Long Press     
              min1 -= 5;                                                    //decrement by 5
              min1 = constrain(min1,0,59); //Limit settings values to a range
              lcd.setCursor(2,1);lcd.print(min1);delay(longPressInterval);   //Display settings data                               
            }
            else{                                                                            //Short Press  
              min1 -= 1;                                                     //decrement by 1
              min1 =  constrain(min1,0,59); //Limit settings values to a range
              lcd.setCursor(2,1);lcd.print(min1);delay(shortPressInterval);   //Display settings data                                      
            }
          }
        }
      }
      if(subMenuPage==2){
        lcd.setCursor(10,0);lcd.print("Take No");
        lcd.setCursor(2,1);lcd.print(takeTimes1);lcd.print("           ");
        if(digitalRead(buttonBack)==1){while(digitalRead(buttonBack)==1){}subMenuPage=1;} 
        if(digitalRead(buttonSelect)==1){while(digitalRead(buttonSelect)==1){}saveSettings();dataSend=1;subMenuPage=0;menuPage=0;setMenuPage=0;}     
        if(digitalRead(buttonRight)==1){                                                    //Right button press (increments setting values)
          while(digitalRead(buttonRight)==1){
            takeTimes1 += 1;                                                    //Increment by 1
            takeTimes1 = constrain(takeTimes1,1,4); //Limit settings values to a range
            lcd.setCursor(2,1);lcd.print(takeTimes1);delay(shortPressInterval);  //Display settings data                            
          }
        }
        else if(digitalRead(buttonLeft)==1){                                                //Left button press (decrements setting values)
          while(digitalRead(buttonLeft)==1){
            takeTimes1 -= 1;                                                    //decrement by 1
            takeTimes1 =  constrain(takeTimes1,1,4); //Limit settings values to a range
            lcd.setCursor(2,1);lcd.print(takeTimes1);delay(shortPressInterval);   //Display settings data                                        
          }
        }
      }   
    }
    // BOX NO2 SETTINGS
    if(menuPage==1 && setMenuPage==1){
      lcd.setCursor(0,0);lcd.print("BOX no2   ");
      lcd.setCursor(0,1);lcd.print(" >");

      //SET MENU - FLOATTYPE
      if(subMenuPage==0){
        lcd.setCursor(10,0);lcd.print(" Hour ");
        lcd.setCursor(2,1);lcd.print(hour2);lcd.print("           ");
        if(digitalRead(buttonBack)==1){while(digitalRead(buttonBack)==1){}subMenuPage=0;menuPage=1;settingMode=1;setMenuPage=0;} 
        if(digitalRead(buttonSelect)==1){while(digitalRead(buttonSelect)==1){}subMenuPage=1;}     
        if(digitalRead(buttonRight)==1){                                                    //Right button press (increments setting values)
          while(digitalRead(buttonRight)==1){
            hour2 += 1;                                                    //Increment by 1
            hour2 = constrain(hour2,0,23); //Limit settings values to a range
            lcd.setCursor(2,1);lcd.print(hour2);delay(shortPressInterval);  //Display settings data                            
          }
        }
        else if(digitalRead(buttonLeft)==1){                                                //Left button press (decrements setting values)
          while(digitalRead(buttonLeft)==1){
            hour2 -= 1;                                                    //decrement by 1
            hour2 =  constrain(hour2,0,23); //Limit settings values to a range
            lcd.setCursor(2,1);lcd.print(hour2);delay(shortPressInterval);   //Display settings data                                        
          }
        }
      }
      if(subMenuPage==1){
        lcd.setCursor(10,0);lcd.print(" min  ");
        lcd.setCursor(2,1);lcd.print(min2);lcd.print("           ");
        if(digitalRead(buttonBack)==1){while(digitalRead(buttonBack)==1){}subMenuPage=0;} 
        if(digitalRead(buttonSelect)==1){while(digitalRead(buttonSelect)==1){}subMenuPage=2;}     
        currentMenuSetMillis = millis();
        if(digitalRead(buttonRight)==1){                                                    //Right button press (increments setting values)
          while(digitalRead(buttonRight)==1){
            if(millis()-currentMenuSetMillis>longPressTime){                                //Long Press     
              min2 += 5;                                                    //Increment by 5
              min2 = constrain(min2,0,59); //Limit settings values to a range
              lcd.setCursor(2,1);lcd.print(min2);delay(longPressInterval);   //Display settings data                               
            }
            else{                                                                           //Short Press  
              min2 += 1;                                                    //Increment by 1
              min2 = constrain(min2,0,59); //Limit settings values to a range
              lcd.setCursor(2,1);lcd.print(min2);delay(shortPressInterval);  //Display settings data                            
            } 
          }
        }
        else if(digitalRead(buttonLeft)==1){                                                //Left button press (decrements setting values)
          while(digitalRead(buttonLeft)==1){
            if(millis()-currentMenuSetMillis>longPressTime){                                //Long Press     
              min2 -= 5;                                                    //decrement by 5
              min2 = constrain(min2,0,59); //Limit settings values to a range
              lcd.setCursor(2,1);lcd.print(min2);delay(longPressInterval);   //Display settings data                               
            }
            else{                                                                            //Short Press  
              min2 -= 1;                                                     //decrement by 1
              min2 =  constrain(min2,0,59); //Limit settings values to a range
              lcd.setCursor(2,1);lcd.print(min2);delay(shortPressInterval);   //Display settings data                                      
            }
          }
        }
      }
      if(subMenuPage==2){
        lcd.setCursor(10,0);lcd.print("Take No");
        lcd.setCursor(2,1);lcd.print(takeTimes2);lcd.print("           ");
        if(digitalRead(buttonBack)==1){while(digitalRead(buttonBack)==1){}subMenuPage=1;} 
        if(digitalRead(buttonSelect)==1){while(digitalRead(buttonSelect)==1){}saveSettings();dataSend=1;subMenuPage=0;menuPage=1;setMenuPage=0;}     
        if(digitalRead(buttonRight)==1){                                                    //Right button press (increments setting values)
          while(digitalRead(buttonRight)==1){
            takeTimes2 += 1;                                                    //Increment by 1
            takeTimes2 = constrain(takeTimes2,1,4); //Limit settings values to a range
            lcd.setCursor(2,1);lcd.print(takeTimes2);delay(shortPressInterval);  //Display settings data                            
          }
        }
        else if(digitalRead(buttonLeft)==1){                                                //Left button press (decrements setting values)
          while(digitalRead(buttonLeft)==1){
            takeTimes2 -= 1;                                                    //decrement by 1
            takeTimes2 =  constrain(takeTimes2,1,4); //Limit settings values to a range
            lcd.setCursor(2,1);lcd.print(takeTimes2);delay(shortPressInterval);   //Display settings data                                        
          }
        }
      }   
    }
    // BOX NO3 SETTINGS
    if(menuPage==2 && setMenuPage==1){
      lcd.setCursor(0,0);lcd.print("BOX no3   ");
      lcd.setCursor(0,1);lcd.print(" >");

      //SET MENU - FLOATTYPE
      if(subMenuPage==0){
        lcd.setCursor(10,0);lcd.print(" Hour ");
        lcd.setCursor(2,1);lcd.print(hour3);lcd.print("           ");
        if(digitalRead(buttonBack)==1){while(digitalRead(buttonBack)==1){}subMenuPage=0;menuPage=2;settingMode=1;setMenuPage=0;} 
        if(digitalRead(buttonSelect)==1){while(digitalRead(buttonSelect)==1){}subMenuPage=1;}     
        if(digitalRead(buttonRight)==1){                                                    //Right button press (increments setting values)
          while(digitalRead(buttonRight)==1){
            hour3 += 1;                                                    //Increment by 1
            hour3 = constrain(hour3,0,23); //Limit settings values to a range
            lcd.setCursor(2,1);lcd.print(hour3);delay(shortPressInterval);  //Display settings data                            
          }
        }
        else if(digitalRead(buttonLeft)==1){                                                //Left button press (decrements setting values)
          while(digitalRead(buttonLeft)==1){
            hour3 -= 1;                                                    //decrement by 1
            hour3 =  constrain(hour3,0,23); //Limit settings values to a range
            lcd.setCursor(2,1);lcd.print(hour3);delay(shortPressInterval);   //Display settings data                                        
          }
        }
      }
      if(subMenuPage==1){
        lcd.setCursor(10,0);lcd.print(" min  ");
        lcd.setCursor(2,1);lcd.print(min3);lcd.print("           ");
        if(digitalRead(buttonBack)==1){while(digitalRead(buttonBack)==1){}subMenuPage=0;} 
        if(digitalRead(buttonSelect)==1){while(digitalRead(buttonSelect)==1){}subMenuPage=2;}     
        currentMenuSetMillis = millis();
        if(digitalRead(buttonRight)==1){                                                    //Right button press (increments setting values)
          while(digitalRead(buttonRight)==1){
            if(millis()-currentMenuSetMillis>longPressTime){                                //Long Press     
              min3 += 5;                                                    //Increment by 5
              min3 = constrain(min3,0,59); //Limit settings values to a range
              lcd.setCursor(2,1);lcd.print(min3);delay(longPressInterval);   //Display settings data                               
            }
            else{                                                                           //Short Press  
              min3 += 1;                                                    //Increment by 1
              min3 = constrain(min3,0,59); //Limit settings values to a range
              lcd.setCursor(2,1);lcd.print(min3);delay(shortPressInterval);  //Display settings data                            
            } 
          }
        }
        else if(digitalRead(buttonLeft)==1){                                                //Left button press (decrements setting values)
          while(digitalRead(buttonLeft)==1){
            if(millis()-currentMenuSetMillis>longPressTime){                                //Long Press     
              min3 -= 5;                                                    //decrement by 5
              min3 = constrain(min3,0,59); //Limit settings values to a range
              lcd.setCursor(2,1);lcd.print(min3);delay(longPressInterval);   //Display settings data                               
            }
            else{                                                                            //Short Press  
              min3 -= 1;                                                     //decrement by 1
              min3 =  constrain(min3,0,59); //Limit settings values to a range
              lcd.setCursor(2,1);lcd.print(min3);delay(shortPressInterval);   //Display settings data                                      
            }
          }
        }
      }
      if(subMenuPage==2){
        lcd.setCursor(10,0);lcd.print("Take No");
        lcd.setCursor(2,1);lcd.print(takeTimes3);lcd.print("           ");
        if(digitalRead(buttonBack)==1){while(digitalRead(buttonBack)==1){}subMenuPage=1;} 
        if(digitalRead(buttonSelect)==1){while(digitalRead(buttonSelect)==1){}saveSettings();dataSend=1;subMenuPage=0;menuPage=2;setMenuPage=0;}     
        if(digitalRead(buttonRight)==1){                                                    //Right button press (increments setting values)
          while(digitalRead(buttonRight)==1){
            takeTimes3 += 1;                                                    //Increment by 1
            takeTimes3 = constrain(takeTimes3,1,4); //Limit settings values to a range
            lcd.setCursor(2,1);lcd.print(takeTimes3);delay(shortPressInterval);  //Display settings data                            
          }
        }
        else if(digitalRead(buttonLeft)==1){                                                //Left button press (decrements setting values)
          while(digitalRead(buttonLeft)==1){
            takeTimes3 -= 1;                                                    //decrement by 1
            takeTimes3 =  constrain(takeTimes3,1,4); //Limit settings values to a range
            lcd.setCursor(2,1);lcd.print(takeTimes3);delay(shortPressInterval);   //Display settings data                                        
          }
        }
      }   
    }
    // BOX NO4 SETTINGS
    if(menuPage==3 && setMenuPage==1){
      lcd.setCursor(0,0);lcd.print("BOX no4   ");
      lcd.setCursor(0,1);lcd.print(" >");

      //SET MENU - FLOATTYPE
      if(subMenuPage==0){
        lcd.setCursor(10,0);lcd.print(" Hour ");
        lcd.setCursor(2,1);lcd.print(hour4);lcd.print("           ");
        if(digitalRead(buttonBack)==1){while(digitalRead(buttonBack)==1){}subMenuPage=0;menuPage=3;settingMode=1;setMenuPage=0;} 
        if(digitalRead(buttonSelect)==1){while(digitalRead(buttonSelect)==1){}subMenuPage=1;}     
        if(digitalRead(buttonRight)==1){                                                    //Right button press (increments setting values)
          while(digitalRead(buttonRight)==1){
            hour4 += 1;                                                    //Increment by 1
            hour4 = constrain(hour4,0,23); //Limit settings values to a range
            lcd.setCursor(2,1);lcd.print(hour4);delay(shortPressInterval);  //Display settings data                            
          }
        }
        else if(digitalRead(buttonLeft)==1){                                                //Left button press (decrements setting values)
          while(digitalRead(buttonLeft)==1){
            hour4 -= 1;                                                    //decrement by 1
            hour4 =  constrain(hour4,0,23); //Limit settings values to a range
            lcd.setCursor(2,1);lcd.print(hour4);delay(shortPressInterval);   //Display settings data                                        
          }
        }
      }
      if(subMenuPage==1){
        lcd.setCursor(10,0);lcd.print(" min  ");
        lcd.setCursor(2,1);lcd.print(min4);lcd.print("           ");
        if(digitalRead(buttonBack)==1){while(digitalRead(buttonBack)==1){}subMenuPage=0;} 
        if(digitalRead(buttonSelect)==1){while(digitalRead(buttonSelect)==1){}subMenuPage=2;}     
        currentMenuSetMillis = millis();
        if(digitalRead(buttonRight)==1){                                                    //Right button press (increments setting values)
          while(digitalRead(buttonRight)==1){
            if(millis()-currentMenuSetMillis>longPressTime){                                //Long Press     
              min4 += 5;                                                    //Increment by 5
              min4 = constrain(min4,0,59); //Limit settings values to a range
              lcd.setCursor(2,1);lcd.print(min4);delay(longPressInterval);   //Display settings data                               
            }
            else{                                                                           //Short Press  
              min4 += 1;                                                    //Increment by 1
              min4 = constrain(min4,0,59); //Limit settings values to a range
              lcd.setCursor(2,1);lcd.print(min4);delay(shortPressInterval);  //Display settings data                            
            } 
          }
        }
        else if(digitalRead(buttonLeft)==1){                                                //Left button press (decrements setting values)
          while(digitalRead(buttonLeft)==1){
            if(millis()-currentMenuSetMillis>longPressTime){                                //Long Press     
              min4 -= 5;                                                    //decrement by 5
              min4 = constrain(min4,0,59); //Limit settings values to a range
              lcd.setCursor(2,1);lcd.print(min4);delay(longPressInterval);   //Display settings data                               
            }
            else{                                                                            //Short Press  
              min4 -= 1;                                                     //decrement by 1
              min4 =  constrain(min4,0,59); //Limit settings values to a range
              lcd.setCursor(2,1);lcd.print(min4);delay(shortPressInterval);   //Display settings data                                      
            }
          }
        }
      }
      if(subMenuPage==2){
        lcd.setCursor(10,0);lcd.print("Take No");
        lcd.setCursor(2,1);lcd.print(takeTimes4);lcd.print("           ");
        if(digitalRead(buttonBack)==1){while(digitalRead(buttonBack)==1){}subMenuPage=1;} 
        if(digitalRead(buttonSelect)==1){while(digitalRead(buttonSelect)==1){}saveSettings();dataSend=1;subMenuPage=0;menuPage=3;setMenuPage=0;}     
        if(digitalRead(buttonRight)==1){                                                    //Right button press (increments setting values)
          while(digitalRead(buttonRight)==1){
            takeTimes4 += 1;                                                    //Increment by 1
            takeTimes4 = constrain(takeTimes4,1,4); //Limit settings values to a range
            lcd.setCursor(2,1);lcd.print(takeTimes4);delay(shortPressInterval);  //Display settings data                            
          }
        }
        else if(digitalRead(buttonLeft)==1){                                                //Left button press (decrements setting values)
          while(digitalRead(buttonLeft)==1){
            takeTimes4 -= 1;                                                    //decrement by 1
            takeTimes4 =  constrain(takeTimes4,1,4); //Limit settings values to a range
            lcd.setCursor(2,1);lcd.print(takeTimes4);delay(shortPressInterval);   //Display settings data                                        
          }
        }
      }   
    }

    else if(menuPage==4 && setMenuPage==1){
      lcd.setCursor(0,0);lcd.print("BACKLIGHT SLEEP ");
      lcd.setCursor(0,1);lcd.print(" >");
      lcd.setCursor(2,1);
      if(backlightSleepMode==1)     {lcd.print("10 SECONDS    ");}
      else if(backlightSleepMode==2){lcd.print("5 MINUTES     ");}
      else if(backlightSleepMode==3){lcd.print("1 HOUR        ");}
      else if(backlightSleepMode==4){lcd.print("6 HOURS       ");}  
      else if(backlightSleepMode==5){lcd.print("12 HOURS      ");}  
      else if(backlightSleepMode==6){lcd.print("1 DAY         ");}
      else if(backlightSleepMode==7){lcd.print("3 DAYS        ");}
      else if(backlightSleepMode==8){lcd.print("1 WEEK        ");}
      else if(backlightSleepMode==9){lcd.print("1 MONTH       ");}     
      else{lcd.print("NEVER         ");}    
      
      //SET MENU - INTMODETYPE
      if(digitalRead(buttonBack)==1){while(digitalRead(buttonBack)==1){}subMenuPage=0;menuPage=4;setMenuPage=0;} 
      if(digitalRead(buttonSelect)==1){while(digitalRead(buttonSelect)==1){}saveSettings();subMenuPage=0;menuPage=4;setMenuPage=0;}     
      if(digitalRead(buttonRight)==1){                                                  //Right button press (increments setting values)
        backlightSleepMode++;                                                           //Increment by 1
        backlightSleepMode = constrain(backlightSleepMode,0,9);                         //Limit settings values to a range   
        while(digitalRead(buttonRight)==1){} 
      }
      else if(digitalRead(buttonLeft)==1){                                              //Left button press (decrements setting values)
        backlightSleepMode--;                                                           //decrement by 1
        backlightSleepMode = constrain(backlightSleepMode,0,9);                         //Limit settings values to a range   
        while(digitalRead(buttonLeft)==1){} 
      }       
    }
    ///// SETTINGS MENU ITEM: FACTORY RESET /////
    if(menuPage==5 && setMenuPage==1){
      if(confirmationMenu==0){lcd.setCursor(0,0);lcd.print(" ARE YOU SURE?  ");lcd.setCursor(0,1);lcd.print("  >NO      YES  ");}  // Display ">No"
      else{lcd.setCursor(0,0);lcd.print(" ARE YOU SURE?  ");lcd.setCursor(0,1);lcd.print("   NO     >YES  ");}                     // Display ">YES"
      if(digitalRead(buttonRight)==1||digitalRead(buttonLeft)==1){while(digitalRead(buttonRight)==1||digitalRead(buttonLeft)==1){}if(confirmationMenu==0){confirmationMenu=1;}else{confirmationMenu=0;}}  //Cycle Yes NO
      if(digitalRead(buttonBack)==1){while(digitalRead(buttonBack)==1){}setMenuPage=0;confirmationMenu=0;menuPage=5;settingMode=1;} //Cancel
      if(digitalRead(buttonSelect)==1){while(digitalRead(buttonSelect)==1){}if(confirmationMenu==1){factoryReset();}setMenuPage=0;confirmationMenu=0;subMenuPage=0;settingMode=0;menuPage=0;dataSend=1;}
  
    }
  }

  
  //MAIN MENU
  else if(settingMode==0){

    //LCD BACKLIGHT SLEEP
    lcdBacklight();

    //BUTTON KEYPRESS
    if(digitalRead(buttonRight)==1) {buttonRightCommand=1;lcdBacklight_Wake();}
    if(digitalRead(buttonLeft)==1)  {buttonLeftCommand=1;lcdBacklight_Wake();}
    if(digitalRead(buttonBack)==1)  {buttonBackCommand=1;lcdBacklight_Wake();}
    if(digitalRead(buttonSelect)==1){buttonSelectCommand=1;lcdBacklight_Wake();}
    
    currentLCDMillis = millis();
    if(currentLCDMillis-prevLCDMillis>=millisLCDInterval){   //Run routine every millisLCDInterval (ms)
      prevLCDMillis = currentLCDMillis;     

      //MENU PAGE BUTTON ACTION
      //if(buttonRightCommand==1)      {buttonRightCommand=0;menuPage++;lcd.clear();}
      //else if(buttonLeftCommand==1)  {buttonLeftCommand=0;menuPage--;lcd.clear();}
      //else if(buttonBackCommand==1)  {buttonBackCommand=0;menuPage=0;lcd.clear();}
      if(buttonSelectCommand==1){buttonSelectCommand=0;settingMode=1;menuPage=0;lcd.clear();}
      
      //if(menuPage>menuPages){menuPage=0;}
      //else if(menuPage<0){menuPage=menuPages;}  

      displayConfig1();
      //else if(menuPage==1){displayConfig2();}
      //else if(menuPage==2){displayConfig3();}
      //else if(menuPage==3){displayConfig4();}
      //else if(menuPage==4){displayConfig5();}
      //else if(menuPage==5){displayConfig6();}
    }
  }
}

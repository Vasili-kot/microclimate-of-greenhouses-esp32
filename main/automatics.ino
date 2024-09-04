void temptimeendh(int timeh, int timem, int timeworkh, int timeworkm)
{
  temprtchmend = timem + timeworkm;
  if (temprtchmend>59){
    temprtchhend++;
    temprtchmend-=60;
  }
  temprtchhend = timeh + timeworkh;
  if (temprtchhend>23){
    temprtchhend-=24;
  }
}
void temptimeendc(int timeh, int timem, int timeworkh, int timeworkm)
{
  temprtccmend = timem + timeworkm;
  if (temprtccmend>59){
    temprtcchend++;
    temprtccmend-=60;
  }
  temprtcchend = timeh + timeworkh;
  if (temprtcchend>23){
    temprtcchend-=24;
  }
}
void lighttimeend(int timeh, int timem, int timeworkh, int timeworkm)
{
  lightrtcmend = timem + timeworkm;
  if (lightrtcmend>59){
    lightrtchend++;
    lightrtcmend-=60;
  }
  lightrtchend = timeh + timeworkh;
  if (lightrtchend>23){
    lightrtchend-=24;
  }
}
void moisttimeend(int timeh, int timem, int timeworkh, int timeworkm)
{
  moistrtcmend = timem + timeworkm;
  if (moistrtcmend>59){
    moistrtchend++;
    moistrtcmend-=60;
  }
  moistrtchend = timeh + timeworkh;
  if (moistrtchend>23){
    moistrtchend-=24;
  }
}

void relay1timeend(int timeh, int timem, int timeworkh, int timeworkm)
{
  relay1rtcmend = timem + timeworkm;
  if (relay1rtcmend>59){
    relay1rtchend++;
    relay1rtcmend-=60;
  }
  relay1rtchend = timeh + timeworkh;
  if (relay1rtchend>23){
    relay1rtchend-=24;
  }
}

void relay2timeend(int timeh, int timem, int timeworkh, int timeworkm)
{
  relay2rtcmend = timem + timeworkm;
  if (relay2rtcmend>59){
    relay2rtchend++;
    relay2rtcmend-=60;
  }
  relay2rtchend = timeh + timeworkh;
  if (relay2rtchend>23){
    relay2rtchend-=24;
  }
}

void servo1timeend(int timeh, int timem, int timeworkh, int timeworkm)
{
  servo1rtcmend = timem + timeworkm;
  if (servo1rtcmend>59){
    servo1rtchend++;
    servo1rtcmend-=60;
  }
  servo1rtchend = timeh + timeworkh;
  if (servo1rtchend>23){
    servo1rtchend-=24;
  }
}

void servo2timeend(int timeh, int timem, int timeworkh, int timeworkm)
{
  servo2rtcmend = timem + timeworkm;
  if (servo2rtcmend>59){
    servo2rtchend++;
    servo2rtcmend-=60;
  }
  servo2rtchend = timeh + timeworkh;
  if (servo2rtchend>23){
    servo2rtchend-=24;
  }
}

void actuatortimeend(int timeh, int timem, int timeworkh, int timeworkm)
{
  actuatorrtcmend = timem + timeworkm;
  if (actuatorrtcmend>59){
    actuatorrtchend++;
    actuatorrtcmend-=60;
  }
  actuatorrtchend = timeh + timeworkh;
  if (actuatorrtchend>23){
    actuatorrtchend-=24;
  }
}

void temprelayh(unsigned long currentMillis)
{
  if(tempcontrolh==0){
      pcf8574.digitalWrite(relaypinheater, HIGH);
  }else if (tempcontrolh==1){
    if(tempcontmodeh==0){    
      if (celsiusdefault>tempuser+tempplus){
        pcf8574.digitalWrite(relaypinheater, HIGH);
      }else if (celsiusdefault<tempuser-tempplus){
        pcf8574.digitalWrite(relaypinheater, LOW);
      }
    } else if (tempcontmodeh==1){
        if (temptimerhstarted==0){
          if ((temptimerstarthm==minutenow)&&(temptimerstarthh==hournow)){
          temptimerhstarted = 1;
          prevmillistimerh = currentMillis;
        }
        } else if (temptimerhstarted==1){
          if (currentMillis - prevmillistimerh >= temptimerintervalh) {
            prevmillistimerh = currentMillis;
            if (temptimerhen==0){
              pcf8574.digitalWrite(relaypinheater, LOW);
              temptimerhen=1;
              temptimerintervalh = timetoms(temptimerworkhh,temptimerworkhm);
            } else if (temptimerhen==1){
              pcf8574.digitalWrite(relaypinheater, HIGH);
              temptimerhen=0;
              temptimerintervalh = timetoms(temptimerhh,temptimerhm);
            }
          }
        }
    } else if (tempcontmodeh==2){
      if (!temprtchen){
        if ((temprtchm==minutenow)&&(temprtchh==hournow)){
          pcf8574.digitalWrite(relaypinheater, LOW);
          temprtchen = 1;
        }
      } else if (temprtchen){
        if ((temprtchmend==minutenow)&&(temprtchhend==hournow)){
          pcf8574.digitalWrite(relaypinheater, HIGH);
          temprtchen = 0;
        }
      }
    } else if (tempcontmodeh==3){ 
      pcf8574.digitalWrite(relaypinheater, LOW);
    }
  } 
}

void temprelayc(unsigned long currentMillis)
{
  if(tempcontrolc==0){
      pcf8574.digitalWrite(relaypincooler, HIGH);
  }else if (tempcontrolc==1){
    if(tempcontmodec==0){    
      if (celsiusdefault<tempuser-tempplus){
        pcf8574.digitalWrite(relaypincooler, HIGH);
      }else if (celsiusdefault>tempuser+tempplus){
        pcf8574.digitalWrite(relaypincooler, LOW);
      }
    } else if (tempcontmodec==1){
        if (temptimercstarted==0){
          if ((temptimerstartcm==minutenow)&&(temptimerstartch==hournow)){
          temptimercstarted = 1;
          prevmillistimerc = currentMillis;
        }
        } else if (temptimercstarted==1){
          if (currentMillis - prevmillistimerc >= temptimerintervalc) {
            prevmillistimerc = currentMillis;
            if (temptimercen==0){
              pcf8574.digitalWrite(relaypincooler, LOW);
              temptimercen=1;
              temptimerintervalc = timetoms(temptimerworkch,temptimerworkcm);
            } else if (temptimercen==1){
              pcf8574.digitalWrite(relaypincooler, HIGH);
              temptimercen=0;
              temptimerintervalc = timetoms(temptimerch,temptimercm);
            }
          }
        }
    } else if (tempcontmodec==2){
      if (!temprtccen){
        if ((temprtccm==minutenow)&&(temprtcch==hournow)){
          pcf8574.digitalWrite(relaypincooler, LOW);
          temprtccen = 1;
        }
      } else if (temprtccen){
        if ((temprtccmend==minutenow)&&(temprtcchend==hournow)){
          pcf8574.digitalWrite(relaypincooler, HIGH);
          temprtccen = 0;
        }
      }
    } else if (tempcontmodec==3){ 
      pcf8574.digitalWrite(relaypincooler, LOW);
    }
  } 
}

void lightrelay(unsigned long currentMillis)
{
  if(lightcontrol==0){
      pcf8574.digitalWrite(relaypinlight, HIGH);
  }else if (lightcontrol==1){
    if(lightcontmode==0){    
      if (light>lightuser+lightplus){
        pcf8574.digitalWrite(relaypinlight, HIGH);
      }else if (light<lightuser-lightplus){
        pcf8574.digitalWrite(relaypinlight, LOW);
      }
    } else if (lightcontmode==1){
        if (lighttimerstarted==0){
          if ((lighttimerstartm==minutenow)&&(lighttimerstarth==hournow)){
          lighttimerstarted = 1;
          prevmillistimerlight = currentMillis;
        }
        } else if (lighttimerstarted==1){
          if (currentMillis - prevmillistimerlight >= lighttimerinterval) {
            prevmillistimerlight = currentMillis;
            if (lighttimeren==0){
              pcf8574.digitalWrite(relaypinlight, LOW);
              lighttimeren=1;
              lighttimerinterval = timetoms(lighttimerworkh,lighttimerworkm);
            } else if (lighttimeren==1){
              pcf8574.digitalWrite(relaypinlight, HIGH);
              lighttimeren=0;
              lighttimerinterval = timetoms(lighttimerh,lighttimerm);
            }
          }
        }
    } else if (lightcontmode==2){
      if (!lightrtcen){
        if ((lightrtcm==minutenow)&&(lightrtch==hournow)){
          pcf8574.digitalWrite(relaypinlight, LOW);
          lightrtcen = 1;
        }
      } else if (lightrtcen){
        if ((lightrtcmend==minutenow)&&(lightrtchend==hournow)){
          pcf8574.digitalWrite(relaypinlight, HIGH);
          lightrtcen = 0;
        }
      }
    } else if (lightcontmode==3){ 
      pcf8574.digitalWrite(relaypinlight, LOW);
    }
  } 
}

void moistrelay(unsigned long currentMillis)
{
  if(moistcontrol==0){
      pcf8574.digitalWrite(relaypinmoist, HIGH);
  }else if (moistcontrol==1){
    if(moistcontmode==0){    
      if (moisture>moistuser+moistplus){
        pcf8574.digitalWrite(relaypinmoist, HIGH);
      }else if (moisture<moistuser-moistplus){
        pcf8574.digitalWrite(relaypinmoist, LOW);
      }
    } else if (moistcontmode==1){
        if (moisttimerstarted==0){
          if ((moisttimerstartm==minutenow)&&(moisttimerstarth==hournow)){
          moisttimerstarted = 1;
          prevmillistimermoist = currentMillis;
        }
        } else if (moisttimerstarted==1){
          if (currentMillis - prevmillistimermoist >= moisttimerinterval) {
            prevmillistimermoist = currentMillis;
            if (moisttimeren==0){
              pcf8574.digitalWrite(relaypinmoist, LOW);
              moisttimeren=1;
              moisttimerinterval = timetoms(moisttimerworkh,moisttimerworkm);
            } else if (moisttimeren==1){
              pcf8574.digitalWrite(relaypinmoist, HIGH);
              moisttimeren=0;
              moisttimerinterval = timetoms(moisttimerh,moisttimerm);
            }
          }
        }
    } else if (moistcontmode==2){
      if (!moistrtcen){
        if ((moistrtcm==minutenow)&&(moistrtch==hournow)){
          pcf8574.digitalWrite(relaypinmoist, LOW);
          moistrtcen = 1;
        }
      } else if (moistrtcen){
        if ((moistrtcmend==minutenow)&&(moistrtchend==hournow)){
          pcf8574.digitalWrite(relaypinmoist, HIGH);
          moistrtcen = 0;
        }
      }
    } else if (moistcontmode==3){ 
      pcf8574.digitalWrite(relaypinmoist, LOW);
    }
  } 
}

void relay1relay(unsigned long currentMillis)
{
  if(relay1control==0){
    if(usermoderelay1direction==0) pcf8574.digitalWrite(relaypinuser1, HIGH);
    else pcf8574.digitalWrite(relaypinuser1, LOW);
  }else if (relay1control==1){
    if(relay1contmode==0){    
      if (relay1sensorvalue>relay1user+relay1plus){
        if(usermoderelay1direction==0) pcf8574.digitalWrite(relaypinuser1, HIGH);
        else pcf8574.digitalWrite(relaypinuser1, LOW);
      }else if (relay1sensorvalue<relay1user-relay1plus){
        if(usermoderelay1direction==0) pcf8574.digitalWrite(relaypinuser1, LOW);
        else pcf8574.digitalWrite(relaypinuser1, HIGH);
      }
    } else if (relay1contmode==1){
        if (relay1timerstarted==0){
          if ((relay1timerstartm==minutenow)&&(relay1timerstarth==hournow)){
          relay1timerstarted = 1;
          prevmillistimerrelay1 = currentMillis;
        }
        } else if (relay1timerstarted==1){
          if (currentMillis - prevmillistimerrelay1 >= relay1timerinterval) {
            prevmillistimerrelay1 = currentMillis;
            if (relay1timeren==0){
              if(usermoderelay1direction==0) pcf8574.digitalWrite(relaypinuser1, LOW);
              else pcf8574.digitalWrite(relaypinuser1, HIGH);
              relay1timeren=1;
              relay1timerinterval = timetoms(relay1timerworkh,relay1timerworkm);
            } else if (relay1timeren==1){
              if(usermoderelay1direction==0) pcf8574.digitalWrite(relaypinuser1, HIGH);
              else pcf8574.digitalWrite(relaypinuser1, LOW);
              relay1timeren=0;
              relay1timerinterval = timetoms(relay1timerh,relay1timerm);
            }
          }
        }
    } else if (relay1contmode==2){
      if (!relay1rtcen){
        if ((relay1rtcm==minutenow)&&(relay1rtch==hournow)){
          if(usermoderelay1direction==0) pcf8574.digitalWrite(relaypinuser1, LOW);
          else pcf8574.digitalWrite(relaypinuser1, HIGH);
          relay1rtcen = 1;
        }
      } else if (relay1rtcen){
        if ((relay1rtcmend==minutenow)&&(relay1rtchend==hournow)){
          if(usermoderelay1direction==0) pcf8574.digitalWrite(relaypinuser1, HIGH);
          else pcf8574.digitalWrite(relaypinuser1, LOW);
          relay1rtcen = 0;
        }
      }
    } else if (relay1contmode==3){ 
      if(usermoderelay1direction==0) pcf8574.digitalWrite(relaypinuser1, LOW);
      else pcf8574.digitalWrite(relaypinuser1, HIGH);
    }
  } 
}

void relay2relay(unsigned long currentMillis)
{
  if(relay2control==0){
    if(usermoderelay2direction==0) pcf8574.digitalWrite(relaypinuser2, HIGH);
    else pcf8574.digitalWrite(relaypinuser2, LOW);
  }else if (relay2control==1){
    if(relay2contmode==0){    
      if (relay2sensorvalue>relay2user+relay2plus){
        if(usermoderelay2direction==0) pcf8574.digitalWrite(relaypinuser2, HIGH);
        else pcf8574.digitalWrite(relaypinuser2, LOW);
      }else if (relay2sensorvalue<relay2user-relay2plus){
        if(usermoderelay2direction==0) pcf8574.digitalWrite(relaypinuser2, LOW);
        else pcf8574.digitalWrite(relaypinuser2, HIGH);
      }
    } else if (relay2contmode==1){
        if (relay2timerstarted==0){
          if ((relay2timerstartm==minutenow)&&(relay2timerstarth==hournow)){
          relay2timerstarted = 1;
          prevmillistimerrelay2 = currentMillis;
        }
        } else if (relay2timerstarted==1){
          if (currentMillis - prevmillistimerrelay2 >= relay2timerinterval) {
            prevmillistimerrelay2 = currentMillis;
            if (relay2timeren==0){
              if(usermoderelay2direction==0) pcf8574.digitalWrite(relaypinuser2, LOW);
              else pcf8574.digitalWrite(relaypinuser2, HIGH);
              relay2timeren=1;
              relay2timerinterval = timetoms(relay2timerworkh,relay2timerworkm);
            } else if (relay2timeren==1){
              if(usermoderelay2direction==0) pcf8574.digitalWrite(relaypinuser2, HIGH);
              else pcf8574.digitalWrite(relaypinuser2, LOW);
              relay2timeren=0;
              relay2timerinterval = timetoms(relay2timerh,relay2timerm);
            }
          }
        }
    } else if (relay2contmode==2){
      if (!relay2rtcen){
        if ((relay2rtcm==minutenow)&&(relay2rtch==hournow)){
          if(usermoderelay2direction==0) pcf8574.digitalWrite(relaypinuser2, LOW);
          else pcf8574.digitalWrite(relaypinuser2, HIGH);
          relay2rtcen = 1;
        }
      } else if (relay2rtcen){
        if ((relay2rtcmend==minutenow)&&(relay2rtchend==hournow)){
          if(usermoderelay2direction==0) pcf8574.digitalWrite(relaypinuser2, HIGH);
          else pcf8574.digitalWrite(relaypinuser2, LOW);
          relay2rtcen = 0;
        }
      }
    } else if (relay2contmode==3){ 
      if(usermoderelay2direction==0) pcf8574.digitalWrite(relaypinuser2, LOW);
      else pcf8574.digitalWrite(relaypinuser2, HIGH);
    }
  } 
}

void servo1relay(unsigned long currentMillis)
{
  if(servo1control==0){
    if(usermodeservo1direction==0) servo1.setTargetDeg(servo1start);
    else servo1.setTargetDeg(servo1stop);
  }else if (servo1control==1){
    if(servo1contmode==0){    
      if (servo1sensorvalue>servo1user+servo1plus){
        if(usermodeservo1direction==0) servo1.setTargetDeg(servo1start);
        else servo1.setTargetDeg(servo1stop);
      }else if (servo1sensorvalue<servo1user-servo1plus){
        if(usermodeservo1direction==0) servo1.setTargetDeg(servo1stop);
        else servo1.setTargetDeg(servo1start);
      }
    } else if (servo1contmode==1){
        if (servo1timerstarted==0){
          if ((servo1timerstartm==minutenow)&&(servo1timerstarth==hournow)){
          servo1timerstarted = 1;
          prevmillistimerservo1 = currentMillis;
        }
        } else if (servo1timerstarted==1){
          if (currentMillis - prevmillistimerservo1 >= servo1timerinterval) {
            prevmillistimerservo1 = currentMillis;
            if (servo1timeren==0){
              if(usermodeservo1direction==0) servo1.setTargetDeg(servo1stop);
              else servo1.setTargetDeg(servo1start);
              servo1timeren=1;
              servo1timerinterval = timetoms(servo1timerworkh,servo1timerworkm);
            } else if (servo1timeren==1){
              if(usermodeservo1direction==0) servo1.setTargetDeg(servo1start);
              else servo1.setTargetDeg(servo1stop);
              servo1timeren=0;
              servo1timerinterval = timetoms(servo1timerh,servo1timerm);
            }
          }
        }
    } else if (servo1contmode==2){
      if (!servo1rtcen){
        if ((servo1rtcm==minutenow)&&(servo1rtch==hournow)){
          if(usermodeservo1direction==0) servo1.setTargetDeg(servo1stop);
          else servo1.setTargetDeg(servo1start);
          servo1rtcen = 1;
        }
      } else if (servo1rtcen){
        if ((servo1rtcmend==minutenow)&&(servo1rtchend==hournow)){
          if(usermodeservo1direction==0) servo1.setTargetDeg(servo1start);
          else servo1.setTargetDeg(servo1stop);
          servo1rtcen = 0;
        }
      }
    } else if (servo1contmode==3){ 
      if(usermodeservo1direction==0) servo1.setTargetDeg(servo1stop);
      else servo1.setTargetDeg(servo1start);
    }
  } 
}

void servo2relay(unsigned long currentMillis)
{
  if(servo2control==0){
    if(usermodeservo2direction==0) servo2.setTargetDeg(servo2start);
    else servo2.setTargetDeg(servo2stop);
  }else if (servo2control==1){
    if(servo2contmode==0){    
      if (servo2sensorvalue>servo2user+servo2plus){
        if(usermodeservo2direction==0) servo2.setTargetDeg(servo2start);
        else servo2.setTargetDeg(servo2stop);
      }else if (servo2sensorvalue<servo2user-servo2plus){
        if(usermodeservo2direction==0) servo2.setTargetDeg(servo2stop);
        else servo2.setTargetDeg(servo2start);
      }
    } else if (servo2contmode==1){
        if (servo2timerstarted==0){
          if ((servo2timerstartm==minutenow)&&(servo2timerstarth==hournow)){
          servo2timerstarted = 1;
          prevmillistimerservo2 = currentMillis;
        }
        } else if (servo2timerstarted==1){
          if (currentMillis - prevmillistimerservo2 >= servo2timerinterval) {
            prevmillistimerservo2 = currentMillis;
            if (servo2timeren==0){
              if(usermodeservo2direction==0) servo2.setTargetDeg(servo2stop);
              else servo2.setTargetDeg(servo2start);
              servo2timeren=1;
              servo2timerinterval = timetoms(servo2timerworkh,servo2timerworkm);
            } else if (servo2timeren==1){
              if(usermodeservo2direction==0) servo2.setTargetDeg(servo2start);
              else servo2.setTargetDeg(servo2stop);
              servo2timeren=0;
              servo2timerinterval = timetoms(servo2timerh,servo2timerm);
            }
          }
        }
    } else if (servo2contmode==2){
      if (!servo2rtcen){
        if ((servo2rtcm==minutenow)&&(servo2rtch==hournow)){
          if(usermodeservo2direction==0) servo2.setTargetDeg(servo2stop);
          else servo2.setTargetDeg(servo2start);
          servo2rtcen = 1;
        }
      } else if (servo2rtcen){
        if ((servo2rtcmend==minutenow)&&(servo2rtchend==hournow)){
          if(usermodeservo2direction==0) servo2.setTargetDeg(servo2start);
          else servo2.setTargetDeg(servo2stop);
          servo2rtcen = 0;
        }
      }
    } else if (servo2contmode==3){ 
      if(usermodeservo2direction==0) servo2.setTargetDeg(servo2stop);
      else servo2.setTargetDeg(servo2start);
    }
  } 
}

void actuatorrelay(unsigned long currentMillis)
{
  if(actuatorcontrol==0){
    actuatorwork(0, currentMillis);
  }else if (actuatorcontrol==1){
    if(actuatorcontmode==0){    
      if (actuatorsensorvalue>actuatoruser+actuatorplus){
        actuatorwork(0, currentMillis);
      }else if (actuatorsensorvalue<actuatoruser-actuatorplus){
        actuatorwork(1, currentMillis);
      }
    } else if (actuatorcontmode==1){
        if (actuatortimerstarted==0){
          if ((actuatortimerstartm==minutenow)&&(actuatortimerstarth==hournow)){
          actuatortimerstarted = 1;
          prevmillistimeractuator = currentMillis;
        }
        } else if (actuatortimerstarted==1){
          if (currentMillis - prevmillistimeractuator >= actuatortimerinterval) {
            prevmillistimeractuator = currentMillis;
            if (actuatortimeren==0){
              actuatorwork(1, currentMillis);
              actuatortimeren=1;
              actuatortimerinterval = timetoms(actuatortimerworkh,actuatortimerworkm);
            } else if (actuatortimeren==1){
              actuatorwork(0, currentMillis);
              actuatortimeren=0;
              actuatortimerinterval = timetoms(actuatortimerh,actuatortimerm);
            }
          }
        }
    } else if (actuatorcontmode==2){
      if (!actuatorrtcen){
        if ((actuatorrtcm==minutenow)&&(actuatorrtch==hournow)){
          actuatorwork(1, currentMillis);
          actuatorrtcen = 1;
        }
      } else if (actuatorrtcen){
        if ((actuatorrtcmend==minutenow)&&(actuatorrtchend==hournow)){
          actuatorwork(0, currentMillis);
          actuatorrtcen = 0;
        }
      }
    } else if (actuatorcontmode==3){ 
      actuatorwork(1, currentMillis);
    }
  } 
}


void actuatorwork(int open,unsigned long currentmillis)
{ 
  if(actuatorstart == 1){
    if (currentmillis - actuatorstartmillis >= actuatortimeout*1000) {
      pcf8574.digitalWrite(relaypinmotor1, HIGH);
      pcf8574.digitalWrite(relaypinmotor2, HIGH);
      if (actuatoropened==1) actuatoropened=0;
      else actuatoropened=1;
      actuatorstart=0;
    }
  } else if (actuatorstart == 0){
    if (open == 0){
      if (actuatoropened==1){
        if(usermodeactuatordirection==0){
          pcf8574.digitalWrite(relaypinmotor1, HIGH);
          pcf8574.digitalWrite(relaypinmotor2, LOW);
        } else{
          pcf8574.digitalWrite(relaypinmotor1, LOW);
          pcf8574.digitalWrite(relaypinmotor2, HIGH);
        } 
        actuatorstartmillis = currentmillis;
        actuatorstart = 1;
      } 
    } else if (open == 1){
      if (actuatoropened==0){
        if(usermodeactuatordirection==0){
          pcf8574.digitalWrite(relaypinmotor1, LOW);
          pcf8574.digitalWrite(relaypinmotor2, HIGH);
        } else{
          pcf8574.digitalWrite(relaypinmotor1, HIGH);
          pcf8574.digitalWrite(relaypinmotor2, LOW);
        } 
        actuatorstartmillis = currentmillis;
        actuatorstart = 1;
      } 
    }
  }
}
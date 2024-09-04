/*----------------------------------редактирование и отрисовка меню света-----------------------*/

void setmoisture(int selmoist)
{
  tft.loadFont(FONT_22); 
  tft.setTextColor(TFT_BLACK);
  tft.setTextSize(2);
  tft.fillRect(0,0,320,40,TFT_GREEN);
  tft.setCursor(10,10);
  tft.print("ПОЛИВ");
  tft.fillRect(0,40,320,160,TFT_MAGENTA);
  tft.fillRect(0,200,320,40,TFT_GREEN);
  tft.setCursor(10,210);
  tft.print("Сейчас ");
  tft.setTextColor(TFT_WHITE);

  if (moistcontrol==0){
    tft.setCursor(10,50);
    tft.print("Контроль отключен");

  }else if (moistcontrol==1){
    tft.setCursor(10,50);
    tft.print("Контроль полива включен");
    if (moistcontmode==0) {
      tft.setCursor(10,90);
      tft.print("Режим АВТО");
      tft.setCursor(10,130);
      tft.print("Полив если ниже ");
      tft.unloadFont();
      tft.setTextSize(2);
      tft.print(moistuser,0);
      tft.setCursor(225,130);
      tft.print("%");
      tft.print("+-");
      tft.print(moistplus,0);
      tft.setCursor(291,130);
      tft.print("%");
      tft.loadFont(FONT_22); 
    } else if (moistcontmode==1) {
      tft.setCursor(10,90);
      tft.print("Режим по таймеру");
      tft.setCursor(10,130);
      tft.print("Полив раз в ");
      tft.unloadFont();
      if(moisttimerh<10)tft.print("0");
      tft.print(moisttimerh);
      tft.print(":");
      if(moisttimerm<10)tft.print("0");
      tft.print(moisttimerm);
      tft.setCursor(200,130);
      tft.loadFont(FONT_22);
      tft.print("на ");   
      tft.unloadFont();
      if(moisttimerworkh<10)tft.print("0");
      tft.print(moisttimerworkh);
      tft.print(":");
      if(moisttimerworkm<10)tft.print("0");
      tft.print(moisttimerworkm);
      tft.loadFont(FONT_22);
      tft.setCursor(10,170);
      tft.print("Запустить таймер в  ");
      tft.unloadFont();
      if(moisttimerstarth<10)tft.print("0");
      tft.print(moisttimerstarth);
      tft.print(":");
      if(moisttimerstartm<10)tft.print("0");
      tft.print(moisttimerstartm);
    } else if (moistcontmode==2) {
      tft.setCursor(10,90);
      tft.print("Режим суточный");
      tft.setCursor(10,130);
      tft.print("Полив в ");
      tft.unloadFont();
      if(moistrtch<10)tft.print("0");
      tft.print(moistrtch);
      tft.print(":");
      if(moistrtcm<10)tft.print("0");
      tft.print(moistrtcm);
      tft.setCursor(162,130);
      tft.loadFont(FONT_22);
      tft.print("на ");   
      tft.unloadFont();
      if(moistrtcworkh<10)tft.print("0");
      tft.print(moistrtcworkh);
      tft.print(":");
      if(moistrtcworkm<10)tft.print("0");
      tft.print(moistrtcworkm);

    } else if (moistcontmode==3) {
      tft.setCursor(10,90);
      tft.print("Режим всегда включен");
    }

  }
  tft.unloadFont(); 

  if(selmoist==1)  
  Selmoist_1();
  else if(selmoist==2)  
  Selmoist_2();
  else if(selmoist==3)  
  Selmoist_3();
  else if(selmoist==4)  
  Selmoist_4();
}

void Selmoist_1()
{
  tft.loadFont(FONT_22); 
  tft.fillRect(0,40,320,40,TFT_RED);
  tft.setCursor(10,50);
  if (moistcontrol==0){
    tft.print("Контроль отключен");
  }else if (moistcontrol==1){
    tft.print("Контроль полива включен");
  }
  tft.unloadFont();
}
void Selmoist_2()
{
  tft.loadFont(FONT_22); 
  tft.fillRect(0,80,320,40,TFT_RED);
  tft.setCursor(10,90);
  if (moistcontrol!=0){
    if (moistcontmode==0) {
      tft.print("Режим АВТО");
    } else if (moistcontmode==1) {
      tft.print("Режим по таймеру");
    } else if (moistcontmode==2) {
      tft.print("Режим суточный");
    } else if (moistcontmode==3) {
      tft.print("Режим всегда включен");
    }
  tft.unloadFont();
  }
}
void Selmoist_3()
{
  tft.loadFont(FONT_22); 
  tft.fillRect(0,120,320,40,TFT_RED);
  tft.setTextSize(2);
  tft.setCursor(10,130);
  if (moistcontrol==1){
    if (moistcontmode==0) {
      tft.print("Полив если ниже ");
      tft.unloadFont();
      tft.setTextSize(2);
      tft.print(moistuser,0);
      tft.setCursor(225,130);
      tft.print("%");
      tft.print("+-");
      tft.print(moistplus,0);
      tft.setCursor(291,130);
      tft.print("%");
      if(seledit==0)
      editmoistuser();
      else editmoistplus();
      tft.loadFont(FONT_22); 
    } else if (moistcontmode==1) {
      tft.print("Полив раз в ");
      tft.unloadFont();
      if(moisttimerh<10)tft.print("0");
      tft.print(moisttimerh);
      tft.print(":");
      if(moisttimerm<10)tft.print("0");
      tft.print(moisttimerm);
      tft.setCursor(200,130);
      tft.loadFont(FONT_22);
      tft.print("на ");   
      tft.unloadFont();
      if(moisttimerworkh<10)tft.print("0");
      tft.print(moisttimerworkh);
      tft.print(":");
      if(moisttimerworkm<10)tft.print("0");
      tft.print(moisttimerworkm);
      tft.unloadFont();
      if(seledit==0)
      editmoisttimer();
      else editmoisttimerwork();
    } else if (moistcontmode==2) {
      tft.print("Полив в ");
      tft.unloadFont();
      if(moistrtch<10)tft.print("0");
      tft.print(moistrtch);
      tft.print(":");
      if(moistrtcm<10)tft.print("0");
      tft.print(moistrtcm);
      tft.setCursor(162,130);
      tft.loadFont(FONT_22);
      tft.print("на ");   
      tft.unloadFont();
      if(moistrtcworkh<10)tft.print("0");
      tft.print(moistrtcworkh);
      tft.print(":");
      if(moistrtcworkm<10)tft.print("0");
      tft.print(moistrtcworkm);
      if(seledit==0)
      editmoistrtc();
      else editmoistrtcwork();
    }
  }
  tft.unloadFont();
}
void Selmoist_4()
{
  tft.loadFont(FONT_22); 
  tft.fillRect(0,160,320,40,TFT_RED);
  tft.setCursor(10,170);
  tft.print("Запустить таймер в  ");
  tft.unloadFont();
  if(moisttimerstarth<10)tft.print("0");
  tft.print(moisttimerstarth);
  tft.print(":");
  if(moisttimerstartm<10)tft.print("0");
  tft.print(moisttimerstartm);
  tft.unloadFont();
  editmoisttimerstart();
}



/*----------------------------------отрисовка меню температуры в зависимости от данных-----------------------*/

// отрисовка редактирования температуры авто
void editmoistuser()
{
  tft.fillRect(188,128,36,16,TFT_BLUE);
  tft.setTextColor(TFT_WHITE);
  tft.setTextSize(2);
  tft.setCursor(189,129);
  tft.print(moistuser,0);
}

// отрисовка редактирования +- температуры авто
void editmoistplus()
{
  tft.fillRect(260,128,24,16,TFT_BLUE);
  tft.setTextColor(TFT_WHITE);
  tft.setTextSize(2);
  tft.setCursor(261,129);
  tft.print(moistplus,0);
}

// отрисовка редактирования таймера нагрева
void editmoisttimer()
{
  tft.fillRect(137,128,60,16,TFT_BLUE);
  tft.setTextColor(TFT_WHITE);
  tft.setTextSize(2);
  tft.setCursor(138,129);
  if(moisttimerh<10)tft.print("0");
  tft.print(moisttimerh);
  tft.print(":");
  if(moisttimerm<10)tft.print("0");
  tft.print(moisttimerm);
}

// отрисовка редактирования таймера работы нагрева
void editmoisttimerwork()
{
  tft.fillRect(226,128,60,16,TFT_BLUE);
  tft.setTextColor(TFT_WHITE);
  tft.setTextSize(2);
  tft.setCursor(227,129);
  if(moisttimerworkh<10)tft.print("0");
  tft.print(moisttimerworkh);
  tft.print(":");
  if(moisttimerworkm<10)tft.print("0");
  tft.print(moisttimerworkm);
}

void editmoisttimerstart()
{
  tft.fillRect(217,168,60,16,TFT_BLUE);
  tft.setTextColor(TFT_WHITE);
  tft.setTextSize(2);
  tft.setCursor(218,169);
  if(moisttimerstarth<10)tft.print("0");
  tft.print(moisttimerstarth);
  tft.print(":");
  if(moisttimerstartm<10)tft.print("0");
  tft.print(moisttimerstartm);
}

// отрисовка редактирования RTC нагрева
void editmoistrtc()
{
  tft.fillRect(98,128,60,16,TFT_BLUE);
  tft.setTextColor(TFT_WHITE);
  tft.setTextSize(2);
  tft.setCursor(99,129);
  if(moistrtch<10)tft.print("0");
  tft.print(moistrtch);
  tft.print(":");
  if(moistrtcm<10)tft.print("0");
  tft.print(moistrtcm);
}

// отрисовка редактирования RTC работы нагрева
void editmoistrtcwork()
{
  tft.fillRect(188,128,60,16,TFT_BLUE);
  tft.setTextColor(TFT_WHITE);
  tft.setTextSize(2);
  tft.setCursor(189,129);
  if(moistrtcworkh<10)tft.print("0");
  tft.print(moistrtcworkh);
  tft.print(":");
  if(moistrtcworkm<10)tft.print("0");
  tft.print(moistrtcworkm);
}



void selmoistup(){
  if(mode == 14) {
    if (moistcontrol==0) selmoist=1;
    else if ((moistcontrol!=0)&&(moistcontmode==3)){
      if(selmoist==2) selmoist = 1;
      else selmoist++;
    } else if((moistcontrol!=0)&&(moistcontmode==1)){
      if(selmoist==4) selmoist = 1;
      else selmoist++; 
    } else if(selmoist==3) selmoist = 1;
    else selmoist++;
    setmoisture(selmoist);
    time1=0;
    moistmenu1=0;
  }
}

void selmoistdown()
{
  if(mode == 14) {
    if (moistcontrol==0) selmoist=1;
    else if ((moistcontrol!=0)&&(moistcontmode==3)){
      if(selmoist==1) selmoist = 2;
      else selmoist--;
    } else if((moistcontrol!=0)&&(moistcontmode==1)){
      if(selmoist==1) selmoist = 4;
      else selmoist--;
    } else if(selmoist==1) selmoist = 3;
    else selmoist--;
    setmoisture(selmoist);
    time1=0;
    moistmenu1=0;
  }
}



void moistleft()
{
  if(mode==14) {
    if (selmoist==1) {
      if (moistcontrol==0){
        moistcontrol=1;
      }else moistcontrol--;
      resetmoist();
    }   
    if (selmoist==2) {
      if (moistcontmode==0){
        moistcontmode=3;
      }else moistcontmode--;
      resetmoist();
    } 
      if (seledit==0){
        seledit=1;
      }else seledit--;
    setmoisture(selmoist);
    time1=0;
    moistmenu1=0;
  }
}

void moistright()
{
  if(mode==14) {
    if (selmoist==1) {
      if (moistcontrol==1) moistcontrol=0;
      else moistcontrol++;   
      resetmoist(); 
    }
    if (selmoist==2) {
      if (moistcontmode==3) moistcontmode=0;
      else moistcontmode++; 
      resetmoist();   
    }
      if (seledit==1) seledit=0;
      else seledit++;
    setmoisture(selmoist);
    time1=0;
    moistmenu1=0;
  }
}

void moistencoderup()
{
  if (mode == 14){
    if(moistcontrol==1){
      if (selmoist==3){
        if(moistcontmode==0){
          if((seledit==0) && (moistuser<100)){
            moistuser+=1;
            editmoistuser();
          } else if ((seledit==1) && (moistplus<50)){
            moistplus+=1;
            editmoistplus();
          }
        }
        if(moistcontmode==1){
          if(seledit==0){
            moisttimerm+=5;
            if (moisttimerm > 59){
              if (moisttimerh>98) moisttimerh=0;
              else moisttimerh++;
              moisttimerm -= 60;
            }
            if((moisttimerh==0)&&(moisttimerm==0)) moisttimerm+=5;
            editmoisttimer();
          } else if (seledit==1){
            moisttimerworkm+=1;
            if (moisttimerworkm > 59){
              if (moisttimerworkh>98) moisttimerworkh=0;
              else moisttimerworkh++;
              moisttimerworkm -= 60;
            }
            if((moisttimerworkh==0)&&(moisttimerworkm==0)) moisttimerworkm+=1;
            editmoisttimerwork();
          }
        }
        if(moistcontmode==2){
          if(seledit==0){
            moistrtcm+=5;
            if (moistrtcm > 59){
              if (moistrtch>22) moistrtch=0;
              else moistrtch++;
              moistrtcm -= 60;
            }
            editmoistrtc();
          } else if (seledit==1){
            moistrtcworkm+=1;
            if (moistrtcworkm > 59){
              if (moistrtcworkh>22) moistrtcworkh=0;
              else moistrtcworkh++;
              moistrtcworkm -= 60;
            }
            if((moistrtcworkh==0)&&(moistrtcworkm==0)) moistrtcworkm+=1;
            editmoistrtcwork();
          }
        }
      }
      if (selmoist==4){
        if(moistcontmode==1){
          moisttimerstartm+=5;
          if (moisttimerstartm > 59){
            if (moisttimerstarth>22) moisttimerstarth=0;
            else moisttimerstarth++;
            moisttimerstartm -= 60;
          }
          editmoisttimerstart();
        }
      }       
    }
  }
}

void moistencoderdown()
{
  if (mode == 14){
    if(moistcontrol==1){
      if (selmoist==3){
        if(moistcontmode==0){
          if((seledit==0) && (moistuser>0)){
            moistuser-=1;
            editmoistuser();
          } else if ((seledit==1) && (moistplus>1)){
            moistplus-=1;
            editmoistplus();
          }
        }
        if(moistcontmode==1){
          if(seledit==0){
            moisttimerm-=5;
            if((moisttimerh==0)&&(moisttimerm==0)) moisttimerm-=5;
            if (moisttimerm < 0){
              if (moisttimerh<1) moisttimerh=99;
              else moisttimerh--;
              moisttimerm += 60;
            }
            editmoisttimer();
          } else if (seledit==1){
            moisttimerworkm-=1;
            if((moisttimerworkh==0)&&(moisttimerworkm==0)) moisttimerworkm-=1;
            if (moisttimerworkm < 0){
              if (moisttimerworkh<1) moisttimerworkh=99;
              else moisttimerworkh--;
              moisttimerworkm += 60;
            }
            editmoisttimerwork();
          }
        }
        if(moistcontmode==2){
          if(seledit==0){
            moistrtcm-=5;
            if (moistrtcm < 0){
              if (moistrtch<1) moistrtch=23;
              else moistrtch--;
              moistrtcm += 60;
            }
            editmoistrtc();
          } else if (seledit==1){
            moistrtcworkm-=1;
            if((moistrtcworkh==0)&&(moistrtcworkm==0)) moistrtcworkm-=1;
            if (moistrtcworkm < 0){
              if (moistrtcworkh<1) moistrtcworkh=23;
              else moistrtcworkh--;
              moistrtcworkm += 60;
            }
            editmoistrtcwork();
          }
        }
      }
      if (selmoist==4){
        if(moistcontmode==1){
            moisttimerstartm-=5;
            if (moisttimerstartm < 0){
              if (moisttimerstarth<1) moisttimerstarth=23;
              else moisttimerstarth--;
              moisttimerstartm += 60;
            }
            editmoisttimerstart();
        }
      }       
    }
  }
}

void resetmoist()
{
  prevmoistcontrol = moistcontrol;
  moistcontrol=0;
  delay(50);
  moistcontrol = prevmoistcontrol;
}



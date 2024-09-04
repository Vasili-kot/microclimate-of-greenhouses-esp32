/*----------------------------------редактирование и отрисовка меню света-----------------------*/

void setlight(int sellight)
{
  tft.loadFont(FONT_22); 
  tft.setTextColor(TFT_BLACK);
  tft.setTextSize(2);
  tft.fillRect(0,0,320,40,TFT_GREEN);
  tft.setCursor(10,10);
  tft.print("ОСВЕЩЕНИЕ");
  tft.fillRect(0,40,320,160,TFT_MAGENTA);
  tft.fillRect(0,200,320,40,TFT_GREEN);
  tft.setCursor(10,210);
  tft.print("Сейчас ");
  tft.setTextColor(TFT_WHITE);

  if (lightcontrol==0){
    tft.setCursor(10,50);
    tft.print("Контроль отключен");

  }else if (lightcontrol==1){
    tft.setCursor(10,50);
    tft.print("Контроль света включен");
    if (lightcontmode==0) {
      tft.setCursor(10,90);
      tft.print("Режим АВТО");
      tft.setCursor(10,130);
      tft.print("Вкл если ниже ");
      tft.unloadFont();
      tft.setTextSize(2);
      tft.print(lightuser,0);
      tft.setCursor(207,130);
      tft.print("lx");
      tft.print("+-");
      tft.print(lightplus,0);
      tft.setCursor(291,130);
      tft.print("lx");
      tft.loadFont(FONT_22); 
    } else if (lightcontmode==1) {
      tft.setCursor(10,90);
      tft.print("Режим по таймеру");
      tft.setCursor(10,130);
      tft.print("Вкл свет раз в ");
      tft.unloadFont();
      if(lighttimerh<10)tft.print("0");
      tft.print(lighttimerh);
      tft.print(":");
      if(lighttimerm<10)tft.print("0");
      tft.print(lighttimerm);
      tft.loadFont(FONT_22); 
      tft.setCursor(220,130);
      tft.print("на ");
      tft.unloadFont();
      if(lighttimerworkh<10)tft.print("0");
      tft.print(lighttimerworkh);
      tft.print(":");
      if(lighttimerworkm<10)tft.print("0");
      tft.print(lighttimerworkm);
      tft.loadFont(FONT_22); 
      tft.setCursor(10,170);
      tft.print("Запустить таймер в ");
      tft.unloadFont();
      if(lighttimerstarth<10)tft.print("0");
      tft.print(lighttimerstarth);
      tft.print(":");
      if(lighttimerstartm<10)tft.print("0");
      tft.print(lighttimerstartm);

    } else if (lightcontmode==2) {
      tft.setCursor(10,90);
      tft.print("Режим суточный");
      tft.setCursor(10,130);
      tft.print("Вкл свет в ");
      tft.unloadFont();
      if(lightrtch<10)tft.print("0");
      tft.print(lightrtch);
      tft.print(":");
      if(lightrtcm<10)tft.print("0");
      tft.print(lightrtcm);
      tft.setCursor(182,130);
      tft.loadFont(FONT_22);
      tft.print("на ");   
      tft.unloadFont();
      if(lightrtcworkh<10)tft.print("0");
      tft.print(lightrtcworkh);
      tft.print(":");
      if(lightrtcworkm<10)tft.print("0");
      tft.print(lightrtcworkm);

    } else if (lightcontmode==3) {
      tft.setCursor(10,90);
      tft.print("Режим всегда включен");
    }

  }
  tft.unloadFont(); 

  if(sellight==1)  
  Sellight_1();
  else if(sellight==2)  
  Sellight_2();
  else if(sellight==3)  
  Sellight_3();
  else if(sellight==4)  
  Sellight_4();
}

void Sellight_1()
{
  tft.loadFont(FONT_22); 
  tft.fillRect(0,40,320,40,TFT_RED);
  tft.setCursor(10,50);
  if (lightcontrol==0){
    tft.print("Контроль отключен");
  }else if (lightcontrol==1){
    tft.print("Контроль света включен");
  }
  tft.unloadFont();
}
void Sellight_2()
{
  tft.loadFont(FONT_22); 
  tft.fillRect(0,80,320,40,TFT_RED);
  tft.setCursor(10,90);
  if (lightcontrol!=0){
    if (lightcontmode==0) {
      tft.print("Режим АВТО");
    } else if (lightcontmode==1) {
      tft.print("Режим по таймеру");
    } else if (lightcontmode==2) {
      tft.print("Режим суточный");
    } else if (lightcontmode==3) {
      tft.print("Режим всегда включен");
    }
  tft.unloadFont();
  }
}
void Sellight_3()
{
  tft.loadFont(FONT_22); 
  tft.fillRect(0,120,320,40,TFT_RED);
  tft.setTextSize(2);
  tft.setCursor(10,130);
  if (lightcontrol==1){
    if (lightcontmode==0) {
      tft.print("Вкл если ниже ");
      tft.unloadFont();
      tft.setTextSize(2);
      tft.print(lightuser,0);
      tft.setCursor(207,130);
      tft.print("lx");
      tft.print("+-");
      tft.print(lightplus,0);
      tft.setCursor(291,130);
      tft.print("lx");
      if(seledit==0)
      editlightuser();
      else editlightplus();
      tft.loadFont(FONT_22); 
    } else if (lightcontmode==1) {
        tft.print("Вкл свет раз в ");
        tft.unloadFont();
        if(lighttimerh<10)tft.print("0");
        tft.print(lighttimerh);
        tft.print(":");
        if(lighttimerm<10)tft.print("0");
        tft.print(lighttimerm);
        tft.loadFont(FONT_22); 
        tft.setCursor(220,130);
        tft.print("на ");
        tft.unloadFont();
        if(lighttimerworkh<10)tft.print("0");
        tft.print(lighttimerworkh);
        tft.print(":");
        if(lighttimerworkm<10)tft.print("0");
        tft.print(lighttimerworkm);
      if(seledit==0)
      editlighttimer();
      else editlighttimerwork();
    } else if (lightcontmode==2) {
      tft.loadFont(FONT_22);
      tft.print("Вкл свет в ");
      tft.unloadFont();
      if(lightrtch<10)tft.print("0");
      tft.print(lightrtch);
      tft.print(":");
      if(lightrtcm<10)tft.print("0");
      tft.print(lightrtcm);
      tft.setCursor(182,130);
      tft.loadFont(FONT_22);
      tft.print("на ");   
      tft.unloadFont();
      if(lightrtcworkh<10)tft.print("0");
      tft.print(lightrtcworkh);
      tft.print(":");
      if(lightrtcworkm<10)tft.print("0");
      tft.print(lightrtcworkm);
      if(seledit==0)
      editlightrtc();
      else editlightrtcwork();
    }
  }
  tft.unloadFont();
}
void Sellight_4()
{
  tft.loadFont(FONT_22); 
  tft.fillRect(0,160,320,40,TFT_RED);
  tft.setCursor(10,170);
  tft.print("Запустить таймер в ");
  tft.unloadFont();
  if(lighttimerstarth<10)tft.print("0");
  tft.print(lighttimerstarth);
  tft.print(":");
  if(lighttimerstartm<10)tft.print("0");
  tft.print(lighttimerstartm);
  editlighttimerstart();
}



/*----------------------------------отрисовка меню температуры в зависимости от данных-----------------------*/

// отрисовка редактирования температуры авто
void editlightuser()
{
  tft.fillRect(159,128,48,16,TFT_BLUE);
  tft.setTextColor(TFT_WHITE);
  tft.setTextSize(2);
  tft.setCursor(160,129);
  tft.print(lightuser,0);
}

// отрисовка редактирования +- температуры авто
void editlightplus()
{
  tft.fillRect(253,128,36,16,TFT_BLUE);
  tft.setTextColor(TFT_WHITE);
  tft.setTextSize(2);
  tft.setCursor(254,129);
  tft.print(lightplus,0);
}

// отрисовка редактирования таймера нагрева
void editlighttimer()
{
  tft.fillRect(159,128,60,16,TFT_BLUE);
  tft.setTextColor(TFT_WHITE);
  tft.setTextSize(2);
  tft.setCursor(160,129);
  if(lighttimerh<10)tft.print("0");
  tft.print(lighttimerh);
  tft.print(":");
  if(lighttimerm<10)tft.print("0");
  tft.print(lighttimerm);
}

// отрисовка редактирования таймера работы нагрева
void editlighttimerwork()
{
  tft.fillRect(246,128,60,16,TFT_BLUE);
  tft.setTextColor(TFT_WHITE);
  tft.setTextSize(2);
  tft.setCursor(247,129);
  if(lighttimerworkh<10)tft.print("0");
  tft.print(lighttimerworkh);
  tft.print(":");
  if(lighttimerworkm<10)tft.print("0");
  tft.print(lighttimerworkm);
}

void editlighttimerstart()
{
  tft.fillRect(213,168,60,16,TFT_BLUE);
  tft.setTextColor(TFT_WHITE);
  tft.setTextSize(2);
  tft.setCursor(214,169);
  if(lighttimerstarth<10)tft.print("0");
  tft.print(lighttimerstarth);
  tft.print(":");
  if(lighttimerstartm<10)tft.print("0");
  tft.print(lighttimerstartm);
}

// отрисовка редактирования RTC нагрева
void editlightrtc()
{
  tft.fillRect(120,128,60,16,TFT_BLUE);
  tft.setTextColor(TFT_WHITE);
  tft.setTextSize(2);
  tft.setCursor(121,129);
  if(lightrtch<10)tft.print("0");
  tft.print(lightrtch);
  tft.print(":");
  if(lightrtcm<10)tft.print("0");
  tft.print(lightrtcm);
}

// отрисовка редактирования RTC работы нагрева
void editlightrtcwork()
{
  tft.fillRect(208,128,60,16,TFT_BLUE);
  tft.setTextColor(TFT_WHITE);
  tft.setTextSize(2);
  tft.setCursor(209,129);
  if(lightrtcworkh<10)tft.print("0");
  tft.print(lightrtcworkh);
  tft.print(":");
  if(lightrtcworkm<10)tft.print("0");
  tft.print(lightrtcworkm);
}


void sellightup(){
  if(mode == 13) {
    if (lightcontrol==0) sellight=1;
    else if ((lightcontrol!=0)&&(lightcontmode==3)){
      if(sellight==2) sellight = 1;
      else sellight++;
    } else if((lightcontrol!=0)&&(lightcontmode==1)){
      if(sellight==4) sellight = 1;
      else sellight++; 
    } else if(sellight==3) sellight = 1;
    else sellight++;
    setlight(sellight);
    time1=0;
    lightmenu1=0;
  }
}


void sellightdown()
{
  if(mode == 13) {
    if (lightcontrol==0) sellight=1;
    else if ((lightcontrol!=0)&&(lightcontmode==3)){
      if(sellight==1) sellight = 2;
      else sellight--;
    } else if((lightcontrol!=0)&&(lightcontmode==1)){
      if(sellight==1) sellight = 4;
      else sellight--;
    } else if(sellight==1) sellight = 3;
    else sellight--;
    setlight(sellight);
    time1=0;
    lightmenu1=0;
  }
}



void lightleft()
{
  if(mode==13) {
    if (sellight==1) {
      if (lightcontrol==0){
        lightcontrol=1;
      }else lightcontrol--;
      resetlight();
    }   
    if (sellight==2) {
      if (lightcontmode==0){
        lightcontmode=3;
      }else lightcontmode--;
      resetlight();
    } 
      if (seledit==0){
        seledit=1;
      }else seledit--;
    setlight(sellight);
    time1=0;
    lightmenu1=0;
  }
}

void lightright()
{
  if(mode==13) {
    if (sellight==1) {
      if (lightcontrol==1) lightcontrol=0;
      else lightcontrol++;   
      resetlight(); 
    }
    if (sellight==2) {
      if (lightcontmode==3) lightcontmode=0;
      else lightcontmode++; 
      resetlight();   
    }
      if (seledit==1) seledit=0;
      else seledit++;
    setlight(sellight);
    time1=0;
    lightmenu1=0;
  }
}


void lightencoderup()
{
  if (mode == 13){
    if(lightcontrol==1){
      if (sellight==3){
        if(lightcontmode==0){
          if((seledit==0) && (lightuser<9995)){
            lightuser+=5;
            editlightuser();
          } else if ((seledit==1) && (lightplus<995)){
            lightplus+=5;
            editlightplus();
          }
        }
        if(lightcontmode==1){
          if(seledit==0){
            lighttimerm+=5;
            if (lighttimerm > 59){
              if (lighttimerh>98) lighttimerh=0;
              else lighttimerh++;
              lighttimerm -= 60;
            }
            if((lighttimerh==0)&&(lighttimerm==0)) lighttimerm+=5;
            editlighttimer();
          } else if (seledit==1){
            lighttimerworkm+=5;
            if (lighttimerworkm > 59){
              if (lighttimerworkh>98) lighttimerworkh=0;
              else lighttimerworkh++;
              lighttimerworkm -= 60;
            }
            if((lighttimerworkh==0)&&(lighttimerworkm==0)) lighttimerworkm+=5;
            editlighttimerwork();
          }
        }
        if(lightcontmode==2){
          if(seledit==0){
            lightrtcm+=5;
            if (lightrtcm > 59){
              if (lightrtch>22) lightrtch=0;
              else lightrtch++;
              lightrtcm -= 60;
            }
            editlightrtc();
          } else if (seledit==1){
            lightrtcworkm+=5;
            if (lightrtcworkm > 59){
              if (lightrtcworkh>22) lightrtcworkh=0;
              else lightrtcworkh++;
              lightrtcworkm -= 60;
            }
            if((lightrtcworkh==0)&&(lightrtcworkm==0)) lightrtcworkm+=5;
            editlightrtcwork();
          }
        }
      }
      if (sellight==4){
        if(lightcontmode==1){
          lighttimerstartm+=5;
          if (lighttimerstartm > 59){
            if (lighttimerstarth>22) lighttimerstarth=0;
            else lighttimerstarth++;
            lighttimerstartm -= 60;
          }
          editlighttimerstart();
        }
      }       
    }
  }
}

void lightencoderdown()
{
  if (mode == 13){
    if(lightcontrol==1){
      if (sellight==3){
        if(lightcontmode==0){
          if((seledit==0) && (lightuser>0)){
            lightuser-=5;
            editlightuser();
          } else if ((seledit==1) && (lightplus>5)){
            lightplus-=5;
            editlightplus();
          }
        }
        if(lightcontmode==1){
          if(seledit==0){
            lighttimerm-=5;
            if((lighttimerh==0)&&(lighttimerm==0)) lighttimerm-=5;
            if (lighttimerm < 0){
              if (lighttimerh<1) lighttimerh=99;
              else lighttimerh--;
              lighttimerm += 60;
            }
            editlighttimer();
          } else if (seledit==1){
            lighttimerworkm-=5;
            if((lighttimerworkh==0)&&(lighttimerworkm==0)) lighttimerworkm-=5;
            if (lighttimerworkm < 0){
              if (lighttimerworkh<1) lighttimerworkh=99;
              else lighttimerworkh--;
              lighttimerworkm += 60;
            }
            editlighttimerwork();
          }
        }
        if(lightcontmode==2){
          if(seledit==0){
            lightrtcm-=5;
            if (lightrtcm < 0){
              if (lightrtch<1) lightrtch=23;
              else lightrtch--;
              lightrtcm += 60;
            }
            editlightrtc();
          } else if (seledit==1){
            lightrtcworkm-=5;
            if((lightrtcworkh==0)&&(lightrtcworkm==0)) lightrtcworkm-=5;
            if (lightrtcworkm < 0){
              if (lightrtcworkh<1) lightrtcworkh=23;
              else lightrtcworkh--;
              lightrtcworkm += 60;
            }
            editlightrtcwork();
          }
        }
      }
      if (sellight==4){
        if(lightcontmode==1){
            lighttimerstartm-=5;
            if (lighttimerstartm < 0){
              if (lighttimerstarth<1) lighttimerstarth=23;
              else lighttimerstarth--;
              lighttimerstartm += 60;
            }
            editlighttimerstart();
        }
      }       
    }
  }
}



void resetlight()
{
  prevlightcontrol = lightcontrol;
  lightcontrol=0;
  delay(50);
  lightcontrol = prevlightcontrol;
}
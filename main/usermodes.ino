/*----------------------------------редактирование и отрисовка меню света-----------------------*/

void setrelay1(int selrelay1)
{
  tft.loadFont(FONT_22); 
  tft.setTextColor(TFT_BLACK);
  tft.setTextSize(2);
  tft.fillRect(0,0,320,40,TFT_GREEN);
  tft.setCursor(10,10);
  tft.print("ДОП РЕЛЕ");
  tft.unloadFont();
  tft.print("1");
  tft.fillRect(0,40,320,160,TFT_MAGENTA);
  tft.fillRect(0,200,320,40,TFT_GREEN);
  tft.setCursor(10,210);
  tft.loadFont(FONT_22);
  tft.print("Сейчас ");
  tft.setTextColor(TFT_WHITE);

  if (relay1control==0){
    tft.setCursor(10,50);
    tft.print("Контроль отключен");

  }else if (relay1control==1){
    tft.setCursor(10,50);
    tft.print("Контроль доп реле включен");
    if (relay1contmode==0) {
      tft.setCursor(10,90);
      tft.print("Режим АВТО");
      tft.setCursor(10,130);
      tft.print("Вкл если ниже ");
      tft.unloadFont();
      tft.setTextSize(2);
      tft.print(relay1user,0);
      tft.setCursor(207,130);
      //tft.print("lx");
      tft.print(" +- ");
      tft.print(relay1plus,0);
      tft.setCursor(291,130);
      //tft.print("lx");
      tft.loadFont(FONT_22); 
    } else if (relay1contmode==1) {
      tft.setCursor(10,90);
      tft.print("Режим по таймеру");
      tft.setCursor(10,130);
      tft.print("Вкл реле раз в ");
      tft.unloadFont();
      if(relay1timerh<10)tft.print("0");
      tft.print(relay1timerh);
      tft.print(":");
      if(relay1timerm<10)tft.print("0");
      tft.print(relay1timerm);
      tft.loadFont(FONT_22); 
      tft.setCursor(225,130);
      tft.print("на ");
      tft.unloadFont();
      if(relay1timerworkh<10)tft.print("0");
      tft.print(relay1timerworkh);
      tft.print(":");
      if(relay1timerworkm<10)tft.print("0");
      tft.print(relay1timerworkm);
      tft.loadFont(FONT_22); 
      tft.setCursor(10,170);
      tft.print("Запустить таймер в ");
      tft.unloadFont();
      if(relay1timerstarth<10)tft.print("0");
      tft.print(relay1timerstarth);
      tft.print(":");
      if(relay1timerstartm<10)tft.print("0");
      tft.print(relay1timerstartm);

    } else if (relay1contmode==2) {
      tft.setCursor(10,90);
      tft.print("Режим суточный");
      tft.setCursor(10,130);
      tft.print("Вкл реле в ");
      tft.unloadFont();
      if(relay1rtch<10)tft.print("0");
      tft.print(relay1rtch);
      tft.print(":");
      if(relay1rtcm<10)tft.print("0");
      tft.print(relay1rtcm);
      tft.setCursor(187,130);
      tft.loadFont(FONT_22);
      tft.print("на ");   
      tft.unloadFont();
      if(relay1rtcworkh<10)tft.print("0");
      tft.print(relay1rtcworkh);
      tft.print(":");
      if(relay1rtcworkm<10)tft.print("0");
      tft.print(relay1rtcworkm);

    } else if (relay1contmode==3) {
      tft.setCursor(10,90);
      tft.print("Режим всегда включен");
    }

  }
  tft.unloadFont(); 

  if(selrelay1==1)  
  Selrelay1_1();
  else if(selrelay1==2)  
  Selrelay1_2();
  else if(selrelay1==3)  
  Selrelay1_3();
  else if(selrelay1==4)  
  Selrelay1_4();
}

void Selrelay1_1()
{
  tft.loadFont(FONT_22); 
  tft.fillRect(0,40,320,40,TFT_RED);
  tft.setCursor(10,50);
  if (relay1control==0){
    tft.print("Контроль отключен");
  }else if (relay1control==1){
    tft.print("Контроль доп реле включен");
  }
  tft.unloadFont();
}
void Selrelay1_2()
{
  tft.loadFont(FONT_22); 
  tft.fillRect(0,80,320,40,TFT_RED);
  tft.setCursor(10,90);
  if (relay1control!=0){
    if (relay1contmode==0) {
      tft.print("Режим АВТО");
    } else if (relay1contmode==1) {
      tft.print("Режим по таймеру");
    } else if (relay1contmode==2) {
      tft.print("Режим суточный");
    } else if (relay1contmode==3) {
      tft.print("Режим всегда включен");
    }
  tft.unloadFont();
  }
}
void Selrelay1_3()
{
  tft.loadFont(FONT_22); 
  tft.fillRect(0,120,320,40,TFT_RED);
  tft.setTextSize(2);
  tft.setCursor(10,130);
  if (relay1control==1){
    if (relay1contmode==0) {
      tft.print("Вкл если ниже ");
      tft.unloadFont();
      tft.setTextSize(2);
      tft.print(relay1user,0);
      tft.setCursor(207,130);
     // tft.print("lx");
      tft.print(" +- ");
      tft.print(relay1plus,0);
      tft.setCursor(291,130);
      //tft.print("lx");
      if(seledit==0)
      editrelay1user();
      else editrelay1plus();
      tft.loadFont(FONT_22); 
    } else if (relay1contmode==1) {
        tft.print("Вкл реле раз в ");
        tft.unloadFont();
        if(relay1timerh<10)tft.print("0");
        tft.print(relay1timerh);
        tft.print(":");
        if(relay1timerm<10)tft.print("0");
        tft.print(relay1timerm);
        tft.loadFont(FONT_22); 
        tft.setCursor(225,130);
        tft.print("на ");
        tft.unloadFont();
        if(relay1timerworkh<10)tft.print("0");
        tft.print(relay1timerworkh);
        tft.print(":");
        if(relay1timerworkm<10)tft.print("0");
        tft.print(relay1timerworkm);
      if(seledit==0)
      editrelay1timer();
      else editrelay1timerwork();
    } else if (relay1contmode==2) {
      tft.loadFont(FONT_22);
      tft.print("Вкл реле в ");
      tft.unloadFont();
      if(relay1rtch<10)tft.print("0");
      tft.print(relay1rtch);
      tft.print(":");
      if(relay1rtcm<10)tft.print("0");
      tft.print(relay1rtcm);
      tft.setCursor(187,130);
      tft.loadFont(FONT_22);
      tft.print("на ");   
      tft.unloadFont();
      if(relay1rtcworkh<10)tft.print("0");
      tft.print(relay1rtcworkh);
      tft.print(":");
      if(relay1rtcworkm<10)tft.print("0");
      tft.print(relay1rtcworkm);
      if(seledit==0)
      editrelay1rtc();
      else editrelay1rtcwork();
    }
  }
  tft.unloadFont();
}
void Selrelay1_4()
{
  tft.loadFont(FONT_22); 
  tft.fillRect(0,160,320,40,TFT_RED);
  tft.setCursor(10,170);
  tft.print("Запустить таймер в ");
  tft.unloadFont();
  if(relay1timerstarth<10)tft.print("0");
  tft.print(relay1timerstarth);
  tft.print(":");
  if(relay1timerstartm<10)tft.print("0");
  tft.print(relay1timerstartm);
  editrelay1timerstart();
}



/*----------------------------------отрисовка меню температуры в зависимости от данных-----------------------*/

// отрисовка редактирования температуры авто
void editrelay1user()
{
  tft.fillRect(159,128,48,16,TFT_BLUE);
  tft.setTextColor(TFT_WHITE);
  tft.setTextSize(2);
  tft.setCursor(160,129);
  tft.print(relay1user,0);
}

// отрисовка редактирования +- температуры авто
void editrelay1plus()
{
  tft.fillRect(253,128,36,16,TFT_BLUE);
  tft.setTextColor(TFT_WHITE);
  tft.setTextSize(2);
  tft.setCursor(254,129);
  tft.print(relay1plus,0);
}

// отрисовка редактирования таймера нагрева
void editrelay1timer()
{
  tft.fillRect(162,128,60,16,TFT_BLUE);
  tft.setTextColor(TFT_WHITE);
  tft.setTextSize(2);
  tft.setCursor(163,129);
  if(relay1timerh<10)tft.print("0");
  tft.print(relay1timerh);
  tft.print(":");
  if(relay1timerm<10)tft.print("0");
  tft.print(relay1timerm);
}

// отрисовка редактирования таймера работы нагрева
void editrelay1timerwork()
{
  tft.fillRect(251,128,60,16,TFT_BLUE);
  tft.setTextColor(TFT_WHITE);
  tft.setTextSize(2);
  tft.setCursor(252,129);
  if(relay1timerworkh<10)tft.print("0");
  tft.print(relay1timerworkh);
  tft.print(":");
  if(relay1timerworkm<10)tft.print("0");
  tft.print(relay1timerworkm);
}

void editrelay1timerstart()
{
  tft.fillRect(213,168,60,16,TFT_BLUE);
  tft.setTextColor(TFT_WHITE);
  tft.setTextSize(2);
  tft.setCursor(214,169);
  if(relay1timerstarth<10)tft.print("0");
  tft.print(relay1timerstarth);
  tft.print(":");
  if(relay1timerstartm<10)tft.print("0");
  tft.print(relay1timerstartm);
}

// отрисовка редактирования RTC нагрева
void editrelay1rtc()
{
  tft.fillRect(123,128,60,16,TFT_BLUE);
  tft.setTextColor(TFT_WHITE);
  tft.setTextSize(2);
  tft.setCursor(124,129);
  if(relay1rtch<10)tft.print("0");
  tft.print(relay1rtch);
  tft.print(":");
  if(relay1rtcm<10)tft.print("0");
  tft.print(relay1rtcm);
}

// отрисовка редактирования RTC работы нагрева
void editrelay1rtcwork()
{
  tft.fillRect(213,128,60,16,TFT_BLUE);
  tft.setTextColor(TFT_WHITE);
  tft.setTextSize(2);
  tft.setCursor(214,129);
  if(relay1rtcworkh<10)tft.print("0");
  tft.print(relay1rtcworkh);
  tft.print(":");
  if(relay1rtcworkm<10)tft.print("0");
  tft.print(relay1rtcworkm);
}



void setrelay2(int selrelay2)
{
  tft.loadFont(FONT_22); 
  tft.setTextColor(TFT_BLACK);
  tft.setTextSize(2);
  tft.fillRect(0,0,320,40,TFT_GREEN);
  tft.setCursor(10,10);
  tft.print("ДОП РЕЛЕ");
  tft.unloadFont();
  tft.print("2");
  tft.fillRect(0,40,320,160,TFT_MAGENTA);
  tft.fillRect(0,200,320,40,TFT_GREEN);
  tft.setCursor(10,210);
  tft.loadFont(FONT_22);
  tft.print("Сейчас ");
  tft.setTextColor(TFT_WHITE);

  if (relay2control==0){
    tft.setCursor(10,50);
    tft.print("Контроль отключен");

  }else if (relay2control==1){
    tft.setCursor(10,50);
    tft.print("Контроль доп реле включен");
    if (relay2contmode==0) {
      tft.setCursor(10,90);
      tft.print("Режим АВТО");
      tft.setCursor(10,130);
      tft.print("Вкл если ниже ");
      tft.unloadFont();
      tft.setTextSize(2);
      tft.print(relay2user,0);
      tft.setCursor(207,130);
      //tft.print("lx");
      tft.print(" +- ");
      tft.print(relay2plus,0);
      tft.setCursor(291,130);
      //tft.print("lx");
      tft.loadFont(FONT_22); 
    } else if (relay2contmode==1) {
      tft.setCursor(10,90);
      tft.print("Режим по таймеру");
      tft.setCursor(10,130);
      tft.print("Вкл реле раз в ");
      tft.unloadFont();
      if(relay2timerh<10)tft.print("0");
      tft.print(relay2timerh);
      tft.print(":");
      if(relay2timerm<10)tft.print("0");
      tft.print(relay2timerm);
      tft.loadFont(FONT_22); 
      tft.setCursor(225,130);
      tft.print("на ");
      tft.unloadFont();
      if(relay2timerworkh<10)tft.print("0");
      tft.print(relay2timerworkh);
      tft.print(":");
      if(relay2timerworkm<10)tft.print("0");
      tft.print(relay2timerworkm);
      tft.loadFont(FONT_22); 
      tft.setCursor(10,170);
      tft.print("Запустить таймер в ");
      tft.unloadFont();
      if(relay2timerstarth<10)tft.print("0");
      tft.print(relay2timerstarth);
      tft.print(":");
      if(relay2timerstartm<10)tft.print("0");
      tft.print(relay2timerstartm);

    } else if (relay2contmode==2) {
      tft.setCursor(10,90);
      tft.print("Режим суточный");
      tft.setCursor(10,130);
      tft.print("Вкл реле в ");
      tft.unloadFont();
      if(relay2rtch<10)tft.print("0");
      tft.print(relay2rtch);
      tft.print(":");
      if(relay2rtcm<10)tft.print("0");
      tft.print(relay2rtcm);
      tft.setCursor(187,130);
      tft.loadFont(FONT_22);
      tft.print("на ");   
      tft.unloadFont();
      if(relay2rtcworkh<10)tft.print("0");
      tft.print(relay2rtcworkh);
      tft.print(":");
      if(relay2rtcworkm<10)tft.print("0");
      tft.print(relay2rtcworkm);

    } else if (relay2contmode==3) {
      tft.setCursor(10,90);
      tft.print("Режим всегда включен");
    }

  }
  tft.unloadFont(); 

  if(selrelay2==1)  
  Selrelay2_1();
  else if(selrelay2==2)  
  Selrelay2_2();
  else if(selrelay2==3)  
  Selrelay2_3();
  else if(selrelay2==4)  
  Selrelay2_4();
}

void Selrelay2_1()
{
  tft.loadFont(FONT_22); 
  tft.fillRect(0,40,320,40,TFT_RED);
  tft.setCursor(10,50);
  if (relay2control==0){
    tft.print("Контроль отключен");
  }else if (relay2control==1){
    tft.print("Контроль доп реле включен");
  }
  tft.unloadFont();
}
void Selrelay2_2()
{
  tft.loadFont(FONT_22); 
  tft.fillRect(0,80,320,40,TFT_RED);
  tft.setCursor(10,90);
  if (relay2control!=0){
    if (relay2contmode==0) {
      tft.print("Режим АВТО");
    } else if (relay2contmode==1) {
      tft.print("Режим по таймеру");
    } else if (relay2contmode==2) {
      tft.print("Режим суточный");
    } else if (relay2contmode==3) {
      tft.print("Режим всегда включен");
    }
  tft.unloadFont();
  }
}
void Selrelay2_3()
{
  tft.loadFont(FONT_22); 
  tft.fillRect(0,120,320,40,TFT_RED);
  tft.setTextSize(2);
  tft.setCursor(10,130);
  if (relay2control==1){
    if (relay2contmode==0) {
      tft.print("Вкл если ниже ");
      tft.unloadFont();
      tft.setTextSize(2);
      tft.print(relay2user,0);
      tft.setCursor(207,130);
     // tft.print("lx");
      tft.print(" +- ");
      tft.print(relay2plus,0);
      tft.setCursor(291,130);
      //tft.print("lx");
      if(seledit==0)
      editrelay2user();
      else editrelay2plus();
      tft.loadFont(FONT_22); 
    } else if (relay2contmode==1) {
        tft.print("Вкл реле раз в ");
        tft.unloadFont();
        if(relay2timerh<10)tft.print("0");
        tft.print(relay2timerh);
        tft.print(":");
        if(relay2timerm<10)tft.print("0");
        tft.print(relay2timerm);
        tft.loadFont(FONT_22); 
        tft.setCursor(225,130);
        tft.print("на ");
        tft.unloadFont();
        if(relay2timerworkh<10)tft.print("0");
        tft.print(relay2timerworkh);
        tft.print(":");
        if(relay2timerworkm<10)tft.print("0");
        tft.print(relay2timerworkm);
      if(seledit==0)
      editrelay2timer();
      else editrelay2timerwork();
    } else if (relay2contmode==2) {
      tft.loadFont(FONT_22);
      tft.print("Вкл реле в ");
      tft.unloadFont();
      if(relay2rtch<10)tft.print("0");
      tft.print(relay2rtch);
      tft.print(":");
      if(relay2rtcm<10)tft.print("0");
      tft.print(relay2rtcm);
      tft.setCursor(187,130);
      tft.loadFont(FONT_22);
      tft.print("на ");   
      tft.unloadFont();
      if(relay2rtcworkh<10)tft.print("0");
      tft.print(relay2rtcworkh);
      tft.print(":");
      if(relay2rtcworkm<10)tft.print("0");
      tft.print(relay2rtcworkm);
      if(seledit==0)
      editrelay2rtc();
      else editrelay2rtcwork();
    }
  }
  tft.unloadFont();
}
void Selrelay2_4()
{
  tft.loadFont(FONT_22); 
  tft.fillRect(0,160,320,40,TFT_RED);
  tft.setCursor(10,170);
  tft.print("Запустить таймер в ");
  tft.unloadFont();
  if(relay2timerstarth<10)tft.print("0");
  tft.print(relay2timerstarth);
  tft.print(":");
  if(relay2timerstartm<10)tft.print("0");
  tft.print(relay2timerstartm);
  editrelay2timerstart();
}



/*----------------------------------отрисовка меню температуры в зависимости от данных-----------------------*/

// отрисовка редактирования температуры авто
void editrelay2user()
{
  tft.fillRect(159,128,48,16,TFT_BLUE);
  tft.setTextColor(TFT_WHITE);
  tft.setTextSize(2);
  tft.setCursor(160,129);
  tft.print(relay2user,0);
}

// отрисовка редактирования +- температуры авто
void editrelay2plus()
{
  tft.fillRect(253,128,36,16,TFT_BLUE);
  tft.setTextColor(TFT_WHITE);
  tft.setTextSize(2);
  tft.setCursor(254,129);
  tft.print(relay2plus,0);
}

// отрисовка редактирования таймера нагрева
void editrelay2timer()
{
  tft.fillRect(162,128,60,16,TFT_BLUE);
  tft.setTextColor(TFT_WHITE);
  tft.setTextSize(2);
  tft.setCursor(163,129);
  if(relay2timerh<10)tft.print("0");
  tft.print(relay2timerh);
  tft.print(":");
  if(relay2timerm<10)tft.print("0");
  tft.print(relay2timerm);
}

// отрисовка редактирования таймера работы нагрева
void editrelay2timerwork()
{
  tft.fillRect(251,128,60,16,TFT_BLUE);
  tft.setTextColor(TFT_WHITE);
  tft.setTextSize(2);
  tft.setCursor(252,129);
  if(relay2timerworkh<10)tft.print("0");
  tft.print(relay2timerworkh);
  tft.print(":");
  if(relay2timerworkm<10)tft.print("0");
  tft.print(relay2timerworkm);
}

void editrelay2timerstart()
{
  tft.fillRect(213,168,60,16,TFT_BLUE);
  tft.setTextColor(TFT_WHITE);
  tft.setTextSize(2);
  tft.setCursor(214,169);
  if(relay2timerstarth<10)tft.print("0");
  tft.print(relay2timerstarth);
  tft.print(":");
  if(relay2timerstartm<10)tft.print("0");
  tft.print(relay2timerstartm);
}

// отрисовка редактирования RTC нагрева
void editrelay2rtc()
{
  tft.fillRect(123,128,60,16,TFT_BLUE);
  tft.setTextColor(TFT_WHITE);
  tft.setTextSize(2);
  tft.setCursor(124,129);
  if(relay2rtch<10)tft.print("0");
  tft.print(relay2rtch);
  tft.print(":");
  if(relay2rtcm<10)tft.print("0");
  tft.print(relay2rtcm);
}

// отрисовка редактирования RTC работы нагрева
void editrelay2rtcwork()
{
  tft.fillRect(213,128,60,16,TFT_BLUE);
  tft.setTextColor(TFT_WHITE);
  tft.setTextSize(2);
  tft.setCursor(214,129);
  if(relay2rtcworkh<10)tft.print("0");
  tft.print(relay2rtcworkh);
  tft.print(":");
  if(relay2rtcworkm<10)tft.print("0");
  tft.print(relay2rtcworkm);
}



void setservo1(int selservo1)
{
  tft.loadFont(FONT_22); 
  tft.setTextColor(TFT_BLACK);
  tft.setTextSize(2);
  tft.fillRect(0,0,320,40,TFT_GREEN);
  tft.setCursor(10,10);
  tft.print("СЕРВО");
  tft.unloadFont();
  tft.print("1");
  tft.fillRect(0,40,320,160,TFT_MAGENTA);
  tft.fillRect(0,200,320,40,TFT_GREEN);
  tft.setCursor(10,210);
  tft.loadFont(FONT_22);
  tft.print("Сейчас ");
  tft.setTextColor(TFT_WHITE);

  if (servo1control==0){
    tft.setCursor(10,50);
    tft.print("Контроль отключен");

  }else if (servo1control==1){
    tft.setCursor(10,50);
    tft.print("Контроль серво включен");
    if (servo1contmode==0) {
      tft.setCursor(10,90);
      tft.print("Режим АВТО");
      tft.setCursor(10,130);
      tft.print("Вкл если ниже ");
      tft.unloadFont();
      tft.setTextSize(2);
      tft.print(servo1user,0);
      tft.setCursor(207,130);
      //tft.print("lx");
      tft.print(" +- ");
      tft.print(servo1plus,0);
      tft.setCursor(291,130);
      //tft.print("lx");
      tft.loadFont(FONT_22); 
    } else if (servo1contmode==1) {
      tft.setCursor(10,90);
      tft.print("Режим по таймеру");
      tft.setCursor(10,130);
      tft.print("Вкл серво раз в");
      tft.unloadFont();
      if(servo1timerh<10)tft.print("0");
      tft.print(servo1timerh);
      tft.print(":");
      if(servo1timerm<10)tft.print("0");
      tft.print(servo1timerm);
      tft.loadFont(FONT_22); 
      tft.setCursor(230,130);
      tft.print("на");
      tft.unloadFont();
      if(servo1timerworkh<10)tft.print("0");
      tft.print(servo1timerworkh);
      tft.print(":");
      if(servo1timerworkm<10)tft.print("0");
      tft.print(servo1timerworkm);
      tft.loadFont(FONT_22); 
      tft.setCursor(10,170);
      tft.print("Запустить таймер в ");
      tft.unloadFont();
      if(servo1timerstarth<10)tft.print("0");
      tft.print(servo1timerstarth);
      tft.print(":");
      if(servo1timerstartm<10)tft.print("0");
      tft.print(servo1timerstartm);

    } else if (servo1contmode==2) {
      tft.setCursor(10,90);
      tft.print("Режим суточный");
      tft.setCursor(10,130);
      tft.print("Вкл серво в ");
      tft.unloadFont();
      if(servo1rtch<10)tft.print("0");
      tft.print(servo1rtch);
      tft.print(":");
      if(servo1rtcm<10)tft.print("0");
      tft.print(servo1rtcm);
      tft.setCursor(197,130);
      tft.loadFont(FONT_22);
      tft.print("на ");   
      tft.unloadFont();
      if(servo1rtcworkh<10)tft.print("0");
      tft.print(servo1rtcworkh);
      tft.print(":");
      if(servo1rtcworkm<10)tft.print("0");
      tft.print(servo1rtcworkm);

    } else if (servo1contmode==3) {
      tft.setCursor(10,90);
      tft.print("Режим всегда включен");
    }

  }
  tft.unloadFont(); 

  if(selservo1==1)  
  Selservo1_1();
  else if(selservo1==2)  
  Selservo1_2();
  else if(selservo1==3)  
  Selservo1_3();
  else if(selservo1==4)  
  Selservo1_4();
}

void Selservo1_1()
{
  tft.loadFont(FONT_22); 
  tft.fillRect(0,40,320,40,TFT_RED);
  tft.setCursor(10,50);
  if (servo1control==0){
    tft.print("Контроль отключен");
  }else if (servo1control==1){
    tft.print("Контроль серво включен");
  }
  tft.unloadFont();
}
void Selservo1_2()
{
  tft.loadFont(FONT_22); 
  tft.fillRect(0,80,320,40,TFT_RED);
  tft.setCursor(10,90);
  if (servo1control!=0){
    if (servo1contmode==0) {
      tft.print("Режим АВТО");
    } else if (servo1contmode==1) {
      tft.print("Режим по таймеру");
    } else if (servo1contmode==2) {
      tft.print("Режим суточный");
    } else if (servo1contmode==3) {
      tft.print("Режим всегда включен");
    }
  tft.unloadFont();
  }
}
void Selservo1_3()
{
  tft.loadFont(FONT_22); 
  tft.fillRect(0,120,320,40,TFT_RED);
  tft.setTextSize(2);
  tft.setCursor(10,130);
  if (servo1control==1){
    if (servo1contmode==0) {
      tft.print("Вкл если ниже ");
      tft.unloadFont();
      tft.setTextSize(2);
      tft.print(servo1user,0);
      tft.setCursor(207,130);
     // tft.print("lx");
      tft.print(" +- ");
      tft.print(servo1plus,0);
      tft.setCursor(291,130);
      //tft.print("lx");
      if(seledit==0)
      editservo1user();
      else editservo1plus();
      tft.loadFont(FONT_22); 
    } else if (servo1contmode==1) {
        tft.print("Вкл серво раз в");
        tft.unloadFont();
        if(servo1timerh<10)tft.print("0");
        tft.print(servo1timerh);
        tft.print(":");
        if(servo1timerm<10)tft.print("0");
        tft.print(servo1timerm);
        tft.loadFont(FONT_22); 
        tft.setCursor(230,130);
        tft.print("на ");
        tft.unloadFont();
        if(servo1timerworkh<10)tft.print("0");
        tft.print(servo1timerworkh);
        tft.print(":");
        if(servo1timerworkm<10)tft.print("0");
        tft.print(servo1timerworkm);
      if(seledit==0)
      editservo1timer();
      else editservo1timerwork();
    } else if (servo1contmode==2) {
      tft.loadFont(FONT_22);
      tft.print("Вкл серво в ");
      tft.unloadFont();
      if(servo1rtch<10)tft.print("0");
      tft.print(servo1rtch);
      tft.print(":");
      if(servo1rtcm<10)tft.print("0");
      tft.print(servo1rtcm);
      tft.setCursor(197,130);
      tft.loadFont(FONT_22);
      tft.print("на ");   
      tft.unloadFont();
      if(servo1rtcworkh<10)tft.print("0");
      tft.print(servo1rtcworkh);
      tft.print(":");
      if(servo1rtcworkm<10)tft.print("0");
      tft.print(servo1rtcworkm);
      if(seledit==0)
      editservo1rtc();
      else editservo1rtcwork();
    }
  }
  tft.unloadFont();
}
void Selservo1_4()
{
  tft.loadFont(FONT_22); 
  tft.fillRect(0,160,320,40,TFT_RED);
  tft.setCursor(10,170);
  tft.print("Запустить таймер в ");
  tft.unloadFont();
  if(servo1timerstarth<10)tft.print("0");
  tft.print(servo1timerstarth);
  tft.print(":");
  if(servo1timerstartm<10)tft.print("0");
  tft.print(servo1timerstartm);
  editservo1timerstart();
}





// отрисовка редактирования температуры авто
void editservo1user()
{
  tft.fillRect(159,128,48,16,TFT_BLUE);
  tft.setTextColor(TFT_WHITE);
  tft.setTextSize(2);
  tft.setCursor(160,129);
  tft.print(servo1user,0);
}

// отрисовка редактирования +- температуры авто
void editservo1plus()
{
  tft.fillRect(253,128,36,16,TFT_BLUE);
  tft.setTextColor(TFT_WHITE);
  tft.setTextSize(2);
  tft.setCursor(254,129);
  tft.print(servo1plus,0);
}

// отрисовка редактирования таймера нагрева
void editservo1timer()
{
  tft.fillRect(169,128,60,16,TFT_BLUE);
  tft.setTextColor(TFT_WHITE);
  tft.setTextSize(2);
  tft.setCursor(170,129);
  if(servo1timerh<10)tft.print("0");
  tft.print(servo1timerh);
  tft.print(":");
  if(servo1timerm<10)tft.print("0");
  tft.print(servo1timerm);
}

// отрисовка редактирования таймера работы нагрева
void editservo1timerwork()
{
  tft.fillRect(256,128,60,16,TFT_BLUE);
  tft.setTextColor(TFT_WHITE);
  tft.setTextSize(2);
  tft.setCursor(257,129);
  if(servo1timerworkh<10)tft.print("0");
  tft.print(servo1timerworkh);
  tft.print(":");
  if(servo1timerworkm<10)tft.print("0");
  tft.print(servo1timerworkm);
}

void editservo1timerstart()
{
  tft.fillRect(213,168,60,16,TFT_BLUE);
  tft.setTextColor(TFT_WHITE);
  tft.setTextSize(2);
  tft.setCursor(214,169);
  if(servo1timerstarth<10)tft.print("0");
  tft.print(servo1timerstarth);
  tft.print(":");
  if(servo1timerstartm<10)tft.print("0");
  tft.print(servo1timerstartm);
}

// отрисовка редактирования RTC нагрева
void editservo1rtc()
{
  tft.fillRect(137,128,60,16,TFT_BLUE);
  tft.setTextColor(TFT_WHITE);
  tft.setTextSize(2);
  tft.setCursor(138,129);
  if(servo1rtch<10)tft.print("0");
  tft.print(servo1rtch);
  tft.print(":");
  if(servo1rtcm<10)tft.print("0");
  tft.print(servo1rtcm);
}

// отрисовка редактирования RTC работы нагрева
void editservo1rtcwork()
{
  tft.fillRect(225,128,60,16,TFT_BLUE);
  tft.setTextColor(TFT_WHITE);
  tft.setTextSize(2);
  tft.setCursor(226,129);
  if(servo1rtcworkh<10)tft.print("0");
  tft.print(servo1rtcworkh);
  tft.print(":");
  if(servo1rtcworkm<10)tft.print("0");
  tft.print(servo1rtcworkm);
}

void setservo2(int selservo2)
{
  tft.loadFont(FONT_22); 
  tft.setTextColor(TFT_BLACK);
  tft.setTextSize(2);
  tft.fillRect(0,0,320,40,TFT_GREEN);
  tft.setCursor(10,10);
  tft.print("СЕРВО");
  tft.unloadFont();
  tft.print("2");
  tft.fillRect(0,40,320,160,TFT_MAGENTA);
  tft.fillRect(0,200,320,40,TFT_GREEN);
  tft.setCursor(10,210);
  tft.loadFont(FONT_22);
  tft.print("Сейчас ");
  tft.setTextColor(TFT_WHITE);

  if (servo2control==0){
    tft.setCursor(10,50);
    tft.print("Контроль отключен");

  }else if (servo2control==1){
    tft.setCursor(10,50);
    tft.print("Контроль серво включен");
    if (servo2contmode==0) {
      tft.setCursor(10,90);
      tft.print("Режим АВТО");
      tft.setCursor(10,130);
      tft.print("Вкл если ниже ");
      tft.unloadFont();
      tft.setTextSize(2);
      tft.print(servo2user,0);
      tft.setCursor(207,130);
      //tft.print("lx");
      tft.print(" +- ");
      tft.print(servo2plus,0);
      tft.setCursor(291,130);
      //tft.print("lx");
      tft.loadFont(FONT_22); 
    } else if (servo2contmode==1) {
      tft.setCursor(10,90);
      tft.print("Режим по таймеру");
      tft.setCursor(10,130);
      tft.print("Вкл серво раз в");
      tft.unloadFont();
      if(servo2timerh<10)tft.print("0");
      tft.print(servo2timerh);
      tft.print(":");
      if(servo2timerm<10)tft.print("0");
      tft.print(servo2timerm);
      tft.loadFont(FONT_22); 
      tft.setCursor(230,130);
      tft.print("на");
      tft.unloadFont();
      if(servo2timerworkh<10)tft.print("0");
      tft.print(servo2timerworkh);
      tft.print(":");
      if(servo2timerworkm<10)tft.print("0");
      tft.print(servo2timerworkm);
      tft.loadFont(FONT_22); 
      tft.setCursor(10,170);
      tft.print("Запустить таймер в ");
      tft.unloadFont();
      if(servo2timerstarth<10)tft.print("0");
      tft.print(servo2timerstarth);
      tft.print(":");
      if(servo2timerstartm<10)tft.print("0");
      tft.print(servo2timerstartm);

    } else if (servo2contmode==2) {
      tft.setCursor(10,90);
      tft.print("Режим суточный");
      tft.setCursor(10,130);
      tft.print("Вкл серво в ");
      tft.unloadFont();
      if(servo2rtch<10)tft.print("0");
      tft.print(servo2rtch);
      tft.print(":");
      if(servo2rtcm<10)tft.print("0");
      tft.print(servo2rtcm);
      tft.setCursor(197,130);
      tft.loadFont(FONT_22);
      tft.print("на ");   
      tft.unloadFont();
      if(servo2rtcworkh<10)tft.print("0");
      tft.print(servo2rtcworkh);
      tft.print(":");
      if(servo2rtcworkm<10)tft.print("0");
      tft.print(servo2rtcworkm);

    } else if (servo2contmode==3) {
      tft.setCursor(10,90);
      tft.print("Режим всегда включен");
    }

  }
  tft.unloadFont(); 

  if(selservo2==1)  
  Selservo2_1();
  else if(selservo2==2)  
  Selservo2_2();
  else if(selservo2==3)  
  Selservo2_3();
  else if(selservo2==4)  
  Selservo2_4();
}

void Selservo2_1()
{
  tft.loadFont(FONT_22); 
  tft.fillRect(0,40,320,40,TFT_RED);
  tft.setCursor(10,50);
  if (servo2control==0){
    tft.print("Контроль отключен");
  }else if (servo2control==1){
    tft.print("Контроль серво включен");
  }
  tft.unloadFont();
}
void Selservo2_2()
{
  tft.loadFont(FONT_22); 
  tft.fillRect(0,80,320,40,TFT_RED);
  tft.setCursor(10,90);
  if (servo2control!=0){
    if (servo2contmode==0) {
      tft.print("Режим АВТО");
    } else if (servo2contmode==1) {
      tft.print("Режим по таймеру");
    } else if (servo2contmode==2) {
      tft.print("Режим суточный");
    } else if (servo2contmode==3) {
      tft.print("Режим всегда включен");
    }
  tft.unloadFont();
  }
}
void Selservo2_3()
{
  tft.loadFont(FONT_22); 
  tft.fillRect(0,120,320,40,TFT_RED);
  tft.setTextSize(2);
  tft.setCursor(10,130);
  if (servo2control==1){
    if (servo2contmode==0) {
      tft.print("Вкл если ниже ");
      tft.unloadFont();
      tft.setTextSize(2);
      tft.print(servo2user,0);
      tft.setCursor(207,130);
     // tft.print("lx");
      tft.print(" +- ");
      tft.print(servo2plus,0);
      tft.setCursor(291,130);
      //tft.print("lx");
      if(seledit==0)
      editservo2user();
      else editservo2plus();
      tft.loadFont(FONT_22); 
    } else if (servo2contmode==1) {
        tft.print("Вкл серво раз в");
        tft.unloadFont();
        if(servo2timerh<10)tft.print("0");
        tft.print(servo2timerh);
        tft.print(":");
        if(servo2timerm<10)tft.print("0");
        tft.print(servo2timerm);
        tft.loadFont(FONT_22); 
        tft.setCursor(230,130);
        tft.print("на ");
        tft.unloadFont();
        if(servo2timerworkh<10)tft.print("0");
        tft.print(servo2timerworkh);
        tft.print(":");
        if(servo2timerworkm<10)tft.print("0");
        tft.print(servo2timerworkm);
      if(seledit==0)
      editservo2timer();
      else editservo2timerwork();
    } else if (servo2contmode==2) {
      tft.loadFont(FONT_22);
      tft.print("Вкл серво в ");
      tft.unloadFont();
      if(servo2rtch<10)tft.print("0");
      tft.print(servo2rtch);
      tft.print(":");
      if(servo2rtcm<10)tft.print("0");
      tft.print(servo2rtcm);
      tft.setCursor(197,130);
      tft.loadFont(FONT_22);
      tft.print("на ");   
      tft.unloadFont();
      if(servo2rtcworkh<10)tft.print("0");
      tft.print(servo2rtcworkh);
      tft.print(":");
      if(servo2rtcworkm<10)tft.print("0");
      tft.print(servo2rtcworkm);
      if(seledit==0)
      editservo2rtc();
      else editservo2rtcwork();
    }
  }
  tft.unloadFont();
}
void Selservo2_4()
{
  tft.loadFont(FONT_22); 
  tft.fillRect(0,160,320,40,TFT_RED);
  tft.setCursor(10,170);
  tft.print("Запустить таймер в ");
  tft.unloadFont();
  if(servo2timerstarth<10)tft.print("0");
  tft.print(servo2timerstarth);
  tft.print(":");
  if(servo2timerstartm<10)tft.print("0");
  tft.print(servo2timerstartm);
  editservo2timerstart();
}


// отрисовка редактирования температуры авто
void editservo2user()
{
  tft.fillRect(159,128,48,16,TFT_BLUE);
  tft.setTextColor(TFT_WHITE);
  tft.setTextSize(2);
  tft.setCursor(160,129);
  tft.print(servo2user,0);
}

// отрисовка редактирования +- температуры авто
void editservo2plus()
{
  tft.fillRect(253,128,36,16,TFT_BLUE);
  tft.setTextColor(TFT_WHITE);
  tft.setTextSize(2);
  tft.setCursor(254,129);
  tft.print(servo2plus,0);
}

// отрисовка редактирования таймера нагрева
void editservo2timer()
{
  tft.fillRect(169,128,60,16,TFT_BLUE);
  tft.setTextColor(TFT_WHITE);
  tft.setTextSize(2);
  tft.setCursor(170,129);
  if(servo2timerh<10)tft.print("0");
  tft.print(servo2timerh);
  tft.print(":");
  if(servo2timerm<10)tft.print("0");
  tft.print(servo2timerm);
}

// отрисовка редактирования таймера работы нагрева
void editservo2timerwork()
{
  tft.fillRect(256,128,60,16,TFT_BLUE);
  tft.setTextColor(TFT_WHITE);
  tft.setTextSize(2);
  tft.setCursor(257,129);
  if(servo2timerworkh<10)tft.print("0");
  tft.print(servo2timerworkh);
  tft.print(":");
  if(servo2timerworkm<10)tft.print("0");
  tft.print(servo2timerworkm);
}

void editservo2timerstart()
{
  tft.fillRect(213,168,60,16,TFT_BLUE);
  tft.setTextColor(TFT_WHITE);
  tft.setTextSize(2);
  tft.setCursor(214,169);
  if(servo2timerstarth<10)tft.print("0");
  tft.print(servo2timerstarth);
  tft.print(":");
  if(servo2timerstartm<10)tft.print("0");
  tft.print(servo2timerstartm);
}

// отрисовка редактирования RTC нагрева
void editservo2rtc()
{
  tft.fillRect(137,128,60,16,TFT_BLUE);
  tft.setTextColor(TFT_WHITE);
  tft.setTextSize(2);
  tft.setCursor(138,129);
  if(servo2rtch<10)tft.print("0");
  tft.print(servo2rtch);
  tft.print(":");
  if(servo2rtcm<10)tft.print("0");
  tft.print(servo2rtcm);
}

// отрисовка редактирования RTC работы нагрева
void editservo2rtcwork()
{
  tft.fillRect(225,128,60,16,TFT_BLUE);
  tft.setTextColor(TFT_WHITE);
  tft.setTextSize(2);
  tft.setCursor(226,129);
  if(servo2rtcworkh<10)tft.print("0");
  tft.print(servo2rtcworkh);
  tft.print(":");
  if(servo2rtcworkm<10)tft.print("0");
  tft.print(servo2rtcworkm);
}


void setactuator(int selactuator)
{
  tft.loadFont(FONT_22); 
  tft.setTextColor(TFT_BLACK);
  tft.setTextSize(2);
  tft.fillRect(0,0,320,40,TFT_GREEN);
  tft.setCursor(10,10);
  tft.print("ПРИВОД");
  tft.unloadFont();
  tft.fillRect(0,40,320,160,TFT_MAGENTA);
  tft.fillRect(0,200,320,40,TFT_GREEN);
  tft.setCursor(10,210);
  tft.loadFont(FONT_22);
  tft.print("Сейчас ");
  tft.setTextColor(TFT_WHITE);

  if (actuatorcontrol==0){
    tft.setCursor(10,50);
    tft.print("Контроль отключен");

  }else if (actuatorcontrol==1){
    tft.setCursor(10,50);
    tft.print("Контроль привода включен");
    if (actuatorcontmode==0) {
      tft.setCursor(10,90);
      tft.print("Режим АВТО");
      tft.setCursor(10,130);
      tft.print("Вкл если ниже ");
      tft.unloadFont();
      tft.setTextSize(2);
      tft.print(actuatoruser,0);
      tft.setCursor(207,130);
      //tft.print("lx");
      tft.print(" +- ");
      tft.print(actuatorplus,0);
      tft.setCursor(291,130);
      //tft.print("lx");
      tft.loadFont(FONT_22); 
    } else if (actuatorcontmode==1) {
      tft.setCursor(10,90);
      tft.print("Режим по таймеру");
      tft.setCursor(10,130);
      tft.print("Включить раз в");
      tft.unloadFont();
      if(actuatortimerh<10)tft.print("0");
      tft.print(actuatortimerh);
      tft.print(":");
      if(actuatortimerm<10)tft.print("0");
      tft.print(actuatortimerm);
      tft.loadFont(FONT_22); 
      tft.setCursor(230,130);
      tft.print("на");
      tft.unloadFont();
      if(actuatortimerworkh<10)tft.print("0");
      tft.print(actuatortimerworkh);
      tft.print(":");
      if(actuatortimerworkm<10)tft.print("0");
      tft.print(actuatortimerworkm);
      tft.loadFont(FONT_22); 
      tft.setCursor(10,170);
      tft.print("Запустить таймер в ");
      tft.unloadFont();
      if(actuatortimerstarth<10)tft.print("0");
      tft.print(actuatortimerstarth);
      tft.print(":");
      if(actuatortimerstartm<10)tft.print("0");
      tft.print(actuatortimerstartm);

    } else if (actuatorcontmode==2) {
      tft.setCursor(10,90);
      tft.print("Режим суточный");
      tft.setCursor(10,130);
      tft.print("Вкл привод в ");
      tft.unloadFont();
      if(actuatorrtch<10)tft.print("0");
      tft.print(actuatorrtch);
      tft.print(":");
      if(actuatorrtcm<10)tft.print("0");
      tft.print(actuatorrtcm);
      tft.setCursor(212,130);
      tft.loadFont(FONT_22);
      tft.print("на ");   
      tft.unloadFont();
      if(actuatorrtcworkh<10)tft.print("0");
      tft.print(actuatorrtcworkh);
      tft.print(":");
      if(actuatorrtcworkm<10)tft.print("0");
      tft.print(actuatorrtcworkm);

    } else if (actuatorcontmode==3) {
      tft.setCursor(10,90);
      tft.print("Режим всегда включен");
    }

  }
  tft.unloadFont(); 

  if(selactuator==1)  
  Selactuator_1();
  else if(selactuator==2)  
  Selactuator_2();
  else if(selactuator==3)  
  Selactuator_3();
  else if(selactuator==4)  
  Selactuator_4();
}

void Selactuator_1()
{
  tft.loadFont(FONT_22); 
  tft.fillRect(0,40,320,40,TFT_RED);
  tft.setCursor(10,50);
  if (actuatorcontrol==0){
    tft.print("Контроль отключен");
  }else if (actuatorcontrol==1){
    tft.print("Контроль привода включен");
  }
  tft.unloadFont();
}
void Selactuator_2()
{
  tft.loadFont(FONT_22); 
  tft.fillRect(0,80,320,40,TFT_RED);
  tft.setCursor(10,90);
  if (actuatorcontrol!=0){
    if (actuatorcontmode==0) {
      tft.print("Режим АВТО");
    } else if (actuatorcontmode==1) {
      tft.print("Режим по таймеру");
    } else if (actuatorcontmode==2) {
      tft.print("Режим суточный");
    } else if (actuatorcontmode==3) {
      tft.print("Режим всегда включен");
    }
  tft.unloadFont();
  }
}
void Selactuator_3()
{
  tft.loadFont(FONT_22); 
  tft.fillRect(0,120,320,40,TFT_RED);
  tft.setTextSize(2);
  tft.setCursor(10,130);
  if (actuatorcontrol==1){
    if (actuatorcontmode==0) {
      tft.print("Вкл если ниже ");
      tft.unloadFont();
      tft.setTextSize(2);
      tft.print(actuatoruser,0);
      tft.setCursor(207,130);
     // tft.print("lx");
      tft.print(" +- ");
      tft.print(actuatorplus,0);
      tft.setCursor(291,130);
      //tft.print("lx");
      if(seledit==0)
      editactuatoruser();
      else editactuatorplus();
      tft.loadFont(FONT_22); 
    } else if (actuatorcontmode==1) {
        tft.print("Включить раз в");
        tft.unloadFont();
        if(actuatortimerh<10)tft.print("0");
        tft.print(actuatortimerh);
        tft.print(":");
        if(actuatortimerm<10)tft.print("0");
        tft.print(actuatortimerm);
        tft.loadFont(FONT_22); 
        tft.setCursor(230,130);
        tft.print("на ");
        tft.unloadFont();
        if(actuatortimerworkh<10)tft.print("0");
        tft.print(actuatortimerworkh);
        tft.print(":");
        if(actuatortimerworkm<10)tft.print("0");
        tft.print(actuatortimerworkm);
      if(seledit==0)
      editactuatortimer();
      else editactuatortimerwork();
    } else if (actuatorcontmode==2) {
      tft.loadFont(FONT_22);
      tft.print("Вкл привод в ");
      tft.unloadFont();
      if(actuatorrtch<10)tft.print("0");
      tft.print(actuatorrtch);
      tft.print(":");
      if(actuatorrtcm<10)tft.print("0");
      tft.print(actuatorrtcm);
      tft.setCursor(212,130);
      tft.loadFont(FONT_22);
      tft.print("на ");   
      tft.unloadFont();
      if(actuatorrtcworkh<10)tft.print("0");
      tft.print(actuatorrtcworkh);
      tft.print(":");
      if(actuatorrtcworkm<10)tft.print("0");
      tft.print(actuatorrtcworkm);
      if(seledit==0)
      editactuatorrtc();
      else editactuatorrtcwork();
    }
  }
  tft.unloadFont();
}
void Selactuator_4()
{
  tft.loadFont(FONT_22); 
  tft.fillRect(0,160,320,40,TFT_RED);
  tft.setCursor(10,170);
  tft.print("Запустить таймер в ");
  tft.unloadFont();
  if(actuatortimerstarth<10)tft.print("0");
  tft.print(actuatortimerstarth);
  tft.print(":");
  if(actuatortimerstartm<10)tft.print("0");
  tft.print(actuatortimerstartm);
  editactuatortimerstart();
}





// отрисовка редактирования температуры авто
void editactuatoruser()
{
  tft.fillRect(159,128,48,16,TFT_BLUE);
  tft.setTextColor(TFT_WHITE);
  tft.setTextSize(2);
  tft.setCursor(160,129);
  tft.print(actuatoruser,0);
}

// отрисовка редактирования +- температуры авто
void editactuatorplus()
{
  tft.fillRect(253,128,36,16,TFT_BLUE);
  tft.setTextColor(TFT_WHITE);
  tft.setTextSize(2);
  tft.setCursor(254,129);
  tft.print(actuatorplus,0);
}

// отрисовка редактирования таймера нагрева
void editactuatortimer()
{
  tft.fillRect(167,128,60,16,TFT_BLUE);
  tft.setTextColor(TFT_WHITE);
  tft.setTextSize(2);
  tft.setCursor(168,129);
  if(actuatortimerh<10)tft.print("0");
  tft.print(actuatortimerh);
  tft.print(":");
  if(actuatortimerm<10)tft.print("0");
  tft.print(actuatortimerm);
}

// отрисовка редактирования таймера работы нагрева
void editactuatortimerwork()
{
  tft.fillRect(256,128,60,16,TFT_BLUE);
  tft.setTextColor(TFT_WHITE);
  tft.setTextSize(2);
  tft.setCursor(257,129);
  if(actuatortimerworkh<10)tft.print("0");
  tft.print(actuatortimerworkh);
  tft.print(":");
  if(actuatortimerworkm<10)tft.print("0");
  tft.print(actuatortimerworkm);
}

void editactuatortimerstart()
{
  tft.fillRect(213,168,60,16,TFT_BLUE);
  tft.setTextColor(TFT_WHITE);
  tft.setTextSize(2);
  tft.setCursor(214,169);
  if(actuatortimerstarth<10)tft.print("0");
  tft.print(actuatortimerstarth);
  tft.print(":");
  if(actuatortimerstartm<10)tft.print("0");
  tft.print(actuatortimerstartm);
}

// отрисовка редактирования RTC нагрева
void editactuatorrtc()
{
  tft.fillRect(150,128,60,16,TFT_BLUE);
  tft.setTextColor(TFT_WHITE);
  tft.setTextSize(2);
  tft.setCursor(151,129);
  if(actuatorrtch<10)tft.print("0");
  tft.print(actuatorrtch);
  tft.print(":");
  if(actuatorrtcm<10)tft.print("0");
  tft.print(actuatorrtcm);
}

// отрисовка редактирования RTC работы нагрева
void editactuatorrtcwork()
{
  tft.fillRect(240,128,60,16,TFT_BLUE);
  tft.setTextColor(TFT_WHITE);
  tft.setTextSize(2);
  tft.setCursor(241,129);
  if(actuatorrtcworkh<10)tft.print("0");
  tft.print(actuatorrtcworkh);
  tft.print(":");
  if(actuatorrtcworkm<10)tft.print("0");
  tft.print(actuatorrtcworkm);
}


void usermodesclimatup(){
  if(mode == 15) {
    if (relay1control==0) selrelay1=1;
    else if ((relay1control!=0)&&(relay1contmode==3)){
      if(selrelay1==2) selrelay1 = 1;
      else selrelay1++;
    } else if((relay1control!=0)&&(relay1contmode==1)){
      if(selrelay1==4) selrelay1 = 1;
      else selrelay1++; 
    } else if(selrelay1==3) selrelay1 = 1;
    else selrelay1++;
    setrelay1(selrelay1);
    time1=0;
    relay1menu1=0;
  }
  if(mode == 16) {
    if (relay2control==0) selrelay2=1;
    else if ((relay2control!=0)&&(relay2contmode==3)){
      if(selrelay2==2) selrelay2 = 1;
      else selrelay2++;
    } else if((relay2control!=0)&&(relay2contmode==1)){
      if(selrelay2==4) selrelay2 = 1;
      else selrelay2++; 
    } else if(selrelay2==3) selrelay2 = 1;
    else selrelay2++;
    setrelay2(selrelay2);
    time1=0;
    relay2menu1=0;
  }
  if(mode == 17) {
    if (servo1control==0) selservo1=1;
    else if ((servo1control!=0)&&(servo1contmode==3)){
      if(selservo1==2) selservo1 = 1;
      else selservo1++;
    } else if((servo1control!=0)&&(servo1contmode==1)){
      if(selservo1==4) selservo1 = 1;
      else selservo1++; 
    } else if(selservo1==3) selservo1 = 1;
    else selservo1++;
    setservo1(selservo1);
    time1=0;
    servo1menu1=0;
  }
  if(mode == 18) {
    if (servo2control==0) selservo2=1;
    else if ((servo2control!=0)&&(servo2contmode==3)){
      if(selservo2==2) selservo2 = 1;
      else selservo2++;
    } else if((servo2control!=0)&&(servo2contmode==1)){
      if(selservo2==4) selservo2 = 1;
      else selservo2++; 
    } else if(selservo2==3) selservo2 = 1;
    else selservo2++;
    setservo2(selservo2);
    time1=0;
    servo2menu1=0;
  }
  if(mode == 19) {
    if (actuatorcontrol==0) selactuator=1;
    else if ((actuatorcontrol!=0)&&(actuatorcontmode==3)){
      if(selactuator==2) selactuator = 1;
      else selactuator++;
    } else if((actuatorcontrol!=0)&&(actuatorcontmode==1)){
      if(selactuator==4) selactuator = 1;
      else selactuator++; 
    } else if(selactuator==3) selactuator = 1;
    else selactuator++;
    setactuator(selactuator);
    time1=0;
    actuatormenu1=0;
  }
}


void usermodesclimatdown()
{
  if(mode == 15) {
    if (relay1control==0) selrelay1=1;
    else if ((relay1control!=0)&&(relay1contmode==3)){
      if(selrelay1==1) selrelay1 = 2;
      else selrelay1--;
    } else if((relay1control!=0)&&(relay1contmode==1)){
      if(selrelay1==1) selrelay1 = 4;
      else selrelay1--;
    } else if(selrelay1==1) selrelay1 = 3;
    else selrelay1--;
    setrelay1(selrelay1);
    time1=0;
    relay1menu1=0;
  }
  if(mode == 16) {
    if (relay2control==0) selrelay2=1;
    else if ((relay2control!=0)&&(relay2contmode==3)){
      if(selrelay2==1) selrelay2 = 2;
      else selrelay2--;
    } else if((relay2control!=0)&&(relay2contmode==1)){
      if(selrelay2==1) selrelay2 = 4;
      else selrelay2--;
    } else if(selrelay2==1) selrelay2 = 3;
    else selrelay2--;
    setrelay2(selrelay2);
    time1=0;
    relay2menu1=0;
  }
  if(mode == 17) {
    if (servo1control==0) selservo1=1;
    else if ((servo1control!=0)&&(servo1contmode==3)){
      if(selservo1==1) selservo1 = 2;
      else selservo1--;
    } else if((servo1control!=0)&&(servo1contmode==1)){
      if(selservo1==1) selservo1 = 4;
      else selservo1--;
    } else if(selservo1==1) selservo1 = 3;
    else selservo1--;
    setservo1(selservo1);
    time1=0;
    servo1menu1=0;
  }
  if(mode == 18) {
    if (servo2control==0) selservo2=1;
    else if ((servo2control!=0)&&(servo2contmode==3)){
      if(selservo2==1) selservo2 = 2;
      else selservo2--;
    } else if((servo2control!=0)&&(servo2contmode==1)){
      if(selservo2==1) selservo2 = 4;
      else selservo2--;
    } else if(selservo2==1) selservo2 = 3;
    else selservo2--;
    setservo2(selservo2);
    time1=0;
    servo2menu1=0;
  }
  if(mode == 19) {
    if (actuatorcontrol==0) selactuator=1;
    else if ((actuatorcontrol!=0)&&(actuatorcontmode==3)){
      if(selactuator==1) selactuator = 2;
      else selactuator--;
    } else if((actuatorcontrol!=0)&&(actuatorcontmode==1)){
      if(selactuator==1) selactuator = 4;
      else selactuator--;
    } else if(selactuator==1) selactuator = 3;
    else selactuator--;
    setactuator(selactuator);
    time1=0;
    actuatormenu1=0;
  }
}



void usermodesclimatleft()
{
  if(mode==15) {
    if (selrelay1==1) {
      if (relay1control==0){
        relay1control=1;
      }else relay1control--;
      resetrelay1();
    }   
    if (selrelay1==2) {
      if (relay1contmode==0){
        relay1contmode=3;
      }else relay1contmode--;
      resetrelay1();
    } 
      if (seledit==0){
        seledit=1;
      }else seledit--;
    setrelay1(selrelay1);
    time1=0;
    relay1menu1=0;
  }
  if(mode==16) {
    if (selrelay2==1) {
      if (relay2control==0){
        relay2control=1;
      }else relay2control--;
      resetrelay2();
    }   
    if (selrelay2==2) {
      if (relay2contmode==0){
        relay2contmode=3;
      }else relay2contmode--;
      resetrelay2();
    } 
      if (seledit==0){
        seledit=1;
      }else seledit--;
    setrelay2(selrelay2);
    time1=0;
    relay2menu1=0;
  }
  if(mode==17) {
    if (selservo1==1) {
      if (servo1control==0){
        servo1control=1;
      }else servo1control--;
      resetservo1();
    }   
    if (selservo1==2) {
      if (servo1contmode==0){
        servo1contmode=3;
      }else servo1contmode--;
      resetservo1();
    } 
      if (seledit==0){
        seledit=1;
      }else seledit--;
    setservo1(selservo1);
    time1=0;
    servo1menu1=0;
  }
  if(mode==18) {
    if (selservo2==1) {
      if (servo2control==0){
        servo2control=1;
      }else servo2control--;
      resetservo2();
    }   
    if (selservo2==2) {
      if (servo2contmode==0){
        servo2contmode=3;
      }else servo2contmode--;
      resetservo2();
    } 
      if (seledit==0){
        seledit=1;
      }else seledit--;
    setservo2(selservo2);
    time1=0;
    servo2menu1=0;
  }
  if(mode==19) {
    if (selactuator==1) {
      if (actuatorcontrol==0){
        actuatorcontrol=1;
      }else actuatorcontrol--;
      resetactuator();
    }   
    if (selactuator==2) {
      if (actuatorcontmode==0){
        actuatorcontmode=3;
      }else actuatorcontmode--;
      resetactuator();
    } 
      if (seledit==0){
        seledit=1;
      }else seledit--;
    setactuator(selactuator);
    time1=0;
    actuatormenu1=0;
  }
}

void usermodesclimatright()
{
  if(mode==15) {
    if (selrelay1==1) {
      if (relay1control==1) relay1control=0;
      else relay1control++;   
      resetrelay1(); 
    }
    if (selrelay1==2) {
      if (relay1contmode==3) relay1contmode=0;
      else relay1contmode++; 
      resetrelay1();   
    }
      if (seledit==1) seledit=0;
      else seledit++;
    setrelay1(selrelay1);
    time1=0;
    relay1menu1=0;
  }
  if(mode==16) {
    if (selrelay2==1) {
      if (relay2control==1) relay2control=0;
      else relay2control++;   
      resetrelay2(); 
    }
    if (selrelay2==2) {
      if (relay2contmode==3) relay2contmode=0;
      else relay2contmode++; 
      resetrelay2();   
    }
      if (seledit==1) seledit=0;
      else seledit++;
    setrelay2(selrelay2);
    time1=0;
    relay2menu1=0;
  }
  if(mode==17) {
    if (selservo1==1) {
      if (servo1control==1) servo1control=0;
      else servo1control++;   
      resetservo1(); 
    }
    if (selservo1==2) {
      if (servo1contmode==3) servo1contmode=0;
      else servo1contmode++; 
      resetservo1();   
    }
      if (seledit==1) seledit=0;
      else seledit++;
    setservo1(selservo1);
    time1=0;
    servo1menu1=0;
  }
  if(mode==18) {
    if (selservo2==1) {
      if (servo2control==1) servo2control=0;
      else servo2control++;   
      resetservo2(); 
    }
    if (selservo2==2) {
      if (servo2contmode==3) servo2contmode=0;
      else servo2contmode++; 
      resetservo2();   
    }
      if (seledit==1) seledit=0;
      else seledit++;
    setservo2(selservo2);
    time1=0;
    servo2menu1=0;
  }
  if(mode==19) {
    if (selactuator==1) {
      if (actuatorcontrol==1) actuatorcontrol=0;
      else actuatorcontrol++;   
      resetactuator(); 
    }
    if (selactuator==2) {
      if (actuatorcontmode==3) actuatorcontmode=0;
      else actuatorcontmode++; 
      resetactuator();   
    }
      if (seledit==1) seledit=0;
      else seledit++;
    setactuator(selactuator);
    time1=0;
    actuatormenu1=0;
  }
}


void usermodesclimatencoderup()
{
  if (mode == 15){
    if(relay1control==1){
      if (selrelay1==3){
        if(relay1contmode==0){
          if((seledit==0) && (relay1user<9995)){
            if(relay1user>=100)
            relay1user+=5;
            else relay1user++;
            editrelay1user();
          } else if ((seledit==1) && (relay1plus<995)){
            if(relay1plus>=100)
            relay1plus+=5;
            else relay1plus++;
            editrelay1plus();
          }
        }
        if(relay1contmode==1){
          if(seledit==0){
            relay1timerm+=5;
            if (relay1timerm > 59){
              if (relay1timerh>98) relay1timerh=0;
              else relay1timerh++;
              relay1timerm -= 60;
            }
            if((relay1timerh==0)&&(relay1timerm==0)) relay1timerm+=5;
            editrelay1timer();
          } else if (seledit==1){
            relay1timerworkm+=5;
            if (relay1timerworkm > 59){
              if (relay1timerworkh>98) relay1timerworkh=0;
              else relay1timerworkh++;
              relay1timerworkm -= 60;
            }
            if((relay1timerworkh==0)&&(relay1timerworkm==0)) relay1timerworkm+=5;
            editrelay1timerwork();
          }
        }
        if(relay1contmode==2){
          if(seledit==0){
            relay1rtcm+=5;
            if (relay1rtcm > 59){
              if (relay1rtch>22) relay1rtch=0;
              else relay1rtch++;
              relay1rtcm -= 60;
            }
            editrelay1rtc();
          } else if (seledit==1){
            relay1rtcworkm+=5;
            if (relay1rtcworkm > 59){
              if (relay1rtcworkh>22) relay1rtcworkh=0;
              else relay1rtcworkh++;
              relay1rtcworkm -= 60;
            }
            if((relay1rtcworkh==0)&&(relay1rtcworkm==0)) relay1rtcworkm+=5;
            editrelay1rtcwork();
          }
        }
      }
      if (selrelay1==4){
        if(relay1contmode==1){
          relay1timerstartm+=5;
          if (relay1timerstartm > 59){
            if (relay1timerstarth>22) relay1timerstarth=0;
            else relay1timerstarth++;
            relay1timerstartm -= 60;
          }
          editrelay1timerstart();
        }
      }       
    }
  }
  if (mode == 16){
    if(relay2control==1){
      if (selrelay2==3){
        if(relay2contmode==0){
          if((seledit==0) && (relay2user<9995)){
            if(relay2user>=100)
            relay2user+=5;
            else relay2user++;
            editrelay2user();
          } else if ((seledit==1) && (relay2plus<995)){
            if(relay2plus>=100)
            relay2plus+=5;
            else relay2plus++;
            editrelay2plus();
          }
        }
        if(relay2contmode==1){
          if(seledit==0){
            relay2timerm+=5;
            if (relay2timerm > 59){
              if (relay2timerh>98) relay2timerh=0;
              else relay2timerh++;
              relay2timerm -= 60;
            }
            if((relay2timerh==0)&&(relay2timerm==0)) relay2timerm+=5;
            editrelay2timer();
          } else if (seledit==1){
            relay2timerworkm+=5;
            if (relay2timerworkm > 59){
              if (relay2timerworkh>98) relay2timerworkh=0;
              else relay2timerworkh++;
              relay2timerworkm -= 60;
            }
            if((relay2timerworkh==0)&&(relay2timerworkm==0)) relay2timerworkm+=5;
            editrelay2timerwork();
          }
        }
        if(relay2contmode==2){
          if(seledit==0){
            relay2rtcm+=5;
            if (relay2rtcm > 59){
              if (relay2rtch>22) relay2rtch=0;
              else relay2rtch++;
              relay2rtcm -= 60;
            }
            editrelay2rtc();
          } else if (seledit==1){
            relay2rtcworkm+=5;
            if (relay2rtcworkm > 59){
              if (relay2rtcworkh>22) relay2rtcworkh=0;
              else relay2rtcworkh++;
              relay2rtcworkm -= 60;
            }
            if((relay2rtcworkh==0)&&(relay2rtcworkm==0)) relay2rtcworkm+=5;
            editrelay2rtcwork();
          }
        }
      }
      if (selrelay2==4){
        if(relay2contmode==1){
          relay2timerstartm+=5;
          if (relay2timerstartm > 59){
            if (relay2timerstarth>22) relay2timerstarth=0;
            else relay2timerstarth++;
            relay2timerstartm -= 60;
          }
          editrelay2timerstart();
        }
      }       
    }
  }
  if (mode == 17){
    if(servo1control==1){
      if (selservo1==3){
        if(servo1contmode==0){
          if((seledit==0) && (servo1user<9995)){
            if(servo1user>=100)
            servo1user+=5;
            else servo1user++;
            editservo1user();
          } else if ((seledit==1) && (servo1plus<995)){
            if(servo1plus>=100)
            servo1plus+=5;
            else servo1plus++;
            editservo1plus();
          }
        }
        if(servo1contmode==1){
          if(seledit==0){
            servo1timerm+=5;
            if (servo1timerm > 59){
              if (servo1timerh>98) servo1timerh=0;
              else servo1timerh++;
              servo1timerm -= 60;
            }
            if((servo1timerh==0)&&(servo1timerm==0)) servo1timerm+=5;
            editservo1timer();
          } else if (seledit==1){
            servo1timerworkm+=5;
            if (servo1timerworkm > 59){
              if (servo1timerworkh>98) servo1timerworkh=0;
              else servo1timerworkh++;
              servo1timerworkm -= 60;
            }
            if((servo1timerworkh==0)&&(servo1timerworkm==0)) servo1timerworkm+=5;
            editservo1timerwork();
          }
        }
        if(servo1contmode==2){
          if(seledit==0){
            servo1rtcm+=5;
            if (servo1rtcm > 59){
              if (servo1rtch>22) servo1rtch=0;
              else servo1rtch++;
              servo1rtcm -= 60;
            }
            editservo1rtc();
          } else if (seledit==1){
            servo1rtcworkm+=5;
            if (servo1rtcworkm > 59){
              if (servo1rtcworkh>22) servo1rtcworkh=0;
              else servo1rtcworkh++;
              servo1rtcworkm -= 60;
            }
            if((servo1rtcworkh==0)&&(servo1rtcworkm==0)) servo1rtcworkm+=5;
            editservo1rtcwork();
          }
        }
      }
      if (selservo1==4){
        if(servo1contmode==1){
          servo1timerstartm+=5;
          if (servo1timerstartm > 59){
            if (servo1timerstarth>22) servo1timerstarth=0;
            else servo1timerstarth++;
            servo1timerstartm -= 60;
          }
          editservo1timerstart();
        }
      }       
    }
  }
  if (mode == 18){
    if(servo2control==1){
      if (selservo2==3){
        if(servo2contmode==0){
          if((seledit==0) && (servo2user<9995)){
            if(servo2user>=100)
            servo2user+=5;
            else servo2user++;
            editservo2user();
          } else if ((seledit==1) && (servo2plus<995)){
            if(servo2plus>=100)
            servo2plus+=5;
            else servo2plus++;
            editservo2plus();
          }
        }
        if(servo2contmode==1){
          if(seledit==0){
            servo2timerm+=5;
            if (servo2timerm > 59){
              if (servo2timerh>98) servo2timerh=0;
              else servo2timerh++;
              servo2timerm -= 60;
            }
            if((servo2timerh==0)&&(servo2timerm==0)) servo2timerm+=5;
            editservo2timer();
          } else if (seledit==1){
            servo2timerworkm+=5;
            if (servo2timerworkm > 59){
              if (servo2timerworkh>98) servo2timerworkh=0;
              else servo2timerworkh++;
              servo2timerworkm -= 60;
            }
            if((servo2timerworkh==0)&&(servo2timerworkm==0)) servo2timerworkm+=5;
            editservo2timerwork();
          }
        }
        if(servo2contmode==2){
          if(seledit==0){
            servo2rtcm+=5;
            if (servo2rtcm > 59){
              if (servo2rtch>22) servo2rtch=0;
              else servo2rtch++;
              servo2rtcm -= 60;
            }
            editservo2rtc();
          } else if (seledit==1){
            servo2rtcworkm+=5;
            if (servo2rtcworkm > 59){
              if (servo2rtcworkh>22) servo2rtcworkh=0;
              else servo2rtcworkh++;
              servo2rtcworkm -= 60;
            }
            if((servo2rtcworkh==0)&&(servo2rtcworkm==0)) servo2rtcworkm+=5;
            editservo2rtcwork();
          }
        }
      }
      if (selservo2==4){
        if(servo2contmode==1){
          servo2timerstartm+=5;
          if (servo2timerstartm > 59){
            if (servo2timerstarth>22) servo2timerstarth=0;
            else servo2timerstarth++;
            servo2timerstartm -= 60;
          }
          editservo2timerstart();
        }
      }       
    }
  }
  if (mode == 19){
    if(actuatorcontrol==1){
      if (selactuator==3){
        if(actuatorcontmode==0){
          if((seledit==0) && (actuatoruser<9995)){
            if(actuatoruser>=100)
            actuatoruser+=5;
            else actuatoruser++;
            editactuatoruser();
          } else if ((seledit==1) && (actuatorplus<995)){
            if(actuatorplus>=100)
            actuatorplus+=5;
            else actuatorplus++;
            editactuatorplus();
          }
        }
        if(actuatorcontmode==1){
          if(seledit==0){
            actuatortimerm+=5;
            if (actuatortimerm > 59){
              if (actuatortimerh>98) actuatortimerh=0;
              else actuatortimerh++;
              actuatortimerm -= 60;
            }
            if((actuatortimerh==0)&&(actuatortimerm==0)) actuatortimerm+=5;
            editactuatortimer();
          } else if (seledit==1){
            actuatortimerworkm+=5;
            if (actuatortimerworkm > 59){
              if (actuatortimerworkh>98) actuatortimerworkh=0;
              else actuatortimerworkh++;
              actuatortimerworkm -= 60;
            }
            if((actuatortimerworkh==0)&&(actuatortimerworkm==0)) actuatortimerworkm+=5;
            editactuatortimerwork();
          }
        }
        if(actuatorcontmode==2){
          if(seledit==0){
            actuatorrtcm+=5;
            if (actuatorrtcm > 59){
              if (actuatorrtch>22) actuatorrtch=0;
              else actuatorrtch++;
              actuatorrtcm -= 60;
            }
            editactuatorrtc();
          } else if (seledit==1){
            actuatorrtcworkm+=5;
            if (actuatorrtcworkm > 59){
              if (actuatorrtcworkh>22) actuatorrtcworkh=0;
              else actuatorrtcworkh++;
              actuatorrtcworkm -= 60;
            }
            if((actuatorrtcworkh==0)&&(actuatorrtcworkm==0)) actuatorrtcworkm+=5;
            editactuatorrtcwork();
          }
        }
      }
      if (selactuator==4){
        if(actuatorcontmode==1){
          actuatortimerstartm+=5;
          if (actuatortimerstartm > 59){
            if (actuatortimerstarth>22) actuatortimerstarth=0;
            else actuatortimerstarth++;
            actuatortimerstartm -= 60;
          }
          editactuatortimerstart();
        }
      }       
    }
  }
}

void usermodesclimatencoderdown()
{
  if (mode == 15){
    if(relay1control==1){
      if (selrelay1==3){
        if(relay1contmode==0){
          if((seledit==0) && (relay1user>0)){
            if(relay1user>100)
            relay1user-=5;
            else relay1user--;
            editrelay1user();
          } else if ((seledit==1) && (relay1plus>1)){
            if(relay1plus>100)            
            relay1plus-=5;
            else relay1plus--;
            editrelay1plus();
          }
        }
        if(relay1contmode==1){
          if(seledit==0){
            relay1timerm-=5;
            if((relay1timerh==0)&&(relay1timerm==0)) relay1timerm-=5;
            if (relay1timerm < 0){
              if (relay1timerh<1) relay1timerh=99;
              else relay1timerh--;
              relay1timerm += 60;
            }
            editrelay1timer();
          } else if (seledit==1){
            relay1timerworkm-=5;
            if((relay1timerworkh==0)&&(relay1timerworkm==0)) relay1timerworkm-=5;
            if (relay1timerworkm < 0){
              if (relay1timerworkh<1) relay1timerworkh=99;
              else relay1timerworkh--;
              relay1timerworkm += 60;
            }
            editrelay1timerwork();
          }
        }
        if(relay1contmode==2){
          if(seledit==0){
            relay1rtcm-=5;
            if (relay1rtcm < 0){
              if (relay1rtch<1) relay1rtch=23;
              else relay1rtch--;
              relay1rtcm += 60;
            }
            editrelay1rtc();
          } else if (seledit==1){
            relay1rtcworkm-=5;
            if((relay1rtcworkh==0)&&(relay1rtcworkm==0)) relay1rtcworkm-=5;
            if (relay1rtcworkm < 0){
              if (relay1rtcworkh<1) relay1rtcworkh=23;
              else relay1rtcworkh--;
              relay1rtcworkm += 60;
            }
            editrelay1rtcwork();
          }
        }
      }
      if (selrelay1==4){
        if(relay1contmode==1){
            relay1timerstartm-=5;
            if (relay1timerstartm < 0){
              if (relay1timerstarth<1) relay1timerstarth=23;
              else relay1timerstarth--;
              relay1timerstartm += 60;
            }
            editrelay1timerstart();
        }
      }       
    }
  }
  if (mode == 16){
    if(relay2control==1){
      if (selrelay2==3){
        if(relay2contmode==0){
          if((seledit==0) && (relay2user>0)){
            if(relay2user>100)
            relay2user-=5;
            else relay2user--;
            editrelay2user();
          } else if ((seledit==1) && (relay2plus>1)){
            if(relay2plus>100)            
            relay2plus-=5;
            else relay2plus--;
            editrelay2plus();
          }
        }
        if(relay2contmode==1){
          if(seledit==0){
            relay2timerm-=5;
            if((relay2timerh==0)&&(relay2timerm==0)) relay2timerm-=5;
            if (relay2timerm < 0){
              if (relay2timerh<1) relay2timerh=99;
              else relay2timerh--;
              relay2timerm += 60;
            }
            editrelay2timer();
          } else if (seledit==1){
            relay2timerworkm-=5;
            if((relay2timerworkh==0)&&(relay2timerworkm==0)) relay2timerworkm-=5;
            if (relay2timerworkm < 0){
              if (relay2timerworkh<1) relay2timerworkh=99;
              else relay2timerworkh--;
              relay2timerworkm += 60;
            }
            editrelay2timerwork();
          }
        }
        if(relay2contmode==2){
          if(seledit==0){
            relay2rtcm-=5;
            if (relay2rtcm < 0){
              if (relay2rtch<1) relay2rtch=23;
              else relay2rtch--;
              relay2rtcm += 60;
            }
            editrelay2rtc();
          } else if (seledit==1){
            relay2rtcworkm-=5;
            if((relay2rtcworkh==0)&&(relay2rtcworkm==0)) relay2rtcworkm-=5;
            if (relay2rtcworkm < 0){
              if (relay2rtcworkh<1) relay2rtcworkh=23;
              else relay2rtcworkh--;
              relay2rtcworkm += 60;
            }
            editrelay2rtcwork();
          }
        }
      }
      if (selrelay2==4){
        if(relay2contmode==1){
            relay2timerstartm-=5;
            if (relay2timerstartm < 0){
              if (relay2timerstarth<1) relay2timerstarth=23;
              else relay2timerstarth--;
              relay2timerstartm += 60;
            }
            editrelay2timerstart();
        }
      }       
    }
  }
  if (mode == 17){
    if(servo1control==1){
      if (selservo1==3){
        if(servo1contmode==0){
          if((seledit==0) && (servo1user>0)){
            if(servo1user>100)
            servo1user-=5;
            else servo1user--;
            editservo1user();
          } else if ((seledit==1) && (servo1plus>1)){
            if(servo1plus>100)            
            servo1plus-=5;
            else servo1plus--;
            editservo1plus();
          }
        }
        if(servo1contmode==1){
          if(seledit==0){
            servo1timerm-=5;
            if((servo1timerh==0)&&(servo1timerm==0)) servo1timerm-=5;
            if (servo1timerm < 0){
              if (servo1timerh<1) servo1timerh=99;
              else servo1timerh--;
              servo1timerm += 60;
            }
            editservo1timer();
          } else if (seledit==1){
            servo1timerworkm-=5;
            if((servo1timerworkh==0)&&(servo1timerworkm==0)) servo1timerworkm-=5;
            if (servo1timerworkm < 0){
              if (servo1timerworkh<1) servo1timerworkh=99;
              else servo1timerworkh--;
              servo1timerworkm += 60;
            }
            editservo1timerwork();
          }
        }
        if(servo1contmode==2){
          if(seledit==0){
            servo1rtcm-=5;
            if (servo1rtcm < 0){
              if (servo1rtch<1) servo1rtch=23;
              else servo1rtch--;
              servo1rtcm += 60;
            }
            editservo1rtc();
          } else if (seledit==1){
            servo1rtcworkm-=5;
            if((servo1rtcworkh==0)&&(servo1rtcworkm==0)) servo1rtcworkm-=5;
            if (servo1rtcworkm < 0){
              if (servo1rtcworkh<1) servo1rtcworkh=23;
              else servo1rtcworkh--;
              servo1rtcworkm += 60;
            }
            editservo1rtcwork();
          }
        }
      }
      if (selservo1==4){
        if(servo1contmode==1){
            servo1timerstartm-=5;
            if (servo1timerstartm < 0){
              if (servo1timerstarth<1) servo1timerstarth=23;
              else servo1timerstarth--;
              servo1timerstartm += 60;
            }
            editservo1timerstart();
        }
      }       
    }
  }
  if (mode == 18){
    if(servo2control==1){
      if (selservo2==3){
        if(servo2contmode==0){
          if((seledit==0) && (servo2user>0)){
            if(servo2user>100)
            servo2user-=5;
            else servo2user--;
            editservo2user();
          } else if ((seledit==1) && (servo2plus>1)){
            if(servo2plus>100)            
            servo2plus-=5;
            else servo2plus--;
            editservo2plus();
          }
        }
        if(servo2contmode==1){
          if(seledit==0){
            servo2timerm-=5;
            if((servo2timerh==0)&&(servo2timerm==0)) servo2timerm-=5;
            if (servo2timerm < 0){
              if (servo2timerh<1) servo2timerh=99;
              else servo2timerh--;
              servo2timerm += 60;
            }
            editservo2timer();
          } else if (seledit==1){
            servo2timerworkm-=5;
            if((servo2timerworkh==0)&&(servo2timerworkm==0)) servo2timerworkm-=5;
            if (servo2timerworkm < 0){
              if (servo2timerworkh<1) servo2timerworkh=99;
              else servo2timerworkh--;
              servo2timerworkm += 60;
            }
            editservo2timerwork();
          }
        }
        if(servo2contmode==2){
          if(seledit==0){
            servo2rtcm-=5;
            if (servo2rtcm < 0){
              if (servo2rtch<1) servo2rtch=23;
              else servo2rtch--;
              servo2rtcm += 60;
            }
            editservo2rtc();
          } else if (seledit==1){
            servo2rtcworkm-=5;
            if((servo2rtcworkh==0)&&(servo2rtcworkm==0)) servo2rtcworkm-=5;
            if (servo2rtcworkm < 0){
              if (servo2rtcworkh<1) servo2rtcworkh=23;
              else servo2rtcworkh--;
              servo2rtcworkm += 60;
            }
            editservo2rtcwork();
          }
        }
      }
      if (selservo2==4){
        if(servo2contmode==1){
            servo2timerstartm-=5;
            if (servo2timerstartm < 0){
              if (servo2timerstarth<1) servo2timerstarth=23;
              else servo2timerstarth--;
              servo2timerstartm += 60;
            }
            editservo2timerstart();
        }
      }       
    }
  }
  if (mode == 19){
    if(actuatorcontrol==1){
      if (selactuator==3){
        if(actuatorcontmode==0){
          if((seledit==0) && (actuatoruser>0)){
            if(actuatoruser>100)
            actuatoruser-=5;
            else actuatoruser--;
            editactuatoruser();
          } else if ((seledit==1) && (actuatorplus>1)){
            if(actuatorplus>100)            
            actuatorplus-=5;
            else actuatorplus--;
            editactuatorplus();
          }
        }
        if(actuatorcontmode==1){
          if(seledit==0){
            actuatortimerm-=5;
            if((actuatortimerh==0)&&(actuatortimerm==0)) actuatortimerm-=5;
            if (actuatortimerm < 0){
              if (actuatortimerh<1) actuatortimerh=99;
              else actuatortimerh--;
              actuatortimerm += 60;
            }
            editactuatortimer();
          } else if (seledit==1){
            actuatortimerworkm-=5;
            if((actuatortimerworkh==0)&&(actuatortimerworkm==0)) actuatortimerworkm-=5;
            if (actuatortimerworkm < 0){
              if (actuatortimerworkh<1) actuatortimerworkh=99;
              else actuatortimerworkh--;
              actuatortimerworkm += 60;
            }
            editactuatortimerwork();
          }
        }
        if(actuatorcontmode==2){
          if(seledit==0){
            actuatorrtcm-=5;
            if (actuatorrtcm < 0){
              if (actuatorrtch<1) actuatorrtch=23;
              else actuatorrtch--;
              actuatorrtcm += 60;
            }
            editactuatorrtc();
          } else if (seledit==1){
            actuatorrtcworkm-=5;
            if((actuatorrtcworkh==0)&&(actuatorrtcworkm==0)) actuatorrtcworkm-=5;
            if (actuatorrtcworkm < 0){
              if (actuatorrtcworkh<1) actuatorrtcworkh=23;
              else actuatorrtcworkh--;
              actuatorrtcworkm += 60;
            }
            editactuatorrtcwork();
          }
        }
      }
      if (selactuator==4){
        if(actuatorcontmode==1){
            actuatortimerstartm-=5;
            if (actuatortimerstartm < 0){
              if (actuatortimerstarth<1) actuatortimerstarth=23;
              else actuatortimerstarth--;
              actuatortimerstartm += 60;
            }
            editactuatortimerstart();
        }
      }       
    }
  }
}



void resetrelay1()
{
  prevrelay1control = relay1control;
  relay1control=0;
  delay(50);
  relay1control = prevrelay1control;
}
void resetrelay2()
{
  prevrelay2control = relay2control;
  relay2control=0;
  delay(50);
  relay2control = prevrelay2control;
}
void resetservo1()
{
  prevservo1control = servo1control;
  servo1control=0;
  delay(50);
  servo1control = prevservo1control;
}
void resetservo2()
{
  prevservo2control = servo2control;
  servo2control=0;
  delay(50);
  servo2control = prevservo2control;
}
void resetactuator()
{
  prevactuatorcontrol = actuatorcontrol;
  actuatorcontrol=0;
  delay(50);
  actuatorcontrol = prevactuatorcontrol;
}
/*----------------------ОТРИСОВКА МЕНЮ НАГРЕВА----------------------*/

void settemperatureh(int seltemph)
{
  tft.loadFont(FONT_22); 
  tft.setTextColor(TFT_BLACK);
  tft.setTextSize(2);
  tft.fillRect(0,0,320,40,TFT_GREEN);
  tft.setCursor(10,10);
  tft.print("НАГРЕВАНИЕ");
  tft.fillRect(0,40,320,160,TFT_MAGENTA);
  tft.fillRect(0,200,320,40,TFT_GREEN);
  tft.setCursor(10,210);
  tft.print("Сейчас ");
  tft.setTextColor(TFT_WHITE);

  if (tempcontrolh==0){
    tft.setCursor(10,50);
    tft.print("Контроль отключен");

  }else if (tempcontrolh==1){
    tft.setCursor(10,50);
    tft.print("Контроль нагрева включен");
    if (tempcontmodeh==0) {
      tft.setCursor(10,90);
      tft.print("Режим АВТО");
      tft.setCursor(10,130);
      tft.print("Поддерживать ");
      tft.unloadFont();
      tft.setTextSize(2);
      tft.print(tempuser,1);
      tft.setCursor(214,130);
      tft.print("÷");
      tft.print("+-");
      tft.print(tempplus,1);
      tft.print("÷");
      tft.loadFont(FONT_22); 
    } else if (tempcontmodeh==1) {
      tft.setCursor(10,90);
      tft.print("Режим по таймеру");
      tft.setCursor(10,130);
      tft.print("Нагрев раз в ");
      tft.unloadFont();
      if(temptimerhh<10)tft.print("0");
      tft.print(temptimerhh);
      tft.print(":");
      if(temptimerhm<10)tft.print("0");
      tft.print(temptimerhm);
      tft.loadFont(FONT_22); 
      tft.setCursor(207,130);
      tft.print("на ");
      tft.unloadFont();
      if(temptimerworkhh<10)tft.print("0");
      tft.print(temptimerworkhh);
      tft.print(":");
      if(temptimerworkhm<10)tft.print("0");
      tft.print(temptimerworkhm);
      tft.setCursor(10,170);
      tft.loadFont(FONT_22); 
      tft.print("Запустить таймер в ");
      tft.unloadFont();
      if(temptimerstarthh<10)tft.print("0");
      tft.print(temptimerstarthh);
      tft.print(":");
      if(temptimerstarthm<10)tft.print("0");
      tft.print(temptimerstarthm);

    } else if (tempcontmodeh==2) {
      tft.setCursor(10,90);
      tft.print("Режим суточный");
      tft.setCursor(10,130);
      tft.print("Нагрев в ");
      tft.unloadFont();
      if(temprtchh<10)tft.print("0");
      tft.print(temprtchh);
      tft.print(":");
      if(temprtchm<10)tft.print("0");
      tft.print(temprtchm);
      tft.setCursor(168,130);
      tft.loadFont(FONT_22);
      tft.print("на ");   
      tft.unloadFont();
      if(temprtcworkhh<10)tft.print("0");
      tft.print(temprtcworkhh);
      tft.print(":");
      if(temprtcworkhm<10)tft.print("0");
      tft.print(temprtcworkhm);

    } else if (tempcontmodeh==3) {
      tft.setCursor(10,90);
      tft.print("Режим всегда включен");
    }
  }
  if(seltemph==1)  
  seltemph_1();
  else if(seltemph==2)  
  seltemph_2();
  else if(seltemph==3)  
  seltemph_3();
  else if(seltemph==4)  
  seltemph_4();
}


void seltemph_1()
{
  tft.loadFont(FONT_22); 
  tft.fillRect(0,40,320,40,TFT_RED);
  tft.setCursor(10,50);
  if (tempcontrolh==0){
    tft.print("Контроль отключен");
  }else if (tempcontrolh==1){
    tft.print("Контроль нагрева включен");
  }
  tft.unloadFont();
}
void seltemph_2()
{
  tft.loadFont(FONT_22); 
  tft.fillRect(0,80,320,40,TFT_RED);
  tft.setCursor(10,90);
  if (tempcontrolh!=0){
    if (tempcontmodeh==0) {
      tft.print("Режим АВТО");
    } else if (tempcontmodeh==1) {
      tft.print("Режим по таймеру");
    } else if (tempcontmodeh==2) {
      tft.print("Режим суточный");
    } else if (tempcontmodeh==3) {
      tft.print("Режим всегда включен");
    }
  tft.unloadFont();
  }
}
void seltemph_3()
{
  tft.loadFont(FONT_22); 
  tft.fillRect(0,120,320,40,TFT_RED);
  tft.setTextSize(2);
  tft.setCursor(10,130);
  if (tempcontrolh==1){
    if (tempcontmodeh==0) {
      tft.print("Поддерживать ");
      tft.unloadFont();
      tft.setTextSize(2);
      tft.print(tempuser,1);
      tft.setCursor(214,130);
      tft.print("÷");
      tft.print("+-");
      tft.print(tempplus,1);
      tft.print("÷");
      if(seledit==0)
      edittempuser();
      else edittempplus(); 

    } else if (tempcontmodeh==1) {
      tft.print("Нагрев раз в ");
      tft.unloadFont();
      if(temptimerhh<10)tft.print("0");
      tft.print(temptimerhh);
      tft.print(":");
      if(temptimerhm<10)tft.print("0");
      tft.print(temptimerhm);
      tft.loadFont(FONT_22); 
      tft.setCursor(207,130);
      tft.print("на ");
      tft.unloadFont();
      if(temptimerworkhh<10)tft.print("0");
      tft.print(temptimerworkhh);
      tft.print(":");
      if(temptimerworkhm<10)tft.print("0");
      tft.print(temptimerworkhm); 
      tft.unloadFont();
      if(seledit==0)
      edittemptimerh();
      else edittemptimerworkh();

    } else if (tempcontmodeh==2) {
      tft.print("Нагрев в ");
      tft.unloadFont();
      if(temprtchh<10)tft.print("0");
      tft.print(temprtchh);
      tft.print(":");
      if(temprtchm<10)tft.print("0");
      tft.print(temprtchm);
      tft.setCursor(165,130);
      tft.loadFont(FONT_22);
      tft.print("на ");   
      tft.unloadFont();
      if(temprtcworkhh<10)tft.print("0");
      tft.print(temprtcworkhh);
      tft.print(":");
      if(temprtcworkhm<10)tft.print("0");
      tft.print(temprtcworkhm);
      if(seledit==0)
      edittemprtch();
      else edittemprtcworkh();
    }
  }
}
void seltemph_4()
{
  tft.loadFont(FONT_22); 
  tft.fillRect(0,160,320,40,TFT_RED);
  tft.setCursor(10,170);
  tft.print("Запустить таймер в ");
  tft.unloadFont();
  if(temptimerstarthh<10)tft.print("0");
  tft.print(temptimerstarthh);
  tft.print(":");
  if(temptimerstarthm<10)tft.print("0");
  tft.print(temptimerstarthm);
  edittemptimerstarth();
}
/*----------------------ОТРИСОВКА МЕНЮ НАГРЕВА----------------------*/
// отрисовка редактирования таймера нагрева
void edittemptimerh()
{
  tft.fillRect(143,128,60,16,TFT_BLUE);
  tft.setTextColor(TFT_WHITE);
  tft.setTextSize(2);
  tft.setCursor(144,129);
  if(temptimerhh<10)tft.print("0");
  tft.print(temptimerhh);
  tft.print(":");
  if(temptimerhm<10)tft.print("0");
  tft.print(temptimerhm);
}

// отрисовка редактирования таймера работы нагрева
void edittemptimerworkh()
{
  tft.fillRect(234,128,60,16,TFT_BLUE);
  tft.setTextColor(TFT_WHITE);
  tft.setTextSize(2);
  tft.setCursor(235,129);
  if(temptimerworkhh<10)tft.print("0");
  tft.print(temptimerworkhh);
  tft.print(":");
  if(temptimerworkhm<10)tft.print("0");
  tft.print(temptimerworkhm);
}

void edittemptimerstarth()
{
  tft.fillRect(214,168,60,16,TFT_BLUE);
  tft.setTextColor(TFT_WHITE);
  tft.setTextSize(2);
  tft.setCursor(215,169);
  if(temptimerstarthh<10)tft.print("0");
  tft.print(temptimerstarthh);
  tft.print(":");
  if(temptimerstarthm<10)tft.print("0");
  tft.print(temptimerstarthm);
}


// отрисовка редактирования RTC нагрева
void edittemprtch()
{
  tft.fillRect(104,128,60,16,TFT_BLUE);
  tft.setTextColor(TFT_WHITE);
  tft.setTextSize(2);
  tft.setCursor(105,129);
  if(temprtchh<10)tft.print("0");
  tft.print(temprtchh);
  tft.print(":");
  if(temprtchm<10)tft.print("0");
  tft.print(temprtchm);
}

// отрисовка редактирования RTC работы нагрева
void edittemprtcworkh()
{
  tft.fillRect(192,128,60,16,TFT_BLUE);
  tft.setTextColor(TFT_WHITE);
  tft.setTextSize(2);
  tft.setCursor(193,129);
  if(temprtcworkhh<10)tft.print("0");
  tft.print(temprtcworkhh);
  tft.print(":");
  if(temprtcworkhm<10)tft.print("0");
  tft.print(temprtcworkhm);
}


/*----------------------------------ОТРИСВОКА МЕНЮ ОХЛАЖДЕНИЯ-----------------------*/

void settemperaturec(int seltempc)
{
  tft.loadFont(FONT_22); 
  tft.setTextColor(TFT_BLACK);
  tft.setTextSize(2);
  tft.fillRect(0,0,320,40,TFT_GREEN);
  tft.setCursor(10,10);
  tft.print("ОХЛАЖДЕНИЕ");
  tft.fillRect(0,40,320,160,TFT_MAGENTA);
  tft.fillRect(0,200,320,40,TFT_GREEN);
  tft.setCursor(10,210);
  tft.print("Сейчас ");
  tft.setTextColor(TFT_WHITE);

  if (tempcontrolc==0){
    tft.setCursor(10,50);
    tft.print("Контроль отключен");

  }else if (tempcontrolc==1){
    tft.setCursor(10,50);
    tft.print("Контроль охлаждения вкл");
    if (tempcontmodec==0) {
      tft.setCursor(10,90);
      tft.print("Режим АВТО");
      tft.setCursor(10,130);
      tft.print("Поддерживать ");
      tft.unloadFont();
      tft.setTextSize(2);
      tft.print(tempuser,1);
      tft.setCursor(214,130);
      tft.print("÷");
      tft.print("+-");
      tft.print(tempplus,1);
      tft.print("÷");
      tft.loadFont(FONT_22); 
    } else if (tempcontmodec==1) {
      tft.setCursor(10,90);
      tft.print("Режим по таймеру");
      tft.setCursor(10,130);
      tft.print("Охлад раз в ");
      tft.unloadFont();
      if(temptimerch<10)tft.print("0");
      tft.print(temptimerch);
      tft.print(":");
      if(temptimercm<10)tft.print("0");
      tft.print(temptimercm);
      tft.loadFont(FONT_22); 
      tft.setCursor(200,130);
      tft.print("на ");
      tft.unloadFont();
      if(temptimerworkch<10)tft.print("0");
      tft.print(temptimerworkch);
      tft.print(":");
      if(temptimerworkcm<10)tft.print("0");
      tft.print(temptimerworkcm);
      tft.loadFont(FONT_22); 
      tft.setCursor(267,130);
      tft.setCursor(10,170);
      tft.print("Запустить таймер в ");
      tft.unloadFont();
      if(temptimerstartch<10)tft.print("0");
      tft.print(temptimerstartch);
      tft.print(":");
      if(temptimerstartcm<10)tft.print("0");
      tft.print(temptimerstartcm);
    } else if (tempcontmodec==2) {
      tft.setCursor(10,90);
      tft.print("Режим суточный");
      tft.setCursor(10,130);
      tft.print("Охлад в ");
      tft.unloadFont();
      if(temprtcch<10)tft.print("0");
      tft.print(temprtcch);
      tft.print(":");
      if(temprtccm<10)tft.print("0");
      tft.print(temprtccm);
      tft.setCursor(162,130);
      tft.loadFont(FONT_22);
      tft.print("на ");   
      tft.unloadFont();
      if(temprtcworkch<10)tft.print("0");
      tft.print(temprtcworkch);
      tft.print(":");
      if(temprtcworkcm<10)tft.print("0");
      tft.print(temprtcworkcm);
    } else if (tempcontmodec==3) {
      tft.setCursor(10,90);
      tft.print("Режим всегда включен");
    }
  }

  if(seltempc==1)  
  seltempc_1();
  else if(seltempc==2)  
  seltempc_2();
  else if(seltempc==3)  
  seltempc_3();
  else if(seltempc==4)  
  seltempc_4();
}



void seltempc_1()
{
  tft.loadFont(FONT_22); 
  tft.fillRect(0,40,320,40,TFT_RED);
  tft.setCursor(10,50);
  if (tempcontrolc==0){
    tft.print("Контроль отключен");
  }else if (tempcontrolc==1){
    tft.print("Контроль охлаждения вкл");
  }
  tft.unloadFont();
}
void seltempc_2()
{
  tft.loadFont(FONT_22); 
  tft.fillRect(0,80,320,40,TFT_RED);
  tft.setCursor(10,90);
  if (tempcontrolc!=0){
    if (tempcontmodec==0) {
      tft.print("Режим АВТО");
    } else if (tempcontmodec==1) {
      tft.print("Режим по таймеру");
    } else if (tempcontmodec==2) {
      tft.print("Режим суточный");
    } else if (tempcontmodec==3) {
      tft.print("Режим всегда включен");
    }
  tft.unloadFont();
  }
}
void seltempc_3()
{
  tft.loadFont(FONT_22); 
  tft.fillRect(0,120,320,40,TFT_RED);
  tft.setTextSize(2);
  tft.setCursor(10,130);
  if (tempcontrolc==1){
    if (tempcontmodec==0) {
      tft.print("Поддерживать ");
      tft.unloadFont();
      tft.setTextSize(2);
      tft.print(tempuser,1);
      tft.setCursor(214,130);
      tft.print("÷");
      tft.print("+-");
      tft.print(tempplus,1);
      tft.print("÷");
      if(seledit==0)
      edittempuser();
      else edittempplus();

    } else if (tempcontmodec==1) {
      tft.print("Охлад раз в ");
      tft.unloadFont();
      if(temptimerch<10)tft.print("0");
      tft.print(temptimerch);
      tft.print(":");
      if(temptimercm<10)tft.print("0");
      tft.print(temptimercm);
      tft.loadFont(FONT_22); 
      tft.setCursor(200,130);
      tft.print("на ");
      tft.unloadFont();
      if(temptimerworkch<10)tft.print("0");
      tft.print(temptimerworkch);
      tft.print(":");
      if(temptimerworkcm<10)tft.print("0");
      tft.print(temptimerworkcm); 
      tft.unloadFont();
      if(seledit==0)
      edittemptimerc();
      else edittemptimerworkc();

    } else if (tempcontmodec==2) {
      tft.print("Охлад в ");
      tft.unloadFont();
      if(temprtcch<10)tft.print("0");
      tft.print(temprtcch);
      tft.print(":");
      if(temprtccm<10)tft.print("0");
      tft.print(temprtccm);
      tft.setCursor(162,130);
      tft.loadFont(FONT_22);
      tft.print("на ");   
      tft.unloadFont();
      if(temprtcworkch<10)tft.print("0");
      tft.print(temprtcworkch);
      tft.print(":");
      if(temprtcworkcm<10)tft.print("0");
      tft.print(temprtcworkcm);
      if(seledit==0)
      edittemprtcc();
      else edittemprtcworkc();
    }
  }
}
void seltempc_4()
{
  tft.loadFont(FONT_22); 
  tft.fillRect(0,160,320,40,TFT_RED);
  tft.setCursor(10,170);
  tft.print("Запустить таймер в ");
  tft.unloadFont();
  if(temptimerstartch<10)tft.print("0");
  tft.print(temptimerstartch);
  tft.print(":");
  if(temptimerstartcm<10)tft.print("0");
  tft.print(temptimerstartcm);
  edittemptimerstartc();
}

/*----------------------------------отрисовка меню температуры в зависимости от данных-----------------------*/

// отрисовка редактирования температуры авто
void edittempuser()
{
  tft.fillRect(167,128,48,16,TFT_BLUE);
  tft.setTextColor(TFT_WHITE);
  tft.setTextSize(2);
  tft.setCursor(168,129);
  tft.print(tempuser,1);
}

// отрисовка редактирования +- температуры авто
void edittempplus()
{
  tft.fillRect(251,128,36,16,TFT_BLUE);
  tft.setTextColor(TFT_WHITE);
  tft.setTextSize(2);
  tft.setCursor(252,129);
  tft.print(tempplus,1);
}



// отрисовка редактирования таймера охлаждения
void edittemptimerc()
{ 
  tft.fillRect(137,128,60,16,TFT_BLUE);//
  tft.setTextColor(TFT_WHITE);
  tft.setTextSize(2);
  tft.setCursor(138,129);//
  if(temptimerch<10)tft.print("0");
  tft.print(temptimerch);
  tft.print(":");
  if(temptimercm<10)tft.print("0");
  tft.print(temptimercm);
}

// отрисовка редактирования таймера работы охлаждения
void edittemptimerworkc()
{
  tft.fillRect(226,128,60,16,TFT_BLUE);//
  tft.setTextColor(TFT_WHITE);
  tft.setTextSize(2);
  tft.setCursor(227,129);//
  if(temptimerworkch<10)tft.print("0");
  tft.print(temptimerworkch);
  tft.print(":");
  if(temptimerworkcm<10)tft.print("0");
  tft.print(temptimerworkcm);
}

void edittemptimerstartc()
{
  tft.fillRect(215,168,60,16,TFT_BLUE);
  tft.setTextColor(TFT_WHITE);
  tft.setTextSize(2);
  tft.setCursor(216,169);
  if(temptimerstartch<10)tft.print("0");
  tft.print(temptimerstartch);
  tft.print(":");
  if(temptimerstartcm<10)tft.print("0");
  tft.print(temptimerstartcm);
}

// отрисовка редактирования RTC охлаждения
void edittemprtcc()
{ 
  tft.fillRect(96,128,60,16,TFT_BLUE);//
  tft.setTextColor(TFT_WHITE);
  tft.setTextSize(2);
  tft.setCursor(97,129);//
  if(temprtcch<10)tft.print("0");
  tft.print(temprtcch);
  tft.print(":");
  if(temprtccm<10)tft.print("0");
  tft.print(temprtccm);  
}

// отрисовка редактирования RTC работы охлаждения
void edittemprtcworkc()
{
    tft.fillRect(189,128,60,16,TFT_BLUE);//
    tft.setTextColor(TFT_WHITE);
    tft.setTextSize(2);
    tft.setCursor(190,129);//
    if(temprtcworkch<10)tft.print("0");
    tft.print(temprtcworkch);
    tft.print(":");
    if(temprtcworkcm<10)tft.print("0");
    tft.print(temprtcworkcm);
}


















/*----------------------управление с клавиатуры и энкодера----------------------*/

void seltempuph(){
  if(mode == 11) {
    if (tempcontrolh==0) seltemph=1;
    else if ((tempcontrolh!=0)&&(tempcontmodeh==3)){
      if(seltemph==2) seltemph = 1;
      else seltemph++;
    } else if((tempcontrolh!=0)&&(tempcontmodeh==1)){
      if(seltemph==4) seltemph = 1;
      else seltemph++; 
    } else if(seltemph==3) seltemph = 1;
    else seltemph++;
    settemperatureh(seltemph);
    time1=0;
    tempmenu1=0;
  }
}

void seltempupc(){
  if(mode == 12) {
    if (tempcontrolc==0) seltempc=1;
    else if ((tempcontrolc!=0)&&(tempcontmodec==3)){
      if(seltempc==2) seltempc = 1;
      else seltempc++;
    } else if((tempcontrolc!=0)&&(tempcontmodec==1)){
      if(seltempc==4) seltempc = 1;
      else seltempc++; 
    } else if(seltempc==3) seltempc = 1;
    else seltempc++;
    settemperaturec(seltempc);
    time1=0;
    tempmenu1=0;
  }
}


void seltempdownh()
{
  if(mode == 11) {
    if (tempcontrolh==0) seltemph=1;
    else if ((tempcontrolh!=0)&&(tempcontmodeh==3)){
      if(seltemph==1) seltemph = 2;
      else seltemph--;
    } else if((tempcontrolh!=0)&&(tempcontmodeh==1)){
      if(seltemph==1) seltemph = 4;
      else seltemph--;
    } else if(seltemph==1) seltemph = 3;
    else seltemph--;
    settemperatureh(seltemph);
    time1=0;
    tempmenu1=0;
  }
}

void seltempdownc()
{
  if(mode == 12) {
    if (tempcontrolc==0) seltempc=1;
    else if ((tempcontrolc!=0)&&(tempcontmodec==3)){
      if(seltempc==1) seltempc = 2;
      else seltempc--;
    } else if((tempcontrolc!=0)&&(tempcontmodec==1)){
      if(seltempc==1) seltempc = 4;
      else seltempc--;
    } else if(seltempc==1) seltempc = 3;
    else seltempc--;
    settemperaturec(seltempc);
    time1=0;
    tempmenu1=0;
  }
}


void templefth()
{
  if(mode==11) {
    if (seltemph==1) {
      if (tempcontrolh==0){
        tempcontrolh=1;
      }else tempcontrolh--;
      resettemph();
    }   
    if (seltemph==2) {
      if (tempcontmodeh==0){
        tempcontmodeh=3;
      }else tempcontmodeh--;
      resettemph();
    } 
      if (seledit==0){
        seledit=1;
      }else seledit--;
    settemperatureh(seltemph);
    time1=0;
    tempmenu1=0;
  }
}

void temprighth()
{
  if(mode==11) {
    if (seltemph==1) {
      if (tempcontrolh==1) tempcontrolh=0;
      else tempcontrolh++;   
      resettemph(); 
    }
    if (seltemph==2) {
      if (tempcontmodeh==3) tempcontmodeh=0;
      else tempcontmodeh++; 
      resettemph();   
    }
      if (seledit==1) seledit=0;
      else seledit++;
    settemperatureh(seltemph);
    time1=0;
    tempmenu1=0;
  }
}

void templeftc()
{
  if(mode==12) {
    if (seltempc==1) {
      if (tempcontrolc==0){
        tempcontrolc=1;
      }else tempcontrolc--;
      resettempc();
    }   
    if (seltempc==2) {
      if (tempcontmodec==0){
        tempcontmodec=3;
      }else tempcontmodec--;
      resettempc();
    } 
      if (seledit==0){
        seledit=1;
      }else seledit--;
    settemperaturec(seltempc);
    time1=0;
    tempmenu1=0;
  }
}

void temprightc()
{
  if(mode==12) {
    if (seltempc==1) {
      if (tempcontrolc==1) tempcontrolc=0;
      else tempcontrolc++;   
      resettempc(); 
    }
    if (seltempc==2) {
      if (tempcontmodec==3) tempcontmodec=0;
      else tempcontmodec++; 
      resettempc();   
    }
      if (seledit==1) seledit=0;
      else seledit++;
    settemperaturec(seltempc);
    time1=0;
    tempmenu1=0;
  }
}



void tempencoderuph()
{
  if (mode == 11){
    if(tempcontrolh==1){
      if (seltemph==3){
        if(tempcontmodeh==0){
          if((seledit==0) && (tempuser<49.9)){
            tempuser+=0.1;
            edittempuser();
          } else if ((seledit==1) && (tempplus<9.9)){
            tempplus+=0.1;
            edittempplus();
          }
        }
        if(tempcontmodeh==1){
          if(seledit==0){
            temptimerhm+=5;
            if (temptimerhm > 59){
              if (temptimerhh>98) temptimerhh=0;
              else temptimerhh++;
              temptimerhm -= 60;
            }
            if((temptimerhh==0)&&(temptimerhm==0)) temptimerhm+=5;
            edittemptimerh();
          } else if (seledit==1){
            temptimerworkhm+=5;
            if (temptimerworkhm > 59){
              if (temptimerworkhh>98) temptimerworkhh=0;
              else temptimerworkhh++;
              temptimerworkhm -= 60;
            }
            if((temptimerworkhh==0)&&(temptimerworkhm==0)) temptimerworkhm+=5;
            edittemptimerworkh();
          }
        }
        if(tempcontmodeh==2){
          if(seledit==0){
            temprtchm+=5;
            if (temprtchm > 59){
              if (temprtchh>22) temprtchh=0;
              else temprtchh++;
              temprtchm -= 60;
            }
            edittemprtch();
          } else if (seledit==1){
            temprtcworkhm+=5;
            if (temprtcworkhm > 59){
              if (temprtcworkhh>22) temprtcworkhh=0;
              else temprtcworkhh++;
              temprtcworkhm -= 60;
            }
            if((temprtcworkhh==0)&&(temprtcworkhm==0)) temprtcworkhm+=5;
            edittemprtcworkh();
          }
        }
      }
      if (seltemph==4){
        if(tempcontmodeh==1){
          temptimerstarthm+=5;
          if (temptimerstarthm > 59){
            if (temptimerstarthh>22) temptimerstarthh=0;
            else temptimerstarthh++;
            temptimerstarthm -= 60;
          }
          edittemptimerstarth();
        }
      }       
    }
  }
}

void tempencoderupc()
{
  if (mode == 12){
    if(tempcontrolc==1){
      if (seltempc==3){
        if(tempcontmodec==0){
          if((seledit==0) && (tempuser<49.9)){
            tempuser+=0.1;
            edittempuser();
          } else if ((seledit==1) && (tempplus<9.9)){
            tempplus+=0.1;
            edittempplus();
          }
        }
        if(tempcontmodec==1){
          if(seledit==0){
            temptimercm+=5;
            if (temptimercm > 59){
              if (temptimerch>98) temptimerch=0;
              else temptimerch++;
              temptimercm -= 60;
            }
            if((temptimerch==0)&&(temptimercm==0)) temptimercm+=5;
            edittemptimerc();
          } else if (seledit==1){
            temptimerworkcm+=5;
            if (temptimerworkcm > 59){
              if (temptimerworkch>98) temptimerworkch=0;
              else temptimerworkch++;
              temptimerworkcm -= 60;
            }
            if((temptimerworkch==0)&&(temptimerworkcm==0)) temptimerworkcm+=5;
            edittemptimerworkc();
          }
        }
        if(tempcontmodec==2){
          if(seledit==0){
            temprtccm+=5;
            if (temprtccm > 59){
              if (temprtcch>22) temprtcch=0;
              else temprtcch++;
              temprtccm -= 60;
            }
            edittemprtcc();
          } else if (seledit==1){
            temprtcworkcm+=5;
            if (temprtcworkcm > 59){
              if (temprtcworkch>22) temprtcworkch=0;
              else temprtcworkch++;
              temprtcworkcm -= 60;
            }
            if((temprtcworkch==0)&&(temprtcworkcm==0)) temprtcworkcm+=5;
            edittemprtcworkc();
          }
        }
      }
      if (seltempc==4){
        if(tempcontmodec==1){
          temptimerstartcm+=5;
          if (temptimerstartcm > 59){
            if (temptimerstartch>22) temptimerstartch=0;
            else temptimerstartch++;
            temptimerstartcm -= 60;
          }
          edittemptimerstartc();
        }
      }       
    }
  }
}

void tempencoderdownh()
{
  if (mode == 11){
    if(tempcontrolh==1){
      if (seltemph==3){
        if(tempcontmodeh==0){
          if((seledit==0) && (tempuser>0)){
            tempuser-=0.1;
            edittempuser();
          } else if ((seledit==1) && (tempplus>0.1)){
            tempplus-=0.1;
            edittempplus();
          }
        }
        if(tempcontmodeh==1){
          if(seledit==0){
            temptimerhm-=5;
            if((temptimerhh==0)&&(temptimerhm==0)) temptimerhm-=5;
            if (temptimerhm < 0){
              if (temptimerhh<1) temptimerhh=99;
              else temptimerhh--;
              temptimerhm += 60;
            }
            edittemptimerh();
          } else if (seledit==1){
            temptimerworkhm-=5;
            if((temptimerworkhh==0)&&(temptimerworkhm==0)) temptimerworkhm-=5;
            if (temptimerworkhm < 0){
              if (temptimerworkhh<1) temptimerworkhh=99;
              else temptimerworkhh--;
              temptimerworkhm += 60;
            }
            edittemptimerworkh();
          }
        }
        if(tempcontmodeh==2){
          if(seledit==0){
            temprtchm-=5;
            if (temprtchm < 0){
              if (temprtchh<1) temprtchh=23;
              else temprtchh--;
              temprtchm += 60;
            }
            edittemprtch();
          } else if (seledit==1){
            temprtcworkhm-=5;
            if((temprtcworkhh==0)&&(temprtcworkhm==0)) temprtcworkhm-=5;
            if (temprtcworkhm < 0){
              if (temprtcworkhh<1) temprtcworkhh=23;
              else temprtcworkhh--;
              temprtcworkhm += 60;
            }
            edittemprtcworkh();
          }
        }
      }
      if (seltemph==4){
        if(tempcontmodeh==1){
            temptimerstarthm-=5;
            if (temptimerstarthm < 0){
              if (temptimerstarthh<1) temptimerstarthh=23;
              else temptimerstarthh--;
              temptimerstarthm += 60;
            }
            edittemptimerstarth();
        }
      }       
    }
  }
}

void tempencoderdownc()
{
  if (mode == 12){
    if(tempcontrolc==1){
      if (seltempc==3){
        if(tempcontmodec==0){
          if((seledit==0) && (tempuser>0)){
            tempuser-=0.1;
            edittempuser();
          } else if ((seledit==1) && (tempplus>0.1)){
            tempplus-=0.1;
            edittempplus();
          }
        }
        if(tempcontmodec==1){
          if(seledit==0){
            temptimercm-=5;
            if((temptimerch==0)&&(temptimercm==0)) temptimercm-=5;
            if (temptimercm < 0){
              if (temptimerch<1) temptimerch=99;
              else temptimerch--;
              temptimercm += 60;
            }
            edittemptimerc();
          } else if (seledit==1){
            temptimerworkcm-=5;
            if((temptimerworkch==0)&&(temptimerworkcm==0)) temptimerworkcm-=5;
            if (temptimerworkcm < 0){
              if (temptimerworkch<1) temptimerworkch=99;
              else temptimerworkch--;
              temptimerworkcm += 60;
            }
            edittemptimerworkc();
          }
        }
        if(tempcontmodec==2){
          if(seledit==0){
            temprtccm-=5;
            if (temprtccm < 0){
              if (temprtcch<1) temprtcch=23;
              else temprtcch--;
              temprtccm += 60;
            }
            edittemprtcc();
          } else if (seledit==1){
            temprtcworkcm-=5;
            if((temprtcworkch==0)&&(temprtcworkcm==0)) temprtcworkcm-=5;
            if (temprtcworkcm < 0){
              if (temprtcworkch<1) temprtcworkch=23;
              else temprtcworkch--;
              temprtcworkcm += 60;
            }
            edittemprtcworkc();
          }
        }
      }
      if (seltempc==4){
        if(tempcontmodec==1){
          temptimerstartcm-=5;
          if (temptimerstartcm < 0){
            if (temptimerstartch<1) temptimerstartch=23;
            else temptimerstartch--;
            temptimerstartcm += 60;
          }
          edittemptimerstartc();
        }
      }       
    }
  }
}



void resettemph()
{
  prevtempcontrolh= tempcontrolh;
  tempcontrolh=0;
  delay(50);
  tempcontrolh = prevtempcontrolh;
}
void resettempc()
{
  prevtempcontrolc = tempcontrolc;
  tempcontrolc=0;
  delay(50);
  tempcontrolc = prevtempcontrolc;
}
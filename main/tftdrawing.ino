// стартовая страница (загрузка...)

void startpage()
{
  tft.setTextSize(1);
	tft.setTextColor(TFT_WHITE);	
	tft.loadFont(FONT_30); 
  tft.fillScreen(TFT_BLACK);
  tft.setCursor(10, 20);  
  tft.setTextColor(TFT_WHITE);
  tft.print("   Устройство    для");
  tft.setCursor(60, 50);  
  tft.print("поддержания");
  tft.setCursor(55, 80);  
  tft.print("микроклимата");
  tft.setCursor(110, 110);  
  tft.print("теплиц");  
  tft.unloadFont();
  tft.loadFont(FONT_20);
  tft.setCursor(110, 140);  
  tft.print("Загрузка"); 
  tft.setCursor(90, 210);
  tft.print("Версия");
  tft.unloadFont();
  tft.setTextSize(2);
  tft.print(" 0.5");
  for (int i=0;i<320;i++){
    tft.fillRect(i, 170, 1, 20, TFT_RED);
    delay(1);
  }
}



// здесь где надо написать быстрый старт для первого включения и для ознакомления
// пользователя с основнями функциями и т д 


/*----------------------------------отрисовка главного экрана-----------------------*/
void HomePage()
{ 
  if(rect==0){
    tft.fillRectVGradient(0, 0, 320, 240, TFT_RED, TFT_YELLOW);
    tft.fillRect(0, 0, 230, 100, TFT_BLUE);
    tft.fillRect(0, 110, 230, 40, TFT_GREEN);
    tft.setCursor(10, 120); 
    tft.loadFont(FONT_22);
    tft.setTextColor(TFT_BLACK); 
    tft.print("Температура");
    tft.unloadFont();
    tft.setTextSize(2);
    tft.print(": ");
    
    tft.fillRect(0, 160, 230, 80, TFT_CYAN);
    tft.setCursor(58, 165);
    tft.loadFont(FONT_22);
    tft.setTextColor(TFT_BLACK); 
    tft.print("Влажность");    
    tft.setCursor(15, 185);
    tft.print("Воздуха");
    tft.drawLine(115, 185, 115, 240, TFT_BLACK);
    tft.setCursor(135, 185);
    tft.print("Почвы");
    tft.unloadFont();
    
    tft.fillRect(240, 0, 80, 70, TFT_YELLOW);
    tft.setCursor(250, 5); 
    tft.loadFont(FONT_22);
    tft.setTextColor(TFT_BLACK); 
    tft.print("Свет");
    tft.unloadFont();

    tft.fillRect(240, 80, 80, 160, TFT_MAGENTA);
    tft.setCursor(250, 90); 
    tft.loadFont(FONT_22);
    tft.setTextColor(TFT_BLACK); 
    tft.print("Реле");

    tft.unloadFont();
    rect++;
  }
  displayrtc();
  displaytemp();
  displaymoisture();
  displaylight();
  displayrelay();
  displayhumidity();
}
/*----------------------------------отрисовка главного экрана-----------------------*/




/*----------------------------------отрисовка температуры на главном экране-----------------------*/
void displaytemp()
{   
  tft.setTextSize(2);
  tft.setTextColor(TFT_BLACK);
  if(temp1==0){
    tft.fillRect(143, 110, 87, 40, TFT_GREEN); 
    tft.setCursor(150, 120); 
    if(celsiusdefault<-270) 
    tft.print("----");
    else
    tft.print(celsiusdefault,1);
    tft.println("÷C");
    temp1++;
  }
  if (celsiusdefaultold!=celsiusdefault){
    celsiusdefaultold = celsiusdefault;
    tft.fillRect(143, 110, 87, 40, TFT_GREEN); 
    tft.setCursor(150, 120); 
    if(celsiusdefault<-270) 
    tft.print("----");
    else
    tft.print(celsiusdefault,1);
    tft.println("÷C");
  }
}
/*----------------------------------отрисовка температуры на главном экране-----------------------*/
void displaytempmenu()
{
  tft.setTextColor(TFT_BLACK);
  tft.setTextSize(3);
  if(tempmenu1==0){
  tft.setTextSize(3);
    tft.fillRect(130, 210, 100, 40, TFT_GREEN);
    tft.setCursor(130,210);
    if(celsiusdefault<-270) 
    tft.print("----");
    else
    tft.print(celsiusdefault,1);
    tft.println("÷C");
    tempmenu1=1;
  } 

  if (celsiusdefaultold!=celsiusdefault){
    celsiusdefaultold = celsiusdefault;
  tft.fillRect(130, 210, 100, 40, TFT_GREEN);
    tft.setCursor(130,210);
    if(celsiusdefault<-270) 
    tft.print("----");
    else
    tft.print(celsiusdefault,1);
    tft.println("÷C");
    tempmenu1=1;
 }
}

void displaylightmenu()
{
  tft.setTextColor(TFT_BLACK);
  tft.setTextSize(3);
  if(lightmenu1==0){
  tft.setTextSize(3);
    tft.fillRect(130, 210, 130, 40, TFT_GREEN);
    tft.setCursor(130,210);
    tft.print(light,0);
    tft.println("lux");
    lightmenu1=1;
  } 

  if (lightold!=light){
    lightold = light;
  tft.fillRect(130, 210, 130, 40, TFT_GREEN);
    tft.setCursor(130,210);
    tft.print(light,0);
    tft.println("lux");
    lightmenu1=1;
 }
}

void displayrelay1menu()
{
  tft.setTextColor(TFT_BLACK);
  tft.setTextSize(3);
  if(relay1menu1==0){
  tft.setTextSize(3);
    tft.fillRect(130, 210, 130, 40, TFT_GREEN);
    tft.setCursor(130,210);
    tft.print(relay1sensorvalue,0);
    relay1menu1=1;
  } 

  if (relay1sensorvalueold!=relay1sensorvalue){
    relay1sensorvalueold = relay1sensorvalue;
  tft.fillRect(130, 210, 130, 40, TFT_GREEN);
    tft.setCursor(130,210);
    tft.print(relay1sensorvalue,0);
    relay1menu1=1;
 }
}

void displayrelay2menu()
{
  tft.setTextColor(TFT_BLACK);
  tft.setTextSize(3);
  if(relay2menu1==0){
  tft.setTextSize(3);
    tft.fillRect(130, 210, 130, 40, TFT_GREEN);
    tft.setCursor(130,210);
    tft.print(relay2sensorvalue,0);
    relay2menu1=1;
  } 

  if (relay2sensorvalueold!=relay2sensorvalue){
    relay2sensorvalueold = relay2sensorvalue;
  tft.fillRect(130, 210, 130, 40, TFT_GREEN);
    tft.setCursor(130,210);
    tft.print(relay2sensorvalue,0);
    relay2menu1=1;
 }
}

void displayservo1menu()
{
  tft.setTextColor(TFT_BLACK);
  tft.setTextSize(3);
  if(servo1menu1==0){
  tft.setTextSize(3);
    tft.fillRect(130, 210, 130, 40, TFT_GREEN);
    tft.setCursor(130,210);
    tft.print(servo1sensorvalue,0);
    servo1menu1=1;
  } 

  if (servo1sensorvalueold!=servo1sensorvalue){
    servo1sensorvalueold = servo1sensorvalue;
  tft.fillRect(130, 210, 130, 40, TFT_GREEN);
    tft.setCursor(130,210);
    tft.print(servo1sensorvalue,0);
    servo1menu1=1;
 }
}

void displayservo2menu()
{
  tft.setTextColor(TFT_BLACK);
  tft.setTextSize(3);
  if(servo2menu1==0){
  tft.setTextSize(3);
    tft.fillRect(130, 210, 130, 40, TFT_GREEN);
    tft.setCursor(130,210);
    tft.print(servo2sensorvalue,0);
    servo2menu1=1;
  } 

  if (servo2sensorvalueold!=servo2sensorvalue){
    servo2sensorvalueold = servo2sensorvalue;
  tft.fillRect(130, 210, 130, 40, TFT_GREEN);
    tft.setCursor(130,210);
    tft.print(servo2sensorvalue,0);
    servo2menu1=1;
 }
}

void displayactuatormenu()
{
  tft.setTextColor(TFT_BLACK);
  tft.setTextSize(3);
  if(actuatormenu1==0){
  tft.setTextSize(3);
    tft.fillRect(130, 210, 130, 40, TFT_GREEN);
    tft.setCursor(130,210);
    tft.print(actuatorsensorvalue,0);
    actuatormenu1=1;
  } 

  if (actuatorsensorvalueold!=actuatorsensorvalue){
    actuatorsensorvalueold = actuatorsensorvalue;
  tft.fillRect(130, 210, 130, 40, TFT_GREEN);
    tft.setCursor(130,210);
    tft.print(actuatorsensorvalue,0);
    actuatormenu1=1;
 }
}

void displaymoistmenu()
{
  tft.setTextColor(TFT_BLACK);
  tft.setTextSize(3);
  if(moistmenu1==0){
  tft.setTextSize(3);
    tft.fillRect(130, 210, 100, 40, TFT_GREEN);
    tft.setCursor(130,210);
    tft.print(moisture,0);
    tft.println("%");
    moistmenu1=1;
  } 

  if (moistureold!=moisture){
    moistureold = moisture;
  tft.fillRect(130, 210, 100, 40, TFT_GREEN);
    tft.setCursor(130,210);
    tft.print(moisture,0);
    tft.println("%");
    moistmenu1=1;
 }
}
/*----------------------------------отрисовка состояния реле на главном экране-----------------------*/
void displayrelay(){
  if(relay1==0){
      for (int i=0;i<4;i++){
    if(pcf8574.digitalRead(relayPins[i+4])!=r[i]){
      r[i]= pcf8574.digitalRead(relayPins[i+4]);      
    }
    if(r[i]==0) tft.fillRect(250, 120+30*i, 60, 25, TFT_RED);
    else tft.fillRect(250, 120+30*i, 60, 25, TFT_GREEN);
  }
    relay1++;
  }
  for (int i=0;i<4;i++){
    if(pcf8574.digitalRead(relayPins[i+4])!=r[i]){
      r[i]= pcf8574.digitalRead(relayPins[i+4]);      
    }
    if(r[i]==0) tft.fillRect(250, 120+30*i, 60, 25, TFT_GREEN);
    else tft.fillRect(250, 120+30*i, 60, 25, TFT_RED);
  }
}
/*----------------------------------отрисовка состояния реле на главном экране-----------------------*/

/*----------------------------------отрисовка влажности на главном экране-----------------------*/
void displaymoisture()
{   
  tft.setTextSize(2);
  tft.setTextColor(TFT_BLACK);
  if(moist1==0){
    tft.fillRect(135, 207, 90, 30, TFT_CYAN); 
    tft.setCursor(140, 210); 
    tft.print(moisture,0);
    tft.println("%");
    moist1++;
  }
  if (moistureold!=moisture){
    moistureold = moisture;
    tft.fillRect(135, 207, 90, 30, TFT_CYAN); 
    tft.setCursor(140, 210); 
    tft.print(moisture,0);
    tft.println("%");
  }
}
/*----------------------------------отрисовка влажности на главном экране-----------------------*/

void displayhumidity()
{   
  tft.setTextSize(2);
  tft.setTextColor(TFT_BLACK);
  if(humidity1==0){
    tft.fillRect(19, 207, 90, 30, TFT_CYAN); 
    tft.setCursor(20, 210); 
    tft.print(humiditydefault,0);
    tft.println("%");
    humidity1++;
  }
  if (humiditydefaultold!=humiditydefault){
    humiditydefaultold = humiditydefault;
    tft.fillRect(19, 207, 90, 30, TFT_CYAN); 
    tft.setCursor(20, 210); 
    tft.print(humiditydefault,0);
    tft.println("%");
  }
}

/*----------------------------------отрисовка света на главном экране-----------------------*/
void displaylight()
{   
  tft.setTextSize(2);
  tft.setTextColor(TFT_BLACK);
  if(light1==0){
    tft.fillRect(240, 25, 80, 40, TFT_YELLOW); 
    tft.setCursor(245, 30); 
    tft.print(light,0);
    tft.println("lx");
    light1++;
  }
  if (lightold!=light){
    lightold = light;
    tft.fillRect(240, 25, 80, 40, TFT_YELLOW); 
    tft.setCursor(245, 30); 
    tft.print(light,0);
    tft.println("lx");
  }
}
/*----------------------------------отрисовка света на главном экране-----------------------*/

/*----------------------------------отрисовка даты и времени на главном экране-----------------------*/
void displayrtc()
{  
  DateTime now = rtc.now();
  tft.setTextColor(TFT_WHITE);
  if(rtc1==0){
      tft.setTextSize(3);
    tft.fillRect(150, 9, 39, 28, TFT_BLUE);
    tft.setCursor(154,10);
    if(now.second()<10){
     tft.print("0");
     tft.print(now.second(), DEC);
  } else tft.print(now.second(), DEC);
  tft.setTextSize(4);
    tft.fillRect(9, 9, 143, 33, TFT_BLUE);
    tft.setCursor(10,10);
    if(now.hour()<10){
      tft.print("0");
      tft.print(now.hour(), DEC);
    }else tft.print(now.hour(), DEC);
    tft.print(":");
    if(now.minute()<10){
      tft.print("0");
      tft.print(now.minute(), DEC);
    } else tft.print(now.minute(), DEC);
    tft.print(":");
        tft.setTextSize(2);
    tft.fillRect(9, 45, 200, 50, TFT_BLUE);
    tft.setCursor(154,10);
    tft.setCursor(10,50);
    tft.print(now.day(), DEC);
    tft.loadFont(FONT_20);
    tft.print(monthh[now.month()-1]);
    tft.unloadFont();
    tft.println(now.year(), DEC);
    tft.setCursor(10,75);
    tft.loadFont(FONT_20);
    tft.print(daysOfTheWeek[now.dayOfTheWeek()]);
    tft.unloadFont();
  rtc1++;
  } 
  if (os !=now.second()){
    os = now.second();
    tft.setTextSize(3);
    tft.fillRect(150, 9, 39, 28, TFT_BLUE);
    tft.setCursor(154,10);
    if(now.second()<10){
     tft.print("0");
     tft.print(now.second(), DEC);
  } else tft.print(now.second(), DEC);
 }else 
 if (om !=now.minute()){
    om = now.minute();
    tft.setTextSize(4);
    tft.fillRect(9, 9, 143, 33, TFT_BLUE);
    tft.setCursor(10,10);
    if(now.hour()<10){
      tft.print("0");
      tft.print(now.hour(), DEC);
    }else tft.print(now.hour(), DEC);
    tft.print(":");
    if(now.minute()<10){
      tft.print("0");
      tft.print(now.minute(), DEC);
    } else tft.print(now.minute(), DEC);
    tft.print(":");
 } else
 if (od !=now.day()){
    od = now.day();
    tft.setTextSize(2);
    tft.fillRect(9, 45, 200, 50, TFT_BLUE);
    tft.setCursor(154,10);
    tft.setCursor(10,50);
    tft.print(now.day(), DEC);
    tft.loadFont(FONT_20);
    tft.print(monthh[now.month()-1]);
    tft.unloadFont();
    tft.println(now.year(), DEC);
    tft.setCursor(10,75);
    tft.loadFont(FONT_20);
    tft.print(daysOfTheWeek[now.dayOfTheWeek()]);
    tft.unloadFont();
 }
}
/*----------------------------------отрисовка даты и времени на главном экране-----------------------*/

/*----------------------------------отрисовка времени в меню -----------------------*/
void displaytime()
{
  DateTime now = rtc.now();
  tft.setTextColor(TFT_BLACK);
  tft.setTextSize(3);
  if(time1==0){
  tft.setTextSize(3);
    tft.fillRect(220, 0, 100, 40, TFT_GREEN);
    tft.setCursor(225,9);
    if(now.hour()<10){
      tft.print("0");
      tft.print(now.hour(), DEC);
    }else tft.print(now.hour(), DEC);
    tft.print(":");
    if(now.minute()<10){
      tft.print("0");
      tft.print(now.minute(), DEC);
    } else tft.print(now.minute(), DEC);
  time1++;
  } 

 if (om !=now.minute()){
  om = now.minute();
  tft.fillRect(220, 0, 100, 40, TFT_GREEN);
  tft.setCursor(225,9);
  if(now.hour()<10){
    tft.print("0");
    tft.print(now.hour(), DEC);
  }else tft.print(now.hour(), DEC);
  tft.print(":");
  if(now.minute()<10){
    tft.print("0");
    tft.print(now.minute(), DEC);
  } else tft.print(now.minute(), DEC);
 }
}
/*----------------------------------отрисовка времени в меню-----------------------*/

/*----------------------------------меню настройки климата-----------------------*/
void setclimat(int selclimat)
{
  if (selclimat<=5){
  tft.loadFont(FONT_22); 
  tft.setTextColor(TFT_BLACK);
  tft.fillRect(0,0,320,40,TFT_GREEN);
  tft.setCursor(10,10);
  tft.print("КЛИМАТ");
  tft.setTextSize(2);
  tft.fillRect(0,40,320,200,TFT_MAGENTA);
  tft.setTextColor(TFT_WHITE);
  tft.setCursor(10,50);
  tft.print("Температура нагрев");
  tft.setCursor(10,90);
  tft.print("Температура охлаждение");
  tft.setCursor(10,130);
  tft.print("Освещение");
  tft.setCursor(10,170);
  tft.print("Полив");
  tft.setCursor(10,210);
  tft.print("Доп реле ");
  tft.unloadFont(); 
  tft.print("1");

  if(selclimat==1)  
  Selclimat_1();
  else if(selclimat==2)  
  Selclimat_2();
  else if(selclimat==3)  
  Selclimat_3();
  else if(selclimat==4)  
  Selclimat_4();
  else if(selclimat==5)  
  Selclimat_5();
  }
  else if ((selclimat>5)&&(selclimat<=10)){
  tft.loadFont(FONT_22); 
  tft.setTextColor(TFT_BLACK);
  tft.fillRect(0,0,320,40,TFT_GREEN);
  tft.setCursor(10,10);
  tft.print("КЛИМАТ");
  tft.setTextSize(2);
  tft.fillRect(0,40,320,200,TFT_MAGENTA);
  tft.setTextColor(TFT_WHITE);
  tft.setCursor(10,50);
  tft.print("Доп реле ");
  tft.unloadFont(); 
  tft.print("2");
  tft.loadFont(FONT_22);
  tft.setCursor(10,90);
  tft.print("Серво ");
  tft.unloadFont(); 
  tft.print("1");
  tft.loadFont(FONT_22);
  tft.setCursor(10,130);
  tft.print("Серво ");
  tft.unloadFont(); 
  tft.print("2");
  tft.loadFont(FONT_22);
  tft.setCursor(10,170);
  tft.print("Линейный привод");
  tft.unloadFont(); 

  if(selclimat==6)  
  Selclimat_6();
  else if(selclimat==7)  
  Selclimat_7();
  else if(selclimat==8)  
  Selclimat_8();
  else if(selclimat==9)  
  Selclimat_9();
  }
}

void Selclimat_1()
{
  tft.loadFont(FONT_22); 
  tft.fillRect(0,40,320,40,TFT_RED);
  tft.setCursor(10,50);
  tft.print("Температура нагрев");
  tft.unloadFont();
}
void Selclimat_2()
{
  tft.loadFont(FONT_22); 
  tft.fillRect(0,80,320,40,TFT_RED);
  tft.setCursor(10,90);
  tft.print("Температура охлаждение");
  tft.unloadFont();
}
void Selclimat_3()
{
  tft.loadFont(FONT_22); 
  tft.fillRect(0,120,320,40,TFT_RED);
  tft.setCursor(10,130);
  tft.print("Освещение");
  tft.unloadFont();
}
void Selclimat_4()
{
  tft.loadFont(FONT_22); 
  tft.fillRect(0,160,320,40,TFT_RED);
  tft.setCursor(10,170);
  tft.print("Полив");
  tft.unloadFont();
}
void Selclimat_5()
{
  tft.loadFont(FONT_22); 
  tft.fillRect(0,200,320,40,TFT_RED);
  tft.setCursor(10,210);
  tft.print("Доп реле ");
  tft.unloadFont(); 
  tft.print("1");
}
void Selclimat_6()
{
  tft.loadFont(FONT_22); 
  tft.fillRect(0,40,320,40,TFT_RED);
  tft.setCursor(10,50);
  tft.print("Доп реле ");
  tft.unloadFont(); 
  tft.print("2");
}
void Selclimat_7()
{
  tft.loadFont(FONT_22); 
  tft.fillRect(0,80,320,40,TFT_RED);
  tft.setCursor(10,90);
  tft.print("Серво ");
  tft.unloadFont(); 
  tft.print("1");
}
void Selclimat_8()
{
  tft.loadFont(FONT_22); 
  tft.fillRect(0,120,320,40,TFT_RED);
  tft.setCursor(10,130);
  tft.print("Серво ");
  tft.unloadFont(); 
  tft.print("2");
}
void Selclimat_9()
{
  tft.loadFont(FONT_22); 
  tft.fillRect(0,160,320,40,TFT_RED);
  tft.setCursor(10,170);
  tft.print("Линейный привод");
  tft.unloadFont(); 
}
/*----------------------------------меню настройки климата-----------------------*/

/*----------------------------------меню настройки устройства-----------------------*/
void settings(int selection)
{
  if (selection<=5){
  tft.loadFont(FONT_22); 
  tft.setTextColor(TFT_BLACK);
  tft.fillRect(0,0,320,40,TFT_GREEN);
  tft.setCursor(10,10);
  tft.print("НАСТРОЙКИ");
  tft.fillRect(0,40,320,200,TFT_MAGENTA);
  tft.setTextColor(TFT_WHITE);
  tft.setCursor(10,50);
  tft.print("Датчики");
  tft.setCursor(10,90);
  tft.print("Пользовательские режимы");
  tft.setCursor(10,130);
  tft.print("Дисплей");
  tft.setCursor(10,170);
  tft.print("Звук");
  tft.setCursor(10,210);
  tft.print("Дата и время");
  tft.unloadFont(); 

  if(selection==1)  
  Selection_1();
  else if(selection==2)  
  Selection_2();
  else if(selection==3)  
  Selection_3();
  else if(selection==4)  
  Selection_4();
  else if(selection==5)  
  Selection_5();
  }
  else if ((selection>5)&&(selection<=10)){
  tft.loadFont(FONT_22); 
  tft.setTextColor(TFT_BLACK);
  tft.fillRect(0,0,320,40,TFT_GREEN);
  tft.setCursor(10,10);
  tft.print("НАСТРОЙКИ");
  tft.fillRect(0,40,320,200,TFT_MAGENTA);
  tft.setTextColor(TFT_WHITE);
  tft.setCursor(10,50);
  tft.print("Перезагрузка устройства");
  tft.setCursor(10,90);
  tft.print("Сброс настроек");


  if(selection==6)  
  Selection_6();
  else if(selection==7)  
  Selection_7();
  }
}

void Selection_1()
{
  tft.loadFont(FONT_22); 
  tft.fillRect(0,40,320,40,TFT_RED);
  tft.setCursor(10,50);
  tft.print("Датчики");
  tft.unloadFont();
}
void Selection_2()
{
  tft.loadFont(FONT_22); 
  tft.fillRect(0,80,320,40,TFT_RED);
  tft.setCursor(10,90);
  tft.print("Пользовательские режимы");
  tft.unloadFont();
}
void Selection_3()
{
  tft.loadFont(FONT_22); 
  tft.fillRect(0,120,320,40,TFT_RED);
  tft.setCursor(10,130);
  tft.print("Дисплей");
  tft.unloadFont();
}
void Selection_4()
{
  tft.loadFont(FONT_22); 
  tft.fillRect(0,160,320,40,TFT_RED);
  tft.setCursor(10,170);
  tft.print("Звук");
  tft.unloadFont();
}
void Selection_5()
{
  tft.loadFont(FONT_22); 
  tft.fillRect(0,200,320,40,TFT_RED);
  tft.setCursor(10,210);
  tft.print("Дата и время");
  tft.unloadFont();
}

void Selection_6()
{
  tft.loadFont(FONT_22); 
  tft.fillRect(0,40,320,40,TFT_RED);
  tft.setCursor(10,50);
  tft.print("Перезагрузка устройства");
  tft.unloadFont();
}
void Selection_7()
{
  tft.loadFont(FONT_22); 
  tft.fillRect(0,80,320,40,TFT_RED);
  tft.setCursor(10,90);
  tft.print("Сброс настроек");
  tft.unloadFont();
}
/*----------------------------------меню настройки устройства-----------------------*/

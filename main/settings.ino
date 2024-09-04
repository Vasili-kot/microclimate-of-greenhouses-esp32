void settingssensors(int selsensors)
{
  tft.loadFont(FONT_22); 
  tft.setTextColor(TFT_BLACK);
  tft.setTextSize(2);
  tft.fillRect(0,0,320,40,TFT_GREEN);
  tft.setCursor(10,10);
  tft.print("ДАТЧИКИ");
  tft.fillRect(0,40,320,200,TFT_MAGENTA);
  tft.setTextColor(TFT_WHITE);

  if ((selsensors>=1)&&(selsensors<=5)){
    tft.setCursor(10,50);
    tft.print("Опрос датчиков раз в  ");
    tft.unloadFont();
    tft.print(intervalsensor);
    tft.loadFont(FONT_22); 
    tft.setCursor(268,50);
    tft.print(" сек");
    tft.unloadFont();
    tft.setCursor(10,90);
    tft.print("BME280");
    tft.setCursor(10,130);
    tft.print("DHT11");
    tft.setCursor(10,170);
    tft.loadFont(FONT_22); 
    tft.print("Термистор");
    tft.setCursor(10,210);
    tft.print("Фоторезистор");
    tft.unloadFont();
    

    if(selsensors==1)  
    Selsensors_1();
    else if(selsensors==2)  
    Selsensors_2();
    else if(selsensors==3)  
    Selsensors_3();
    else if(selsensors==4)  
    Selsensors_4();
    else if(selsensors==5)  
    Selsensors_5();

  } else if ((selsensors>=6)&&(selsensors<=10)){
    tft.setCursor(10,50);
    tft.loadFont(FONT_22);
    tft.print("Доп аналоговый ");
    tft.unloadFont();
    tft.print("1");
    tft.setCursor(10,90);
    tft.loadFont(FONT_22);
    tft.print("Доп аналоговый ");
    tft.unloadFont();
    tft.print("2");

    if(selsensors==6)  
    Selsensors_6();
    else if(selsensors==7)  
    Selsensors_7();
  }
}

void Selsensors_1()
{
  tft.loadFont(FONT_22); 
  tft.setTextSize(2);
  tft.fillRect(0,40,320,40,TFT_RED);
  tft.setCursor(10,50);
  tft.print("Опрос датчиков раз в  ");
  tft.unloadFont();
  tft.print(intervalsensor);
  tft.loadFont(FONT_22); 
  tft.setCursor(268,50);
  tft.print(" сек");
  tft.unloadFont();
  editsensorinterval();
}
void Selsensors_2()
{ 
  tft.setTextSize(2);
  tft.fillRect(0,80,320,40,TFT_RED);
  tft.setCursor(10,90);
  tft.print("BME280");
}
void Selsensors_3()
{ 
  tft.fillRect(0,120,320,40,TFT_RED);
  tft.setCursor(10,130);
  tft.print("DHT11");
}
void Selsensors_4()
{
  tft.loadFont(FONT_22); 
  tft.fillRect(0,160,320,40,TFT_RED);
  tft.setCursor(10,170);
  tft.print("Термистор");
  tft.unloadFont();
}
void Selsensors_5()
{
  tft.loadFont(FONT_22); 
  tft.fillRect(0,200,320,40,TFT_RED);
  tft.setCursor(10,210);
  tft.print("Фоторезистор");
  tft.unloadFont();
}

void Selsensors_6()
{
  tft.loadFont(FONT_22); 
  tft.fillRect(0,40,320,40,TFT_RED);
  tft.setCursor(10,50);
  tft.print("Доп аналоговый ");
  tft.unloadFont();
  tft.print("1");
}
void Selsensors_7()
{
  tft.loadFont(FONT_22); 
  tft.fillRect(0,80,320,40,TFT_RED);
  tft.setCursor(10,90);
  tft.print("Доп аналоговый ");
  tft.unloadFont();
  tft.print("2");
}
void editsensorinterval()
{
  tft.fillRect(239,48,24,16,TFT_BLUE);
  tft.setTextColor(TFT_WHITE);
  tft.setTextSize(2);
  tft.setCursor(240,49);
  tft.print(intervalsensor);
}

void settingsbme(int selbme)
{ 
  tft.setTextColor(TFT_BLACK);
  tft.setTextSize(3);
  tft.fillRect(0,0,320,40,TFT_GREEN);
  tft.setCursor(10,10);
  tft.print("BME280");
  tft.fillRect(0,40,320,200,TFT_MAGENTA);
  tft.loadFont(FONT_22); 
  tft.fillRect(0,200,320,40,TFT_GREEN);
  //tft.setCursor(10,210);
  tft.setTextSize(2);
  tft.setTextColor(TFT_WHITE);

  if (bme280status==0){
    tft.setCursor(10,50);
    tft.print("Не использовать ");
    tft.unloadFont();
    tft.print("BME280");

  }else if (bme280status==1){
    tft.setCursor(10,50);
    tft.loadFont(FONT_22);
    tft.print("Использовать ");
    tft.unloadFont();
    tft.print("BME280");
    tft.setCursor(10,90);  
    tft.loadFont(FONT_18);
    if(temperaturesensor==2){
      tft.print("Использ для темпер по умолч");
    } else tft.print("Не использ для темпер по умолч");
    tft.setCursor(10,130); 
    tft.loadFont(FONT_18);
    if(humiditysensor==2){
      tft.print("Использ для вл воздуха по умолч");
      } else tft.print("Не использ для вл воздуха по умолч");
    }             
    tft.unloadFont();

  if(selbme==1)  
  Selbme_1();
  else if(selbme==2)  
  Selbme_2();
  else if(selbme==3)  
  Selbme_3();
}

void Selbme_1()
{
  tft.loadFont(FONT_22); 
  tft.fillRect(0,40,320,40,TFT_RED);
  if (bme280status==0){
    tft.setCursor(10,50);
    tft.print("Не использовать ");
    tft.unloadFont();
    tft.print("BME280");
  }else if (bme280status==1){
    tft.setCursor(10,50);
    tft.loadFont(FONT_22);
    tft.print("Использовать ");
    tft.unloadFont();
    tft.print("BME280");
  }
}
void Selbme_2()
{
  tft.loadFont(FONT_22); 
  tft.fillRect(0,80,320,40,TFT_RED);
  if (bme280status==1){
    tft.setCursor(10,90);  
    tft.loadFont(FONT_18);
    if(temperaturesensor==2){
      tft.print("Использ для темпер по умолч");
    } else tft.print("Не использ для темпер по умолч");        
    tft.unloadFont();
  }
}

void Selbme_3()
{
  tft.loadFont(FONT_22); 
  tft.fillRect(0,120,320,40,TFT_RED);
  if (bme280status==1){
    tft.setCursor(10,130); 
    tft.loadFont(FONT_18);
    if(humiditysensor==2){
      tft.print("Использ для вл воздуха по умолч");
    } else tft.print("Не использ для вл воздуха по умолч");
  }             
  tft.unloadFont();
}



void settingsdht(int seldht)
{ 
  tft.setTextColor(TFT_BLACK);
  tft.setTextSize(3);
  tft.fillRect(0,0,320,40,TFT_GREEN);
  tft.setCursor(10,10);
  tft.print("DHT11");
  tft.fillRect(0,40,320,200,TFT_MAGENTA);
  tft.loadFont(FONT_22); 
  tft.fillRect(0,200,320,40,TFT_GREEN);
  //tft.setCursor(10,210);
  tft.setTextSize(2);
  tft.setTextColor(TFT_WHITE);

  if (dht11status==0){
    tft.setCursor(10,50);
    tft.print("Не использовать ");
    tft.unloadFont();
    tft.print("DHT11");

  }else if (dht11status==1){
    tft.setCursor(10,50);
    tft.loadFont(FONT_22);
    tft.print("Использовать ");
    tft.unloadFont();
    tft.print("DHT11");
    tft.setCursor(10,90);  
    tft.loadFont(FONT_18);
    if(temperaturesensor==1){
      tft.print("Использ для темпер по умолч");
    } else tft.print("Не использ для темпер по умолч");
    tft.setCursor(10,130); 
    tft.loadFont(FONT_18);
    if(humiditysensor==1){
      tft.print("Использ для вл воздуха по умолч");
      } else tft.print("Не использ для вл воздуха по умолч");
    }             
    tft.unloadFont();

  if(seldht==1)  
  Seldht_1();
  else if(seldht==2)  
  Seldht_2();
  else if(seldht==3)  
  Seldht_3();
}

void Seldht_1()
{
  tft.loadFont(FONT_22); 
  tft.fillRect(0,40,320,40,TFT_RED);
  if (dht11status==0){
    tft.setCursor(10,50);
    tft.print("Не использовать ");
    tft.unloadFont();
    tft.print("DHT11");
  }else if (dht11status==1){
    tft.setCursor(10,50);
    tft.loadFont(FONT_22);
    tft.print("Использовать ");
    tft.unloadFont();
    tft.print("DHT11");
  }
}
void Seldht_2()
{
  tft.loadFont(FONT_22); 
  tft.fillRect(0,80,320,40,TFT_RED);
  if (dht11status==1){
    tft.setCursor(10,90);  
    tft.loadFont(FONT_18);
    if(temperaturesensor==1){
      tft.print("Использ для темпер по умолч");
    } else tft.print("Не использ для темпер по умолч");        
    tft.unloadFont();
  }
}

void Seldht_3()
{
  tft.loadFont(FONT_22); 
  tft.fillRect(0,120,320,40,TFT_RED);
  if (dht11status==1){
    tft.setCursor(10,130); 
    tft.loadFont(FONT_18);
    if(humiditysensor==1){
      tft.print("Использ для вл воздуха по умолч");
    } else tft.print("Не использ для вл воздуха по умолч");
  }             
  tft.unloadFont();
}

void settingsntc(int selntc)
{ 
  tft.setTextColor(TFT_BLACK);
  tft.setTextSize(3);
  tft.fillRect(0,0,320,40,TFT_GREEN);
  tft.setCursor(10,10);
  tft.loadFont(FONT_22);
  tft.print("ТЕРМИСТОР");
  tft.fillRect(0,40,320,200,TFT_MAGENTA);
  tft.fillRect(0,200,320,40,TFT_GREEN);
  //tft.setCursor(10,210);
  tft.setTextSize(2);
  tft.setTextColor(TFT_WHITE);

  tft.setCursor(10,50); 
  tft.loadFont(FONT_18);
  if(temperaturesensor==0){
    tft.print("Использ для темпер по умолч");
  } else tft.print("Не использ для темпер по умолч");
  tft.setCursor(10,90); 
  tft.loadFont(FONT_18);
  if(humiditysensor==0){
    tft.print("Не измерять влажность воздуха");
  } else tft.print("Измерять влажность воздуха");             
  tft.unloadFont();
  tft.setCursor(10,130); 
  tft.loadFont(FONT_22);
  tft.print("Бета коэффициент ");
  tft.unloadFont();
  tft.print(BETA);     
  tft.setCursor(10,170); 
  tft.loadFont(FONT_22);
  tft.print("По умолчанию ");
  tft.unloadFont();
  tft.print("3950");             
  

  if(selntc==1)  
  Selntc_1();
  else if(selntc==2)  
  Selntc_2();
  else if(selntc==3)  
  Selntc_3();
}

void Selntc_1()
{
  tft.fillRect(0,40,320,40,TFT_RED);
  tft.loadFont(FONT_18);
  tft.setCursor(10,50);
  if(temperaturesensor==0){
    tft.print("Использ для темпер по умолч");
  } else tft.print("Не использ для темпер по умолч");        
  tft.unloadFont();
}
void Selntc_2()
{
  tft.fillRect(0,80,320,40,TFT_RED);
  tft.setCursor(10,90);  
  tft.loadFont(FONT_18);
  if(humiditysensor==0){
    tft.print("Не измерять влажность воздуха");
  } else tft.print("Измерять влажность воздуха");        
  tft.unloadFont();
}

void Selntc_3()
{
  tft.loadFont(FONT_22); 
  tft.fillRect(0,120,320,40,TFT_RED);
  tft.setCursor(10,130); 
  tft.print("Бета коэффициент ");
  tft.unloadFont();
  tft.print(BETA);
  editbeta();
}

void editbeta()
{
  tft.fillRect(209,128,48,16,TFT_BLUE);
  tft.setTextColor(TFT_WHITE);
  tft.setTextSize(2);
  tft.setCursor(210,129);
  tft.print(BETA);
}


void setldr(int selldr)
{
  tft.setTextColor(TFT_BLACK);
  tft.setTextSize(3);
  tft.fillRect(0,0,320,40,TFT_GREEN);
  tft.setCursor(10,10);
  tft.loadFont(FONT_22);
  tft.print("ФОТОРЕЗИСТОР");
  tft.fillRect(0,40,320,200,TFT_MAGENTA);
  tft.fillRect(0,200,320,40,TFT_GREEN);
  tft.setCursor(10,210);
  tft.print("Сейчас ");
  tft.setTextSize(2);
  tft.setTextColor(TFT_WHITE);

  tft.setCursor(10,50);  
  tft.loadFont(FONT_22);
  tft.print("Гамма коэффициент ");
  tft.unloadFont();
  tft.print(gammas);     
  tft.setCursor(10,90); 
  tft.loadFont(FONT_22);
  tft.print("Сопр при ");
  tft.unloadFont();
  tft.print("1 lux ");
  tft.print(r1);  
  tft.loadFont(FONT_22);
  tft.setCursor(230,90); 
  tft.print(" кОм");
  tft.unloadFont();   
  tft.setCursor(10,130); 
  tft.loadFont(FONT_22);
  tft.print("По умолчанию ");
  tft.unloadFont();
  tft.print("0.6");   
  tft.loadFont(FONT_22);
  tft.print(" и ");
  tft.unloadFont(); 
  tft.print("200");   
  tft.loadFont(FONT_22);
  tft.print(" кОм");
  tft.unloadFont();          
  

  if(selldr==1)  
  Selldr_1();
  else if(selldr==2)  
  Selldr_2();
}

void Selldr_1()
{
  tft.fillRect(0,40,320,40,TFT_RED);
  tft.loadFont(FONT_18);
  tft.setCursor(10,50);
  tft.loadFont(FONT_22);
  tft.print("Гамма коэффициент ");
  tft.unloadFont();
  tft.print(gammas);  
  editgamma();       
}
void Selldr_2()
{
  tft.fillRect(0,80,320,40,TFT_RED);
  tft.setCursor(10,90);  
  tft.loadFont(FONT_22);
  tft.print("Сопр при ");
  tft.unloadFont();
  tft.print("1 lux ");
  tft.print(r1);  
  tft.loadFont(FONT_22);
  tft.setCursor(230,90); 
  tft.print(" кОм");
  tft.unloadFont();   
  editr1();
}


void editgamma()
{
  tft.fillRect(226,48,48,16,TFT_BLUE);
  tft.setTextColor(TFT_WHITE);
  tft.setTextSize(2);
  tft.setCursor(227,49);
  tft.print(gammas);
}

void editr1()
{
  tft.fillRect(181,88,36,16,TFT_BLUE);
  tft.setTextColor(TFT_WHITE);
  tft.setTextSize(2);
  tft.setCursor(182,89);
  tft.print(r1);
}

void settingsusermodes(int selusermodes)
{
  tft.loadFont(FONT_22); 
  tft.setTextColor(TFT_BLACK);
  tft.setTextSize(2);
  tft.fillRect(0,0,320,40,TFT_GREEN);
  tft.setCursor(10,10);
  tft.print("ДОП РЕЖИМЫ");
  tft.fillRect(0,40,320,200,TFT_MAGENTA);
  tft.setTextColor(TFT_WHITE);
  tft.unloadFont();
  tft.setCursor(10,50);
  tft.loadFont(FONT_22); 
  tft.print("Режим доп реле ");
  tft.unloadFont();
  tft.print("1");
  tft.loadFont(FONT_22); 
  tft.setCursor(10,90);
  tft.print("Режим доп реле ");
  tft.unloadFont();
  tft.print("2");
  tft.loadFont(FONT_22); 
  tft.setCursor(10,130);
  tft.loadFont(FONT_22); 
  tft.print("Режим серво ");
  tft.unloadFont();
  tft.print("1");
  tft.loadFont(FONT_22); 
  tft.setCursor(10,170);
  tft.print("Режим серво ");
  tft.unloadFont();
  tft.print("2");
  tft.loadFont(FONT_22); 
  tft.setCursor(10,210);
  tft.print("Режим линейный привод");
  tft.unloadFont();
  

  if(selusermodes==1)  
  Selusermodes_1();
  else if(selusermodes==2)  
  Selusermodes_2();
  else if(selusermodes==3)  
  Selusermodes_3();
  else if(selusermodes==4)  
  Selusermodes_4();
  else if(selusermodes==5)  
  Selusermodes_5();
}

void Selusermodes_1()
{
  tft.loadFont(FONT_22);
  tft.setTextSize(2);
  tft.fillRect(0,40,320,40,TFT_RED);
  tft.setCursor(10,50);
  tft.print("Режим доп реле ");
  tft.unloadFont();
  tft.print("1");
}
void Selusermodes_2()
{ 
  tft.loadFont(FONT_22);
  tft.setTextSize(2);
  tft.fillRect(0,80,320,40,TFT_RED);
  tft.setCursor(10,90);
  tft.print("Режим доп реле ");
  tft.unloadFont();
  tft.print("2");
}
void Selusermodes_3()
{
  tft.loadFont(FONT_22);
  tft.fillRect(0,120,320,40,TFT_RED);
  tft.setCursor(10,130);
  tft.print("Режим серво ");
  tft.unloadFont();
  tft.print("1");
}
void Selusermodes_4()
{
  tft.loadFont(FONT_22); 
  tft.fillRect(0,160,320,40,TFT_RED);
  tft.setCursor(10,170);
  tft.print("Режим серво ");
  tft.unloadFont();
  tft.print("2");
 
}
void Selusermodes_5()
{
  tft.loadFont(FONT_22); 
  tft.fillRect(0,200,320,40,TFT_RED);
  tft.setCursor(10,210);
  tft.print("Режим линейный привод");
  tft.unloadFont();
}



/*----------------------------------------------Настройка дисплея---------------------------------*/
void settingsdisplay(int seldisplay)
{
  tft.loadFont(FONT_22); 
  tft.setTextColor(TFT_BLACK);
  tft.setTextSize(2);
  tft.fillRect(0,0,320,40,TFT_GREEN);
  tft.setCursor(10,10);
  tft.print("ДИСПЛЕЙ");
  tft.fillRect(0,40,320,200,TFT_MAGENTA);
  tft.setTextColor(TFT_WHITE);

  if (displayautooff==0){
    tft.setCursor(10,50);
    tft.print("Яркость  ");
    tft.unloadFont();
    tft.setTextSize(2);
    tft.print(setbrightness);
    tft.setCursor(10,90);
    tft.loadFont(FONT_22); 
    tft.print("Автоотключение экрана выкл");

  }else if (displayautooff==1){
    tft.setCursor(10,50);
    tft.print("Яркость ");
    tft.unloadFont();
    tft.setTextSize(2);
    tft.print(setbrightness);
    tft.setCursor(10,90);
    tft.loadFont(FONT_22); 
    tft.print("Автоотключение экрана вкл");
    tft.setCursor(10,130);
    tft.print("Отключать через ");
    tft.unloadFont();
    tft.print(displayautoofftime);
    tft.loadFont(FONT_22); 
    tft.setCursor(219,130);
    tft.print(" мин");
  }
  if(seldisplay==1)  
  Seldisplay_1();
  else if(seldisplay==2)  
  Seldisplay_2();
  else if(seldisplay==3)  
  Seldisplay_3();
}

void Seldisplay_1()
{
  tft.loadFont(FONT_22); 
  tft.fillRect(0,40,320,40,TFT_RED);
  tft.setCursor(10,50);
  tft.print("Яркость  ");
  tft.unloadFont();
  tft.setTextSize(2);
  tft.print(setbrightness);
  editbrightness();
}
void Seldisplay_2()
{
  tft.loadFont(FONT_22); 
  tft.fillRect(0,80,320,40,TFT_RED);
  if (displayautooff==0){
    tft.setCursor(10,90);
    tft.loadFont(FONT_22); 
    tft.print("Автоотключение экрана выкл");
    tft.unloadFont();

  }else if (displayautooff==1){
    tft.setCursor(10,90);
    tft.loadFont(FONT_22); 
    tft.print("Автоотключение экрана вкл");
    tft.unloadFont();
  }
}
void Seldisplay_3()
{
  tft.loadFont(FONT_22); 
  tft.fillRect(0,120,320,40,TFT_RED);
  if (displayautooff==1){
    tft.setCursor(10,130);
    tft.print("Отключать через ");
    tft.unloadFont();
    tft.print(displayautoofftime);
    tft.loadFont(FONT_22); 
    tft.setCursor(219,130);
    tft.print(" мин");
    tft.unloadFont();
    editautoofftime();
  }
}

// отрисовка редактирования температуры авто
void editbrightness()
{
  tft.fillRect(102,48,12,16,TFT_BLUE);
  tft.setTextColor(TFT_WHITE);
  tft.setTextSize(2);
  tft.setCursor(103,49);
  tft.print(setbrightness);
}

void editautoofftime()
{
  tft.fillRect(187,128,24,16,TFT_BLUE);
  tft.setTextColor(TFT_WHITE);
  tft.setTextSize(2);
  tft.setCursor(188,129);
  tft.print(displayautoofftime);
}
/*----------------------------------------------Настройка дисплея---------------------------------*/



/*----------------------------------------------Настройка звука---------------------------------*/
void settingssound(int selsound)
{
  tft.loadFont(FONT_22); 
  tft.setTextColor(TFT_BLACK);
  tft.setTextSize(2);
  tft.fillRect(0,0,320,40,TFT_GREEN);
  tft.setCursor(10,10);
  tft.print("ЗВУК");
  tft.fillRect(0,40,320,200,TFT_MAGENTA);
  tft.setTextColor(TFT_WHITE);

  if (piezoenabled==0){
    tft.setCursor(10,50);
    tft.print("Звук выключен");
    tft.unloadFont();

  }else if (piezoenabled==1){
    tft.setCursor(10,50);
    tft.print("Звук включен");
    tft.setCursor(10,90); 
    tft.print("Тон звука  ");
    tft.unloadFont();
    tft.print(freqs);
  }
  if(selsound==1)  
  Selsound_1();
  else if(selsound==2)  
  Selsound_2();
}

void Selsound_1()
{
  tft.loadFont(FONT_22); 
  tft.fillRect(0,40,320,40,TFT_RED);
  if (piezoenabled==0){
    tft.setCursor(10,50);
    tft.print("Звук выключен");
    tft.unloadFont();
  }else if (piezoenabled==1){
    tft.setCursor(10,50);
    tft.print("Звук включен");
    tft.unloadFont();
  }
}
void Selsound_2()
{
  tft.loadFont(FONT_22); 
  tft.fillRect(0,80,320,40,TFT_RED);
  if (piezoenabled==1){
    tft.setCursor(10,90); 
    tft.print("Тон звука  ");
    tft.unloadFont();
    tft.print(freqs);
  }
  editfreq();
}

// отрисовка редактирования температуры авто
void editfreq()
{
  tft.fillRect(117,88,12,16,TFT_BLUE);
  tft.setTextColor(TFT_WHITE);
  tft.setTextSize(2);
  tft.setCursor(118,89);
  tft.print(freqs);
}
/*----------------------------------------------Настройка звука---------------------------------*/

void settingsdatetime(int seldatetime)
{
  tft.loadFont(FONT_22); 
  tft.setTextColor(TFT_BLACK);
  tft.setTextSize(2);
  tft.fillRect(0,0,320,40,TFT_GREEN);
  tft.setCursor(10,10);
  tft.print("ДАТА И ВРЕМЯ");
  tft.fillRect(0,40,320,200,TFT_MAGENTA);
  tft.setTextColor(TFT_WHITE);
  tft.unloadFont();
  tft.setCursor(10,50);
  if(newhour<10)tft.print("0");
  tft.print(newhour);
  tft.print(":");
  if(newminute<10)tft.print("0");
  tft.print(newminute);
  tft.print(":");
  if(newsecond<10)tft.print("0");
  tft.print(newsecond);
  tft.setCursor(10,90);
  if(newday<10)tft.print("0");
  tft.print(newday);
  tft.print(".");
  if(newmonth<10)tft.print("0");
  tft.print(newmonth);
  tft.print(".");
  tft.print(newyear);
  tft.setCursor(10,130);
  tft.loadFont(FONT_22); 
  tft.print("Установить дату и время");
  tft.unloadFont();

  if(seldatetime==1)  
  Seldatetime_1();
  else if(seldatetime==2)  
  Seldatetime_2();
  else if(seldatetime==3)  
  Seldatetime_3();
}
void Seldatetime_1()
{
  tft.fillRect(0,40,320,40,TFT_RED);
  tft.setCursor(10,50);
  if(newhour<10)tft.print("0");
  tft.print(newhour);
  tft.print(":");
  if(newminute<10)tft.print("0");
  tft.print(newminute);
  tft.print(":");
  if(newsecond<10)tft.print("0");
  tft.print(newsecond);
  if(seledittime==0)
  editnewhour();
  else if(seledittime==1)
  editnewminute();
  else editnewsecond();
}
void Seldatetime_2()
{
  tft.fillRect(0,80,320,40,TFT_RED);
  tft.setCursor(10,90);
  if(newday<10)tft.print("0");
  tft.print(newday);
  tft.print(".");
  if(newmonth<10)tft.print("0");
  tft.print(newmonth);
  tft.print(".");
  tft.print(newyear);
  if(seledittime==0)
  editnewday();
  else if(seledittime==1)
  editnewmonth();
  else editnewyear();
}
void Seldatetime_3()
{
  tft.loadFont(FONT_22); 
  tft.fillRect(0,120,320,40,TFT_RED);
  tft.setCursor(10,130);
  tft.print("Установить дату и время");
  tft.unloadFont();
}

void editnewhour()
{
  tft.fillRect(10,48,24,16,TFT_BLUE);
  tft.setTextColor(TFT_WHITE);
  tft.setTextSize(2);
  tft.setCursor(11,49);
  if(newhour<10)tft.print("0");
  tft.print(newhour);
}
void editnewminute()
{
  tft.fillRect(46,48,24,16,TFT_BLUE);
  tft.setTextColor(TFT_WHITE);
  tft.setTextSize(2);
  tft.setCursor(47,49);
  if(newminute<10)tft.print("0");
  tft.print(newminute);
}
void editnewsecond()
{
  tft.fillRect(82,48,24,16,TFT_BLUE);
  tft.setTextColor(TFT_WHITE);
  tft.setTextSize(2);
  tft.setCursor(83,49);
  if(newsecond<10)tft.print("0");
  tft.print(newsecond);
}
void editnewday()
{
  tft.fillRect(10,88,24,16,TFT_BLUE);
  tft.setTextColor(TFT_WHITE);
  tft.setTextSize(2);
  tft.setCursor(11,89);
  if(newday<10)tft.print("0");
  tft.print(newday);
}
void editnewmonth()
{
  tft.fillRect(46,88,24,16,TFT_BLUE);
  tft.setTextColor(TFT_WHITE);
  tft.setTextSize(2);
  tft.setCursor(47,89);
  if(newmonth<10)tft.print("0");
  tft.print(newmonth);
}
void editnewyear()
{
  tft.fillRect(82,88,48,16,TFT_BLUE);
  tft.setTextColor(TFT_WHITE);
  tft.setTextSize(2);
  tft.setCursor(83,89);
  tft.print(newyear);
}

/*----------------------------------------------Перезагрузка---------------------------------*/
void restart(int selrestart)
{
  tft.loadFont(FONT_22); 
  tft.setTextColor(TFT_BLACK);
  tft.fillRect(0,0,320,40,TFT_GREEN);
  tft.setCursor(10,10);
  tft.print("ПЕРЕЗАГРУЗКА");
  tft.fillRect(0,40,320,200,TFT_MAGENTA);
  tft.setTextColor(TFT_WHITE);
  tft.setCursor(10,50);
  tft.print("Вы действительно хотите");
  tft.setCursor(10,90);
  tft.print("перезагрузить устройство");
  tft.unloadFont();
  tft.setTextSize(2);
  tft.print("?");
  tft.loadFont(FONT_22); 
  tft.setCursor(10,130);
  tft.print("Нет");
  tft.setCursor(10,170);
  tft.print("Да");
  tft.unloadFont(); 

  if(selrestart==1)  
  Selrestart_1();
  else if(selrestart==2)  
  Selrestart_2();
}
void Selrestart_1()
{
  tft.loadFont(FONT_22); 
  tft.fillRect(0,120,320,40,TFT_RED);
  tft.setCursor(10,130);
  tft.print("Нет");
  tft.unloadFont();
}
void Selrestart_2()
{
  tft.loadFont(FONT_22); 
  tft.fillRect(0,160,320,40,TFT_RED);
  tft.setCursor(10,170);
  tft.print("Да");
  tft.unloadFont();
}
/*----------------------------------------------Перезагрузка---------------------------------*/







/*----------------------------------------------Сброс настроек---------------------------------*/
void reset(int selreset)
{
  tft.loadFont(FONT_22); 
  tft.setTextColor(TFT_BLACK);
  tft.fillRect(0,0,320,40,TFT_GREEN);
  tft.setCursor(10,10);
  tft.print("СБРОС НАСТРОЕК");
  tft.fillRect(0,40,320,200,TFT_MAGENTA);
  tft.setTextColor(TFT_WHITE);
  tft.setCursor(10,50);
  tft.print("Вы действительно хотите");
  tft.setCursor(10,90);
  tft.print("сбросить все настройки");
  tft.unloadFont();
  tft.setTextSize(2);
  tft.print("?");
  tft.loadFont(FONT_22); 
  tft.setCursor(10,130);
  tft.print("Нет");
  tft.setCursor(10,170);
  tft.print("Да");
  tft.unloadFont(); 

  if(selreset==1)  
  Selreset_1();
  else if(selreset==2)  
  Selreset_2();
}
void Selreset_1()
{
  tft.loadFont(FONT_22); 
  tft.fillRect(0,120,320,40,TFT_RED);
  tft.setCursor(10,130);
  tft.print("Нет");
  tft.unloadFont();
}
void Selreset_2()
{
  tft.loadFont(FONT_22); 
  tft.fillRect(0,160,320,40,TFT_RED);
  tft.setCursor(10,170);
  tft.print("Да");
  tft.unloadFont();
}
/*----------------------------------------------Сброс настроек---------------------------------*/









void selsettingsup(){
  if(mode == 21) {
      if(selsensors==7) selsensors = 1;
      else selsensors++;
    settingssensors(selsensors);
    time1=0;
  }
  if(mode == 22) {
      if(selusermodes==5) selusermodes = 1;
      else selusermodes++;
    settingsusermodes(selusermodes);
    time1=0;
  }
  if(mode == 23) {
    if (displayautooff==0) {
      if(seldisplay==2) seldisplay = 1;
      else seldisplay++;
    } else if (displayautooff==1){
      if(seldisplay==3) seldisplay = 1;
      else seldisplay++;
    }
    settingsdisplay(seldisplay);
    time1=0;
  }
  if(mode == 24) {
    if (piezoenabled==0) selsound = 1; 
    else if (piezoenabled==1){
      if(selsound==2) selsound = 1;
      else selsound++;
    }
    settingssound(selsound);
    time1=0;
  }
  if(mode == 25) {
    if(seldatetime==3) seldatetime = 1;
    else seldatetime++;
    settingsdatetime(seldatetime);
    time1=0;
  }
  if(mode == 27) {
    if(selreset==2) selreset = 1;
    else selreset++;
    reset(selreset);
    time1=0;
  }
  if(mode == 26) {
    if(selrestart==2) selrestart = 1;
    else selrestart++;
    restart(selrestart);
    time1=0;
  }
  if(mode == 212) {
    if(bme280status==0){
      selbme = 1;
    }
    if(bme280status==1){
      if(selbme==3) selbme = 1;
    else selbme++;
    }
    settingsbme(selbme);
    time1=0;
  }
  if(mode == 213) {
    if(dht11status==0){
      seldht = 1;
    }
    if(dht11status==1){
      if(seldht==3) seldht = 1;
    else seldht++;
    }
    settingsdht(seldht);
    time1=0;
  }
  if (mode==214){
    if(selntc==3) selntc = 1;
    else selntc++;
    settingsntc(selntc);
    time1=0;
  }
  if (mode==215){
    if(selldr==2) selldr = 1;
    else selldr++;
    setldr(selldr);
    time1=0;
  }
}

void selsettingsdown(){
  if(mode == 21) {
    if(selsensors==1) selsensors = 7;
    else selsensors--;
    settingssensors(selsensors);
    time1=0;
  }
  if(mode == 22) {
    if(selusermodes==1) selusermodes = 5;
    else selusermodes--;
    settingsusermodes(selusermodes);
    time1=0;
  }
  if(mode == 23) {
    if (displayautooff==0) {
      if(seldisplay==1) seldisplay = 2;
      else seldisplay--;
    } else if (displayautooff==1){
      if(seldisplay==1) seldisplay = 3;
      else seldisplay--;
    }
    settingsdisplay(seldisplay);
    time1=0;
  }
  if(mode == 24) {
    if (piezoenabled==0) selsound = 1; 
    else if (piezoenabled==1){
      if(selsound==1) selsound = 2;
      else selsound--;
    }
    settingssound(selsound);
    time1=0;
  }
  if(mode == 25) {
    if(seldatetime==1) seldatetime = 3;
    else seldatetime--;
    settingsdatetime(seldatetime);
    time1=0;
  }
  if(mode == 27) {
    if(selreset==1) selreset = 2;
    else selreset--;
    reset(selreset);
    time1=0;
  }
  if(mode == 26) {
    if(selrestart==1) selrestart = 2;
    else selrestart--;
    restart(selrestart);
    time1=0;
  }
  if(mode == 212) {
    if(bme280status==0){
      selbme = 1;
    }
    if(bme280status==1){
      if(selbme==1) selbme = 3;
    else selbme--;
    }
    settingsbme(selbme);
    time1=0;
  }
  if(mode == 213) {
    if(dht11status==0){
      seldht = 1;
    }
    if(dht11status==1){
      if(seldht==1) seldht = 3;
    else seldht--;
    }
    settingsdht(seldht);
    time1=0;
  }
  if (mode==214){
    if(selntc==1) selntc = 3;
    else selntc--;
    settingsntc(selntc);
    time1=0;
  }
  if (mode==215){
    if(selldr==1) selldr = 2;
    else selldr--;
    setldr(selldr);
    time1=0;
  }
}



void settingsleft()
{
  if(mode==23) {
    if (seldisplay==2) {
      if (displayautooff==0){
        displayautooff=1;
      }else displayautooff--;
    }   
    settingsdisplay(seldisplay);
    EEPROM.put(1, displayautooff);
    EEPROM.commit();
    time1=0;
  }
  if(mode==24) {
    if (selsound==1) {
      if (piezoenabled==0){
        piezoenabled=1;
      }else piezoenabled--;
    }   
    settingssound(selsound);
    EEPROM.put(3, piezoenabled);
    EEPROM.commit();
    time1=0;
  }
  if(mode==25) {
    if ((seldatetime==1)||(seldatetime==2)) {
      if(seledittime==0) seledittime = 2;
    else seledittime--;
    settingsdatetime(seldatetime);
    time1=0;
    } 
  } 
  if(mode==212) {
    if (bme280status==0){
      if (selbme==1) {
        if(bme.begin(0x76)){
          bme280status=1;
          settingsbme(selbme);
          time1=0;
          tft.fillRect(0,200,320,40, TFT_GREEN);
          tft.setCursor(10,210);
          tft.setTextColor(TFT_BLACK);
            tft.setTextSize(3);
          tft.print("BME280 OK");
        } else {
          bme280status=0;
          settingsbme(selbme);
          time1=0;
          tft.fillRect(0,200,320,40, TFT_GREEN);
          tft.setCursor(10,210);
          tft.setTextColor(TFT_BLACK);
            tft.setTextSize(3);
          tft.print("BME280 ERROR");
        }
      }
    } else if (bme280status==1){
      if (selbme==1) {
        bme280status=0;
        selbme=1;
        settingsbme(selbme);
        time1=0;
      }
      if (selbme==2) {
        temperaturesensor=2;
        settingsbme(selbme);
        time1=0;
      }
      if (selbme==3) {
        humiditysensor=2;
        settingsbme(selbme);
        time1=0;
      }
    }
  }
  if(mode==213) {
    if (dht11status==0){
      if (seldht==1) {
        if(!(isnan(tempC) || isnan(humi))){
          dht11status=1;
          settingsdht(seldht);
          time1=0;
          tft.fillRect(0,200,320,40, TFT_GREEN);
          tft.setCursor(10,210);
          tft.setTextColor(TFT_BLACK);
            tft.setTextSize(3);
          tft.print("DHT11 OK");
        } else {
          dht11status=0;
          settingsdht(seldht);
          time1=0;
          tft.fillRect(0,200,320,40, TFT_GREEN);
          tft.setCursor(10,210);
          tft.setTextColor(TFT_BLACK);
            tft.setTextSize(3);
          tft.print("DHT11 ERROR");
        }
      }
    } else if (dht11status==1){
      if (seldht==1) {
        dht11status=0;
        seldht=1;
        settingsdht(seldht);
        time1=0;
      }
      if (seldht==2) {
        temperaturesensor=1;
        settingsdht(seldht);
        time1=0;
      }
      if (seldht==3) {
        humiditysensor=1;
        settingsdht(seldht);
        time1=0;
      }
    }
  }
  if (mode==214){
    if (selntc==1) {
      temperaturesensor=0;
      settingsntc(selntc);
      time1=0;
    }
    if (selntc==2) {
      humiditysensor=0;
      settingsntc(selntc);
      time1=0;
    }
  }
}

void settingsright()
{
  if(mode==23) {
    if (seldisplay==2) {
      if (displayautooff==1){
        displayautooff=0;
      }else displayautooff++;
    }   
    settingsdisplay(seldisplay);
    EEPROM.put(1, displayautooff);
    EEPROM.commit();
    time1=0;
  }
    if(mode==24) {
    if (selsound==1) {
      if (piezoenabled==1){
        piezoenabled=0;
      }else piezoenabled++;
    }   
    settingssound(selsound);
    EEPROM.put(3, piezoenabled);
    EEPROM.commit();
    time1=0;
  }
    if(mode==25) {
    if ((seldatetime==1)||(seldatetime==2)) {
      if(seledittime==2) seledittime = 0;
    else seledittime++;
    settingsdatetime(seldatetime);
    time1=0;
    } 
  }
  if(mode==212) {
    if (bme280status==0){
      if (selbme==1) {
        if(bme.begin(0x76)){
          bme280status=1;
          settingsbme(selbme);
          time1=0;
          tft.fillRect(0,200,320,40, TFT_GREEN);
          tft.setCursor(10,210);
          tft.setTextColor(TFT_BLACK);
            tft.setTextSize(3);
          tft.print("BME280 OK");
        } else {
          bme280status=0;
          settingsbme(selbme);
          time1=0;
          tft.fillRect(0,200,320,40, TFT_GREEN);
          tft.setCursor(10,210);
          tft.setTextColor(TFT_BLACK);
            tft.setTextSize(3);
          tft.print("BME280 ERROR");
        }
      }
    } else if (bme280status==1){
      if (selbme==1) {
        bme280status=0;
        selbme=1;
        settingsbme(selbme);
        time1=0;
      }
      if (selbme==2) {
        temperaturesensor=2;
        settingsbme(selbme);
        time1=0;
      }
      if (selbme==3) {
        humiditysensor=2;
        settingsbme(selbme);
        time1=0;
      }
    }
  }
  if(mode==213) {
    if (dht11status==0){
      if (seldht==1) {
        if(!(isnan(tempC) || isnan(humi))){
          dht11status=1;
          settingsdht(seldht);
          time1=0;
          tft.fillRect(0,200,320,40, TFT_GREEN);
          tft.setCursor(10,210);
          tft.setTextColor(TFT_BLACK);
            tft.setTextSize(3);
          tft.print("DHT11 OK");
        } else {
          dht11status=0;
          settingsdht(seldht);
          time1=0;
          tft.fillRect(0,200,320,40, TFT_GREEN);
          tft.setCursor(10,210);
          tft.setTextColor(TFT_BLACK);
            tft.setTextSize(3);
          tft.print("DHT11 ERROR");
        }
      }
    } else if (dht11status==1){
      if (seldht==1) {
        dht11status=0;
        seldht=1;
        settingsdht(seldht);
        time1=0;
      }
      if (seldht==2) {
        temperaturesensor=1;
        settingsdht(seldht);
        time1=0;
      }
      if (seldht==3) {
        humiditysensor=1;
        settingsdht(seldht);
        time1=0;
      }
    }
  }
  if (mode==214){
    if (selntc==1) {
      temperaturesensor=0;
      settingsntc(selntc);
      time1=0;
    }
    if (selntc==2) {
      humiditysensor=0;
      settingsntc(selntc);
      time1=0;
    }
  }
}


void settingsencoderup()
{
  if (mode == 21){
    if(selsensors==1){
      if(intervalsensor<60){
        intervalsensor++;
        editsensorinterval();
        EEPROM.put(5, intervalsensor);
        EEPROM.commit();
      }  
    }
  }
  if (mode == 23){
    if(seldisplay==1){
      if(setbrightness<5){
        setbrightness++;
        editbrightness();
        EEPROM.put(0, setbrightness);
        EEPROM.commit();
      }  
    }
    if(seldisplay==3){
      if(displayautoofftime<60){
        displayautoofftime++;
        editautoofftime();
        EEPROM.put(2, displayautoofftime);
        EEPROM.commit();
      }  
    }
  }
  if (mode == 24){
    if(selsound==2){
      if(freqs<9){
        freqs++;
        editfreq();
        EEPROM.put(4, freqs);
        EEPROM.commit();
      }  
    }
  }
  if (mode == 25){
    if(seldatetime==1){
      if(seledittime==0){
        if (newhour<23)newhour++;
        editnewhour();
      }
      if(seledittime==1){
        if (newminute<59)newminute++;
        editnewminute();
      }
      if(seledittime==2){
        if (newsecond<59)newsecond++;
        editnewsecond();
      }
    }
    if(seldatetime==2){
      if(seledittime==0){
        if ((newmonth==1)||(newmonth==3)||(newmonth==5)||(newmonth==7)||(newmonth==8)||(newmonth==10)||(newmonth==12)){
          if (newday<31)newday++;
        }
        if (newmonth==2){
          if (newday<28)newday++;
        } else if (newday<30)newday++;
        editnewday();
      }
      if(seledittime==1){
        if (newmonth<12)newmonth++;
        editnewmonth();
      }
      if(seledittime==2){
        if (newyear<2100)newyear++;
        editnewyear();
      }
    }
  }
  if (mode==214){
    if (selntc==3){
      if (BETA<9999) 
      {
        BETA++;
        editbeta();
        EEPROM.put(6, BETA);
        EEPROM.commit();
      }
    }
  }
   if (mode==215){
    if (selldr==1){
      if (gammas<0.99) 
      {
        gammas+=0.01;
        editgamma();
        EEPROM.put(10, gammas);
        EEPROM.commit();
      }
    }
    if (selldr==2){
      if (r1<999) 
      {
        r1++;
        editr1();
        EEPROM.put(14, r1);
        EEPROM.commit();
      }
    }
  }
}

void settingsencoderdown()
{
  if (mode == 21){
    if(selsensors==1){
      if(intervalsensor>1){
        intervalsensor--;
        editsensorinterval();
        EEPROM.put(5, intervalsensor);
        EEPROM.commit();
      }  
    }
  }
  if (mode == 23){
    if(seldisplay==1){
      if(setbrightness>1){
        setbrightness--;
        editbrightness();
        EEPROM.put(0, setbrightness); 
        EEPROM.commit(); 
      }  
    }
    if(seldisplay==3){
      if(displayautoofftime>1){
        displayautoofftime--;
        editautoofftime();
        EEPROM.put(2, displayautoofftime);
        EEPROM.commit();
      }  
    }
  }
  if (mode == 24){
    if(selsound==2){
      if(freqs>1){
        freqs--;
        editfreq();
        EEPROM.put(4, freqs);
        EEPROM.commit();
      }  
    }
  }
  if (mode == 25){
    if(seldatetime==1){
      if(seledittime==0){
        if (newhour>0)newhour--;
        editnewhour();
      }
      if(seledittime==1){
        if (newminute>0)newminute--;
        editnewminute();
      }
      if(seledittime==2){
        if (newsecond>0)newsecond--;
        editnewsecond();
      }
    }
    if(seldatetime==2){
      if(seledittime==0){
        if (newday>1)newday--;
        editnewday();
      }
      if(seledittime==1){
        if (newmonth>1)newmonth--;
        editnewmonth();
      }
      if(seledittime==2){
        if (newyear>2000)newyear--;
        editnewyear();
      }
    }
  }
  if (mode==214){
    if (selntc==3){
      if (BETA>1000) 
      {
        BETA--;
        editbeta();
        EEPROM.put(6, BETA);
        EEPROM.commit();
      }
    }
  }
  if (mode==215){
    if (selldr==1){
      if (gammas>0.02) 
      {
        gammas-=0.01;
        editgamma();
        EEPROM.put(10, gammas);
        EEPROM.commit();
      }
    }
    if (selldr==2){
      if (r1>1) 
      {
        r1--;
        editr1();
        EEPROM.put(14, r1);
        EEPROM.commit();
      }
    }
  }
}

void settingsok()
{
  DateTime now = rtc.now();
  if (mode==2) {
    if (selection==1){
    mode = 21;
    settingssensors(selsensors);
    }

    if (selection==2){
    mode = 22;
    settingsusermodes(selusermodes);
    }

    if (selection==3){
    mode = 23;
    settingsdisplay(seldisplay);
    }

    if (selection==4){
    mode = 24;
    settingssound(selsound);
    }

    if (selection==5){
    mode = 25;
    newhour = now.hour();
    newminute = now.minute();
    newsecond = now.second();
    newday = now.day();
    newmonth = now.month();
    newyear = now.year();
    settingsdatetime(seldatetime);
    }   

    if (selection==6){
    mode = 26;
    restart(selrestart);
    }

    if (selection==7){
    mode = 27;
    reset(selreset);
    }
    time1=0;
    tempmenu1=0;
    lightmenu1=0;
    moistmenu1=0;
  } else if (mode==21) {
    if (selsensors==2){
      mode = 212;
      settingsbme(selbme);
      time1=0;
    }
    if (selsensors==3){
      mode = 213;
      settingsdht(seldht);
      time1=0;
    }
    if (selsensors==4){
      mode = 214;
      settingsntc(selntc);
      time1=0;
    }
    if (selsensors==5){
      mode = 215;
      setldr(selldr);
      time1=0;
    }
  } else if (mode==22) {
    if (selusermodes==1){
      mode = 221;
      setusermoderelay1(selusermoderelay1);
      relay1menu1=0;
      time1=0;
    }

    if (selusermodes==2){
      mode = 222;
      setusermoderelay2(selusermoderelay2);
      relay2menu1=0;
      time1=0;
    }

    if (selusermodes==3){
      mode = 223;
      setusermodeservo1(selusermodeservo1);
      servo1menu1=0;
      time1=0;
    }

    if (selusermodes==4){
      mode = 224;
      setusermodeservo2(selusermodeservo2);
      servo2menu1=0;
      time1=0;
    }

    if (selusermodes==5){
      mode = 225;
      setusermodeactuator(selusermodeactuator);
      actuatormenu1=0;
      time1=0;
    }
  }
  
  
  else if (mode==25) {
    if (seldatetime==3){
      rtc.adjust(DateTime(newyear, newmonth, newday, newhour, newminute, newsecond));
      mode = 2;
      settings(selection);
      time1=0;
    }
  }
    
    
  else if (mode==26) {
    if (selrestart==1){
    mode = 2;
    settings(selection);
    time1=0;
    }
    if (selrestart==2){
    ESP.restart();
    }
  }



  else if (mode==27) {
    if (selreset==1){
    mode = 2;
    settings(selection);
    time1=0;
    }
    if (selreset==2){
      EEPROM.write(INIT_ADDR, 51);
      EEPROM.commit();
      ESP.restart();
    }
  } 
}

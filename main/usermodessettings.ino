void setusermoderelay1(int selusermoderelay1)
{
  tft.loadFont(FONT_22); 
  tft.setTextColor(TFT_BLACK);
  tft.setTextSize(2);
  tft.fillRect(0,0,320,40,TFT_GREEN);
  tft.setCursor(10,10);
  tft.print("РЕЖИМ РЕЛЕ ");
  tft.unloadFont();
  tft.print("1");
  tft.fillRect(0,40,320,200,TFT_MAGENTA);
  tft.fillRect(0,200,320,40,TFT_GREEN);
  tft.setCursor(10,210);
  tft.loadFont(FONT_22);
  tft.print("Сейчас ");
  tft.setTextColor(TFT_WHITE);

  tft.setCursor(10,50);
  tft.loadFont(FONT_22); 
  tft.print("Параметр ");
  tft.unloadFont();
  switch (usermoderelay1sensor) {
  case 0:
    tft.print("t÷C");
    break;
  case 1:
    tft.loadFont(FONT_22); 
    tft.print("Вл воздуха ");
    tft.unloadFont();
    tft.print("%");
    break;
  case 2:
    tft.print("NTC t÷C");
    break;
  case 3:
    tft.loadFont(FONT_22); 
    tft.print("Свет ");
    tft.unloadFont();
    tft.print("lux");
    break;
  case 4:
    tft.loadFont(FONT_22); 
    tft.print("Вл почвы ");
    tft.unloadFont();
    tft.print("%");
    break;
  case 5:
    tft.loadFont(FONT_22); 
    tft.print("аналог ");
    tft.unloadFont();
    tft.print("1");
    break;
  case 6:
    tft.loadFont(FONT_22); 
    tft.print("аналог ");
    tft.unloadFont();
    tft.print("2");
    break;
}

  tft.loadFont(FONT_22); 
  tft.setCursor(10,90);
  tft.print("Направление ");
  if (usermoderelay1direction==0) tft.print("Выкл Вкл");
  else tft.print("Вкл Выкл");
  tft.unloadFont();
  

  if(selusermoderelay1==1)  
  Selusermoderelay1_1();
  else if(selusermoderelay1==2)  
  Selusermoderelay1_2();
}

void Selusermoderelay1_1()
{
  tft.loadFont(FONT_22);
  tft.setTextSize(2);
  tft.fillRect(0,40,320,40,TFT_RED);
  tft.setCursor(10,50);
  tft.print("Параметр ");
  tft.unloadFont();
  switch (usermoderelay1sensor) {
  case 0:
    tft.print("t÷C");
    break;
  case 1:
    tft.loadFont(FONT_22); 
    tft.print("Вл воздуха ");
    tft.unloadFont();
    tft.print("%");
    break;
  case 2:
    tft.print("NTC t÷C");
    break;
  case 3:
    tft.loadFont(FONT_22); 
    tft.print("Свет ");
    tft.unloadFont();
    tft.print("lux");
    break;
  case 4:
    tft.loadFont(FONT_22); 
    tft.print("Вл почвы ");
    tft.unloadFont();
    tft.print("%");
    break;
  case 5:
    tft.loadFont(FONT_22); 
    tft.print("аналог ");
    tft.unloadFont();
    tft.print("1");
    break;
  case 6:
    tft.loadFont(FONT_22); 
    tft.print("аналог ");
    tft.unloadFont();
    tft.print("2");
    break;
}
}
void Selusermoderelay1_2()
{ 
  tft.loadFont(FONT_22);
  tft.setTextSize(2);
  tft.fillRect(0,80,320,40,TFT_RED);
  tft.setCursor(10,90);
  tft.loadFont(FONT_22); 
  tft.setCursor(10,90);
  tft.print("Направление ");
  if (usermoderelay1direction==0) tft.print("Выкл Вкл");
  else tft.print("Вкл Выкл");
  tft.unloadFont();
}

void setusermoderelay2(int selusermoderelay2)
{
  tft.loadFont(FONT_22); 
  tft.setTextColor(TFT_BLACK);
  tft.setTextSize(2);
  tft.fillRect(0,0,320,40,TFT_GREEN);
  tft.setCursor(10,10);
  tft.print("РЕЖИМ РЕЛЕ ");
  tft.unloadFont();
  tft.print("2");
  tft.fillRect(0,40,320,200,TFT_MAGENTA);
  tft.fillRect(0,200,320,40,TFT_GREEN);
  tft.setCursor(10,210);
  tft.loadFont(FONT_22);
  tft.print("Сейчас ");
  tft.setTextColor(TFT_WHITE);
  tft.unloadFont();

  tft.setCursor(10,50);
  tft.loadFont(FONT_22); 
  tft.print("Параметр ");
  tft.unloadFont();
  switch (usermoderelay2sensor) {
  case 0:
    tft.print("t÷C");
    break;
  case 1:
    tft.loadFont(FONT_22); 
    tft.print("Вл воздуха ");
    tft.unloadFont();
    tft.print("%");
    break;
  case 2:
    tft.print("NTC t÷C");
    break;
  case 3:
    tft.loadFont(FONT_22); 
    tft.print("Свет ");
    tft.unloadFont();
    tft.print("lux");
    break;
  case 4:
    tft.loadFont(FONT_22); 
    tft.print("Вл почвы ");
    tft.unloadFont();
    tft.print("%");
    break;
  case 5:
    tft.loadFont(FONT_22); 
    tft.print("аналог ");
    tft.unloadFont();
    tft.print("1");
    break;
  case 6:
    tft.loadFont(FONT_22); 
    tft.print("аналог ");
    tft.unloadFont();
    tft.print("2");
    break;
}

  tft.loadFont(FONT_22); 
  tft.setCursor(10,90);
  tft.print("Направление ");
  if (usermoderelay2direction==0) tft.print("Выкл Вкл");
  else tft.print("Вкл Выкл");
  tft.unloadFont();
  

  if(selusermoderelay2==1)  
  Selusermoderelay2_1();
  else if(selusermoderelay2==2)  
  Selusermoderelay2_2();
}

void Selusermoderelay2_1()
{
  tft.loadFont(FONT_22);
  tft.setTextSize(2);
  tft.fillRect(0,40,320,40,TFT_RED);
  tft.setCursor(10,50);
  tft.print("Параметр ");
  tft.unloadFont();
  switch (usermoderelay2sensor) {
  case 0:
    tft.print("t÷C");
    break;
  case 1:
    tft.loadFont(FONT_22); 
    tft.print("Вл воздуха ");
    tft.unloadFont();
    tft.print("%");
    break;
  case 2:
    tft.print("NTC t÷C");
    break;
  case 3:
    tft.loadFont(FONT_22); 
    tft.print("Свет ");
    tft.unloadFont();
    tft.print("lux");
    break;
  case 4:
    tft.loadFont(FONT_22); 
    tft.print("Вл почвы ");
    tft.unloadFont();
    tft.print("%");
    break;
  case 5:
    tft.loadFont(FONT_22); 
    tft.print("аналог ");
    tft.unloadFont();
    tft.print("1");
    break;
  case 6:
    tft.loadFont(FONT_22); 
    tft.print("аналог ");
    tft.unloadFont();
    tft.print("2");
    break;
}
}
void Selusermoderelay2_2()
{ 
  tft.loadFont(FONT_22);
  tft.setTextSize(2);
  tft.fillRect(0,80,320,40,TFT_RED);
  tft.setCursor(10,90);
  tft.loadFont(FONT_22); 
  tft.setCursor(10,90);
  tft.print("Направление ");
  if (usermoderelay2direction==0) tft.print("Выкл Вкл");
  else tft.print("Вкл Выкл");
  tft.unloadFont();
}



void setusermodeservo1(int selusermodeservo1)
{
  tft.loadFont(FONT_22); 
  tft.setTextColor(TFT_BLACK);
  tft.setTextSize(2);
  tft.fillRect(0,0,320,40,TFT_GREEN);
  tft.setCursor(10,10);
  tft.print("РЕЖИМ СЕРВО ");
  tft.unloadFont();
  tft.print("1");
  tft.fillRect(0,40,320,200,TFT_MAGENTA);
  tft.setTextColor(TFT_WHITE);
  tft.unloadFont();

  tft.setCursor(10,50);
  tft.loadFont(FONT_22); 
  tft.print("Параметр ");
  tft.unloadFont();
  switch (usermodeservo1sensor) {
  case 0:
    tft.print("t÷C");
    break;
  case 1:
    tft.loadFont(FONT_22); 
    tft.print("Вл воздуха ");
    tft.unloadFont();
    tft.print("%");
    break;
  case 2:
    tft.print("NTC t÷C");
    break;
  case 3:
    tft.loadFont(FONT_22); 
    tft.print("Свет ");
    tft.unloadFont();
    tft.print("lux");
    break;
  case 4:
    tft.loadFont(FONT_22); 
    tft.print("Вл почвы ");
    tft.unloadFont();
    tft.print("%");
    break;
  case 5:
    tft.loadFont(FONT_22); 
    tft.print("аналог ");
    tft.unloadFont();
    tft.print("1");
    break;
  case 6:
    tft.loadFont(FONT_22); 
    tft.print("аналог ");
    tft.unloadFont();
    tft.print("2");
    break;
}

  tft.loadFont(FONT_22); 
  tft.setCursor(10,90);
  tft.print("Направление ");
  if (usermodeservo1direction==0) tft.print("Выкл Вкл");
  else tft.print("Вкл Выкл");

  tft.setCursor(10,130);
  tft.print("Пределы от ");
  tft.unloadFont();
  tft.print(servo1start);
  tft.setCursor(175,130);
  tft.loadFont(FONT_22);
  tft.print("до ");
  tft.unloadFont();
  tft.print(servo1stop);

  tft.setCursor(10,170);
  tft.loadFont(FONT_22); 
  tft.print("Скорость ");
  tft.unloadFont();
  tft.print(servo1speed);
  tft.setCursor(152,170);
  tft.loadFont(FONT_22);
  tft.print("ускорение ");
  tft.unloadFont();
  tft.print(servo1acceleration,1);

  tft.setCursor(10,210);
  tft.loadFont(FONT_22);
  tft.print("По умолч ");
  tft.unloadFont();
  tft.print("100");
  tft.loadFont(FONT_22);
  tft.print("грд");
  tft.unloadFont();
  tft.print("/");
  tft.loadFont(FONT_22);
  tft.print("с");
  tft.unloadFont();
  tft.print("|");
  tft.loadFont(FONT_22);
  tft.print("ускор ");
  tft.unloadFont();
  tft.print("0.2");

  if(selusermodeservo1==1)  
  Selusermodeservo1_1();
  else if(selusermodeservo1==2)  
  Selusermodeservo1_2();
  else if(selusermodeservo1==3)  
  Selusermodeservo1_3();
  else if(selusermodeservo1==4)  
  Selusermodeservo1_4();
}

void Selusermodeservo1_1()
{
  tft.loadFont(FONT_22);
  tft.setTextSize(2);
  tft.fillRect(0,40,320,40,TFT_RED);
  tft.setCursor(10,50);
  tft.print("Параметр ");
  tft.unloadFont();
  switch (usermodeservo1sensor) {
  case 0:
    tft.print("t÷C");
    break;
  case 1:
    tft.loadFont(FONT_22); 
    tft.print("Вл воздуха ");
    tft.unloadFont();
    tft.print("%");
    break;
  case 2:
    tft.print("NTC t÷C");
    break;
  case 3:
    tft.loadFont(FONT_22); 
    tft.print("Свет ");
    tft.unloadFont();
    tft.print("lux");
    break;
  case 4:
    tft.loadFont(FONT_22); 
    tft.print("Вл почвы ");
    tft.unloadFont();
    tft.print("%");
    break;
  case 5:
    tft.loadFont(FONT_22); 
    tft.print("аналог ");
    tft.unloadFont();
    tft.print("1");
    break;
  case 6:
    tft.loadFont(FONT_22); 
    tft.print("аналог ");
    tft.unloadFont();
    tft.print("2");
    break;
}
}
void Selusermodeservo1_2()
{ 
  tft.loadFont(FONT_22);
  tft.setTextSize(2);
  tft.fillRect(0,80,320,40,TFT_RED);
  tft.setCursor(10,90);
  tft.print("Направление ");
  if (usermodeservo1direction==0) tft.print("Выкл Вкл");
  else tft.print("Вкл Выкл");
  tft.unloadFont();
}

void Selusermodeservo1_3()
{
   tft.loadFont(FONT_22);
  tft.setTextSize(2);
  tft.fillRect(0,120,320,40,TFT_RED);
  tft.setCursor(10,130);
  tft.print("Пределы от ");
  tft.unloadFont();
  tft.print(servo1start);
  tft.setCursor(175,130);
  tft.loadFont(FONT_22);
  tft.print("до ");
  tft.unloadFont();
  tft.print(servo1stop);
  if(seledit==0)
    editservo1start();
  else editservo1stop();
}

void Selusermodeservo1_4()
{
  tft.loadFont(FONT_22);
  tft.setTextSize(2);
  tft.fillRect(0,160,320,40,TFT_RED);
  tft.setCursor(10,170);
  tft.print("Скорость ");
  tft.unloadFont();
  tft.print(servo1speed);
  tft.setCursor(152,170);
  tft.loadFont(FONT_22);
  tft.print("ускорение ");
  tft.unloadFont();
  tft.print(servo1acceleration,1);
  if(seledit==0)
    editservo1speed();
  else editservo1acceleration();
}

void editservo1start()
{
  tft.fillRect(137,128,36,16,TFT_BLUE);
  tft.setTextColor(TFT_WHITE);
  tft.setTextSize(2);
  tft.setCursor(138,129);
  tft.print(servo1start,0);
}

// отрисовка редактирования +- температуры авто
void editservo1stop()
{
  tft.fillRect(204,128,36,16,TFT_BLUE);
  tft.setTextColor(TFT_WHITE);
  tft.setTextSize(2);
  tft.setCursor(205,129);
  tft.print(servo1stop,0);
}

void editservo1speed()
{
  tft.fillRect(111,168,36,16,TFT_BLUE);
  tft.setTextColor(TFT_WHITE);
  tft.setTextSize(2);
  tft.setCursor(112,169);
  tft.print(servo1speed,0);
}

// отрисовка редактирования +- температуры авто
void editservo1acceleration()
{
  tft.fillRect(260,168,36,16,TFT_BLUE);
  tft.setTextColor(TFT_WHITE);
  tft.setTextSize(2);
  tft.setCursor(261,169);
  tft.print(servo1acceleration,1);
}


void setusermodeservo2(int selusermodeservo2)
{
  tft.loadFont(FONT_22); 
  tft.setTextColor(TFT_BLACK);
  tft.setTextSize(2);
  tft.fillRect(0,0,320,40,TFT_GREEN);
  tft.setCursor(10,10);
  tft.print("РЕЖИМ СЕРВО ");
  tft.unloadFont();
  tft.print("2");
  tft.fillRect(0,40,320,200,TFT_MAGENTA);
  tft.setTextColor(TFT_WHITE);
  tft.unloadFont();

  tft.setCursor(10,50);
  tft.loadFont(FONT_22); 
  tft.print("Параметр ");
  tft.unloadFont();
  switch (usermodeservo2sensor) {
  case 0:
    tft.print("t÷C");
    break;
  case 1:
    tft.loadFont(FONT_22); 
    tft.print("Вл воздуха ");
    tft.unloadFont();
    tft.print("%");
    break;
  case 2:
    tft.print("NTC t÷C");
    break;
  case 3:
    tft.loadFont(FONT_22); 
    tft.print("Свет ");
    tft.unloadFont();
    tft.print("lux");
    break;
  case 4:
    tft.loadFont(FONT_22); 
    tft.print("Вл почвы ");
    tft.unloadFont();
    tft.print("%");
    break;
  case 5:
    tft.loadFont(FONT_22); 
    tft.print("аналог ");
    tft.unloadFont();
    tft.print("1");
    break;
  case 6:
    tft.loadFont(FONT_22); 
    tft.print("аналог ");
    tft.unloadFont();
    tft.print("2");
    break;
}

  tft.loadFont(FONT_22); 
  tft.setCursor(10,90);
  tft.print("Направление ");
  if (usermodeservo2direction==0) tft.print("Выкл Вкл");
  else tft.print("Вкл Выкл");

  tft.setCursor(10,130);
  tft.print("Пределы от ");
  tft.unloadFont();
  tft.print(servo2start);
  tft.setCursor(175,130);
  tft.loadFont(FONT_22);
  tft.print("до ");
  tft.unloadFont();
  tft.print(servo2stop);

  tft.setCursor(10,170);
  tft.loadFont(FONT_22); 
  tft.print("Скорость ");
  tft.unloadFont();
  tft.print(servo2speed);
  tft.setCursor(152,170);
  tft.loadFont(FONT_22);
  tft.print("ускорение ");
  tft.unloadFont();
  tft.print(servo2acceleration,1);

  tft.setCursor(10,210);
  tft.loadFont(FONT_22);
  tft.print("По умолч ");
  tft.unloadFont();
  tft.print("100");
  tft.loadFont(FONT_22);
  tft.print("грд");
  tft.unloadFont();
  tft.print("/");
  tft.loadFont(FONT_22);
  tft.print("с");
  tft.unloadFont();
  tft.print("|");
  tft.loadFont(FONT_22);
  tft.print("ускор ");
  tft.unloadFont();
  tft.print("0.2");

  if(selusermodeservo2==1)  
  Selusermodeservo2_1();
  else if(selusermodeservo2==2)  
  Selusermodeservo2_2();
  else if(selusermodeservo2==3)  
  Selusermodeservo2_3();
  else if(selusermodeservo2==4)  
  Selusermodeservo2_4();
}

void Selusermodeservo2_1()
{
  tft.loadFont(FONT_22);
  tft.setTextSize(2);
  tft.fillRect(0,40,320,40,TFT_RED);
  tft.setCursor(10,50);
  tft.print("Параметр ");
  tft.unloadFont();
  switch (usermodeservo2sensor) {
  case 0:
    tft.print("t÷C");
    break;
  case 1:
    tft.loadFont(FONT_22); 
    tft.print("Вл воздуха ");
    tft.unloadFont();
    tft.print("%");
    break;
  case 2:
    tft.print("NTC t÷C");
    break;
  case 3:
    tft.loadFont(FONT_22); 
    tft.print("Свет ");
    tft.unloadFont();
    tft.print("lux");
    break;
  case 4:
    tft.loadFont(FONT_22); 
    tft.print("Вл почвы ");
    tft.unloadFont();
    tft.print("%");
    break;
  case 5:
    tft.loadFont(FONT_22); 
    tft.print("аналог ");
    tft.unloadFont();
    tft.print("1");
    break;
  case 6:
    tft.loadFont(FONT_22); 
    tft.print("аналог ");
    tft.unloadFont();
    tft.print("2");
    break;
}
}
void Selusermodeservo2_2()
{ 
  tft.loadFont(FONT_22);
  tft.setTextSize(2);
  tft.fillRect(0,80,320,40,TFT_RED);
  tft.setCursor(10,90);
  tft.print("Направление ");
  if (usermodeservo2direction==0) tft.print("Выкл Вкл");
  else tft.print("Вкл Выкл");
  tft.unloadFont();
}

void Selusermodeservo2_3()
{
   tft.loadFont(FONT_22);
  tft.setTextSize(2);
  tft.fillRect(0,120,320,40,TFT_RED);
  tft.setCursor(10,130);
  tft.print("Пределы от ");
  tft.unloadFont();
  tft.print(servo2start);
  tft.setCursor(175,130);
  tft.loadFont(FONT_22);
  tft.print("до ");
  tft.unloadFont();
  tft.print(servo2stop);
  if(seledit==0)
    editservo2start();
  else editservo2stop();
}

void Selusermodeservo2_4()
{
  tft.loadFont(FONT_22);
  tft.setTextSize(2);
  tft.fillRect(0,160,320,40,TFT_RED);
  tft.setCursor(10,170);
  tft.print("Скорость ");
  tft.unloadFont();
  tft.print(servo2speed);
  tft.setCursor(152,170);
  tft.loadFont(FONT_22);
  tft.print("ускорение ");
  tft.unloadFont();
  tft.print(servo2acceleration,1);
  if(seledit==0)
    editservo2speed();
  else editservo2acceleration();
}

void editservo2start()
{
  tft.fillRect(137,128,36,16,TFT_BLUE);
  tft.setTextColor(TFT_WHITE);
  tft.setTextSize(2);
  tft.setCursor(138,129);
  tft.print(servo2start,0);
}

// отрисовка редактирования +- температуры авто
void editservo2stop()
{
  tft.fillRect(204,128,36,16,TFT_BLUE);
  tft.setTextColor(TFT_WHITE);
  tft.setTextSize(2);
  tft.setCursor(205,129);
  tft.print(servo2stop,0);
}

void editservo2speed()
{
  tft.fillRect(111,168,36,16,TFT_BLUE);
  tft.setTextColor(TFT_WHITE);
  tft.setTextSize(2);
  tft.setCursor(112,169);
  tft.print(servo2speed,0);
}

// отрисовка редактирования +- температуры авто
void editservo2acceleration()
{
  tft.fillRect(260,168,36,16,TFT_BLUE);
  tft.setTextColor(TFT_WHITE);
  tft.setTextSize(2);
  tft.setCursor(261,169);
  tft.print(servo2acceleration,1);
}

void setusermodeactuator(int selusermodeactuator)
{
  tft.loadFont(FONT_22); 
  tft.setTextColor(TFT_BLACK);
  tft.setTextSize(2);
  tft.fillRect(0,0,320,40,TFT_GREEN);
  tft.setCursor(10,10);
  tft.print("ПРИВОД");
  tft.fillRect(0,40,320,200,TFT_MAGENTA);
   tft.fillRect(0,200,320,40,TFT_GREEN);
  tft.setCursor(10,210);
  tft.loadFont(FONT_22);
  tft.print("Сейчас ");
  tft.setTextColor(TFT_WHITE);
  tft.unloadFont();

  tft.setCursor(10,50);
  tft.loadFont(FONT_22); 
  tft.print("Параметр ");
  tft.unloadFont();
  switch (usermodeactuatorsensor) {
  case 0:
    tft.print("t÷C");
    break;
  case 1:
    tft.loadFont(FONT_22); 
    tft.print("Вл воздуха ");
    tft.unloadFont();
    tft.print("%");
    break;
  case 2:
    tft.print("NTC t÷C");
    break;
  case 3:
    tft.loadFont(FONT_22); 
    tft.print("Свет ");
    tft.unloadFont();
    tft.print("lux");
    break;
  case 4:
    tft.loadFont(FONT_22); 
    tft.print("Вл почвы ");
    tft.unloadFont();
    tft.print("%");
    break;
  case 5:
    tft.loadFont(FONT_22); 
    tft.print("аналог ");
    tft.unloadFont();
    tft.print("1");
    break;
  case 6:
    tft.loadFont(FONT_22); 
    tft.print("аналог ");
    tft.unloadFont();
    tft.print("2");
    break;
}

  tft.loadFont(FONT_22); 
  tft.setCursor(10,90);
  tft.print("Направление ");
  if (usermodeactuatordirection==0) tft.print("Закр Откр");
  else tft.print("Закр Откр");

  tft.setCursor(10,130);
  tft.print("Время открытия ");
  tft.unloadFont();
  tft.print(actuatortimeout);
  tft.loadFont(FONT_22); 
  tft.setCursor(208,130);
  tft.print("сек");
  tft.unloadFont();
  
  if(selusermodeactuator==1)  
  Selusermodeactuator_1();
  else if(selusermodeactuator==2)  
  Selusermodeactuator_2();
  else if(selusermodeactuator==3)  
  Selusermodeactuator_3();
}

void Selusermodeactuator_1()
{
  tft.loadFont(FONT_22);
  tft.setTextSize(2);
  tft.fillRect(0,40,320,40,TFT_RED);
  tft.setCursor(10,50);
  tft.print("Параметр ");
  tft.unloadFont();
  switch (usermodeactuatorsensor) {
  case 0:
    tft.print("t÷C");
    break;
  case 1:
    tft.loadFont(FONT_22); 
    tft.print("Вл воздуха ");
    tft.unloadFont();
    tft.print("%");
    break;
  case 2:
    tft.print("NTC t÷C");
    break;
  case 3:
    tft.loadFont(FONT_22); 
    tft.print("Свет ");
    tft.unloadFont();
    tft.print("lux");
    break;
  case 4:
    tft.loadFont(FONT_22); 
    tft.print("Вл почвы ");
    tft.unloadFont();
    tft.print("%");
    break;
  case 5:
    tft.loadFont(FONT_22); 
    tft.print("аналог ");
    tft.unloadFont();
    tft.print("1");
    break;
  case 6:
    tft.loadFont(FONT_22); 
    tft.print("аналог ");
    tft.unloadFont();
    tft.print("2");
    break;
}
}
void Selusermodeactuator_2()
{ 
  tft.loadFont(FONT_22);
  tft.setTextSize(2);
  tft.fillRect(0,80,320,40,TFT_RED);
  tft.setCursor(10,90);
  tft.print("Направление ");
  if (usermodeactuatordirection==0) tft.print("Закр Откр");
  else tft.print("Откр Закр");
  tft.unloadFont();
}

void Selusermodeactuator_3()
{
   tft.loadFont(FONT_22);
  tft.setTextSize(2);
  tft.fillRect(0,120,320,40,TFT_RED);
  tft.setCursor(10,130);
  tft.print("Время открытия ");
  tft.unloadFont();
  tft.print(actuatortimeout);
  tft.loadFont(FONT_22); 
  tft.setCursor(208,130);
  tft.print("сек");
  tft.unloadFont();
  editactuatortimeout();


}



void editactuatortimeout()
{
  tft.fillRect(180,128,24,16,TFT_BLUE);
  tft.setTextColor(TFT_WHITE);
  tft.setTextSize(2);
  tft.setCursor(181,129);
  tft.print(actuatortimeout,0);
}




void selusermodesup(){
  if(mode == 221) {
      if(selusermoderelay1==2) selusermoderelay1 = 1;
      else selusermoderelay1++;
    setusermoderelay1(selusermoderelay1);
    relay1menu1=0;
    time1=0;
  }
  if(mode == 222) {
      if(selusermoderelay2==2) selusermoderelay2 = 1;
      else selusermoderelay2++;
    setusermoderelay2(selusermoderelay2);
    relay2menu1=0;
    time1=0;
  }
  if(mode == 223) {
    if(selusermodeservo1==4) selusermodeservo1 = 1;
      else selusermodeservo1++;
    setusermodeservo1(selusermodeservo1);
    servo1menu1=0;
    time1=0;
  }
  if(mode == 224) {
    if(selusermodeservo2==4) selusermodeservo2 = 1;
      else selusermodeservo2++;
    setusermodeservo2(selusermodeservo2);
    servo2menu1=0;
    time1=0;
  }
  if(mode == 225) {
    if(selusermodeactuator==3) selusermodeactuator = 1;
      else selusermodeactuator++;
    setusermodeactuator(selusermodeactuator);
    actuatormenu1=0;
    time1=0;
  }
}

void selusermodesdown(){
  if(mode == 221) {
    if(selusermoderelay1==1) selusermoderelay1 = 2;
    else selusermoderelay1--;
    setusermoderelay1(selusermoderelay1);
    relay1menu1=0;
    time1=0;
  }
  if(mode == 222) {
    if(selusermoderelay2==1) selusermoderelay2 = 2;
    else selusermoderelay2--;
    setusermoderelay2(selusermoderelay2);
    relay2menu1=0;
    time1=0;
  }
  if(mode == 223) {
    if(selusermodeservo1==1) selusermodeservo1 = 4;
    else selusermodeservo1--;
    setusermodeservo1(selusermodeservo1);
    servo1menu1=0;
    time1=0;
  }
  if(mode == 224) {
    if(selusermodeservo2==1) selusermodeservo2 = 4;
    else selusermodeservo2--;
    setusermodeservo2(selusermodeservo2);
    servo2menu1=0;
    time1=0;
  }
  if(mode == 225) {
    if(selusermodeactuator==1) selusermodeactuator = 3;
    else selusermodeactuator--;
    setusermodeactuator(selusermodeactuator);
    actuatormenu1=0;
    time1=0;
  }
}


void usermodesleft()
{
  if(mode==221) {
    if (selusermoderelay1==1) {
      if (usermoderelay1sensor==0){
        usermoderelay1sensor=6;
      }else usermoderelay1sensor--;
    }   
    if (selusermoderelay1==2) {
      if (usermoderelay1direction==0){
        usermoderelay1direction=1;
      }else usermoderelay1direction--;
    }   
    setusermoderelay1(selusermoderelay1);
    relay1menu1=0;
    time1=0;
  }

  if(mode==222) {
    if (selusermoderelay2==1) {
      if (usermoderelay2sensor==0){
        usermoderelay2sensor=6;
      }else usermoderelay2sensor--;
    }   
    if (selusermoderelay2==2) {
      if (usermoderelay2direction==0){
        usermoderelay2direction=1;
      }else usermoderelay2direction--;
    }   
    setusermoderelay2(selusermoderelay2);
    relay2menu1=0;
    time1=0;
  }

  if(mode==223) {
    if (selusermodeservo1==1) {
      if (usermodeservo1sensor==0){
        usermodeservo1sensor=6;
      }else usermodeservo1sensor--;
    }   
    if (selusermodeservo1==2) {
      if (usermodeservo1direction==0){
        usermodeservo1direction=1;
      }else usermodeservo1direction--;
    }   
    if (seledit==1) seledit=0;
    else seledit++;
    setusermodeservo1(selusermodeservo1);
    servo1menu1=0;
    time1=0;
  }

  if(mode==224) {
    if (selusermodeservo2==1) {
      if (usermodeservo2sensor==0){
        usermodeservo2sensor=6;
      }else usermodeservo2sensor--;
    }   
    if (selusermodeservo2==2) {
      if (usermodeservo2direction==0){
        usermodeservo2direction=1;
      }else usermodeservo2direction--;
    }   
    if (seledit==1) seledit=0;
    else seledit++;
    setusermodeservo2(selusermodeservo2);
    servo2menu1=0;
    time1=0;
  }

  if(mode==225) {
    if (selusermodeactuator==1) {
      if (usermodeactuatorsensor==0){
        usermodeactuatorsensor=6;
      }else usermodeactuatorsensor--;
    }   
    if (selusermodeactuator==2) {
      if (usermodeactuatordirection==0){
        usermodeactuatordirection=1;
      }else usermodeactuatordirection--;
    }   
    setusermodeactuator(selusermodeactuator);
    actuatormenu1=0;
    time1=0;
  }
}

void usermodesright()
{
  if(mode==221) {
    if (selusermoderelay1==1) {
      if (usermoderelay1sensor==6){
        usermoderelay1sensor=0;
      }else usermoderelay1sensor++;
    }   
    if (selusermoderelay1==2) {
      if (usermoderelay1direction==1){
        usermoderelay1direction=0;
      }else usermoderelay1direction++;
    }   
    setusermoderelay1(selusermoderelay1);
    relay1menu1=0;
    time1=0;
  }
  if(mode==222) {
    if (selusermoderelay2==1) {
      if (usermoderelay2sensor==6){
        usermoderelay2sensor=0;
      }else usermoderelay2sensor++;
    }   
    if (selusermoderelay2==2) {
      if (usermoderelay2direction==1){
        usermoderelay2direction=0;
      }else usermoderelay2direction++;
    }   
    setusermoderelay2(selusermoderelay2);
    relay2menu1=0;
    time1=0;
  }

  if(mode==223) {
    if (selusermodeservo1==1) {
      if (usermodeservo1sensor==6){
        usermodeservo1sensor=0;
      }else usermodeservo1sensor++;
    }   
    if (selusermodeservo1==2) {
      if (usermodeservo1direction==1){
        usermodeservo1direction=0;
      }else usermodeservo1direction++;
    }   
    if (seledit==1) seledit=0;
      else seledit++;
    setusermodeservo1(selusermodeservo1);
    servo1menu1=0;
    time1=0;
  }

  if(mode==224) {
    if (selusermodeservo2==1) {
      if (usermodeservo2sensor==6){
        usermodeservo2sensor=0;
      }else usermodeservo2sensor++;
    }   
    if (selusermodeservo2==2) {
      if (usermodeservo2direction==1){
        usermodeservo2direction=0;
      }else usermodeservo2direction++;
    }   
    if (seledit==1) seledit=0;
      else seledit++;
    setusermodeservo2(selusermodeservo2);
    servo2menu1=0;
    time1=0;
  }  

  if(mode==225) {
    if (selusermodeactuator==1) {
      if (usermodeactuatorsensor==6){
        usermodeactuatorsensor=0;
      }else usermodeactuatorsensor++;
    }   
    if (selusermodeactuator==2) {
      if (usermodeactuatordirection==1){
        usermodeactuatordirection=0;
      }else usermodeactuatordirection++;
    }   
    setusermodeactuator(selusermodeactuator);
    actuatormenu1=0;
    time1=0;
  }  
}


void usermodesencoderup()
{
  if (mode == 223){
    if(selusermodeservo1==3){
      if (seledit==0){
        if(servo1start<servo1stop-5){
          servo1start+=5;
          editservo1start();
        }
      } else {
        if(servo1stop<180){
        servo1stop+=5;
        editservo1stop();
        }
      }  
    }
    if(selusermodeservo1==4){
      if (seledit==0){
        if(servo1speed<500){
          servo1speed+=5;
          editservo1speed();
          servo1.setSpeed(servo1speed); 
        }
      } else {
        if(servo1acceleration<1){
        servo1acceleration+=0.1;
        editservo1acceleration();
        servo1.setAccel(servo1acceleration);
        }
      }
    }
  }
  if (mode == 224){
    if(selusermodeservo2==3){
      if (seledit==0){
        if(servo2start<servo2stop-5){
          servo2start+=5;
          editservo2start();
        }
      } else {
        if(servo2stop<180){
        servo2stop+=5;
        editservo2stop();
        }
      }  
    }
    if(selusermodeservo2==4){
      if (seledit==0){
        if(servo2speed<500){
          servo2speed+=5;
          editservo2speed();
          servo2.setSpeed(servo2speed); 
        }
      } else {
        if(servo2acceleration<1){
        servo2acceleration+=0.1;
        editservo2acceleration();
        servo2.setAccel(servo2acceleration);
        }
      }
    }
  }

  if (mode == 225){
    if(selusermodeactuator==3){
      if(actuatortimeout<99){
        actuatortimeout++;
        editactuatortimeout();
      }  
    }
  }
}

void usermodesencoderdown()
{
  if (mode == 223){
    if(selusermodeservo1==3){
      if (seledit==0){
        if(servo1start>0){
        servo1start-=5;
        editservo1start();
        }
      } else {
        if(servo1stop>servo1start+5){
        servo1stop-=5;
        editservo1stop();
        }
      }  
    }
    if(selusermodeservo1==4){
      if (seledit==0){
        if(servo1speed>10){
        servo1speed-=5;
        editservo1speed();
        servo1.setSpeed(servo1speed); 
        }
      } else {
        if(servo1acceleration>0.2){
        servo1acceleration-=0.1;
        editservo1acceleration();
        servo1.setAccel(servo1acceleration);
        }
      }
    }
  }
  if (mode == 224){
    if(selusermodeservo2==3){
      if (seledit==0){
        if(servo2start>0){
        servo2start-=5;
        editservo2start();
        }
      } else {
        if(servo2stop>servo2start+5){
        servo2stop-=5;
        editservo2stop();
        }
      }  
    }
    if(selusermodeservo2==4){
      if (seledit==0){
        if(servo2speed>10){
        servo2speed-=5;
        editservo2speed();
        servo2.setSpeed(servo2speed); 
        }
      } else {
        if(servo2acceleration>0.2){
        servo2acceleration-=0.1;
        editservo2acceleration();
        servo2.setAccel(servo2acceleration);
        }
      }
    }
  }

  if (mode == 225){
    if(selusermodeactuator==3){
      if(actuatortimeout>1){
        actuatortimeout--;
        editactuatortimeout();
      }  
    }
  }
}

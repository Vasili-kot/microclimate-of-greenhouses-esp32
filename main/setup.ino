void setup(){
  Serial.begin(115200);
  EEPROM.begin(1024);
  if (EEPROM.read(INIT_ADDR) != INIT_KEY) { // первый запуск
    EEPROM.write(INIT_ADDR, INIT_KEY);    // записали ключ
    EEPROM.put(0, setbrightness);
    EEPROM.put(1, displayautooff);
    EEPROM.put(2, displayautoofftime);
    EEPROM.put(3, piezoenabled);
    EEPROM.put(4, freqs);
    EEPROM.put(5, intervalsensor);
    EEPROM.put(6, BETA);
    EEPROM.put(10, gammas);
    EEPROM.put(14, r1);
    EEPROM.commit();
  }

  EEPROM.get(0, setbrightness);
  EEPROM.get(1, displayautooff);
  EEPROM.get(2, displayautoofftime);
  EEPROM.get(3, piezoenabled);
  EEPROM.get(4, freqs);
  EEPROM.get(5, intervalsensor);
  EEPROM.get(6, BETA);
  EEPROM.get(10, gammas);
  EEPROM.get(14, r1);






  //инит второго ядра
  xTaskCreatePinnedToCore(Task2code, "Task2", 100000, NULL, 1, &Task2,1);
  delay(50); 
  
  //****** проверка работы RTC
  if (! rtc.begin()) {
  Serial.println("Couldn't find RTC");
  while (1);
  }

  //****** проверка загрузки шрифтов
  if (!SPIFFS.begin()) {
  Serial.println("Ошибка инициализации SPIFFS!");
  while (1) yield(); 
  } 
  
  // настраиваем ШИМ-сигнал, используя свойства выше:
  ledcSetup(ledChannel, freq, resolution);
  // привязываем канал к GPIO-контакту, которым будем управлять:
  ledcAttachPin(ledPin, ledChannel);
  ledcWrite(ledChannel, brightness);

  // пины энкодера
  pinMode (PinA, INPUT_PULLUP);   // Как вход и внутренняя подтяжка
  pinMode (PinC, INPUT_PULLUP);   // Как вход и внутренняя подтяжка
  attachInterrupt(digitalPinToInterrupt(PinA), pinACHANGE, CHANGE);
  attachInterrupt(digitalPinToInterrupt(PinC), pinCCHANGE, CHANGE);


  //пины аналоговых датчиков
  analogReadResolution(10);
  pinMode(34,INPUT);
  pinMode(35,INPUT);
  pinMode(39,INPUT);
  pinMode(36,INPUT);
  pinMode(26,INPUT);

  dht_sensor.begin();

// расширитель портов и реле
  for(int i=0;i<8;i++) {
    pcf8574.pinMode(i, OUTPUT);
  }
  pcf8574.begin();
  for(int i=0;i<8;i++) {
    pcf8574.digitalWrite(i, HIGH);
  }
  
  //servo1.attach(33);
  //servo2.attach(32);



  servo1.attach(33, 500, 2500);  
  servo2.attach(32, 500, 2500);
  
  servo1.setSpeed(servo1speed);   // ограничить скорость
  servo1.setAccel(servo1acceleration);  	// установить ускорение (разгон и торможение)
  servo2.setSpeed(servo2speed);   // ограничить скорость
  servo2.setAccel(servo2acceleration); 
  
  servo1.setAutoDetach(false);
  servo2.setAutoDetach(false);

  readsensors();
  tempdefaultdata[NUM_POINTS - 1] = celsiusdefault;
  humiditydefaultdata[NUM_POINTS - 1] = humiditydefault;
  lightdata[NUM_POINTS - 1] = light;
  moisturedata[NUM_POINTS - 1] = moisture;
  ntcdata[NUM_POINTS - 1] = celsiusntc;
  sensor1data[NUM_POINTS - 1] = user1sensor;
  sensor2data[NUM_POINTS - 1] = user2sensor;
  
  // инит дисплея и вывод стартовой и домашней страницы
  tft.init();
  tft.setRotation(2);  // альбомная ориентация экрана
	startpage();
  HomePage();
}
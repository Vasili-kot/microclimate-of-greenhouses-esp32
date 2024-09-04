TaskHandle_t Task2;

const int ledPin = 25; //пин подсветки дисплея
const int freq = 5000;
const int ledChannel = 5;
const int resolution = 8;
int brightness = 255,brightnessold=0; //яркость подсветки от 0 до 255
uint8_t displayautooff=0, displayautoofftime=1,setbrightness=5,displayoff=0;

float tempC;
float humi;

float celsiusntc;
float celsiusdefault,celsiusdefaultold=-300;//температура
float celsiusbme,celsiusbmeold=0;
float celsiusdht,celsiusdhtold=0;
int humiditydefault, humiditydefaultold=0;
int humiditybme, humiditybmeold=0;
int humiditydht, humiditydhtold=0;
float moisture,moistureold=-1;// влажность почвы
int light,lightold=-1;// освещенность

int user1sensor,user2sensor;
float relay1sensorvalue,relay1sensorvalueold,relay2sensorvalue,relay2sensorvalueold,servo1sensorvalue,servo1sensorvalueold,servo2sensorvalue,servo2sensorvalueold,actuatorsensorvalue,actuatorsensorvalueold;


uint8_t os=0,om=0,od=0;// переменные для сравнения времени с предыдущим значением и перерисовка если отличается
uint8_t rect=0; //флаг чтобы отрисовывать страницу 1 раз
uint8_t rtc1=0,temp1=0,tempmenu1=0,lightmenu1=0,moistmenu1=0, moist1=0,light1=0,time1=0,relay1=0,humidity1=0,relay1menu1=0,relay2menu1=0,servo1menu1=0,servo2menu1=0,actuatormenu1=0; //отрисовка поля 1 раз


uint8_t intervalsensor = 1; // интервал опроса датчиков, с
uint8_t temperaturesensor = 2; //0 термистор, 1-dht11, 2-bme280
uint8_t humiditysensor = 2; //0 откл, 1-dht11, 2-bme280
uint8_t dht11status = 1;
uint8_t dht11error=0;
uint8_t bme280status = 1;
uint8_t bme280error = 0;

int mode = 0; // режим работы 0-главный экран, 1-настройки климата, 2-настройки устройства


int tempcontrolh=0,prevtempcontrolh=0,tempcontmodeh=0,temptimerhh=5,temptimerhm=30,temptimerworkhh=1,temptimerworkhm=30,temprtchh=12,temprtchm=0,temprtcworkhh=1,temprtcworkhm=0,temptimerstarthh=18,temptimerstarthm=0;
int tempcontrolc=0,prevtempcontrolc=0,tempcontmodec=0,temptimerch=0,temptimerworkch=3,temptimercm=30,temptimerworkcm=10,temprtcch=22,temprtccm=30,temprtcworkch=2,temprtcworkcm=0,temptimerstartch=10,temptimerstartcm=30;
int lightcontrol=0,prevlightcontrol=0,lightcontmode=0,lighttimerh=8,lighttimerworkh=4,lighttimerm=0,lighttimerworkm=0,lightrtch=12,lightrtcm=0,lightrtcworkh=1,lightrtcworkm=0,lighttimerstarth=10,lighttimerstartm=20;
int moistcontrol=0,prevmoistcontrol=0,moistcontmode=0,moisttimerh=8,moisttimerworkh=0,moisttimerm=0,moisttimerworkm=30,moistrtch=12,moistrtcm=0,moistrtcworkh=1,moistrtcworkm=0,moisttimerstarth=3,moisttimerstartm=30;
int relay1control=0,prevrelay1control=0,relay1contmode=0,relay1timerh=8,relay1timerworkh=4,relay1timerm=0,relay1timerworkm=0,relay1rtch=12,relay1rtcm=0,relay1rtcworkh=1,relay1rtcworkm=0,relay1timerstarth=10,relay1timerstartm=20;
int relay2control=0,prevrelay2control=0,relay2contmode=0,relay2timerh=8,relay2timerworkh=4,relay2timerm=0,relay2timerworkm=0,relay2rtch=12,relay2rtcm=0,relay2rtcworkh=1,relay2rtcworkm=0,relay2timerstarth=10,relay2timerstartm=20;
int servo1control=0,prevservo1control=0,servo1contmode=0,servo1timerh=8,servo1timerworkh=4,servo1timerm=0,servo1timerworkm=0,servo1rtch=12,servo1rtcm=0,servo1rtcworkh=1,servo1rtcworkm=0,servo1timerstarth=10,servo1timerstartm=20;
int servo2control=0,prevservo2control=0,servo2contmode=0,servo2timerh=8,servo2timerworkh=4,servo2timerm=0,servo2timerworkm=0,servo2rtch=12,servo2rtcm=0,servo2rtcworkh=1,servo2rtcworkm=0,servo2timerstarth=10,servo2timerstartm=20;
int actuatorcontrol=0,prevactuatorcontrol=0,actuatorcontmode=0,actuatortimerh=8,actuatortimerworkh=4,actuatortimerm=0,actuatortimerworkm=0,actuatorrtch=12,actuatorrtcm=0,actuatorrtcworkh=1,actuatorrtcworkm=0,actuatortimerstarth=10,actuatortimerstartm=20;

uint8_t seledit=0;

float tempuser=25.0,tempplus=1.0;
int lightuser=1000,lightplus=100;
int moistuser=50,moistplus=5;
int relay1user=1000, relay1plus=100;
int relay2user=1000, relay2plus=100;
int servo1user=1000, servo1plus=100;
int servo2user=1000, servo2plus=100;
int actuatoruser=1000, actuatorplus=100;

int selection = 1,selclimat = 1, seltemph=1,seltempc=1,sellight=1,selmoist=1,seldisplay=1,selsound=1,selsensors=1,selbme=1,seldht=1,selntc=1,selldr=1,selphotores=1,selrestart=1,selreset=1,seldatetime=1,selusermodes=1;
int selusermoderelay1=1,selusermoderelay2=1,selusermodeservo1=1,selusermodeservo2=1,selusermodeactuator=1,selrelay1=1,selrelay2=1,selservo1=1,selservo2=1,selactuator=1;
int hournow=0,minutenow=0;



int usermoderelay1sensor=0,usermoderelay1direction=0;
int usermoderelay2sensor=0,usermoderelay2direction=0;
int usermodeservo1sensor=0,usermodeservo1direction=0,servo1start=100,servo1stop=150,servo1speed=100;
float servo1acceleration=0.2;
int usermodeservo2sensor=0,usermodeservo2direction=0,servo2start=120,servo2stop=170,servo2speed=150;
float servo2acceleration=0.1;
int usermodeactuatorsensor=0,usermodeactuatordirection=0,actuatortimeout=5;

int actuatoropened = 0;
unsigned long actuatorstartmillis = 0;
int actuatorstart = 0;



/*----------------------------------I2C и rtc-----------------------*/
#include <Wire.h>
#include "RTClib.h"
RTC_DS3231 rtc;
const char* daysOfTheWeek[] = {"Воскресенье", "Понедельник", "Вторник", "Среда", "Четверг", "Пятница", "Суббота"};
const char* monthh[] = {" ЯНВАРЯ ", " ФЕВРАЛЯ ", " МАРТА ", " АПРЕЛЯ ", " МАЯ ", " ИЮНЯ ", " ИЮЛЯ ", " АВГУСТА ", " СЕНТЯБРЯ ", " ОКТЯБРЯ ", " НОЯБРЯ ", " ДЕКАБРЯ ",};
int newyear=2000,newmonth=1,newday=1,newhour=0,newminute=0,newsecond=0,seledittime=1;
/*----------------------------------I2C и rtc-----------------------*/



#include <ServoSmooth.h>
ServoSmooth servo1;
ServoSmooth servo2;

//#include <ESP32Servo.h>
//Servo servo1;
//Servo servo2;







#define INIT_ADDR 1001  // номер резервной ячейки
#define INIT_KEY 55     // ключ первого запуска. 0-254, на выбор
#include <EEPROM.h>
#include <Adafruit_Sensor.h>
#include <Adafruit_BME280.h>
#include <DHT.h>
#define DHT_SENSOR_PIN  14 
#define DHT_SENSOR_TYPE DHT11

DHT dht_sensor(DHT_SENSOR_PIN, DHT_SENSOR_TYPE);

Adafruit_BME280 bme;
/*----------------------------------I2C расширитель портов и реле----------------------*/
#include "PCF8574.h"  
 
PCF8574 pcf8574(0x20);

const int relaycount = 8;
int relaypinuser1=6;
int relaypinuser2=7;
int relaypinmotor1=4;
int relaypinmotor2=5;
int relaypinheater=0;
int relaypincooler=1;
int relaypinmoist=3;
int relaypinlight=2;
int relayPins[] = {relaypinuser1, relaypinuser2, relaypinmotor1, relaypinmotor2, relaypinheater, relaypincooler,relaypinlight,relaypinmoist}; // пины подключения реле
int r[] = {0,0,0,0};



uint32_t timetoms(int timeh, int timem){  //преобразует время типа ЧЧ:ММ в силлисекунды
  return timeh*3600000+timem*60000;
}
/*----------------------------------Получение значений с датичков на втором ядре----------------------*/
float gammas = 0.6;
int r1 = 200;
int BETA = 3950;  // коэффициент термистора

int temprtchen = 0,  temprtchhend = 0, temprtchmend = 0, prevmillistimerh=0, temptimerhen=0, temptimerhstarted=0;
uint32_t temptimerintervalh=0;

int temprtccen = 0,temprtcchend = 0, temprtccmend = 0, prevmillistimerc=0, temptimercen=0, temptimercstarted=0;
uint32_t temptimerintervalc=0;

int lightrtcen = 0,  lightrtchend = 0, lightrtcmend = 0,prevmillistimerlight=0, lighttimeren=0, lighttimerstarted=0;
uint32_t lighttimerinterval=0;

int moistrtcen = 0,moistrtchend = 0, moistrtcmend = 0,prevmillistimermoist=0, moisttimeren=0, moisttimerstarted=0;
uint32_t moisttimerinterval=0;

int relay1rtcen = 0,relay1rtchend = 0, relay1rtcmend = 0,prevmillistimerrelay1=0,relay1timeren=0, relay1timerstarted=0;
uint32_t relay1timerinterval=0;

int relay2rtcen = 0,relay2rtchend = 0, relay2rtcmend = 0,prevmillistimerrelay2=0,relay2timeren=0, relay2timerstarted=0;
uint32_t relay2timerinterval=0;

int servo1rtcen = 0,servo1rtchend = 0, servo1rtcmend = 0,prevmillistimerservo1=0,servo1timeren=0, servo1timerstarted=0;
uint32_t servo1timerinterval=0;

int servo2rtcen = 0,servo2rtchend = 0, servo2rtcmend = 0,prevmillistimerservo2=0,servo2timeren=0, servo2timerstarted=0;
uint32_t servo2timerinterval=0;

int actuatorrtcen = 0,actuatorrtchend = 0, actuatorrtcmend = 0,prevmillistimeractuator=0,actuatortimeren=0, actuatortimerstarted=0;
uint32_t actuatortimerinterval=0;





unsigned long previousMillissensor = 0,previousMillisrelay=0, prevmillisdisplay=0,previousMillisgraphics=0;
int intervalrelay = 25;



#define NUM_POINTS 1440  // 60 точек в минуту за 24 часа
// Массивы для хранения данных с датчика
float tempdefaultdata[NUM_POINTS];
float humiditydefaultdata[NUM_POINTS]; // Значения с датчика
float lightdata[NUM_POINTS];
float moisturedata[NUM_POINTS];
float ntcdata[NUM_POINTS];
float sensor1data[NUM_POINTS];
float sensor2data[NUM_POINTS];




void Task2code( void * pvParameters ){

  for(;;){
    unsigned long currentMillis = millis();  

    if (currentMillis - previousMillissensor >= intervalsensor*1000) {
      previousMillissensor = currentMillis;
      readsensors(); // опрос датчиков
    }

    if (currentMillis - previousMillisgraphics >= 60000) {
      previousMillisgraphics = currentMillis;
      for (int i = 0; i < NUM_POINTS - 1; i++) {
        tempdefaultdata[i] = tempdefaultdata[i + 1];
        humiditydefaultdata[i] = humiditydefaultdata[i + 1];
        lightdata[i] = lightdata[i + 1];
        moisturedata[i] = moisturedata[i + 1];
        ntcdata[i] = ntcdata[i + 1];
        sensor1data[i] = sensor1data[i + 1];
        sensor2data[i] = sensor2data[i + 1];
      }
      
      tempdefaultdata[NUM_POINTS - 1] = celsiusdefault;
      humiditydefaultdata[NUM_POINTS - 1] = humiditydefault;
      lightdata[NUM_POINTS - 1] = light;
      moisturedata[NUM_POINTS - 1] = moisture;
      ntcdata[NUM_POINTS - 1] = celsiusntc;
      sensor1data[NUM_POINTS - 1] = user1sensor;
      sensor2data[NUM_POINTS - 1] = user2sensor;
    }



    if (currentMillis - previousMillisrelay >= intervalrelay) {
      previousMillisrelay = currentMillis;


      temptimeendh(temprtchh,temprtchm,temprtcworkhh,temprtcworkhm);
      if (tempcontmodeh!=2) temprtchen = 0;
      if (tempcontmodeh!=1) 
      {
        temptimerhen=0; 
        temptimerhstarted=0;
      }   
      if (temptimerhen==0) temptimerintervalh = timetoms(temptimerhh,temptimerhm);
      else temptimerintervalh = timetoms(temptimerworkhh,temptimerworkhm);
      temprelayh(currentMillis);

      temptimeendc(temprtcch,temprtccm,temprtcworkch,temprtcworkcm);
      if (tempcontmodec!=2) temprtccen = 0;
      if (tempcontmodec!=1)
      {
        temptimercen=0;
        temptimercstarted=0;
      }     
      if (temptimercen==0) temptimerintervalc = timetoms(temptimerch,temptimercm);
      else temptimerintervalc = timetoms(temptimerworkch,temptimerworkcm);
      temprelayc(currentMillis);

      lighttimeend(lightrtch,lightrtcm,lightrtcworkh,lightrtcworkm);
      if (lightcontmode!=2) lightrtcen = 0;
      if (lightcontmode!=1) 
      {
        lighttimeren=0; 
        lighttimerstarted=0;
      } 
      if (lighttimeren==0) lighttimerinterval = timetoms(lighttimerh,lighttimerm);
      else lighttimerinterval = timetoms(lighttimerworkh,lighttimerworkm);
      lightrelay(currentMillis);

      moisttimeend(moistrtch,moistrtcm,moistrtcworkh,moistrtcworkm);
      if (moistcontmode!=2) moistrtcen = 0;
      if (moistcontmode!=1)
      {
        moisttimeren=0;
        moisttimerstarted=0;
      } 
      if (moisttimeren==0) moisttimerinterval = timetoms(moisttimerh,moisttimerm);
      else moisttimerinterval = timetoms(moisttimerworkh,moisttimerworkm);
      moistrelay(currentMillis);

      relay1timeend(relay1rtch,relay1rtcm,relay1rtcworkh,relay1rtcworkm);
      if (relay1contmode!=2) relay1rtcen = 0;
      if (relay1contmode!=1)
      {
        relay1timeren=0;
        relay1timerstarted=0;
      } 
      if (relay1timeren==0) relay1timerinterval = timetoms(relay1timerh,relay1timerm);
      else relay1timerinterval = timetoms(relay1timerworkh,relay1timerworkm);
      relay1relay(currentMillis);

      relay2timeend(relay2rtch,relay2rtcm,relay2rtcworkh,relay2rtcworkm);
      if (relay2contmode!=2) relay2rtcen = 0;
      if (relay2contmode!=1)
      {
        relay2timeren=0;
        relay2timerstarted=0;
      } 
      if (relay2timeren==0) relay2timerinterval = timetoms(relay2timerh,relay2timerm);
      else relay2timerinterval = timetoms(relay2timerworkh,relay2timerworkm);
      relay2relay(currentMillis);

      servo1timeend(servo1rtch,servo1rtcm,servo1rtcworkh,servo1rtcworkm);
      if (servo1contmode!=2) servo1rtcen = 0;
      if (servo1contmode!=1)
      {
        servo1timeren=0;
        servo1timerstarted=0;
      } 
      if (servo1timeren==0) servo1timerinterval = timetoms(servo1timerh,servo1timerm);
      else servo1timerinterval = timetoms(servo1timerworkh,servo1timerworkm);
      servo1relay(currentMillis);

      servo2timeend(servo2rtch,servo2rtcm,servo2rtcworkh,servo2rtcworkm);
      if (servo2contmode!=2) servo2rtcen = 0;
      if (servo2contmode!=1)
      {
        servo2timeren=0;
        servo2timerstarted=0;
      } 
      if (servo2timeren==0) servo2timerinterval = timetoms(servo2timerh,servo2timerm);
      else servo2timerinterval = timetoms(servo2timerworkh,servo2timerworkm);
      servo2relay(currentMillis);

      actuatortimeend(actuatorrtch,actuatorrtcm,actuatorrtcworkh,actuatorrtcworkm);
      if (actuatorcontmode!=2) actuatorrtcen = 0;
      if (actuatorcontmode!=1)
      {
        actuatortimeren=0;
        actuatortimerstarted=0;
      } 
      if (actuatortimeren==0) actuatortimerinterval = timetoms(actuatortimerh,actuatortimerm);
      else actuatortimerinterval = timetoms(actuatortimerworkh,actuatortimerworkm);
      actuatorrelay(currentMillis);

    }
  }
}


/*----------------------------------шрифты из SPIFFS и инициализация дисплея TFT_eSPI-----------------------*/
#define FONT_12 "arial12"
#define FONT_14 "arial14"
#define FONT_16 "arial16"
#define FONT_18 "arial18"
#define FONT_20 "arial20"
#define FONT_22 "arial22"
#define FONT_25 "arial25"
#define FONT_30 "arial30"

#include <SPI.h>
#include "TFT_eSPI.h"

// Use hardware SPI
TFT_eSPI tft = TFT_eSPI();
/*----------------------------------шрифты из SPIFFS и инициализация дисплея TFT_eSPI------------------------*/





/*----------------------------------Инициализация и работа энкодера------------------------------------------*/
#define PinA 13               // контат AB
#define PinC 12               // контат BC

uint8_t pinA = 0;             // состояние контата AB
uint8_t pinC = 0;             // состояние контата BC

uint8_t blockA = false;       // блокировка прерывания на контакте AB
uint8_t blockC = false;       // блокировка прерывания на контакте BC

uint8_t encoderResult = 0;    // Результирующая переменная
int16_t encoderCount = 0;     // Счетчик щелчков энкодера
int16_t oldencoderCount = 0;  // Счетчик старое значение

void encoderFilter () {
  encoderResult = encoderResult & B00001111;
  if (encoderResult == B1011) encoderCount ++;  // по часовой стрелке
  if (encoderResult == B0111) encoderCount --;  // против часосовой стрелки
  }
void pinACHANGE () {          // Изменилось состояние контакта АB
  if (blockA == true) return;
  pinA = !digitalRead(PinA);
  pinC = !digitalRead(PinC);  
  encoderResult  <<= 1;
  bitWrite(encoderResult, 0, pinA);
  encoderResult  <<= 1;
  bitWrite(encoderResult, 0, pinC);
  encoderFilter();  
  if (!pinA && !pinC) blockA = false; else blockA = true; 
  blockC = false;
}
void pinCCHANGE () {          // Изменилось состояние контакта BC
  if (blockC == true) return;
  pinA = !digitalRead(PinA);
  pinC = !digitalRead(PinC);  
  encoderResult  <<= 1;
  bitWrite(encoderResult, 0, pinA);
  encoderResult  <<= 1;
  bitWrite(encoderResult, 0, pinC);
  encoderFilter(); 
  if (!pinA && !pinC) blockC = false; else blockC = true; 
  blockA = false;
}
/*----------------------------------Инициализация и работа энкодера----------------------------------------*/


//пьезодинамик//
uint8_t piezoenabled = 1, freqs = 3;
int piezoPin = 19;
int freqtone = 500+500*(freqs-1);
//пьезодинамик//



/*----------------------------------Инициализация клавиатуры-----------------------------------------------*/
#include <Keypad.h>
 
#define ROWS  3
#define COLS  3
 
char keyMap[ROWS][COLS] = {
  {'1','2','3'},
  {'4','5','6'},
  {'7','8','9'}
};
 
uint8_t rowPins[ROWS] = {4, 16, 17}; 
uint8_t colPins[COLS] = {0, 2, 15}; 

Keypad keypad = Keypad(makeKeymap(keyMap), rowPins, colPins, ROWS, COLS );

/*----------------------------------Инициализация клавиатуры-----------------------------------------------*/


 

void loop(){
  servo1.tick();
  servo2.tick();
  unsigned long currentMillis = millis();  
  DateTime now = rtc.now();
  hournow=now.hour();
  minutenow=now.minute();
  char key = keypad.getKey();
  if (key) {
    if (displayoff==1){
      displayoff=0;
      ledcWrite(ledChannel, brightness);
    }
    prevmillisdisplay = currentMillis;

    if (piezoenabled){
      freqtone = 500+500*(freqs-1);
      tone(piezoPin, freqtone, 100);
    } 
    if((key=='1')&&(mode==0)) {
      mode = 1;
      setclimat(selclimat);
    }

    if((key=='3')&&(mode==0)) {
      mode = 2;
      settings(selection);
    }

    if(key=='5'){
      if (mode==1) {
        if (selclimat==1){
        mode = 11;
        settemperatureh(seltemph);
        }
        if (selclimat==2){
        mode = 12;
        settemperaturec(seltempc);
        }
        if (selclimat==3){
        mode = 13;
        setlight(sellight);
        }
        if (selclimat==4){
        mode = 14;
        setmoisture(selmoist);
        }
        if (selclimat==5){
        mode = 15;
        setrelay1(selrelay1);
        }
        if (selclimat==6){
        mode = 16;
        setrelay2(selrelay2);
        }
        if (selclimat==7){
        mode = 17;
        setservo1(selservo1);
        }
        if (selclimat==8){
        mode = 18;
        setservo2(selservo2);
        }
        if (selclimat==9){
        mode = 19;
        setactuator(selactuator);
        }
        time1=0;
        tempmenu1=0;
        lightmenu1=0;
        moistmenu1=0;
      }
      settingsok();
    }

    if((key=='7')&&(mode!=0)) {
      if ((mode == 1)||(mode==2)){
        mode = 0;
        rect=0;
        rtc1=0;
        temp1=0;
        moist1=0;
        light1=0;
        time1=0;
        relay1=0;
        humidity1=0;
        selection = 1;
        selclimat = 1;
        seltemph=1;
        seltempc=1;
        seledit=0;
        tempmenu1=0;
        lightmenu1=0;
        moistmenu1=0;
        relay1menu1=0;
        relay2menu1=0;
        servo1menu1=0;
        servo2menu1=0;
        actuatormenu1=0;
      }
      if ((mode >= 11)&&(mode < 20)){
        setclimat(selclimat);
        mode = 1;
        time1=0;
        tempmenu1=0;
        lightmenu1=0;
        moistmenu1=0;
        relay1menu1=0;
        relay2menu1=0;
        servo1menu1=0;
        servo2menu1=0;
        actuatormenu1=0;
      }
      if ((mode >= 21)&&(mode < 30)){
        settings(selection);
        mode = 2;
        time1=0;
        tempmenu1=0;
        lightmenu1=0;
        moistmenu1=0;
        relay1menu1=0;
        relay2menu1=0;
        servo1menu1=0;
        servo2menu1=0;
        actuatormenu1=0;
      }
      if ((mode >=210 )&&(mode < 220)){
        settingssensors(selsensors);
        mode = 21;
        time1=0;
      }
       if ((mode >=220 )&&(mode < 230)){
        settingsusermodes(selusermodes);
        mode = 22;
        time1=0;
      }
    }

    if((key=='9')&&(mode!=0)) {
      mode = 0;
      rect=0;
      rtc1=0;
      temp1=0;
      moist1=0;
      light1=0;
      time1=0;
      relay1=0;
      humidity1=0;
      selection = 1;
      selclimat = 1;
      seltemph=1;
      seltempc=1;
      seledit=0;
      tempmenu1=0;
      lightmenu1=0;
      moistmenu1=0;
      relay1menu1=0;
      relay2menu1=0;
      servo1menu1=0;
      servo2menu1=0;
      actuatormenu1=0;
    }

    if(key=='8'){
      if (mode==41){
        mode = 0;
        rect=0;
        rtc1=0;
        temp1=0;
        moist1=0;
        light1=0;
        time1=0;
        relay1=0;
        humidity1=0;
      } else
      if (mode==42){
        mode = 41;
        drawGraphicHour(tempdefaultdata, "ТЕМПЕР ЧАС");
        time1=0;
      }else
      if (mode==43){
        mode = 42;
        drawGraphicHour(humiditydefaultdata, "ВЛ ВОЗД ЧАС");
        time1=0;
      }else
      if (mode==44){
        mode = 43;
        drawGraphicHour(lightdata, "СВЕТ ЧАС");
        time1=0;
      }else
      if (mode==45){
        mode = 44;
        drawGraphicHour(moisturedata, "ВЛ ПОЧВЫ ЧАС");
        time1=0;
      }else
      if (mode==46){
        mode = 45;
        drawGraphicHour(ntcdata, "ТЕРМИСТОР ЧАС");
        time1=0;
      }else
      if (mode==47){
        mode = 46;
        drawGraphicHour(sensor1data, "ДАТЧИК А ЧАС");
        time1=0;
      } else

      if (mode==0){
        mode = 31;
        drawGraphicDay(tempdefaultdata, "ТЕМПЕР СУТКИ");
        time1=0;
      } else
      if (mode==31){
        mode = 32;
        drawGraphicDay(humiditydefaultdata, "ВЛ ВОЗД СУТКИ");
        time1=0;
      }else
      if (mode==32){
        mode = 33;
        drawGraphicDay(lightdata, "СВЕТ СУТКИ");
        time1=0;
      }else
      if (mode==33){
        mode = 34;
        drawGraphicDay(moisturedata, "ВЛ ПОЧВЫ СУТКИ");
        time1=0;
      }else
      if (mode==34){
        mode = 35;
        drawGraphicDay(ntcdata, "ТЕРМИСТОР СУТКИ");
        time1=0;
      }else
      if (mode==35){
        mode = 36;
        drawGraphicDay(sensor1data, "ДАТЧИК А СУТКИ");
        time1=0;
      }else
      if (mode==36){
        mode = 37;
        drawGraphicDay(sensor2data, "ДАТЧИК Б СУТКИ");
        time1=0;
      }
      
      
      else
      if(mode == 1) {
        if(selclimat==9){
          selclimat = 1;
        } else{
          selclimat++;
        }
        setclimat(selclimat);
        time1=0;
      } else
      if(mode == 2) {
        if(selection==7){
          selection = 1;
        } else{
          selection++;
        }
        settings(selection);
        time1=0;
      } 
      seltempuph();
      seltempupc();
      sellightup();
      selmoistup();
      usermodesclimatup();
      selsettingsup();
      selusermodesup();
    } 

    if(key=='2'){
      if (mode==31){
        mode = 0;
        rect=0;
        rtc1=0;
        temp1=0;
        moist1=0;
        light1=0;
        time1=0;
        relay1=0;
        humidity1=0;
      } else
      if (mode==32){
        mode = 31;
        drawGraphicDay(tempdefaultdata, "ТЕМПЕР СУТКИ");
        time1=0;
      }else
      if (mode==33){
        mode = 32;
        drawGraphicDay(humiditydefaultdata, "ВЛ ВОЗД СУТКИ");
        time1=0;
      }else
      if (mode==34){
        mode = 33;
        drawGraphicDay(lightdata, "СВЕТ СУТКИ");
        time1=0;
      }else
      if (mode==35){
        mode = 34;
        drawGraphicDay(moisturedata, "ВЛ ПОЧВЫ СУТКИ");
        time1=0;
      }else
      if (mode==36){
        mode = 35;
        drawGraphicDay(ntcdata, "ТЕРМИСТОР СУТКИ");
        time1=0;
      }else
      if (mode==37){
        mode = 36;
        drawGraphicDay(sensor1data, "ДАТЧИК А СУТКИ");
        time1=0;
      }else
      if (mode==0){
        mode = 41;
        drawGraphicHour(tempdefaultdata, "ТЕМПЕР ЧАС");
        time1=0;
      } else
      if (mode==41){
        mode = 42;
        drawGraphicHour(humiditydefaultdata, "ВЛ ВОЗД ЧАС");
        time1=0;
      }else
      if (mode==42){
        mode = 43;
        drawGraphicHour(lightdata, "СВЕТ ЧАС");
        time1=0;
      }else
      if (mode==43){
        mode = 44;
        drawGraphicHour(moisturedata, "ВЛ ПОЧВЫ ЧАС");
        time1=0;
      }else
      if (mode==44){
        mode = 45;
        drawGraphicHour(ntcdata, "ТЕРМИСТОР ЧАС");
        time1=0;
      }else
      if (mode==45){
        mode = 46;
        drawGraphicHour(sensor1data, "ДАТЧИК А ЧАС");
        time1=0;
      }else
      if (mode==46){
        mode = 47;
        drawGraphicHour(sensor2data, "ДАТЧИК Б ЧАС");
        time1=0;
      }


      if(mode == 1) {
        if(selclimat==1){
          selclimat = 9;
        } else{
        selclimat--;
        }
        setclimat(selclimat);  
        time1=0;    
      } else
      if(mode == 2) {
        if(selection==1){
          selection = 7;
        } else{
        selection--;
        }
        settings(selection);
        time1=0;
      } 
      seltempdownh();
      seltempdownc();
      sellightdown();
      selmoistdown();
      usermodesclimatdown();


      selsettingsdown();
      selusermodesdown();
    } 

    if(key=='4'){
      templefth();
      templeftc();
      lightleft();
      moistleft();
      usermodesclimatleft();
      settingsleft();
      usermodesleft();
    }



    if(key=='6'){
      temprighth();
      temprightc();
      lightright();
      moistright();
      usermodesclimatright();
      settingsright();
      usermodesright();
    }

  }

  if (mode == 0)
    HomePage();
  if (mode != 0)
    displaytime();
  if ((mode==11)||(mode==12))
    displaytempmenu();
  if (mode==13||mode==215)
    displaylightmenu();
  if (mode==14)
    displaymoistmenu();
  if (mode==15||mode==221)
    displayrelay1menu();
  if (mode==16||mode==222)
    displayrelay2menu();
  if (mode==17)
    displayservo1menu();
  if (mode==18)
    displayservo2menu();
  if (mode==19||mode==225)
    displayactuatormenu();



  if (oldencoderCount != encoderCount) {
    if (displayoff==1){
      displayoff=0;
      ledcWrite(ledChannel, brightness);
    }
    prevmillisdisplay = currentMillis;
    if (piezoenabled){
      freqtone = 500+500*(freqs-1);
      tone(piezoPin, freqtone, 10);
    } 
    if(oldencoderCount < encoderCount){            //увеличение
      tempencoderuph();
      tempencoderupc();
      lightencoderup();
      moistencoderup();
      usermodesclimatencoderup();
      settingsencoderup();
      usermodesencoderup();
    }


    if(oldencoderCount > encoderCount){               //уменьшение
      tempencoderdownh();
      tempencoderdownc();
      lightencoderdown();
      moistencoderdown();
      usermodesclimatencoderdown();
      settingsencoderdown();
      usermodesencoderdown();
    }
    oldencoderCount = encoderCount;
  }
brightness = setbrightness*51;
displayauto(currentMillis);

}
float prevtempdef=0,ntctemp=0;
  int prevhumidef=0;
void readsensors()
{
  float bmetemp=0,dhttemp=0;
  int bmehumi=0,dhthumi=0;
  
  humi  = dht_sensor.readHumidity();
  tempC = dht_sensor.readTemperature();


  if (bme280status){
    if(!bme.begin(0x76)){
      if (bme280error<3) bme280error++;
    } else bme280error=0;
    if (bme280error==3){
      bme280status = 0;
      selbme=1;
      bme280error=0;
    }
  }
  if (dht11status){
    if( isnan(tempC) || isnan(humi)){
      if (dht11error<3) dht11error++;
    } else dht11error=0;
    if (dht11error==3){
      dht11status = 0;
      seldht=1;
      dht11error=0;
    }
  }


  if (!bme280status){
    if(temperaturesensor==2)
      if (dht11status){
      temperaturesensor=1;
    }else temperaturesensor=0;
    if(humiditysensor==2)
      if (dht11status){
      humiditysensor=1;
    }else humiditysensor=0;
  }
  if (!dht11status){
    if(temperaturesensor==1)
      if (bme280status){
      temperaturesensor=2;
    }else temperaturesensor=0;
    if(humiditysensor==1)
      if (bme280status){
      humiditysensor=2;
    }else humiditysensor=0;
  }
  if (temperaturesensor==0&&ntctemp<-100){
    if (bme280status){
      temperaturesensor=2;
    } else if (dht11status){
      temperaturesensor=1;
    }
  }

  int analogValue1 = analogRead(34); // ПИН подключения термистора


  if (temperaturesensor==0){
    ntctemp = 1 / (log(1 / (1023. / analogValue1 - 1)) / BETA + 1.0 / 298.15) - 273.15;
    if(ntctemp<-50||ntctemp>100||isnan(ntctemp))
    {
      celsiusdefault = 0;
    } else {
      celsiusdefault=ntctemp;
      prevtempdef = celsiusdefault;
    }
  } else if (temperaturesensor==1)
  { 
    dhttemp = tempC;
    if(dhttemp<-50||dhttemp>100||isnan(dhttemp))
    {
      celsiusdefault = prevtempdef;
    } else {
      celsiusdefault=dhttemp;
      prevtempdef = celsiusdefault;
    }
    
  } else if (temperaturesensor==2)
  {
    bmetemp = bme.readTemperature();
    if(bmetemp<-50||bmetemp>100||isnan(bmetemp))
    {
      celsiusdefault = prevtempdef;
    } else {
      celsiusdefault = bmetemp;
      prevtempdef = celsiusdefault;
    }
  }

  if (humiditysensor==0){
    humiditydefault = 0;
  } else if (humiditysensor==1)
  {
    dhthumi = humi;
    if(dhthumi<0||dhthumi>=100||isnan(dhthumi))
    {
      humiditydefault = prevhumidef;
    } else {
      humiditydefault=dhthumi;
      prevhumidef = humiditydefault;
    }
  } else if (humiditysensor==2)
  {
    bmehumi = bme.readHumidity();
    if(bmehumi<0||bmehumi>=100||isnan(bmehumi))
    {
      humiditydefault = prevhumidef;
    } else {
      humiditydefault = bmehumi;
      prevhumidef = humiditydefault;
    }
  }
  

  
  celsiusntc = 1 / (log(1 / (1023. / analogValue1 - 1)) / BETA + 1.0 / 298.15) - 273.15;
  if (celsiusntc<-100)celsiusntc=0;

  
  int analogValue2 = analogRead(35); // ПИН подключения влажности
  moisture = 100-((float)analogValue2/1023*100);

  int analogValue3 = analogRead(39); // ПИН подключения света
  float R=(float)((analogValue3*10000)/(1024-analogValue3));
  light = pow(10, (log10(r1*1000/R)/gammas));
  if (light>9999) light = 9999;

  // Пользовательские датчики
  int analogValue4 = analogRead(36); 
  user1sensor = analogValue4;
  int analogValue5 = analogRead(26); 
  user2sensor = analogValue5;

  switch (usermoderelay1sensor) {
  case 0:
    relay1sensorvalue = celsiusdefault;
    break;
  case 1:
    relay1sensorvalue = humiditydefault;
    break;
  case 2:
    relay1sensorvalue = celsiusntc;
    break;
  case 3:
    relay1sensorvalue = light;
    break;
  case 4:
    relay1sensorvalue = moisture;
    break;
  case 5:
    relay1sensorvalue = user1sensor;
    break;
  case 6:
    relay1sensorvalue = user2sensor;
    break;
}
switch (usermoderelay2sensor) {
  case 0:
    relay2sensorvalue = celsiusdefault;
    break;
  case 1:
    relay2sensorvalue = humiditydefault;
    break;
  case 2:
    relay2sensorvalue = celsiusntc;
    break;
  case 3:
    relay2sensorvalue = light;
    break;
  case 4:
    relay2sensorvalue = moisture;
    break;
  case 5:
    relay2sensorvalue = user1sensor;
    break;
  case 6:
    relay2sensorvalue = user2sensor;
    break;
}
switch (usermodeservo1sensor) {
  case 0:
    servo1sensorvalue = celsiusdefault;
    break;
  case 1:
    servo1sensorvalue = humiditydefault;
    break;
  case 2:
    servo1sensorvalue = celsiusntc;
    break;
  case 3:
    servo1sensorvalue = light;
    break;
  case 4:
    servo1sensorvalue = moisture;
    break;
  case 5:
    servo1sensorvalue = user1sensor;
    break;
  case 6:
    servo1sensorvalue = user2sensor;
    break;
}
switch (usermodeservo2sensor) {
  case 0:
    servo2sensorvalue = celsiusdefault;
    break;
  case 1:
    servo2sensorvalue = humiditydefault;
    break;
  case 2:
    servo2sensorvalue = celsiusntc;
    break;
  case 3:
    servo2sensorvalue = light;
    break;
  case 4:
    servo2sensorvalue = moisture;
    break;
  case 5:
    servo2sensorvalue = user1sensor;
    break;
  case 6:
    servo2sensorvalue = user2sensor;
    break;
}
switch (usermodeactuatorsensor) {
  case 0:
    actuatorsensorvalue = celsiusdefault;
    break;
  case 1:
    actuatorsensorvalue = humiditydefault;
    break;
  case 2:
    actuatorsensorvalue = celsiusntc;
    break;
  case 3:
    actuatorsensorvalue = light;
    break;
  case 4:
    actuatorsensorvalue = moisture;
    break;
  case 5:
    actuatorsensorvalue = user1sensor;
    break;
  case 6:
    actuatorsensorvalue = user2sensor;
    break;
}
}

void displayauto(unsigned long currentMillis)
{
  if(displayoff==0){
    brightness = setbrightness*51;
    if(brightness != brightnessold){   
      // меняем яркость светодиода при помощи ШИМ:
      brightnessold = brightness; 
      ledcWrite(ledChannel, brightness);
      delay(15);
    }
    if (displayautooff==1)
    {
      if (currentMillis - prevmillisdisplay >= displayautoofftime*60000) {
      prevmillisdisplay = currentMillis;
      displayoff=1;
      }
    }
  }
  else if (displayoff==1)
  {
    ledcWrite(ledChannel, 0);
  }
}


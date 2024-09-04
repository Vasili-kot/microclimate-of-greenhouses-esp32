void drawGraphicDay(float data[], const char* title) {
  tft.fillScreen(TFT_BLACK);
  tft.loadFont(FONT_22); 
  tft.setTextColor(TFT_BLACK);
  tft.setTextSize(2);
  tft.fillRect(0,0,320,40,TFT_GREEN);
  tft.setCursor(10,10);
  tft.print(title);
  tft.unloadFont();

  tft.drawLine(39, 221, 39, 45, TFT_WHITE);
  tft.drawLine(39, 221, 310, 221, TFT_WHITE);

  for (int i=0; i<5; i++) {
    tft.drawLine(35, i*40+55, 39, i*40+55, TFT_WHITE);
  }

  for (int i=0; i<24; i++) {
    tft.drawLine(i*11+40, 222, i*11+40, 225, TFT_WHITE);
  }

  float minValue = data[0];
  float maxValue = data[0];
  for (int i = 1; i < NUM_POINTS; i++) {
    if (data[i] < minValue) {
      minValue = data[i];
    }
    if (data[i] > maxValue) {
      maxValue = data[i];
    }
  }

  int hour;
  tft.setTextSize(1);
  tft.setTextColor(TFT_WHITE);
  tft.fillRect(0,50,34,220,TFT_BLACK);
  for (int i=0; i<5; i++) {
    tft.setCursor(5, i*40+50);
    if (i<4) tft.print(maxValue-((maxValue-minValue)/4*i), (strcmp(title, "ТЕМПЕР СУТКИ") == 0 || strcmp(title, "ТЕРМИСТОР СУТКИ") == 0) ? 1 : 0);
    else if (i==4) tft.print(minValue, (strcmp(title, "ТЕМПЕР СУТКИ") == 0 || strcmp(title, "ТЕРМИСТОР СУТКИ") == 0) ? 1 : 0);
  }

  tft.fillRect(35,226,280,14,TFT_BLACK);
  for (int i=12; i>0; i--) {
    tft.setCursor(((12-i)*22)+37, 227);
    hour = (hournow-i*2)+1;
    if (hour < 0) {
      hour = 24 - abs(hour);
    }
    tft.print(hour);
  }

  float xScale = 264.0 / (NUM_POINTS - 1); // Size scale by X
  float yScale = 160.0 / (maxValue - minValue); // Size scale by Y

  tft.setTextColor(TFT_GREEN);
  tft.setTextSize(1);

  for (int i = 1; i < NUM_POINTS; i++) {
    int x1 = 40 + (i - 1) * xScale;
    int y1 = 214 - (data[i - 1] - minValue) * yScale;
    int x2 = 40 + i * xScale;
    int y2 = 214 - (data[i] - minValue) * yScale;
    tft.drawLine(x1, y1, x2, y2, TFT_GREEN);
  }
}

void drawGraphicHour(float data[], const char* title) {
  int numReadings = 60, dataStartIdx = 1380;
  tft.fillScreen(TFT_BLACK);
  tft.loadFont(FONT_22); 
  tft.setTextColor(TFT_BLACK);
  tft.setTextSize(2);
  tft.fillRect(0,0,320,40,TFT_GREEN);
  tft.setCursor(10,10);
  tft.print(title);
  tft.unloadFont();

  tft.drawLine(39, 221, 39, 45, TFT_WHITE);
  tft.drawLine(39, 221, 310, 221, TFT_WHITE);

  for (int i=0; i<5; i++) {
    tft.drawLine(35, i*40+55, 39, i*40+55, TFT_WHITE);
  }

  for (int i=0; i<24; i++) {
    tft.drawLine(i*11+40, 222, i*11+40, 225, TFT_WHITE);
  }

  float minValue = data[dataStartIdx];
  float maxValue = data[dataStartIdx];
  for (int i = 1; i < numReadings; i++) {
      if (data[dataStartIdx + i] < minValue) {
          minValue = data[dataStartIdx + i];
      }
      if (data[dataStartIdx + i] > maxValue) {
          maxValue = data[dataStartIdx + i];
      }
  }

  int hour;
  tft.setTextSize(1);
  tft.setTextColor(TFT_WHITE);
  tft.fillRect(0,50,34,220,TFT_BLACK);
  for (int i=0; i<5; i++) {
    tft.setCursor(5, i*40+50);
    if (i<4) tft.print(maxValue-((maxValue-minValue)/4*i), (strcmp(title, "ТЕМПЕР ЧАС") == 0 || strcmp(title, "ТЕРМИСТОР ЧАС") == 0) ? 1 : 0);
    else if (i==4) tft.print(minValue, (strcmp(title, "ТЕМПЕР ЧАС") == 0 || strcmp(title, "ТЕРМИСТОР ЧАС") == 0) ? 1 : 0);
  }

  tft.fillRect(35, 226, 280, 14, TFT_BLACK);
  for (int i = 0; i < 12; i++) {
      tft.setCursor(((12 - i) * 22) + 26, 227);
      tft.print(65 - (i * 5 + 5));
  }

  float xScale = 264.0 / (numReadings - 1); // Размер шкалы по X
  float yScale = 160.0 / (maxValue - minValue); // Размер шкалы по Y

  tft.setTextColor(TFT_GREEN);
  tft.setTextSize(1);

  for (int i = 1; i < numReadings; i++) {
      int x1 = 40 + (i - 1) * xScale;
      int y1 = 214 - (data[dataStartIdx + i - 1] - minValue) * yScale;
      int x2 = 40 + i * xScale;
      int y2 = 214 - (data[dataStartIdx + i] - minValue) * yScale;
      tft.drawLine(x1, y1, x2, y2, TFT_GREEN);
  }
}
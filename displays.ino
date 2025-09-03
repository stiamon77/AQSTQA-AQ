/**
TL_DATUM = 0 = Top left
TC_DATUM = 1 = Top centre
TR_DATUM = 2 = Top right
ML_DATUM = 3 = Middle left
MC_DATUM = 4 = Middle centre
MR_DATUM = 5 = Middle right
BL_DATUM = 6 = Bottom left
BC_DATUM = 7 = Bottom centre
BR_DATUM = 8 = Bottom right
*/
void displayN(int dNumber){
  if (dNumber == 0){
    digitalWrite (display1_CS, HIGH);
    digitalWrite (display2_CS, HIGH);
  }else if (dNumber == 1){
    digitalWrite (display1_CS, LOW);
    digitalWrite (display2_CS, HIGH);
  }else if (dNumber == 2){
  digitalWrite (display1_CS, HIGH);
  digitalWrite (display2_CS, LOW);
  }
}

void startDisplays(){
  pinMode (display1_CS, OUTPUT);
  pinMode (display2_CS, OUTPUT);
  
// general intalization three devices
  digitalWrite (display1_CS, LOW);  
  digitalWrite (display2_CS, LOW);  

  tft.begin ();  
  tft.setSwapBytes (true);                      // swap the byte order for pushImage() - corrects endianness
  tft.setRotation (0);
  tft.fillScreen (BLACK);

  digitalWrite (display1_CS, HIGH); 
  digitalWrite (display2_CS, HIGH); 

  displayN(2);
  tft.fillScreen (BLACK);
  tft.fillScreen (TFT_BLACK);
  tft.pushImage (35,0,172,320,fon1);
}

void printDisplays(){
  
  displayN(2);
  // tft.fillScreen (TFT_BLACK);
  // tft.pushImage (0,0,130,261,fon1);
  tft.setTextSize(1);
  tft.setFreeFont(FSS24);
  tft.setTextColor(WHITE);


  // if (SensorCO2O != SensorCO2 || SensorPm25O != SensorPm25 || SensorVocO != SensorVoc){
  //   tft.pushImage (35,0,172,320,fon1);
  //   tft.drawNumber(SensorCO2, 70, 38);
  //   tft.setTextDatum(TR_DATUM);
  //   tft.drawNumber(SensorVoc, 175, 140);
  //   tft.drawNumber(SensorPm25, 175, 248);
  //   tft.setTextDatum(0);
  // }

  if (SensorCO2O != SensorCO2){
    tft.pushImage (65,29,112,47,fon1_1);
    tft.setTextDatum(TR_DATUM);
    tft.drawNumber(SensorCO2, 175, 38);
    tft.setTextDatum(0);
  }

    if (SensorVocO != SensorVoc){
    tft.pushImage (65,135,112,41,fon1_2);
    tft.setTextDatum(TR_DATUM);
    tft.drawNumber(SensorVoc, 175, 140);
    tft.setTextDatum(0);
  }

  if (SensorPm25O != SensorPm25){
    tft.pushImage (65,243,112,41,fon1_3);
    tft.setTextDatum(TR_DATUM);
    tft.drawNumber(SensorPm25, 175, 248);
    tft.setTextDatum(0);
  }

  displayN(1);

  int ypos = 50;
  int xpos = 0;
  int xpos2 = 0;

  tft.setFreeFont(FF0);
  tft.setTextColor(WHITE,BLACK);
  tft.setTextSize(2);
  tft.drawString("Test", xpos, ypos);
  
  ypos += tft.fontHeight();   // Get the font height and move ypos down

  tft.drawString("Lux:        ", xpos, ypos);
  xpos2 = tft.textWidth("Lux:        ");

  //fillRect(int32_t x, int32_t y, int32_t w, int32_t h, uint32_t color)

  if (SensorLuxO != SensorLux){
    int frH = tft.fontHeight();
    int frW = tft.textWidth("000000");
    tft.fillRect(xpos2, ypos, frW, frH, BLACK);
    tft.setTextColor(GREEN, BLACK, true);
    tft.drawNumber(SensorLux, xpos2, ypos);
    SensorLuxO = SensorLux;
  }

  tft.setTextColor(WHITE,BLACK);
  ypos += tft.fontHeight();   // Get the font height and move ypos down
  tft.drawString("%:          ", xpos, ypos);

  if (SensorHumO != SensorHum){
    int frH = tft.fontHeight();
    int frW = tft.textWidth("00.00");
    tft.fillRect(xpos2, ypos, frW, frH, BLACK);
    tft.setTextColor(RED, BLACK, true);
    tft.drawFloat(SensorHum, 2, xpos2, ypos);
    SensorHumO = SensorHum;
  }

  tft.setTextColor(WHITE,BLACK);
  ypos += tft.fontHeight();   // Get the font height and move ypos down
  tft.drawString("C:          ", xpos, ypos);

  if (SensorTempO != SensorTemp){
    int frH = tft.fontHeight();
    int frW = tft.textWidth("00.00");
    tft.fillRect(xpos2, ypos, frW, frH, BLACK);
    tft.setTextColor(GREEN, BLACK, true);
    tft.drawFloat(SensorTemp, 2, xpos2, ypos);
    SensorTempO = SensorTemp;
  }  

  tft.setTextColor(WHITE,BLACK);
  ypos += tft.fontHeight();   // Get the font height and move ypos down
  tft.drawString("mmHg:       ", xpos, ypos);

  if (SensorPresO != SensorPres){
    int frH = tft.fontHeight();
    int frW = tft.textWidth("0000");
    tft.fillRect(xpos2, ypos, frW, frH, BLACK);
    tft.setTextColor(RED, BLACK, true);
    tft.drawNumber(SensorPres, xpos2, ypos);
    SensorPresO = SensorPres;
    presSensor.setValue(SensorPres);
  }

  tft.setTextColor(WHITE,BLACK);
  ypos += tft.fontHeight();   // Get the font height and move ypos down
  tft.drawString("Pm10:       ", xpos, ypos);

  if (SensorPm10O != SensorPm10){
    int frH = tft.fontHeight();
    int frW = tft.textWidth("000000");
    tft.fillRect(xpos2, ypos, frW, frH, BLACK);
    tft.setTextColor(GREEN, BLACK, true);
    tft.drawNumber(SensorPm10, xpos2, ypos);
    SensorPm10O = SensorPm10;
  }

  tft.setTextColor(WHITE,BLACK);
  ypos += tft.fontHeight();   // Get the font height and move ypos down
  tft.drawString("NOx index:  ", xpos, ypos);

  if (SensorNoxO != SensorNox){
    int frH = tft.fontHeight();
    int frW = tft.textWidth("000");
    tft.fillRect(xpos2, ypos, frW, frH, BLACK);
    tft.setTextColor(RED, BLACK, true);
    tft.drawNumber(SensorNox, xpos2, ypos);
    SensorNoxO = SensorNox;
  }

  // tft.setTextColor(WHITE,BLACK);
  // ypos += tft.fontHeight();   // Get the font height and move ypos down
  // tft.drawString("NOx:        ", xpos, ypos);

  // if (SensorSrawNoxO != SensorSrawNox){
  //   int frH = tft.fontHeight();
  //   int frW = tft.textWidth("000000");
  //   tft.fillRect(xpos2, ypos, frW, frH, BLACK);
  //   tft.setTextColor(GREEN, BLACK, true);
  //   tft.drawNumber(SensorSrawNox, xpos2, ypos);
  //   SensorSrawNoxO = SensorSrawNox;
  // }

  tft.setTextColor(WHITE,BLACK);
  ypos += tft.fontHeight();   // Get the font height and move ypos down
  tft.drawString("VOC index:  ", xpos, ypos);

  if (SensorVocO != SensorVoc){
    int frH = tft.fontHeight();
    int frW = tft.textWidth("000");
    tft.fillRect(xpos2, ypos, frW, frH, BLACK);
    tft.setTextColor(GREEN, BLACK, true);
    tft.drawNumber(SensorVoc, xpos2, ypos);
    SensorVocO = SensorVoc;
  }

//Clock display calendar

  ypos += tft.fontHeight() * 2; //Position down

  tft.setTextSize(3);
  int frH = tft.fontHeight(); //Font height
  int frW = tft.textWidth("00"); //Font length

  if (timDateO != timDate){
    tft.fillRect(xpos, ypos, frW, frH, BLACK); //Cleaning before publishing
    tft.setTextColor(WHITE, BLACK, true);

    if (timDate <= 9){
      tft.drawString(String("0") + timDate, xpos, ypos);
    }else{
      tft.drawNumber(timDate, xpos, ypos);
    }
    timDateO = timDate;    
  }

  xpos = xpos + frW; //Font length

  // tft.setTextDatum(6);

  tft.setTextSize(2);

  ypos += tft.fontHeight() / 2; //Position down

  // frH = tft.fontHeight(); //Font height
  frW = tft.textWidth("SUN"); //Font length
  

  if (timWeekO != timWeek){
    tft.fillRect(xpos, ypos, frW, frH, BLACK); //Cleaning before publishing
    tft.setTextColor(WHITE, BLACK, true);
    tft.drawString(daysOfTheWeek[timWeek], xpos, ypos);
    timWeekO = timWeek;   
  }

  xpos = xpos + frW;
  frW = tft.textWidth("|   "); //Font length

  if (timMonthO != timMonth){
    tft.fillRect(xpos, ypos, frW, frH, BLACK); //Cleaning before publishing
    tft.setTextColor(WHITE, BLACK, true);
    tft.drawString(String("|") + months[timMonth + 1], xpos, ypos);
    timMonthO = timMonth;   
  }

  xpos = xpos + frW;
  // tft.setTextDatum(0);

  ypos -= tft.fontHeight() / 2; //Position down

  tft.setTextSize(3);  

  frH = tft.fontHeight(); //Font height
  frW = tft.textWidth("0000"); //Font length

  if (timYearO != timYear){
    tft.fillRect(xpos, ypos, frW, frH, BLACK); //Cleaning before publishing
    tft.setTextColor(WHITE, BLACK, true);
    tft.drawNumber(timYear + 1900, xpos, ypos);
    timYearO = timYear;    
  }

//Clock display time

  ypos += tft.fontHeight() * 2; //Position down
  frH = tft.fontHeight(); //Font height
  frW = tft.textWidth("00:"); //Font length

  xpos = 0;

  if(timHo !=timH){
    tft.fillRect(xpos, ypos, frW, frH, BLACK); //Cleaning before publishing
    tft.setTextColor(WHITE, BLACK, true);
    if (timH <= 9){
      tft.drawString(String("0") + timH + String(":"), xpos, ypos);
    }else{
      tft.drawString(timH + String(":"), xpos, ypos);
    }
    timHo = timH; 
  }

  xpos = frW;
  frW = tft.textWidth("00:"); //Font length

  if(timMo !=timM){
    tft.fillRect(xpos, ypos, frW, frH, BLACK); //Cleaning before publishing
    tft.setTextColor(WHITE, BLACK, true);
    if (timM <= 9){
      tft.drawString(String("0") + timM + String(":"), xpos, ypos);
    }else{
      tft.drawString(timM + String(":"), xpos, ypos);
    }
    timMo = timM;
  }

  xpos = xpos + frW; //Font length
  frW = tft.textWidth("00"); //Font length

  tft.fillRect(xpos, ypos, frW, frH, BLACK); //Cleaning before publishing
  tft.setTextColor(WHITE, BLACK, true);
  if (timS <= 9){
    tft.drawString(String("0") + timS, xpos, ypos);
  }else{
    tft.drawNumber(timS, xpos, ypos);
  }

  
  
/**
  tft.fillRect(xpos, ypos, frW, frH, BLACK); //Cleaning before publishing
  tft.setTextColor(WHITE, BLACK, true);
  tft.drawString(dayDate + "" + dayOfWeek + "|" + dayMonth + "" + dayYear, xpos, ypos);


  // tft.setTextColor(WHITE,BLACK);

  // tft.drawString("VOC index:  ", xpos, ypos);
  // xpos2 = xpos2 / 2;

  // String timeCL = %H:%M:%S;
  
//  tft.setTextDatum(TR_DATUM);
//  if (timeCLO != timeCL){
    int frH = tft.fontHeight();
    int frW = tft.textWidth("00 123 123 0000");
    tft.fillRect(xpos, ypos, frW, frH, BLACK);
    tft.setTextColor(WHITE, BLACK, true);
    tft.drawString(dayDate + "" + dayOfWeek + "|" + dayMonth + "" + dayYear, xpos, ypos);

  ypos += tft.fontHeight() * 2;;   // Get the font height and move ypos down

    frH = tft.fontHeight();
    frW = tft.textWidth("00:00:00");
    tft.fillRect(xpos, ypos, frW, frH, BLACK);
    tft.setTextColor(WHITE, BLACK, true);
    tft.drawString(timH + ":" + timM + ":" + timS, xpos, ypos);    
//    timeCLO = timeCL;
//  }
*/

  if (SensorPm25O != SensorPm25){
    SensorPm25O = SensorPm25;
  }

  if (SensorCO2O != SensorCO2){
    SensorCO2O = SensorCO2;
  }
}
void startLED(){
  FastLED.addLeds<LED_TYPE,DATA_PIN,COLOR_ORDER>(leds, NUM_LEDS).setCorrection(TypicalLEDStrip);
  FastLED.setBrightness(100);
}

void testLED(){

  FastLED.clear();
  FastLED.show();

  for (uint8_t i = 0; i < 255; i++) {
    ledShowSend(0,i,150,0);
    ledShowSend(1,i,150,0);
    ledShowSend(2,i,150,0);
    delay(10);
  }

  leds[0] = CRGB::Black;
  delay(100);
  leds[1] = CRGB::Black;
  delay(100);
  leds[2] = CRGB::Black;
  delay(100);

  FastLED.show();
  FastLED.clear();
  FastLED.show();
  //-------------------------------------------------
}

void dataLEDs(){

//LED CO2
  if (SensorCO2 <= CO2GreenZone){
    ledShowSend(LED_CO2,96,0,0);
  }else{
    if(SensorCO2 <= CO2OrangeZone){

    colorLEDs(LED_CO2,CO2GreenZone,CO2OrangeZone,SensorCO2,0);

    }else{
      if(SensorCO2 < CO2DangerZone){
        colorLEDs(LED_CO2,CO2OrangeZone,CO2DangerZone,SensorCO2,1);
      }else{
        if(SensorCO2 >= CO2DangerZone){
          ledShowSend(LED_CO2,0,0,1);
        }
      }
    }
  }

//LED VOC
  if (SensorVoc <= VOCGreenZone){
    ledShowSend(LED_VOC,96,0,0);
  }else{
    if(SensorVoc <= VOCOrangeZone){

    colorLEDs(LED_VOC,VOCGreenZone,VOCOrangeZone,SensorVoc,0);

    }else{
      if(SensorVoc < VOCDangerZone){
        colorLEDs(LED_VOC,VOCOrangeZone,VOCDangerZone,SensorVoc,1);
      }else{
        if(SensorVoc >= VOCDangerZone){
          ledShowSend(LED_VOC,0,0,1);
        }
      }
    }
  }

//LED PM
  if (SensorPm25 <= PM25GreenZone){
    ledShowSend(LED_PM,96,0,0);
  }else{
    if(SensorPm25 <= PM25OrangeZone){

    colorLEDs(LED_PM,PM25GreenZone,PM25OrangeZone,SensorPm25,0);

    }else{
      if(SensorPm25 < PM25DangerZone){
        colorLEDs(LED_PM,PM25OrangeZone,PM25DangerZone,SensorPm25,1);
      }else{
        if(SensorPm25 >= PM25DangerZone){
          ledShowSend(LED_PM,0,0,1);
        }
      }
    }
  }
}

void colorLEDs(uint8_t _numLed, uint16_t _greenZone, uint16_t _orangeZone, uint16_t _sensorParam, bool _flagZ) {

  uint8_t _ledCOLOR;
  
  uint16_t _zoneS = _orangeZone - _greenZone;
  _sensorParam = _sensorParam - _greenZone;
  if(!_flagZ){
    _ledCOLOR = map(_sensorParam, 0, _zoneS, 96, 32);
  }else{
    _ledCOLOR = map(_sensorParam, 0, _zoneS, 32, 0);
  }
  
  ledShowSend(_numLed,_ledCOLOR,0,0);
}

void ledShowSend(uint8_t _numLed,uint8_t _ledCOLOR,uint8_t _ledBrightnes, bool _blinkLed){

  if(_blinkLed){
    if(blinkLed){
      leds[_numLed].setHSV(_ledCOLOR, 255, ledBrightnesSend(_ledBrightnes));  // HSV, 0-255
      FastLED.show();
    }else{
      leds[_numLed].setHSV(0, 0, 0);  // HSV, 0-255
      FastLED.show();
    }

  }else{
    leds[_numLed].setHSV(_ledCOLOR, 255, ledBrightnesSend(_ledBrightnes));  // HSV, 0-255
    FastLED.show();
  }
}

uint8_t ledBrightnesSend(uint8_t _ledBrightness){

  if (_ledBrightness == 0){
    if(AdaptiveBright){
      uint16_t _SensorLux = SensorLux;
      if(_SensorLux > 100){
        _SensorLux = 100;
      }
      _ledBrightness = map(_SensorLux, 0, 100, AdaptiveBrightMin, AdaptiveBrightMax);
    }else{
      _ledBrightness = NotAdaptiveBright;
    }
  }else{
    _ledBrightness = _ledBrightness;
  }

  if(_ledBrightness > 255){
    _ledBrightness = 255;
  }

  return _ledBrightness;
}

/**
RED = 255, 0, 0
Green = 0, 255, 0
Halfway between green and orange 255, 127, 0
orange = 255, 165, 0
greenZone 1000 255
orangeZone 1500 0

Red (0..) "HUE_RED"
Orange (32..) "HUE_ORANGE"
Yellow (64..) "HUE_YELLOW"
Green (96..) "HUE_GREEN"
*/


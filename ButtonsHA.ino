void onButtonCommand(HAButton* sender){
  if (sender == &buttonRestart) {
    // button was clicked
    #ifdef DEBUG
    Serial.println("----------------Restart----------------");
    #endif
    ESP.restart();

  } else if (sender == &buttonDefault) {
    // button was clicked
    #ifdef DEBUG
    Serial.println("----------------Default----------------");
    #endif  

    // butDefault = true;  
    PM25OrangeZone = 100;
    numberPM25OrangeZone.setState(PM25OrangeZone);
    PM25GreenZone = 50;
    numberPM25GreenZone.setState(PM25GreenZone);
    VOCOrangeZone = 200;
    numberVOCOrangeZone.setState(VOCOrangeZone);
    VOCGreenZone = 100;
    numberVOCGreenZone.setState(VOCGreenZone);
    NOxOrangeZone = 100;
    numberNOxOrangeZone.setState(NOxOrangeZone);
    NOxGreenZone = 10;
    numberNOxGreenZone.setState(NOxGreenZone);
    CO2OrangeZone = 1500;
    numberCO2OrangeZone.setState(CO2OrangeZone);
    CO2GreenZone = 1000;
    numberCO2GreenZone.setState(CO2GreenZone);
    AdaptiveBrightMax = 150;
    numberAdaptiveBrightMax.setState(AdaptiveBrightMax);
    AdaptiveBrightMin = 30;   
    numberAdaptiveBrightMin.setState(AdaptiveBrightMin);
    NotAdaptiveBright = 50;    
    numberNotAdaptiveBright.setState(NotAdaptiveBright);

    CO2DangerZone = 2500;
    numberCO2DangerZone.setState(CO2DangerZone);
    PM25DangerZone = 150;    
    numberPM25DangerZone.setState(PM25DangerZone);
    VOCDangerZone = 300;
    numberVOCDangerZone.setState(VOCDangerZone);
    NOxDangerZone = 200;    
    numberNOxDangerZone.setState(NOxDangerZone);
    
    AlarmBuzzer = true;
    switchBuzzer.setState(AlarmBuzzer);
    AlarmVibration = true;
    switchVibration.setState(AlarmVibration);
    AdaptiveBright = true;
    switchAdaptiveBright.setState(AdaptiveBright);

    defMemW = true;

    // selectAdaptiveBright.setState(1);
    // selectVibration.setState(1);
    // selectBuzzer.setState(1);

  }
}


void startHA() {

  // set device's details (optional)
  device.setName(clientId.c_str());
  device.setSoftwareVersion("3.1.1");
  device.setManufacturer("AQSTQA");
  device.setModel("Air quality sensor (AQSTQA-AQ-V3)");

//Sensors
  luxSensor.setIcon("mdi:brightness-7");
  luxSensor.setName("Illuminance");
  luxSensor.setUnitOfMeasurement("lx");

  signalSensor.setIcon("mdi:wifi");
  signalSensor.setName("Signal Strength");
  signalSensor.setUnitOfMeasurement("%");


  co2Sensor.setIcon("mdi:molecule-co2");
  co2Sensor.setName("CO2");
  co2Sensor.setUnitOfMeasurement("ppm");


  VOCindexSensor.setIcon("mdi:molecule");
  VOCindexSensor.setName("VOC Index");
  VOCindexSensor.setUnitOfMeasurement("ind");


  NOxindexSensor.setIcon("mdi:molecule");
  NOxindexSensor.setName("NOx Index");
  NOxindexSensor.setUnitOfMeasurement("ind");


  pm25Sensor.setIcon("mdi:molecule");
  pm25Sensor.setName("pm2.5");
  pm25Sensor.setUnitOfMeasurement("µg/m³");

  pm10Sensor.setIcon("mdi:molecule");
  pm10Sensor.setName("pm10");
  pm10Sensor.setUnitOfMeasurement("µg/m³");

  pm1Sensor.setIcon("mdi:molecule");
  pm1Sensor.setName("pm1");
  pm1Sensor.setUnitOfMeasurement("µg/m³");


  presSensor.setIcon("mdi:gauge");
  presSensor.setName("Atmospheric pressure");
  presSensor.setUnitOfMeasurement("mmHg");

  // approxSensor.setIcon("mdi:waves-arrow-up");
  // approxSensor.setName("Approx altitude");
  // approxSensor.setUnitOfMeasurement("m");

  humSensor.setIcon("mdi:water-percent");
  humSensor.setName("Humidity");
  humSensor.setUnitOfMeasurement("%");

  tempSensor.setIcon("mdi:thermometer");
  tempSensor.setName("Temperature");
  tempSensor.setUnitOfMeasurement("°C");

//AdaptiveBright
  numberAdaptiveBrightMax.onCommand(numAdaptiveBrightMaxCom);
  numberAdaptiveBrightMax.setIcon("mdi:cogs");
  numberAdaptiveBrightMax.setName("Ad. Bright Max");
  numberAdaptiveBrightMax.setMin(1); // can be float if precision is set via the constructor
  numberAdaptiveBrightMax.setMax(255); // can be float if precision is set via the constructor
  numberAdaptiveBrightMax.setStep(1); // minimum step: 0.001f
  // numberTh1.setMode(HANumber::ModeBox);
  numberAdaptiveBrightMax.setMode(HANumber::ModeSlider);
  numberAdaptiveBrightMax.setRetain(true);

  numberAdaptiveBrightMin.onCommand(numAdaptiveBrightMinCom);
  numberAdaptiveBrightMin.setIcon("mdi:cogs");
  numberAdaptiveBrightMin.setName("Ad. Bright Min");
  numberAdaptiveBrightMin.setMin(0); // can be float if precision is set via the constructor
  numberAdaptiveBrightMin.setMax(254); // can be float if precision is set via the constructor
  numberAdaptiveBrightMin.setStep(1); // minimum step: 0.001f
  // numberTh1.setMode(HANumber::ModeBox);
  numberAdaptiveBrightMin.setMode(HANumber::ModeSlider);
  numberAdaptiveBrightMin.setRetain(true);

  numberNotAdaptiveBright.onCommand(numNotAdaptiveBrightCom);
  numberNotAdaptiveBright.setIcon("mdi:cogs");
  numberNotAdaptiveBright.setName("Ad. Bright Off");
  numberNotAdaptiveBright.setMin(0); // can be float if precision is set via the constructor
  numberNotAdaptiveBright.setMax(255); // can be float if precision is set via the constructor
  numberNotAdaptiveBright.setStep(1); // minimum step: 0.001f
  // numberTh1.setMode(HANumber::ModeBox);
  numberNotAdaptiveBright.setMode(HANumber::ModeSlider);
  numberNotAdaptiveBright.setRetain(true);

//CO2
  numberCO2GreenZone.onCommand(numCO2GreenZoneCom);
  numberCO2GreenZone.setIcon("mdi:molecule-co2");
  numberCO2GreenZone.setName("CO2 Green Z.");
  numberCO2GreenZone.setMin(400); // can be float if precision is set via the constructor
  numberCO2GreenZone.setMax(2000); // can be float if precision is set via the constructor
  numberCO2GreenZone.setStep(100); // minimum step: 0.001f
  // numberTh1.setMode(HANumber::ModeBox);
  numberCO2GreenZone.setMode(HANumber::ModeSlider);
  numberCO2GreenZone.setRetain(true);
//  numberCO2GreenZone.setState(1000);

  numberCO2OrangeZone.onCommand(numCO2OrangeZoneCom);
  numberCO2OrangeZone.setIcon("mdi:molecule-co2");
  numberCO2OrangeZone.setName("CO2 Orange Z.");
  numberCO2OrangeZone.setMin(700); // can be float if precision is set via the constructor
  numberCO2OrangeZone.setMax(3000); // can be float if precision is set via the constructor
  numberCO2OrangeZone.setStep(100); // minimum step: 0.001f
  // numberTh1.setMode(HANumber::ModeBox);
  numberCO2OrangeZone.setMode(HANumber::ModeSlider);
  numberCO2OrangeZone.setRetain(true);
//  numberCO2OrangeZone.setState(1500);

  numberCO2DangerZone.onCommand(numCO2DangerZoneCom);
  numberCO2DangerZone.setIcon("mdi:molecule-co2");
  numberCO2DangerZone.setName("CO2 Danger Z.");
  numberCO2DangerZone.setMin(700); // can be float if precision is set via the constructor
  numberCO2DangerZone.setMax(3000); // can be float if precision is set via the constructor
  numberCO2DangerZone.setStep(100); // minimum step: 0.001f
  // numberTh1.setMode(HANumber::ModeBox);
  numberCO2DangerZone.setMode(HANumber::ModeSlider);
  numberCO2DangerZone.setRetain(true);
//  numberCO2OrangeZone.setState(1500);

//NOx
  numberNOxGreenZone.onCommand(numNOxGreenZoneCom);
  numberNOxGreenZone.setIcon("mdi:molecule");
  numberNOxGreenZone.setName("NOx Green Z.");
  numberNOxGreenZone.setMin(1); // can be float if precision is set via the constructor
  numberNOxGreenZone.setMax(100); // can be float if precision is set via the constructor
  numberNOxGreenZone.setStep(1); // minimum step: 0.001f
  // numberTh1.setMode(HANumber::ModeBox);
  numberNOxGreenZone.setMode(HANumber::ModeSlider);
  numberNOxGreenZone.setRetain(true);
//  numberNOxGreenZone.setState(10);

  numberNOxOrangeZone.onCommand(numNOxOrangeZoneCom);
  numberNOxOrangeZone.setIcon("mdi:molecule");
  numberNOxOrangeZone.setName("NOx Orange Z.");
  numberNOxOrangeZone.setMin(2); // can be float if precision is set via the constructor
  numberNOxOrangeZone.setMax(300); // can be float if precision is set via the constructor
  numberNOxOrangeZone.setStep(1); // minimum step: 0.001f
  // numberTh1.setMode(HANumber::ModeBox);
  numberNOxOrangeZone.setMode(HANumber::ModeSlider);
  numberNOxOrangeZone.setRetain(true);
//  numberNOxOrangeZone.setState(100);

  numberNOxDangerZone.onCommand(numNOxDangerZoneCom);
  numberNOxDangerZone.setIcon("mdi:molecule");
  numberNOxDangerZone.setName("NOx Danger Z.");
  numberNOxDangerZone.setMin(2); // can be float if precision is set via the constructor
  numberNOxDangerZone.setMax(300); // can be float if precision is set via the constructor
  numberNOxDangerZone.setStep(1); // minimum step: 0.001f
  // numberTh1.setMode(HANumber::ModeBox);
  numberNOxDangerZone.setMode(HANumber::ModeSlider);
  numberNOxDangerZone.setRetain(true);
//  numberNOxOrangeZone.setState(100);

//VOC
  numberVOCGreenZone.onCommand(numVOCGreenZoneCom);
  numberVOCGreenZone.setIcon("mdi:molecule");
  numberVOCGreenZone.setName("VOC Green Z.");
  numberVOCGreenZone.setMin(1); // can be float if precision is set via the constructor
  numberVOCGreenZone.setMax(100); // can be float if precision is set via the constructor
  numberVOCGreenZone.setStep(1); // minimum step: 0.001f
  // numberTh1.setMode(HANumber::ModeBox);
  numberVOCGreenZone.setMode(HANumber::ModeSlider);
  numberVOCGreenZone.setRetain(true);
//  numberVOCGreenZone.setState(100);  

  numberVOCOrangeZone.onCommand(numVOCOrangeZoneCom);
  numberVOCOrangeZone.setIcon("mdi:molecule");
  numberVOCOrangeZone.setName("VOC Orange Z.");
  numberVOCOrangeZone.setMin(2); // can be float if precision is set via the constructor
  numberVOCOrangeZone.setMax(300); // can be float if precision is set via the constructor
  numberVOCOrangeZone.setStep(1); // minimum step: 0.001f
  // numberTh1.setMode(HANumber::ModeBox);
  numberVOCOrangeZone.setMode(HANumber::ModeSlider);
  numberVOCOrangeZone.setRetain(true);
//  numberVOCOrangeZone.setState(200);

  numberVOCDangerZone.onCommand(numVOCDangerZoneCom);
  numberVOCDangerZone.setIcon("mdi:molecule");
  numberVOCDangerZone.setName("VOC Danger Z.");
  numberVOCDangerZone.setMin(2); // can be float if precision is set via the constructor
  numberVOCDangerZone.setMax(300); // can be float if precision is set via the constructor
  numberVOCDangerZone.setStep(1); // minimum step: 0.001f
  // numberTh1.setMode(HANumber::ModeBox);
  numberVOCDangerZone.setMode(HANumber::ModeSlider);
  numberVOCDangerZone.setRetain(true);
//  numberVOCOrangeZone.setState(200);

//PM2.5
  numberPM25GreenZone.onCommand(numPM25GreenZoneCom);
  numberPM25GreenZone.setIcon("mdi:molecule");
  numberPM25GreenZone.setName("PM25 Green Z.");
  numberPM25GreenZone.setMin(1); // can be float if precision is set via the constructor
  numberPM25GreenZone.setMax(100); // can be float if precision is set via the constructor
  numberPM25GreenZone.setStep(1); // minimum step: 0.001f
  // numberTh1.setMode(HANumber::ModeBox);
  numberPM25GreenZone.setMode(HANumber::ModeSlider);
  numberPM25GreenZone.setRetain(true);
//  numberPM25GreenZone.setState(50);  

  numberPM25OrangeZone.onCommand(numPM25OrangeZoneCom);
  numberPM25OrangeZone.setIcon("mdi:molecule");
  numberPM25OrangeZone.setName("PM25 Orange Z.");
  numberPM25OrangeZone.setMin(2); // can be float if precision is set via the constructor
  numberPM25OrangeZone.setMax(300); // can be float if precision is set via the constructor
  numberPM25OrangeZone.setStep(1); // minimum step: 0.001f
  // numberTh1.setMode(HANumber::ModeBox);
  numberPM25OrangeZone.setMode(HANumber::ModeSlider);
  numberPM25OrangeZone.setRetain(true);
//  numberPM25OrangeZone.setState(100);

  numberPM25DangerZone.onCommand(numPM25DangerZoneCom);
  numberPM25DangerZone.setIcon("mdi:molecule");
  numberPM25DangerZone.setName("PM25 Danger Z.");
  numberPM25DangerZone.setMin(2); // can be float if precision is set via the constructor
  numberPM25DangerZone.setMax(300); // can be float if precision is set via the constructor
  numberPM25DangerZone.setStep(1); // minimum step: 0.001f
  // numberTh1.setMode(HANumber::ModeBox);
  numberPM25DangerZone.setMode(HANumber::ModeSlider);
  numberPM25DangerZone.setRetain(true);
//  numberPM25OrangeZone.setState(100);

//Switchs

  // selectAdaptiveBright.setOptions("On;Off"); // use semicolons as separator of options
  // selectAdaptiveBright.onCommand(onAdaptiveBrightCommand);
  // selectAdaptiveBright.setRetain(true);
  // selectAdaptiveBright.setIcon("mdi:brightness-auto"); // optional
  // selectAdaptiveBright.setName("Adaptive Bright"); // optional

  switchAdaptiveBright.setIcon("mdi:brightness-auto");
  switchAdaptiveBright.setName("Ad. Bright On");
  switchAdaptiveBright.setRetain(true);
  switchAdaptiveBright.onCommand(onAdaptiveBrightCommand);

  // selectVibration.setOptions("On;Off"); // use semicolons as separator of options
  // selectVibration.onCommand(onVibrationCommand);
  // selectVibration.setRetain(true);
  // selectVibration.setIcon("mdi:vibrate"); // optional
  // selectVibration.setName("Alarm Vibration"); // optional

  switchVibration.setIcon("mdi:vibrate");
  switchVibration.setName("Alarm Vibration");
  switchVibration.setRetain(true);
  switchVibration.onCommand(onVibrationCommand);

  // selectBuzzer.setOptions("On;Off"); // use semicolons as separator of options
  // selectBuzzer.onCommand(onBuzzerCommand);
  // selectBuzzer.setRetain(true);
  // selectBuzzer.setIcon("mdi:alarm-bell"); // optional
  // selectBuzzer.setName("Alarm Buzzer"); // optional

  switchBuzzer.setIcon("mdi:alarm-bell");
  switchBuzzer.setName("Alarm Buzzer");
  switchBuzzer.setRetain(true);
  switchBuzzer.onCommand(onBuzzerCommand);

//Bbuttons
  buttonRestart.setIcon("mdi:restart");
  buttonRestart.setName("Restart");
  buttonRestart.onCommand(onButtonCommand);

  buttonDefault.setIcon("mdi:restart-off");
  buttonDefault.setName("reset to default (settings only)");
  buttonDefault.onCommand(onButtonCommand);

//
  device.enableSharedAvailability();  //This is the control of the availability of the entire device.
//    device.setAvailability(true);
  device.enableLastWill(); //Availability control by sensors, together with general control, do not work, something is the same(

  mqtt.begin(BROKER_ADDR, BROKER_USERNAME, BROKER_PASSWORD);
}

// void startSendHA(){
//   if(startSendPar){ 

//     numberPM25OrangeZone.setState(PM25OrangeZone);
//     numberPM25GreenZone.setState(PM25GreenZone);
//     numberPM25DangerZone.setState(PM25DangerZone);

//     numberVOCOrangeZone.setState(VOCOrangeZone);
//     numberVOCGreenZone.setState(VOCGreenZone);
//     numberVOCDangerZone.setState(VOCDangerZone);

//     numberNOxOrangeZone.setState(NOxOrangeZone);
//     numberNOxGreenZone.setState(NOxGreenZone);
//     numberNOxDangerZone.setState(NOxDangerZone);

//     numberCO2OrangeZone.setState(CO2OrangeZone);
//     numberCO2GreenZone.setState(CO2GreenZone);
//     numberCO2DangerZone.setState(CO2DangerZone);

//     numberAdaptiveBrightMax.setState(AdaptiveBrightMax); 
//     numberAdaptiveBrightMin.setState(AdaptiveBrightMin);   
//     numberNotAdaptiveBright.setState(NotAdaptiveBright);

//     switchBuzzer.setState(AlarmBuzzer);
//     switchVibration.setState(AlarmVibration);
//     switchAdaptiveBright.setState(AdaptiveBright);

//     startSendPar = false;
//   }
// }
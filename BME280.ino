void startBME280(){

  bme.begin(0x76, &Wire); 
  unsigned statusBME280;
  statusBME280 = bme.begin(); 

  delay(2000);

  if (!statusBME280) {

    #ifdef DEBUG
    Serial.println(F("BME280 test"));
    Serial.println("Could not find a valid BME280 sensor, check wiring, address, sensor ID!");
    Serial.print("SensorID was: 0x"); 
    Serial.println(bme.sensorID(),16);
    Serial.print("        ID of 0xFF probably means a bad address, a BMP 180 or BMP 085\n");
    Serial.print("        ID of 0x56-0x58 represents a BMP 280,\n");
    Serial.print("        ID of 0x60 represents a BME 280.\n");
    Serial.print("        ID of 0x61 represents a BME 680.\n");
    #endif

    errorSensorBME280 = 1;
  }

  if (! bme.begin(0x76, &Wire)) {

    #ifdef DEBUG
    Serial.println("Could not find a valid BME280 sensor, check wiring!");
    #endif
    
    errorSensorBME280 = 1;
  }
}

void dataBME280(){
  // float SensorHumS;
  // float SensorTempS;
  uint16_t SensorPresS;
  uint16_t SensorAltitudeS;
  //Serial.print(bme.readPressure() / 100.0F);
  //Serial.println(" hPa");

  //Serial.print(SensorPres);
 // Serial.println(" hPa");
//  Serial.print("Approx. Altitude = ");
//     Serial.print(bme.readAltitude(SEALEVELPRESSURE_HPA));
//     Serial.println(" m");

// Не нужные параметры//  SensorMSL = bme.readAltitude(SEALEVELPRESSURE_HPA);
  // SensorTempS = bme.readTemperature();
  SensorPresS = bme.readPressure() * 0.00750062;
  SensorAltitudeS = bme.readAltitude(SEALEVELPRESSURE_HPA);
  SensorPresMbar = bme.readPressure()/100.0; // in mbar
  // SensorHumS = bme.readHumidity();
  // SensorTempS = SensorTempS - TempKor;
  // SensorHumS = SensorHumS + HumKor;

  // if(SensorTemp != SensorTempS){
  //   SensorTempO = SensorTemp;
  //   SensorTemp = SensorTempS;  
  // }

  if(SensorPres != SensorPresS){
    SensorPresO = SensorPres;
    SensorPres = SensorPresS; 
    presSensor.setValue(SensorPresS); 
  }

  if(SensorAltitude != SensorAltitudeS){
    SensorAltitude = SensorAltitudeS; 
    // approxSensor.setValue(SensorAltitude); 
  }

  // if(SensorHum != SensorHumS){
  //   SensorHumO = SensorHum;
  //   SensorHum = SensorHumS;  
  // }
  
  errorSensorBME280 = 0;
  
}
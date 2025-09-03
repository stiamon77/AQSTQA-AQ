void startSCD30(){





  if (airSensor.begin() == false)
  {
    #ifdef DEBUG
    Serial.println("Air sensor not detected. Please check wiring. Freezing...");
    #endif
    errorSensorSCD30 = 1;
  }

  airSensor.setMeasurementInterval(5); //Change number of seconds between measurements: 2 to 1800 (30 minutes), stored in non-volatile memory of SCD30
  //While the setting is recorded, it is not immediately available to be read.
  delay(200);
  airSensor.setAltitudeCompensation(SensorAltitude); //Set altitude of the sensor in m, stored in non-volatile memory of SCD30
// airSensor.setTemperatureOffset(5); //Optionally we can set temperature offset to 5°C, stored in non-volatile memory of SCD30

//Это может менятся, возможно стоит обновлять раз в час  
  //Pressure in Boulder, CO is 24.65inHg or 834.74mBar
  airSensor.setAmbientPressure(SensorPresMbar); //Current ambient pressure in mBar: 700 to 1200, will overwrite altitude compensation

}

void dataSCD30(){
  if (airSensor.dataAvailable()){

    int SensorCO2S;
    float SensorHumS;
    float SensorTempS;

    SensorCO2S = airSensor.getCO2();
    SensorTempS = airSensor.getTemperature();
    SensorHumS = airSensor.getHumidity();
    SensorTempS = SensorTempS - TempKor;
    SensorHumS = SensorHumS + HumKor;

    #ifdef DEBUG
    Serial.print("co2(ppm):");
    Serial.print(airSensor.getCO2());

    Serial.print(" temp(C):");
    Serial.print(airSensor.getTemperature(), 1);

    Serial.print(" humidity(%):");
    Serial.print(airSensor.getHumidity(), 1);

    Serial.println();
    #endif

    if(SensorCO2 != SensorCO2S){
      SensorCO2O = SensorCO2;
      SensorCO2 = SensorCO2S;
      co2Sensor.setValue(SensorCO2);  
    }

    if(SensorTemp != SensorTempS){
      SensorTempO = SensorTemp;
      SensorTemp = SensorTempS;
      tempSensor.setValue(SensorTemp);  
    }

    if(SensorHum != SensorHumS){
      SensorHumO = SensorHum;
      SensorHum = SensorHumS; 
      humSensor.setValue(SensorHum); 
    }
    
    errorSensorSCD30 = 0;

  }else{

    #ifdef DEBUG
    Serial.println("Waiting for new data");
    #endif
  }
}
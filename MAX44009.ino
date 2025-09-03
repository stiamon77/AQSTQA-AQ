void startMAX44009(){
  if(light.begin()){

    #ifdef DEBUG
    Serial.println("Could not find a valid MAX44009 sensor, check wiring!");
    #endif
    errorSensorMAX44009 = 1;

	}else{
    errorSensorMAX44009 = 0;
  }
}

void dataMAX44009(){
  int SensorLuxS;
  SensorLuxS = light.get_lux();

  #ifdef DEBUG
  Serial.println(SensorLuxS);
  #endif

  if(SensorLux != SensorLuxS){
    SensorLuxO = SensorLux;
    SensorLux = SensorLuxS; 
    luxSensor.setValue(SensorLux);     
  }
}
void startSGP41() {
  sgp41.begin(Wire);
}

void dataSGP41() {
  uint16_t error;
  uint16_t srawVoc = 0;
  uint16_t srawNox = 0;
  uint16_t compensationRh = 0;              // in ticks as defined by SGP41
  uint16_t compensationT = 0;               // in ticks as defined by SGP41
  // uint16_t defaultRh = 0x8000;
  // uint16_t defaultT = 0x6666;

// convert temperature and humidity to ticks as defined by SGP41
// interface
// NOTE: in case you read RH and T raw signals check out the
// ticks specification in the datasheet, as they can be different for
// different sensors
  compensationT = static_cast<uint16_t>((SensorTemp + 45) * 65535 / 175);
  compensationRh = static_cast<uint16_t>(SensorHum * 65535 / 100);

  if (conditioning_s > 0) {
// During NOx conditioning (10s) SRAW NOx will remain 0
    error = sgp41.executeConditioning(compensationRh, compensationT, srawVoc);
    conditioning_s--;
  } else {
    error = sgp41.measureRawSignals(compensationRh, compensationT, srawVoc, srawNox);
  }

  if (error) {

    #ifdef DEBUG
    Serial.print("SGP41 - Error trying to execute measureRawSignals(): ");
    errorToString(error, errorMessage, 256);
    Serial.println(errorMessage);
    #endif

    errorSensorSGP41 = 1;

  } else {
    int32_t voc_index = voc_algorithm.process(srawVoc);
    int32_t nox_index = nox_algorithm.process(srawNox);

   #ifdef DEBUG
    Serial.print("VOC Index: ");
    Serial.print(voc_index);
    Serial.print("\t");
    Serial.print("NOx Index: ");
    Serial.println(nox_index);
    Serial.print("VOC: ");
    Serial.print(srawVoc);
    Serial.print("\t");
    Serial.print("NOx: ");
    Serial.println(srawNox);
    Serial.print("errorSensorSGP41: ");
    Serial.println(errorSensorSGP41);
   #endif
    
  if(SensorVoc != voc_index){
    SensorVocO = SensorVoc;
    SensorVoc = voc_index;
    VOCindexSensor.setValue(SensorVoc);  
  }

  if(SensorNox != nox_index){
    SensorNoxO = SensorNox;
    SensorNox = nox_index; 
    NOxindexSensor.setValue(SensorNox); 
  }

  // if(SensorSrawVoc != srawVoc){
  //   SensorSrawVocO = SensorSrawVoc;
  //   SensorSrawVoc = srawVoc;  
  // }

  // if(SensorSrawNox != srawNox){
  //   SensorSrawNoxO = SensorSrawNox;
  //   SensorSrawNox = srawNox;  
  // }
    
    errorSensorSGP41 = 0;
  }

}
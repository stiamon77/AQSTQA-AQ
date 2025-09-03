void dataPMSA003(){
  pms.read();

  int SensorPm01S; 
  int SensorPm25S;
  int SensorPm10S;  

  if (pms){ // successfull read
// Unnecessary parameters//    SensorPm1 = pms.pm01;
    SensorPm01S = pms.pm01;
    SensorPm25S = pms.pm25;
    SensorPm10S = pms.pm10;
    
  if (SensorPm25 != SensorPm25S){
    SensorPm25O = SensorPm25;
    SensorPm25 = SensorPm25S;
    pm25Sensor.setValue(SensorPm25); 
  }

  if (SensorPm10 != SensorPm10S){
    SensorPm10O = SensorPm10;
    SensorPm10 = SensorPm10S;
    pm10Sensor.setValue(SensorPm10); 
  }

  if (SensorPm01 != SensorPm01S){
    SensorPm01O = SensorPm01;
    SensorPm01 = SensorPm01S;
    pm1Sensor.setValue(SensorPm01); 
  }
  
    errorSensorPMSA003 = 0;

// Unnecessary parameters//    if (pms.has_number_concentration()){
// Unnecessary parameters//      SensorNc03 = pms.n0p3;
// Unnecessary parameters//      SensorNc05 = pms.n0p5;
// Unnecessary parameters//      SensorNc10 = pms.n1p0;
// Unnecessary parameters//      SensorNc25 = pms.n2p5;
// Unnecessary parameters//      SensorNc50 = pms.n5p0;
// Unnecessary parameters//      SensorNc100 = pms.n10p0;
// Unnecessary parameters//    }

  }else{ // something went wrong

    switch (pms.status){
      
    case pms.OK: // should never come here
      break;     // included to compile without warnings

    case pms.ERROR_TIMEOUT:
      errorSensorPMSA003 = 1;

      #ifdef DEBUG
      Serial.println("----------------PMSA-003----------------");
      Serial.println(F(PMS_ERROR_TIMEOUT));
      #endif

      break;

    case pms.ERROR_MSG_UNKNOWN:
      errorSensorPMSA003 = 1;

      #ifdef DEBUG
      Serial.println("----------------PMSA-003----------------");
      Serial.println(F(PMS_ERROR_MSG_UNKNOWN));
      #endif

      break;

    case pms.ERROR_MSG_HEADER:
      errorSensorPMSA003 = 1;

      #ifdef DEBUG
      Serial.println("----------------PMSA-003----------------");
      Serial.println(F(PMS_ERROR_MSG_HEADER));
      #endif

      break;

    case pms.ERROR_MSG_BODY:
      errorSensorPMSA003 = 1;

      #ifdef DEBUG
      Serial.println("----------------PMSA-003----------------");
      Serial.println(F(PMS_ERROR_MSG_BODY));
      #endif

      break;

    case pms.ERROR_MSG_START:
      errorSensorPMSA003 = 1;

      #ifdef DEBUG
      Serial.println("----------------PMSA-003----------------");
      Serial.println(F(PMS_ERROR_MSG_START));
      #endif

      break;

    case pms.ERROR_MSG_LENGTH:
      errorSensorPMSA003 = 1;

      #ifdef DEBUG
      Serial.println("----------------PMSA-003----------------");
      Serial.println(F(PMS_ERROR_MSG_LENGTH));
      #endif

      break;

    case pms.ERROR_MSG_CKSUM:
      errorSensorPMSA003 = 1;

      #ifdef DEBUG
      Serial.println("----------------PMSA-003----------------");
      Serial.println(F(PMS_ERROR_MSG_CKSUM));
      #endif

      break;

    case pms.ERROR_PMS_TYPE:
      errorSensorPMSA003 = 1;

      #ifdef DEBUG
      Serial.println("----------------PMSA-003----------------");
      Serial.println(F(PMS_ERROR_PMS_TYPE));
      #endif
      
      break;
    }
  }
}
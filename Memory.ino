// bool defMemW = false; 0
// bool butDefault = false; 1 --
// bool AlarmBuzzer = true; 2
// bool AlarmVibration = true; 3
// bool AdaptiveBright = true; 4

// AdaptiveBright

// uint8_t AdaptiveBrightMax = 150; 5
// uint8_t AdaptiveBrightMin = 30;  6
// uint8_t NotAdaptiveBright = 50;  7
// //CO2
// uint16_t CO2GreenZone = 1000; 2 bytes 8
// uint16_t CO2OrangeZone = 2000; 2 bytes 10
// uint16_t CO2DangerZone = 2500; 2 bytes 12
// //NOx
// uint16_t NOxGreenZone = 10; 2 bytes 14
// uint16_t NOxOrangeZone = 100; 2 bytes 16
// uint16_t NOxDangerZone = 200; 2 bytes 18
// //VOC
// uint16_t VOCGreenZone = 100; 2 bytes 20
// uint16_t VOCOrangeZone = 200; 2 bytes 22
// uint16_t VOCDangerZone = 300; 2 bytes 24
// //PM2.5
// uint16_t PM25GreenZone = 50; 2 bytes 26
// uint16_t PM25OrangeZone = 100; 2 bytes 28
// uint16_t PM25DangerZone = 150; 2 bytes 30

// bool=1 address=1
// uint8_t=1 address=3
// uint16_t=2 address=8



void memStart(){

  EEPROM.begin(100);

  // Read parameters on startup

  bool _defSt;

  if(EEPROM.get(0, _defSt)){
    EEPROM.get(1, AlarmBuzzer);
    EEPROM.get(2, AlarmVibration);
    EEPROM.get(3, AdaptiveBright);
    

    EEPROM.get(4, AdaptiveBrightMax);
    EEPROM.get(5, AdaptiveBrightMin);
    EEPROM.get(6, NotAdaptiveBright);
    
//CO2
    EEPROM.get(8, CO2GreenZone);
    EEPROM.get(12, CO2OrangeZone);
    EEPROM.get(16, CO2DangerZone);
    
//NOx
    EEPROM.get(20, NOxGreenZone);
    EEPROM.get(24, NOxOrangeZone);
    EEPROM.get(28, NOxDangerZone);
    
//VOC
    EEPROM.get(32, VOCGreenZone);
    EEPROM.get(36, VOCOrangeZone);
    EEPROM.get(40, VOCDangerZone);
//PM2.5
    EEPROM.get(44, PM25GreenZone);
    EEPROM.get(48, PM25OrangeZone);
    EEPROM.get(52, PM25DangerZone);

    #ifdef DEBUG
    Serial.println(String("AlarmBuzzer=") + AlarmBuzzer);
    Serial.println(String("AlarmVibration=") + AlarmVibration);
    Serial.println(String("AlarmVibration=") + AlarmVibration);
    Serial.println(String("AdaptiveBright=") + AdaptiveBright);

    Serial.println(String("AdaptiveBrightMax=") + AdaptiveBrightMax);
    Serial.println(String("AdaptiveBrightMin=") + AdaptiveBrightMin);
    Serial.println(String("NotAdaptiveBright=") + NotAdaptiveBright);

    Serial.println(String("CO2GreenZone=") + CO2GreenZone);
    Serial.println(String("CO2OrangeZone=") + CO2OrangeZone);
    Serial.println(String("CO2DangerZone=") + CO2DangerZone);

    Serial.println(String("NOxGreenZone=") + NOxGreenZone);
    Serial.println(String("NOxOrangeZone=") + NOxOrangeZone);
    Serial.println(String("NOxDangerZone=") + NOxDangerZone);

    Serial.println(String("VOCGreenZone=") + VOCGreenZone);
    Serial.println(String("VOCOrangeZone=") + VOCOrangeZone);
    Serial.println(String("VOCDangerZone=") + VOCDangerZone);


    Serial.println(String("PM25GreenZone=") + PM25GreenZone);
    Serial.println(String("PM25OrangeZone=") + PM25OrangeZone);
    Serial.println(String("PM25DangerZone=") + PM25DangerZone);
    #endif

  }else{
    // Writing by default
    
    EEPROM.put(1, AlarmBuzzer);
    EEPROM.put(2, AlarmVibration);
    EEPROM.put(3, AdaptiveBright);

    EEPROM.put(4, AdaptiveBrightMax);
    EEPROM.put(5, AdaptiveBrightMin);
    EEPROM.put(6, NotAdaptiveBright);
//CO2
    EEPROM.put(8, CO2GreenZone);
    EEPROM.put(12, CO2OrangeZone);
    EEPROM.put(16, CO2DangerZone);
//NOx
    EEPROM.put(20, NOxGreenZone);
    EEPROM.put(24, NOxOrangeZone);
    EEPROM.put(28, NOxDangerZone);
//VOC
    EEPROM.put(32, VOCGreenZone);
    EEPROM.put(36, VOCOrangeZone);
    EEPROM.put(40, VOCDangerZone);
//PM2.5
    EEPROM.put(44, PM25GreenZone);
    EEPROM.put(48, PM25OrangeZone);
    EEPROM.put(52, PM25DangerZone);

    EEPROM.put(0, true);

    EEPROM.commit();

    memStart();
  }
}

void memUpdate(){
  
  //We write when changing

  bool _memVRB;
  uint8_t _memVR8;
  uint16_t _memVR16;

  if(defMemW){
    if(AlarmBuzzer != EEPROM.get(1, _memVRB)){EEPROM.put(1, AlarmBuzzer);}
    if(AlarmVibration != EEPROM.get(2, _memVRB)){EEPROM.put(2, AlarmVibration);}
    if(AdaptiveBright != EEPROM.get(3, _memVRB)){EEPROM.put(3, AdaptiveBright);}

    if(AdaptiveBrightMax != EEPROM.get(4, _memVR8)){EEPROM.put(4, AdaptiveBrightMax);}
    if(AdaptiveBrightMin != EEPROM.get(5, _memVR8)){EEPROM.put(5, AdaptiveBrightMin);}
    if(NotAdaptiveBright != EEPROM.get(6, _memVR8)){EEPROM.put(6, NotAdaptiveBright);}
//CO2
    if(CO2GreenZone != EEPROM.get(8, _memVR16)){EEPROM.put(8, CO2GreenZone);}
    if(CO2OrangeZone != EEPROM.get(12, _memVR16)){EEPROM.put(12, CO2OrangeZone);}
    if(CO2DangerZone != EEPROM.get(16, _memVR16)){EEPROM.put(16, CO2DangerZone);}
//NOx
    if(NOxGreenZone != EEPROM.get(20, _memVR16)){EEPROM.put(20, NOxGreenZone);}
    if(NOxOrangeZone != EEPROM.get(24, _memVR16)){EEPROM.put(24, NOxOrangeZone);}
    if(NOxDangerZone != EEPROM.get(28, _memVR16)){EEPROM.put(28, NOxDangerZone);}
//VOC
    if(VOCGreenZone != EEPROM.get(32, _memVR16)){EEPROM.put(32, VOCGreenZone);}
    if(VOCOrangeZone != EEPROM.get(36, _memVR16)){EEPROM.put(36, VOCOrangeZone);}
    if(VOCDangerZone != EEPROM.get(40, _memVR16)){EEPROM.put(40, VOCDangerZone);}
//PM2.5
    if(PM25GreenZone != EEPROM.get(44, _memVR16)){EEPROM.put(44, PM25GreenZone);}
    if(PM25OrangeZone != EEPROM.get(48, _memVR16)){EEPROM.put(48, PM25OrangeZone);}
    if(PM25DangerZone != EEPROM.get(52, _memVR16)){EEPROM.put(52, PM25DangerZone);}

    EEPROM.commit();

    defMemW = !defMemW;

  }

}
/**
uint8_t readByte(int address);
int8_t readChar(int address);
uint8_t readUChar(int address);
int16_t readShort(int address);
uint16_t get(int address);
int32_t readInt(int address);
uint32_t readUInt(int address);
int32_t readLong(int address);
uint32_t readULong(int address);
int64_t readLong64(int address);
uint64_t readULong64(int address);
float_t readFloat(int address);
double_t readDouble(int address);
bool readBool(int address);
size_t readString(int address, char* value, size_t maxLen);
String readString(int address);
size_t readBytes(int address, void * value, size_t maxLen);
template <class T> T readAll (int address, T &);

size_t put(int address, uint8_t value);
size_t writeChar(int address, int8_t value);
size_t writeUChar(int address, uint8_t value);
size_t writeShort(int address, int16_t value);
size_t put(int address, uint16_t value);
size_t writeInt(int address, int32_t value);
size_t writeUInt(int address, uint32_t value);
size_t writeLong(int address, int32_t value);
size_t writeULong(int address, uint32_t value);
size_t writeLong64(int address, int64_t value);
size_t writeULong64(int address, uint64_t value);
size_t writeFloat(int address, float_t value);
size_t writeDouble(int address, double_t value);
size_t put(int address, bool value);
size_t writeString(int address, const char* value);
size_t writeString(int address, String value);
size_t puts(int address, const void* value, size_t len);
*/
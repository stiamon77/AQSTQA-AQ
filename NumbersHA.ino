//AdaptiveBright
void numAdaptiveBrightMaxCom(HANumeric numberAdaptiveBrightMax, HANumber* numberAdaptiveBrightMaxsender){
    if (!numberAdaptiveBrightMax.isSet()) {
        // command was send by Home Assistant
        AdaptiveBrightMax = 255;
    } else {
        AdaptiveBrightMax = numberAdaptiveBrightMax.toUInt8();
    }
    numberAdaptiveBrightMaxsender->setState(AdaptiveBrightMax); // report the selected option back to the HA panel
    defMemW = true;
}

void numAdaptiveBrightMinCom(HANumeric numberAdaptiveBrightMin, HANumber* numberAdaptiveBrightMinsender){
    if (!numberAdaptiveBrightMin.isSet()) {
        // command was send by Home Assistant
        AdaptiveBrightMin = 50;
    } else {
        AdaptiveBrightMin = numberAdaptiveBrightMin.toUInt8();
    }
    numberAdaptiveBrightMinsender->setState(AdaptiveBrightMin); // report the selected option back to the HA panel
    defMemW = true;
}

void numNotAdaptiveBrightCom(HANumeric numberNotAdaptiveBright, HANumber* numberNotAdaptiveBrightsender){
    if (!numberNotAdaptiveBright.isSet()) {
        // command was send by Home Assistant
        NotAdaptiveBright = 150;
    } else {
        NotAdaptiveBright = numberNotAdaptiveBright.toUInt8();
    }
    numberNotAdaptiveBrightsender->setState(NotAdaptiveBright); // report the selected option back to the HA panel
    defMemW = true;
}
//CO2
void numCO2GreenZoneCom(HANumeric numberCO2GreenZone, HANumber* numberCO2GreenZonesender){
    if (!numberCO2GreenZone.isSet()) {
        // command was send by Home Assistant
        CO2GreenZone = 1000;
    } else {
        CO2GreenZone = numberCO2GreenZone.toUInt16();
    }
    numberCO2GreenZonesender->setState(CO2GreenZone); // report the selected option back to the HA panel
    defMemW = true;
}

void numCO2OrangeZoneCom(HANumeric numberCO2OrangeZone, HANumber* numberCO2OrangeZonesender){
    if (!numberCO2OrangeZone.isSet()) {
        // command was send by Home Assistant
        CO2OrangeZone = 2000;
    } else {
        CO2OrangeZone = numberCO2OrangeZone.toUInt16();
    }
    numberCO2OrangeZonesender->setState(CO2OrangeZone); // report the selected option back to the HA panel
    defMemW = true;
}

void numCO2DangerZoneCom(HANumeric numberCO2DangerZone, HANumber* numberCO2DangerZonesender){
    if (!numberCO2DangerZone.isSet()) {
        // command was send by Home Assistant
        CO2DangerZone = 2500;
    } else {
        CO2DangerZone = numberCO2DangerZone.toUInt16();
    }
    numberCO2DangerZonesender->setState(CO2DangerZone); // report the selected option back to the HA panel
    defMemW = true;
}

//NOx
void numNOxGreenZoneCom(HANumeric numberNOxGreenZone, HANumber* numberNOxGreenZonesender){
    if (!numberNOxGreenZone.isSet()) {
        // command was send by Home Assistant
        NOxGreenZone = 10;
    } else {
        NOxGreenZone = numberNOxGreenZone.toUInt16();
    }
    numberNOxGreenZonesender->setState(NOxGreenZone); // report the selected option back to the HA panel
    defMemW = true;
}

void numNOxOrangeZoneCom(HANumeric numberNOxOrangeZone, HANumber* numberNOxOrangeZonesender){
    if (!numberNOxOrangeZone.isSet()) {
        // command was send by Home Assistant
        NOxOrangeZone = 100;
    } else {
        NOxOrangeZone = numberNOxOrangeZone.toUInt16();
    }
    numberNOxOrangeZonesender->setState(NOxOrangeZone); // report the selected option back to the HA panel
    defMemW = true;
}

void numNOxDangerZoneCom(HANumeric numberNOxDangerZone, HANumber* numberNOxDangerZonesender){
    if (!numberNOxDangerZone.isSet()) {
        // command was send by Home Assistant
        NOxDangerZone = 200;
    } else {
        NOxDangerZone = numberNOxDangerZone.toUInt16();
    }
    numberNOxDangerZonesender->setState(NOxDangerZone); // report the selected option back to the HA panel
    defMemW = true;
}
//VOC
void numVOCGreenZoneCom(HANumeric numberVOCGreenZone, HANumber* numberVOCGreenZonesender){
    if (!numberVOCGreenZone.isSet()) {
        // command was send by Home Assistant
        VOCGreenZone = 100;
    } else {
        VOCGreenZone = numberVOCGreenZone.toUInt16();
    }
    numberVOCGreenZonesender->setState(VOCGreenZone); // report the selected option back to the HA panel
    defMemW = true;
}

void numVOCOrangeZoneCom(HANumeric numberVOCOrangeZone, HANumber* numberVOCOrangeZonesender){
    if (!numberVOCOrangeZone.isSet()) {
        // command was send by Home Assistant
        VOCOrangeZone = 200;
    } else {
        VOCOrangeZone = numberVOCOrangeZone.toUInt16();
    }
    numberVOCOrangeZonesender->setState(VOCOrangeZone); // report the selected option back to the HA panel
    defMemW = true;
}

void numVOCDangerZoneCom(HANumeric numberVOCDangerZone, HANumber* numberVOCDangerZonesender){
    if (!numberVOCDangerZone.isSet()) {
        // command was send by Home Assistant
        VOCDangerZone = 200;
    } else {
        VOCDangerZone = numberVOCDangerZone.toUInt16();
    }
    numberVOCDangerZonesender->setState(VOCDangerZone); // report the selected option back to the HA panel
    defMemW = true;
}
//PM25
void numPM25GreenZoneCom(HANumeric numberPM25GreenZone, HANumber* numberPM25GreenZonesender){
    if (!numberPM25GreenZone.isSet()) {
        // command was send by Home Assistant
        PM25GreenZone = 50;
    } else {
        PM25GreenZone = numberPM25GreenZone.toUInt16();
    }
    numberPM25GreenZonesender->setState(PM25GreenZone); // report the selected option back to the HA panel
    defMemW = true;
}

void numPM25OrangeZoneCom(HANumeric numberPM25OrangeZone, HANumber* numberPM25OrangeZonesender){
    if (!numberPM25OrangeZone.isSet()) {
        // command was send by Home Assistant
        PM25OrangeZone = 100;
    } else {
        PM25OrangeZone = numberPM25OrangeZone.toUInt16();
    }
    numberPM25OrangeZonesender->setState(PM25OrangeZone); // report the selected option back to the HA panel
    defMemW = true;
}

void numPM25DangerZoneCom(HANumeric numberPM25DangerZone, HANumber* numberPM25DangerZonesender){
    if (!numberPM25DangerZone.isSet()) {
        // command was send by Home Assistant
        PM25DangerZone = 100;
    } else {
        PM25DangerZone = numberPM25DangerZone.toUInt16();
    }
    numberPM25DangerZonesender->setState(PM25DangerZone); // report the selected option back to the HA panel
    defMemW = true;
}
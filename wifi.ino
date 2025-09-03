void startWIFI (){
// Unique ID must be set!
/*  
  byte mac[WL_MAC_ADDR_LENGTH];
  WiFi.macAddress(mac);
  device.setUniqueId(mac, sizeof(mac));
*/

  byte mac[6];
  WiFi.macAddress(mac);
  device.setUniqueId(mac, sizeof(mac));

  for(int i=0; i<17; i=i+8) {
	chipId |= ((ESP.getEfuseMac() >> (40 - i)) & 0xff) << i;
	}

  clientId = "AQSTQA-AQ-"+String(chipId, HEX);

  // init the WiFi connection
  #ifdef DEBUG
  Serial.println();
  Serial.println();
  Serial.print("INFO: Connecting to ");
  #endif

  WiFi.mode(WIFI_STA);

  #ifdef DEBUG
  Serial.println(WIFI_SSID);
  #endif 

  WiFi.begin(WIFI_SSID, WIFI_PASSWORD);
 
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);

    #ifdef DEBUG
    Serial.print(".");
    #endif 
    
  }
  
  #ifdef DEBUG
  Serial.println("");
  Serial.println("INFO: WiFi connected");
  Serial.print("INFO: IP address: ");
  Serial.println(WiFi.localIP());

  Serial.print(". Signal strength: ");
  Serial.print(2*(WiFi.RSSI()+100));
  Serial.println("%");

  Serial.println();
  Serial.print("MAC: ");
  Serial.println(WiFi.macAddress());    
  
  Serial.print("Free Heap size: ");
  Serial.print(ESP.getFreeHeap()/1024);
  Serial.println("Kb");
  #endif 

  // IPAddress ipa = WiFi.localIP();
  // uint8_t IP_array[4]= {ipa[0],ipa[1],ipa[2],ipa[3]};
  // String strIP=
  //   String(IP_array[0])+"."+
  //   String(IP_array[1])+"."+
  //   String(IP_array[2])+"."+
  //   String(IP_array[3]);

  // ipAddressS = strIP;
  // macAddressS = String(WiFi.macAddress());
  // SensorWiFi_RSSIS = String(2*(WiFi.RSSI()+100));

  clientId.toUpperCase();
  /* esp8266
  if (MDNS.begin(clientId)) {
    #ifdef DEBUG
    // at this stage your device will be available using the domain name "arduinoha.local"
    Serial.println("MDNS initialized - "+clientId+".local");
    #endif
  } else {
    #ifdef DEBUG
    Serial.println("Failed to initialize MDNS");
    #endif
    return;
  }
  */
  WiFi.hostname(clientId); //esp32
}
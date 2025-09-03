esp_timer_handle_t timer1;
volatile bool timerActive1 = false;
int timeSec1 = 5*1000*1000;


void timer1Start(){
//TIMERS
//create timer parameters..
  const esp_timer_create_args_t timer_args1 = {
    .callback = &timer_callback1, //link the call back
    .arg = nullptr, //not passing in anything
    .dispatch_method = ESP_TIMER_TASK, // The handler will be called from the task (another option is from the ISR)
    .name = "timer1", //nice name
    .skip_unhandled_events = false     // If any timer trigger was missed, then process it anyway
  };
//create timer, not running yet..
  ESP_ERROR_CHECK(esp_timer_create(&timer_args1, &timer1));
}

void timer1Data(){

  if (esp_timer_is_active(timer1)) {
    timerActive1 = true;
  }else{
    timerActive1 = false;
  }

  if (!timerActive1) {
    //check state of timer and stop it if needed..
    if (esp_timer_is_active(timer1)) {
      ESP_ERROR_CHECK(esp_timer_stop(timer1));
    }
    //start our one shot timer for 1 second.. periodic
    ESP_ERROR_CHECK(esp_timer_start_periodic(timer1, timeSec1));

    #ifdef DEBUG
    Serial.println("Restarting On-shot timer with 3s period, time since boot");
    #endif

    timerActive1 = true;
  }
}

//call back for timer 3s..
static void timer_callback1(void* arg){

  #ifdef DEBUG
  Serial.println("One-shot timer called, time since boot"); //ln
  #endif

  timerActive1 = true;

  //Таймер------------------------------------------------------

  dataBME280();
  dataSCD30();
  dataSGP41();

  //Checking WiFi connection
  if (WiFi.status() != WL_CONNECTED) {

    #ifdef DEBUG
    Serial.print(millis());
    Serial.println("Reconnecting to WiFi...");
    #endif

    WiFi.disconnect();
    WiFi.reconnect();

  } 


  //---------Data Telemetry---------
  float SensorWiFi_RSSIs; //signal level

  SensorWiFi_RSSIs = 2*(WiFi.RSSI()+100);

  if(SensorWiFi_RSSI != SensorWiFi_RSSIs){
    SensorWiFi_RSSI = SensorWiFi_RSSIs;
    // SensorWiFi_RSSIS = String(SensorWiFi_RSSI);
    signalSensor.setValue(SensorWiFi_RSSIs);

    #ifdef DEBUG
    Serial.print("Signal strength: ");
    Serial.print(SensorWiFi_RSSI);
    Serial.println("%");
    #endif 
    
  }
//------------------------------------------------------
}
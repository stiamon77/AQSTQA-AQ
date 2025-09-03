esp_timer_handle_t timer2;
volatile bool timerActive2 = false;
int timeSec2 = 1*1000*1000;


void timer2Start(){
//TIMERS
//create timer parameters..
  const esp_timer_create_args_t timer_args2 = {
    .callback = &timer_callback2, //link the call back
    .arg = nullptr, //not passing in anything
    .dispatch_method = ESP_TIMER_TASK, // The handler will be called from the task (another option is from the ISR)
    .name = "timer2", //nice name
    .skip_unhandled_events = false     // If any timer trigger was missed, then process it anyway
  };
//create timer, not running yet..
  ESP_ERROR_CHECK(esp_timer_create(&timer_args2, &timer2));
}

void timer2Data(){

  if (esp_timer_is_active(timer2)) {
    timerActive2 = true;
  }else{
    timerActive2 = false;
  }

  if (!timerActive2) {
    //check state of timer and stop it if needed..
    if (esp_timer_is_active(timer2)) {
      ESP_ERROR_CHECK(esp_timer_stop(timer2));
    }
    //start our one shot timer for 2 second.. periodic
    ESP_ERROR_CHECK(esp_timer_start_periodic(timer2, timeSec2));

    #ifdef DEBUG
    Serial.println("Restarting On-shot timer2 with 3s period, time since boot");
    #endif

    timerActive2 = true;
  }
}

//call back for timer 3s..
static void timer_callback2(void* arg){

  #ifdef DEBUG
  Serial.println("One-shot timer called, time since boot"); //ln
  #endif

  timerActive2 = true;

//Timer------------------------------------------------------
  dataMAX44009(); //data MAX44009


  clockTime();
  dataLEDs();
  printDisplays();
  blinkLed = !blinkLed;
#ifdef DEBUG
    Serial.println(String("defMemW=")+defMemW);
    Serial.println(String("AlarmBuzzer=")+AlarmBuzzer);
    Serial.println(String("AlarmVibration=")+AlarmVibration);
    Serial.println(String("AdaptiveBright=")+AdaptiveBright);

    Serial.println(String("AdaptiveBrightMax=")+AdaptiveBrightMax);
    Serial.println(String("AdaptiveBrightMin=")+AdaptiveBrightMin);
    Serial.println(String("NotAdaptiveBright=")+NotAdaptiveBright);

    Serial.println(String("CO2GreenZone=")+CO2GreenZone);
    Serial.println(String("CO2OrangeZone=")+CO2OrangeZone);
    Serial.println(String("CO2DangerZone=")+CO2DangerZone);

    Serial.println(String("NOxGreenZone=")+NOxGreenZone);
    Serial.println(String("NOxOrangeZone=")+NOxOrangeZone);
    Serial.println(String("NOxDangerZone=")+NOxDangerZone);

    Serial.println(String("VOCGreenZone=")+VOCGreenZone);
    Serial.println(String("VOCOrangeZone=")+VOCOrangeZone);
    Serial.println(String("VOCDangerZone=")+VOCDangerZone);


    Serial.println(String("PM25GreenZone=")+PM25GreenZone);
    Serial.println(String("PM25OrangeZone=")+PM25OrangeZone);
    Serial.println(String("PM25DangerZone=")+PM25DangerZone);
#endif  
//------------------------------------------------------------
}
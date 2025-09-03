esp_timer_handle_t timer3;
volatile bool timerActive3 = false;
int timeSec3 = 12*1000*1000;


void timer3Start(){
//TIMERS
//create timer parameters..
  const esp_timer_create_args_t timer_args3 = {
    .callback = &timer_callback3, //link the call back
    .arg = nullptr, //not passing in anything
    .dispatch_method = ESP_TIMER_TASK, // The handler will be called from the task (another option is from the ISR)
    .name = "timer3", //nice name
    .skip_unhandled_events = false     // If any timer trigger was missed, then process it anyway
  };
//create timer, not running yet..
  ESP_ERROR_CHECK(esp_timer_create(&timer_args3, &timer3));
}

void timer3Data(){

  if (esp_timer_is_active(timer3)) {
    timerActive3 = true;
  }else{
    timerActive3 = false;
  }

  if (!timerActive3) {
    //check state of timer and stop it if needed..
    if (esp_timer_is_active(timer3)) {
      ESP_ERROR_CHECK(esp_timer_stop(timer3));
    }
    //start our one shot timer for 2 second.. periodic
    ESP_ERROR_CHECK(esp_timer_start_periodic(timer3, timeSec3));

    #ifdef DEBUG
    Serial.println("Restarting On-shot timer3 with 3s period, time since boot");
    #endif

    timerActive3 = true;
  }
}

//call back for timer 3s..
static void timer_callback3(void* arg){

  #ifdef DEBUG
  Serial.println("One-shot timer called, time since boot"); //ln
  #endif

  timerActive3 = true;

//Timer------------------------------------------------------
  // startSendHA();
  memUpdate();
  dataPMSA003();
  
//------------------------------------------------------------
}
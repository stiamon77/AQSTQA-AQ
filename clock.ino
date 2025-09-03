/**
%A	returns day of week
%B	returns month of year
%d	returns day of month
%Y	returns year
%H	returns hour
%M	returns minutes
%S	returns seconds

https://cplusplus.com/reference/ctime/tm/

The tm structure contains a calendar date and time broken down into its components:

tm_sec: seconds after the minute;
tm_min: minutes after the hour;
tm_hour: hours since midnight;
tm_mday: day of the month;
tm_year: years since 1900;
tm_wday: days since Sunday;
tm_yday: days since January 1;
tm_isdst: Daylight Saving Time flag;

%A	Full weekday name
%B	Full month name
%d	Day of the month
%Y	Year
%H	Hour in 24h format
%I	Hour in 12h format
%M	Minute
%S	Second

https://cplusplus.com/reference/ctime/strftime/

https://randomnerdtutorials.com/esp32-date-time-ntp-client-server-arduino/
*/

// Callback function (get's called when time adjusts via NTP)
void timeavailable(struct timeval *t){
  #ifdef DEBUG
  Serial.println("Got time adjustment from NTP!");
  #endif
  clockTime();
}

void ntpStart(){
  // set notification call-back function
  sntp_set_time_sync_notification_cb( timeavailable );

  /**
   * NTP server address could be aquired via DHCP,
   *
   * NOTE: This call should be made BEFORE esp32 aquires IP address via DHCP,
   * otherwise SNTP option 42 would be rejected by default.
   * NOTE: configTime() function call if made AFTER DHCP-client run
   * will OVERRIDE aquired NTP server address
   */
  // sntp_servermode_dhcp(1);    // (optional)
  // sntp_setservername(1, "europe.pool.ntp.org"); //fallback server
  // sntp_init();

  /**
   * This will set configured ntp servers and constant TimeZone/daylightOffset
   * should be OK if your time zone does not need to adjust daylightOffset twice a year,
   * in such a case time adjustment won't be handled automagicaly.
   */
  configTime(gmtOffset_sec, daylightOffset_sec, ntpServer1, ntpServer2);
}

void clockTime(){
  struct tm timeinfo;
  if(!getLocalTime(&timeinfo)){
    #ifdef DEBUG
    Serial.println("No time available (yet)");
    #endif
    return;
  }
 #ifdef DEBUG
  Serial.println(&timeinfo, "%A, %B %d %Y %H:%M:%S");
 #endif

  timS = timeinfo.tm_sec;
  timM = timeinfo.tm_min;
  timH = timeinfo.tm_hour;

  timDate = timeinfo.tm_mday;
  timWeek = timeinfo.tm_wday;
  timMonth = timeinfo.tm_mon;
  timYear = timeinfo.tm_year;

  // dayOfWeek = daysOfTheWeek[timeinfo.tm_wday];
  // dayDate = timeinfo.tm_mday;
  // dayMonth = months[timeinfo.tm_mon + 1];
  // dayYear = timeinfo.tm_year + 1900;

/**
  //Display Clock
  if (timeinfo.tm_sec <= 9){
    timS = String("0") + timeinfo.tm_sec;
  }else{
    timS = timeinfo.tm_sec;
  }

  if (timeinfo.tm_min <= 9){
    timM = String("0") + timeinfo.tm_min;
  }else{
    timM = timeinfo.tm_min;
  }

  if (timeinfo.tm_hour <= 9){
    timH = String("0") + timeinfo.tm_hour;
  }else{
    timH = timeinfo.tm_hour;
  }

tm_mday: day of the month;
tm_year: years since 1900;
tm_wday: days since Sunday;
tm_yday: days since January 1;
*/

}
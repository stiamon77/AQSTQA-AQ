void onBuzzerCommand(bool BuzzerState, HASwitch* BuzzerSender){
    if (BuzzerState){
      AlarmBuzzer = true;
    }else{
      AlarmBuzzer = false;
    }
  BuzzerSender->setState(BuzzerState); // report state back to the Home Assistant
  defMemW = true;
}

void onVibrationCommand(bool VibrationState, HASwitch* VibrationSender){
    if (VibrationState){
      AlarmVibration = true;
    }else{
      AlarmVibration = false;
    }
  VibrationSender->setState(VibrationState); // report state back to the Home Assistant
  defMemW = true;
}

void onAdaptiveBrightCommand(bool AdaptiveBrightState, HASwitch* AdaptiveBrightSender){
    if (AdaptiveBrightState){
      AdaptiveBright = true;
    }else{
      AdaptiveBright = false;
    }
  AdaptiveBrightSender->setState(AdaptiveBrightState); // report state back to the Home Assistant
  defMemW = true;
}





// void onBuzzerCommand(int8_t index, HASelect* senderBuzzer)
// {
//     switch (index) {
//     case 0:
//         // Option "Off" was selected
//         AlarmBuzzer = true;
//         #ifdef DEBUG
//         Serial.println("----------------Buzzer Select On----------------");
//         #endif
//         break;
//     case 1:
//         // Option "2" was selected
//         AlarmBuzzer = false;
//         #ifdef DEBUG
//         Serial.println("----------------Buzzer Select Off----------------");
//         #endif
//         break;

//     default:
//         // unknown option
//         AlarmBuzzer = true;
//         selectBuzzer.setState(0);
//         return;
//     }

//     senderBuzzer->setState(index); // report the selected option back to the HA panel
// }

// void onVibrationCommand(int8_t index, HASelect* senderVibration)
// {
//     switch (index) {
//     case 0:
//         // Option "Off" was selected
//         AlarmVibration = true;
//         #ifdef DEBUG
//         Serial.println("----------------Vibration Select On----------------");
//         #endif
//         break;
//     case 1:
//         // Option "2" was selected
//         AlarmVibration = false;
//         #ifdef DEBUG
//         Serial.println("----------------Vibration Select Off----------------");
//         #endif
//         break;

//     default:
//         // unknown option
//         AlarmVibration = true;
//         selectVibration.setState(0);
//         return;
//     }

//     senderVibration->setState(index); // report the selected option back to the HA panel
// }

// void onAdaptiveBrightCommand(int8_t index, HASelect* senderAdaptiveBright)
// {
//     switch (index) {
//     case 0:
//         // Option "Off" was selected
//         AdaptiveBright = true;
//         #ifdef DEBUG
//         Serial.println("----------------AdaptiveBright Select On----------------");
//         #endif
//         break;
//     case 1:
//         // Option "2" was selected
//         AdaptiveBright = false;
//         #ifdef DEBUG
//         Serial.println("----------------AdaptiveBright Select Off----------------");
//         #endif
//         break;

//     default:
//         // unknown option
//         AdaptiveBright = true;
//         selectVibration.setState(0);
//         return;
//     }

//     senderAdaptiveBright->setState(index); // report the selected option back to the HA panel
// }
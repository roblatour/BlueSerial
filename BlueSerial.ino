/*
  BlueSerial
  Copyright, Rob Latour. 2021
  License: MIT
  Proof of concept

  Leverages the ESP's bluetooth functionality, and your computer's monitor as a display for debugging outputs much like a serial monitor

  Step 1: open a blank text document on your computer/iPad/whatever

  Step 2: upload and run sketch

  Step 3: pair this device with a Windows computer/iPad/whatever

     1. Go to your computers/iPad's settings
     2. Ensure Bluetooth is turned on
     3. Scan for new Bluetooth devices
     4. Connect to the device called BlueSerial

  Step 4: (in the next 30 seconds) click on the blank text document to make it your active window

  Step 5: (wait for the 30 seconds to end) enjoy the show

*/

#include <Arduino.h>
#include <BleKeyboard.h>
BleKeyboard bleKeyboard("BlueSerial", "", 100);

void log(String message) {

  if (bleKeyboard.isConnected()) {
    int len = message.length();
    for (int i = 0; i <= len - 1; i++) {
      bleKeyboard.write(message.charAt(i));
      delay(10);
    }
    bleKeyboard.write(KEY_RETURN);
    delay(10);
  }

}

void setup() {
  
  bleKeyboard.begin();
  
}

void loop() {

  static bool DoOnce = true;

  if (bleKeyboard.isConnected()) {

    if (DoOnce) {

      DoOnce = false;

      // pause 30 seconds to let the user do setp 4 as noted above
      // however once paired, this delay can be removed
      delay(30 *  1000);

      log("Started");
      log("This is a test.");
      for (int i = 0; i <= 10; i++)
        log(String(i));
      log("That's it, have a nice day!");

    }

  }

}

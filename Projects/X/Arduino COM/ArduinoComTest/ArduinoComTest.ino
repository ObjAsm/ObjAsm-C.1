// ************************************************************************************************
// Project:     ArduinoComTest
// Description: Arduino - PC communication test
// Author:      G. Friedrich
// Version:     1.0.0, October 2020
// Docs:        https://www.arduino.cc/reference/en/language/functions/communication/serial/


// **** Globals switches **************************************************************************
#define DEBUGGING                                       // Use Serial to show debug information


// **** Code **************************************************************************************
void setup() {
  #ifdef DEBUGGING
    Serial.begin(9600, SERIAL_8N1);                     // Setup serial COM Port
    while (!Serial) {}                                  // Wait for serial port to connect
  #endif                                                // Needed for native USB port only
  //Serial.println("Arduino ready");
}

void loop() {
  String InString;

  if (Serial.available() > 0) {                         // Test if serial data arrived
    InString = Serial.readString();
    if (InString == "PC is here") {
      Serial.println("Arduino is here too...");         // Respond on Serial
      Serial.flush();                                   // Send the message
    }
  }
}

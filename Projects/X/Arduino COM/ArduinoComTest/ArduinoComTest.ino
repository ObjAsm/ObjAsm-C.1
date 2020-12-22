// ************************************************************************************************
// Project:     ArduinoComTest
// Description: Arduino - PC ObjAsm communication test
// Author:      G. Friedrich
// Version:     1.0.0, October 2020
// Docs:        https://www.arduino.cc/reference/en/language/functions/communication/serial/


// **** Code **************************************************************************************
void setup() {
  Serial.begin(9600, SERIAL_8N1);                       // Setup serial COM Port
  while (!Serial) {}                                    // Wait for serial port to connect
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

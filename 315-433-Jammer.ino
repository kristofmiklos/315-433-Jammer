// This sketch has been tested as working with the FS1000A 315mhz transmitter.  
// 12V input recommended to maximize effective range (up to 150m).
// Written by Chris Nicholas of Alpha Victor Technical

int ledState = LOW;
unsigned long previousMillis = 0;
const long interval = 25;

#define VCC 2           // VCC Pin to Digital Pin 2
#define Data 3          // Data Pin to Digital Pin 3
#define Gnd 4           // Gnd Pin to Digital Pin 4
#define LED 13          // Built-in LED

void setup() {


  pinMode(VCC, OUTPUT);
  pinMode(Data, OUTPUT);
  pinMode(Gnd, OUTPUT);
  pinMode(LED, LED_BUILTIN);

  digitalWrite(VCC, HIGH);
  digitalWrite(Gnd, LOW);

}

void loop() {

  unsigned long currentMillis = millis();

  if (currentMillis - previousMillis >= interval) {
    previousMillis = currentMillis;

    if (ledState == LOW) {
      ledState = HIGH;
    } else {
      ledState = LOW;
    }

    digitalWrite(LED, ledState);
  }


  digitalWrite(Data, HIGH);     // Transmit a binary 1
  delay(5);                     // Pause
  digitalWrite(Data, HIGH);      // Transmit a binary 1



}

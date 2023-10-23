
#include <Arduino.h>

void setup() {
  Serial.begin(115200);
  delay(100);
  while (!Serial) {
  }
  Serial.print("hello");
}

void loop() {
  Serial.print("project-mahiwa\n");

  delay(100);
}

#include <Arduino.h>
#include "DisplayEngine.h"
#include "AnimatingCircle.h"
#include "AnimatingArrow.h"

DisplayEngine engine = DisplayEngine();
Point origin = engine.getCenterScreen();

int16_t angle = 0;
void setup() {  
  Serial.begin(115200);
  engine.addComponent(new AnimatingCircle(origin, 0, 60)); //TODO: FREE MEMORY
  engine.addComponent(new AnimatingArrow(origin, 45, 6, 0));

  engine.init();
  engine.clear();
  engine.end();
}

void loop() {
  engine.init();
  
  engine.loop();

  engine.end();
  delay(50);  
}


#include <Arduino.h>

#define MA_BROCHE_BOUTON 39 //bouton
#include <MicroOscSlip.h>
#define MA_BROCHE_ANGLE 32 //potentiomètre
#include <FastLED.h>

MicroOscSlip<128> monOsc(& Serial); // nombre entre 0 à 128 
CRGB pixelATOM;

void setup() {
  Serial.begin(115200);
  pinMode( MA_BROCHE_BOUTON , INPUT );
  FastLED.addLeds < WS2812,27,GRB> ( & pixelATOM, 1);
}

void loop() {
  int maLectureBouton = digitalRead( MA_BROCHE_BOUTON );
  //Serial.println(maLectureBouton);
  

  //exercice 1 - 
  int maLectureAngle = analogRead(MA_BROCHE_ANGLE);
  monOsc.sendInt("/angle", maLectureAngle);
  
  monOsc.sendInt("/bouton", maLectureBouton);

  // exercice 2 - 
  pixelATOM = CRGB(0,(millis() % 255),0);
  FastLED.show();

  delay(100);
}
/* 
 * Project: Skibidi Cuckoo Clock IOT Midterm
 * Author: Caroline Blaker
 * Date: 2024-10-29
 * Completely unserious novelty room controller clock that celebrates the hour.
 * https://docs.particle.io/firmware/best-practices/firmware-template/
 */


#include "Particle.h"
#include "Button.h"
#include "Neopixel.h"
#include "IoTClassroom_CNM.h"
#include "Colors.h"
// Add Libraries
// Servo
// Mp3 player
// OLED

// Pin number straight from sample code. Change at will
const int MYWEMO = 1;
const int BUTTONPIN = D2;
const int BUTTON2PIN = D7;
const int PIXELCOUNT = 16;
bool onOff = 0;
bool playNow =0;
int now;
int timeCode;
int timeHour;
int timeMinute;
int timeSeconds;
int begin = 55;

// Use our WiFi
//SYSTEM_MODE(SEMI_AUTOMATIC);
SYSTEM_MODE(MANUAL);

Button lightButton(BUTTONPIN);
Button powerButton(BUTTON2PIN);
Adafruit_NeoPixel pixel(PIXELCOUNT, SPI, WS2812B);

void displayTheTime(int timeHour,int timeMinute);
void playShow();
void pixelFill(int start, int end, int color);

// Let's get going
void setup() {
  Serial.begin(9600);

  pixel.begin();
  pixel.setBrightness(37);
  pixel.show(); //initialize all off
  
  WiFi.on();
  WiFi.clearCredentials();
  WiFi.setCredentials("IoTNetwork");
  WiFi.connect();
  while (WiFi.connecting()){
  //  Serial.print(".");
  }
  waitFor(Serial.isConnected,15000);
  //Serial.print("\nSerial begin\n");
  //TODO: get the time
  timeCode = millis();
}

void loop() { 
  now= millis();
 // Serial.print("Loop\n");
  if (powerButton.isClicked()){
    onOff= !onOff;
    Serial.print("Power button clicked\n");
  }
  if (lightButton.isClicked()){
    Serial.print("Light button clicked\n");
    playNow=1;
  }
  // Display the time
  // If the time is right, do the show
  // if (time seconds ==56){
  //  playNow=1;
  //}
  if (playNow){
    playShow();
  }
}

void  displayTheTime(int timeHour, int timeMinute){
 // display
}
void  playShow(){
  Serial.print("\nWelcome to the shit show\n");
  wemoWrite(MYWEMO,1);
  // Sequence of cool shit (come on, it's toilet themed.)
  pixelFill(0,15,magenta);
  playNow=0;
  delay(5000);
  wemoWrite(MYWEMO,0);
  pixel.clear(); // not working
  pixel.show();

}
void pixelFill(int start, int end, int color) {
    int _i;
    for (_i = start; _i <= end; _i++ ){
        pixel.setPixelColor(_i, color);
    }
    pixel.show();
  }

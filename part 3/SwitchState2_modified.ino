/*
  basic state machine 2
 
  Modified to switch between states to write, read and clear EEPROM
 
 Demonstrates how to use a case statement to create a simple state machine.
 This code uses a potentiometer knob to select between 3 states.
 
 The circuit:
 * pot from analog in 0 to +5V
 * 10K resistor from analog in 0 to ground
 
 created 13 Apr 2010
 by Wendy Ju 
 modified from switchCase by Tom Igoe
 
 12 Sep 2018
 Modified to switch between states to write, read and clear EEPROM
 */

#include <EEPROM.h>

#include <SPI.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#include <Adafruit_LIS3DH.h>
#include <Adafruit_Sensor.h>

#define SCREEN_WIDTH 128 // OLED display width, in pixels
#define SCREEN_HEIGHT 32 // OLED display height, in pixels

// Used for software SPI
#define LIS3DH_CLK 13
#define LIS3DH_MISO 12
#define LIS3DH_MOSI 11
// Used for hardware & software SPI
#define LIS3DH_CS 10

// Declaration for an SSD1306 display connected to I2C (SDA, SCL pins)
#define OLED_RESET     4 // Reset pin # (or -1 if sharing Arduino reset pin)
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);

// I2C
//Adafruit_LIS3DH lis = Adafruit_LIS3DH();

const int numStates = 3;
const int sensorMin =0;
const int sensorMax = 1024;
const int EEPROMSIZE=1024;


struct SensorValue {
  int field1;
};

int sensorPin = 0;    // select the input pin for the potentiometer
int ledPin = LED_BUILTIN;    
int state,lastState = -1;

const int analogInPin = A1;
int sensorValue = 0; 
int outputValue = 0;  
const int totalValues = 20;
int current = 0;
int prevAddress = 0;


void setup() {
  // initialize serial communication:
  Serial.begin(9600);  
  pinMode(ledPin, OUTPUT);  

  // SSD1306_SWITCHCAPVCC = generate display voltage from 3.3V internally
  if(!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) { // Address 0x3C for 128x32
    Serial.println(F("SSD1306 allocation failed"));
    for(;;); // Don't proceed, loop forever
  }

  // Show initial display buffer contents on the screen --
  // the library initializes this with an Adafruit splash screen.
  display.display();
  delay(2000); // Pause for 2 seconds

  // Clear the buffer
  display.clearDisplay();

  // Draw a single pixel in white
  display.drawPixel(10, 10, WHITE);

  // Show the display buffer on the screen. You MUST call display() after
  // drawing commands to make them visible on screen!
  display.display();
  delay(2000);
}

void loop() {

  if(current < totalValues && state == 2) 
  {
    // read the analog in value:
    sensorValue = analogRead(analogInPin);
    outputValue = sensorValue;//map(sensorValue, 0, 1023, 0, 255);
  
    // print the results to the Serial Monitor:
    Serial.print(String(current) + "sensor = ");
    Serial.print(sensorValue);
    Serial.print("\t output = ");
    Serial.println(outputValue);
    delay(1000);
    
    //Serial.println("Pin reading " + String(sensorPinVal));
    // do something different depending on the 
    // range value:

    current = current + 1;
  }

  // map the pot range to number of states :
    float sensorPinVal = analogRead(sensorPin);
    state = map(sensorPinVal, sensorMin, sensorMax, 0, numStates);
    
  switch (state) {
  case 0:   
    current = 0; 
    prevAddress = 0;
    doState0();
    lastState = state;
    testscrolltext("done clearing", "Grrrrrrrrrrr");
    break;
  case 1:    
  
    doState1();
    testscrolltext("done reading", "Boring :( :( :( :(");
    lastState = state;
    
    break;
  case 2:
  if(current < totalValues) {    
      doState2(outputValue); 
      lastState = state;
    }
    else {
      testscrolltext("Done writing", "Hurrayyyyyyyyy!");
    }
    break;
  } 
}

void testscrolltext(String firstline, String secondline) {
  display.clearDisplay();

  display.setTextSize(1); // Draw 2X-scale text
  display.setTextColor(WHITE);
  display.setCursor(10, 0);
  display.println(firstline);
  display.setCursor(10, 16);
  display.println(secondline);
  display.display();      // Show initial text
  delay(100);
}

void testscrolltext3lines(String firstline, String secondline, String thirdline) {
  display.clearDisplay();

  display.setTextSize(1); // Draw 2X-scale text
  display.setTextColor(WHITE);
  display.setCursor(10, 0);
  display.println(firstline);
  display.setCursor(10, 8);
  display.println(secondline);
  display.setCursor(10, 24);
  display.println(thirdline);
  display.display();      // Show initial text
  delay(100);
}

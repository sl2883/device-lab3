    /*
    Adafruit Arduino - Lesson 3. RGB LED
    */
     
    int redPin = 11;
    int greenPin = 10;
    int bluePin = 9;
    int fsrAnalogPin = 0;
    
    
    //uncomment this line if using a Common Anode LED
    #define COMMON_ANODE
     
    void setup()
    {
      Serial.begin(9600);
      pinMode(redPin, OUTPUT);
      pinMode(greenPin, OUTPUT);
      pinMode(bluePin, OUTPUT);  
    }
     
    void loop()
    {
      int fsrReading = analogRead(fsrAnalogPin);
      
      setColor(fsrReading%255, 0, 0);  // red
    }
     
    void setColor(int red, int green, int blue)
    {
      Serial.println(red);
      #ifdef COMMON_ANODE
        red = 255 - red;
        green = 255 - green;
        blue = 255 - blue;
      #endif
      analogWrite(redPin, red);
      analogWrite(greenPin, green);
      analogWrite(bluePin, blue);  

      delay(100);
    }

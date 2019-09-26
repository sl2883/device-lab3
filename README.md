# device-lab3


#### a. Based on the readings from the serial monitor, what is the range of the analog values being read?
0-1000

#### b. How many bits of resolution does the analog to digital converter (ADC) on the Arduino have
1024 = (2^10) = 10 bits

#### What voltage values do you see from your force sensor?
0-5V

#### What kind of relationship does the voltage have as a function of the force applied? (e.g., linear?)

Logorithmic. Goes up as soon as you touch it, but then it doesn't

#### In Examples->Basic->Fading the LED values range from 0-255. What do you have to do so that you get the full range of output voltages from the LED when using your FSR to change the LED color?

[Code](https://github.com/sl2883/device-lab3/blob/master/FSRRande.ino)

#### a. What resistance do you need to have in series to get a reasonable range of voltages from each sensor?

#### b. What kind of relationship does the resistance have as a function of stimulus? (e.g., linear?)

FSR- Logorithmic

Flex Sensor-Linear

Photo - linear

#### a. Include your accelerometer read-out code in your write-up.
[Code](https://github.com/sl2883/device-lab3/blob/master/Acce.ino)

#### a. Modify the example code so that you can print out the output of the A0 pin. Include your code in your lab report.
[Code](https://github.com/sl2883/device-lab3/blob/master/acceDisplay.ino)

#### a. Does it matter what actions are assigned to which state? Why?
It depends. If instead of a potentiometer, we have had another switch to select different states, the actions assigned to state wouldn't matter. In this case, if "Read" state is not inbetween the other two, we'd either read only 0 values or read only assigned values. We won't be able to have the read work for both states. 
So, it matters if we can't change the input method.

#### c. How many byte-sized data samples can you store on the Atmega328?
1024

#### d. How would you get analog data from the Arduino analog pins to be byte-sized? How about analog data from the I2C devices?

A byte is ranged 0-255. The analog data that we get is upto 1023. So, we'll split 1024 to four parts and store that to eprom. I2C devices are sending 1 byte of data.

#### e. Alternately, how would we store the data if it were bigger than a byte? (hint: take a look at the EEPROMPut example)
Put method handles custom structures to be stored in EPROM.

//Data to store.
  MyObject customVar = {
    3.14f,
    65,
    "Working!"
  };

  eeAddress += sizeof(float);
  EEPROM.put(eeAddress, customVar);
  
  #### a. Turn in a copy of your final state diagram.
  <img src="https://i.imgur.com/mNmTwTF.jpg" width="50%" height="50%">
  
  #### a. Record and upload a short demo video of your logger in action.
  [Video](https://www.youtube.com/watch?v=Y_kOCBv0BXU)

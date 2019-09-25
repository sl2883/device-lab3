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

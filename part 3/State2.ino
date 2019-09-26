// This borrows code from Examples->EEPROM->eeprom_write

int textarray = 0;
int endAddr;


void state2Setup(int outputValue) {
  digitalWrite(ledPin, LOW);
  Serial.println("Writing to EEPROM");
  textarray = int(outputValue);
  testscrolltext("Bright reading " +String(prevAddress) + ": ", String(textarray));
  SensorValue newVal = {textarray};
  EEPROM.put(prevAddress, newVal);
  prevAddress += sizeof(SensorValue); //Move address to the next byte after float 'f'.
  
  Serial.println("Writing string " + String(textarray));
  Serial.println("String committed to EEPROM!");
}

void state2Loop() {
  digitalWrite(LED_BUILTIN, HIGH);   // turn the LED on (HIGH is the voltage level)
}

void doState2(int outputValue) {
  state2Setup(outputValue);
  state2Loop();
}

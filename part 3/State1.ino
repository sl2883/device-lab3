// This borrows code from Examples->EEPROM->eeprom_read

byte value;

void state1Setup() {
  int currentAd = 0;
  Serial.println("Reading from EEPROM");
  SensorValue customVar; //Variable to store custom object read from EEPROM.
  while(currentAd < prevAddress) {  
    EEPROM.get(currentAd, customVar);
    Serial.println("Value = " + String(customVar.field1));
    String third = "";
    if(customVar.field1 > 700)      third = "Bright***************";
    else if(customVar.field1 > 500) third = "Ok Bright************";
    else if(customVar.field1 > 250) third = "Hiding me?***********";
    else                            third = "Too dark!************";
    testscrolltext3lines("Reading " + String(currentAd) + "th value: ", String(customVar.field1), third);
    delay(1000);
    currentAd += sizeof(SensorValue);
  }
  
  Serial.println("Done reading from EEPROM");
}

void state1Loop() {
  digitalWrite(LED_BUILTIN, LOW);    // turn the LED off by making the voltage LOW
}

void doState1() {
  if (lastState != 1) { state1Setup(); }
  state1Loop();
}

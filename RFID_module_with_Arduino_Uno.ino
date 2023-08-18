// for I2C Communication
#include <Wire.h>
#include <PN532_I2C.h>
#include <PN532.h>
#include <NfcAdapter.h>

PN532_I2C pn532_i2c(Wire);
 int ledpin1=3;
 int ledpin2=4;
 int ledpin3=5;
 int ledpin4=6;

NfcAdapter nfc = NfcAdapter(pn532_i2c);
String tagId1 ="FA 5F 99 1A";
String tagId2= "C6 45 22 4B";
String tagId3= "A9 1B D3 6E";
String tagId4= "39 0B B6 B0";

String tagId = "None";
byte nuidPICC[4];

void setup(void) {
  Serial.begin(115200);
  pinMode(ledpin1,OUTPUT);
  pinMode(ledpin2,OUTPUT);
  pinMode(ledpin3,OUTPUT);
  pinMode(ledpin4,OUTPUT);

  Serial.println("System initialized");
  nfc.begin();
   digitalWrite(ledpin1, LOW);
   digitalWrite(ledpin2, LOW);
   digitalWrite(ledpin3, LOW);
   digitalWrite(ledpin4, LOW);

}

void loop() {

  readNFC();
  if(tagId==tagId1)
  { 
      digitalWrite(ledpin1, !digitalRead(ledpin1));
      tagId = "";
      delay(1000);
  }     
      if(tagId==tagId2)
  {
    digitalWrite(ledpin2, !digitalRead(ledpin2));
      tagId = "";
      delay(1000);
  }

      if(tagId==tagId3)
  {
      digitalWrite(ledpin3, !digitalRead(ledpin3));
      tagId = "";
      delay(1000);
  }
       if(tagId==tagId4)
  {
      digitalWrite(ledpin4, !digitalRead(ledpin4));
      tagId = "";
      delay(1000);

  }

}

void readNFC() {
  if (nfc.tagPresent())
  {
    NfcTag tag = nfc.read();
    tag.print();
    tagId = tag.getUidString();
    Serial.println("Tag id");
    Serial.println(tagId);
  }
  delay(1000);
}

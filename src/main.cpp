// /*************************************************** 
//   This is an example sketch for our optical Fingerprint sensor

//   Adafruit invests time and resources providing this open source code, 
//   please support Adafruit and open-source hardware by purchasing 
//   products from Adafruit!

//   Written by Limor Fried/Ladyada for Adafruit Industries.  
//   BSD license, all text above must be included in any redistribution
//  ****************************************************/


// #include <custom_adafruit_fingerprint.h>

// int getFingerprintIDez();
// uint8_t downloadFingerprintTemplate(uint16_t id);
// void printHex(int num, int precision);

// // pin #2 is IN from sensor (GREEN wire)
// // pin #3 is OUT from arduino  (WHITE wire)
// SoftwareSerial mySerial(2, 3);



// Adafruit_Fingerprint finger = Adafruit_Fingerprint(&mySerial);

// void setup()  
// {
//   while(!Serial);
//   Serial.begin(9600);
//   Serial.println("Fingerprint template extractor");

//   // set the data rate for the sensor serial port
//   finger.begin(57600);
  
//   if (finger.verifyPassword()) {
//     Serial.println("Found fingerprint sensor!");
//   } else {
//     Serial.println("Did not find fingerprint sensor :(");
//     while (1);
//   }

//   // Try to get the templates for fingers 1 through 10
//   for (int finger = 1; finger < 10; finger++) {
//     downloadFingerprintTemplate(finger);
//   }
// }

// uint8_t downloadFingerprintTemplate(uint16_t id)
// {
//   Serial.println("------------------------------------");
//   Serial.print("Attempting to load #"); Serial.println(id);
//   uint8_t p = finger.loadModel(id);
//   switch (p) {
//     case FINGERPRINT_OK:
//       Serial.print("Template "); Serial.print(id); Serial.println(" loaded");
//       break;
//     case FINGERPRINT_PACKETRECIEVEERR:
//       Serial.println("Communication error");
//       return p;
//     default:
//       Serial.print("Unknown error "); Serial.println(p);
//       return p;
//   }

//   // OK success!

//   Serial.print("Attempting to get #"); Serial.println(id);
//   p = finger.getModel();
//   switch (p) {
//     case FINGERPRINT_OK:
//       Serial.print("Template "); Serial.print(id); Serial.println(" transferring:");
//       break;
//    default:
//       Serial.print("Unknown error "); Serial.println(p);
//       return p;
//   }
  
//   // one data packet is 267 bytes. in one data packet, 11 bytes are 'usesless' :D
//   uint8_t bytesReceived[534]; // 2 data packets
//   memset(bytesReceived, 0xff, 534);

//   uint32_t starttime = millis();
//   int i = 0;
//   while (i < 534 && (millis() - starttime) < 20000) {
//       if (mySerial.available()) {
//           bytesReceived[i++] = mySerial.read();
//       }
//   }
//   Serial.print(i); Serial.println(" bytes read.");
//   Serial.println("Decoding packet...");

//   uint8_t fingerTemplate[512]; // the real template
//   memset(fingerTemplate, 0xff, 512);

//   // filtering only the data packets
//   int uindx = 9, index = 0;
//   while (index < 534) {
//       while (index < uindx) ++index;
//       uindx += 256;
//       while (index < uindx) {
//           fingerTemplate[index++] = bytesReceived[index];
//       }
//       uindx += 2;
//       while (index < uindx) ++index;
//       uindx = index + 9;
//   }
//   for (int i = 0; i < 512; ++i) {
//       // Serial.print("0x");
//       Serial.print(fingerTemplate[i]);
//       // Serial.print(", ");
//   }
//   Serial.println();
//   Serial.println("\ndone.");

//   /*
//   uint8_t templateBuffer[256];
//   memset(templateBuffer, 0xff, 256);  //zero out template buffer
//   int index=0;
//   uint32_t starttime = millis();
//   while ((index < 256) && ((millis() - starttime) < 1000))
//   {
//     if (mySerial.available())
//     {
//       templateBuffer[index] = mySerial.read();
//       index++;
//     }
//   }
  
//   Serial.print(index); Serial.println(" bytes read");
  
//   //dump entire templateBuffer.  This prints out 16 lines of 16 bytes
//   for (int count= 0; count < 16; count++)
//   {
//     for (int i = 0; i < 16; i++)
//     {
//       Serial.print("0x");
//       Serial.print(templateBuffer[count*16+i], HEX);
//       Serial.print(", ");
//     }
//     Serial.println();
//   }*/
// }



// void printHex(int num, int precision) {
//     char tmp[16];
//     char format[128];
 
//     sprintf(format, "%%.%dX", precision);
 
//     sprintf(tmp, format, num);
//     Serial.print(tmp);
// }

// void loop()
// {}
/*************************************************** 
  This is an example sketch for our optical Fingerprint sensor
  Designed specifically to work with the Adafruit Fingerprint sensor
  ----> http://www.adafruit.com/products/751
  These displays use TTL Serial to communicate, 2 pins are required to 
  interface
  Adafruit invests time and resources providing this open source code, 
  please support Adafruit and open-source hardware by purchasing 
  products from Adafruit!
  Written by Limor Fried/Ladyada for Adafruit Industries.  
  BSD license, all text above must be included in any redistribution
 ****************************************************/

// #include <custom_adafruit_fingerprint.h>

// // On Leonardo/Micro or others with hardware serial, use those! #0 is green wire, #1 is white
// // uncomment this line:
// // #define mySerial Serial1

// // For UNO and others without hardware serial, we must use software serial...
// // pin #2 is IN from sensor (GREEN wire)
// // pin #3 is OUT from arduino  (WHITE wire)
// // comment these two lines if using hardware serial
// SoftwareSerial mySerial(2, 3);

// Adafruit_Fingerprint finger = Adafruit_Fingerprint(&mySerial);

// void setup()  
// {
//   Serial.begin(9600);
//   while (!Serial);  // For Yun/Leo/Micro/Zero/...
//   delay(100);

//   Serial.println("\n\nDeleting all fingerprint templates!");
//   Serial.println("Press 'Y' key to continue");

//   while (1) {
//     if (Serial.available() && (Serial.read() == 'Y')) {
//       break;
//     }
  
//   }

//   // set the data rate for the sensor serial port
//   finger.begin(57600);
  
//   if (finger.verifyPassword()) {
//     Serial.println("Found fingerprint sensor!");
//   } else {
//     Serial.println("Did not find fingerprint sensor :(");
//     while (1);
//   }
  
//   finger.emptyDatabase();

//   Serial.println("Now database is empty :)");

//   finger.uploadModel();
//   finger.storeModel(5);
// }

// void loop() {
// }

/*************************************************** 
  This is an example sketch for our optical Fingerprint sensor

  Designed specifically to work with the Adafruit BMP085 Breakout 
  ----> http://www.adafruit.com/products/751

  These displays use TTL Serial to communicate, 2 pins are required to 
  interface
  Adafruit invests time and resources providing this open source code, 
  please support Adafruit and open-source hardware by purchasing 
  products from Adafruit!

  Written by Limor Fried/Ladyada for Adafruit Industries.  
  BSD license, all text above must be included in any redistribution
 ****************************************************/


#include <custom_adafruit_fingerprint.h>

// On Leonardo/Micro or others with hardware serial, use those! #0 is green wire, #1 is white
// uncomment this line:
// #define mySerial Serial1

// For UNO and others without hardware serial, we must use software serial...
// pin #2 is IN from sensor (GREEN wire)
// pin #3 is OUT from arduino  (WHITE wire)
// comment these two lines if using hardware serial
SoftwareSerial mySerial(2, 3);

Adafruit_Fingerprint finger = Adafruit_Fingerprint(&mySerial);

int getFingerprintIDez();
uint8_t getFingerprintID();

void setup()  
{
  Serial.begin(9600);
  while (!Serial);  // For Yun/Leo/Micro/Zero/...
  delay(100);
  Serial.println("\n\nAdafruit finger detect test");

  // set the data rate for the sensor serial port
  finger.begin(57600);
  delay(5);
  if (finger.verifyPassword()) {
    Serial.println("Found fingerprint sensor!");
  } else {
    Serial.println("Did not find fingerprint sensor :(");
    while (1) { delay(1); }
  }

  finger.getTemplateCount();
  Serial.print("Sensor contains "); Serial.print(finger.templateCount); Serial.println(" templates");
  Serial.println("Waiting for valid finger...");
}

void loop()                     // run over and over again
{
  getFingerprintIDez();
  delay(50);            //don't ned to run this at full speed.
}

uint8_t getFingerprintID() {
  uint8_t p = finger.getImage();
  switch (p) {
    case FINGERPRINT_OK:
      Serial.println("Image taken");
      break;
    case FINGERPRINT_NOFINGER:
      Serial.println("No finger detected");
      return p;
    case FINGERPRINT_PACKETRECIEVEERR:
      Serial.println("Communication error");
      return p;
    case FINGERPRINT_IMAGEFAIL:
      Serial.println("Imaging error");
      return p;
    default:
      Serial.println("Unknown error");
      return p;
  }

  // OK success!

  p = finger.image2Tz();
  switch (p) {
    case FINGERPRINT_OK:
      Serial.println("Image converted");
      break;
    case FINGERPRINT_IMAGEMESS:
      Serial.println("Image too messy");
      return p;
    case FINGERPRINT_PACKETRECIEVEERR:
      Serial.println("Communication error");
      return p;
    case FINGERPRINT_FEATUREFAIL:
      Serial.println("Could not find fingerprint features");
      return p;
    case FINGERPRINT_INVALIDIMAGE:
      Serial.println("Could not find fingerprint features");
      return p;
    default:
      Serial.println("Unknown error");
      return p;
  }
  
  // OK converted!
  p = finger.fingerFastSearch();
  if (p == FINGERPRINT_OK) {
    Serial.println("Found a print match!");
  } else if (p == FINGERPRINT_PACKETRECIEVEERR) {
    Serial.println("Communication error");
    return p;
  } else if (p == FINGERPRINT_NOTFOUND) {
    Serial.println("Did not find a match");
    return p;
  } else {
    Serial.println("Unknown error");
    return p;
  }   
  
  // found a match!
  Serial.print("Found ID #"); Serial.print(finger.fingerID); 
  Serial.print(" with confidence of "); Serial.println(finger.confidence); 

  return finger.fingerID;
}

// returns -1 if failed, otherwise returns ID #
int getFingerprintIDez() {
  uint8_t p = finger.getImage();
  if (p != FINGERPRINT_OK)  return -1;

  p = finger.image2Tz();
  if (p != FINGERPRINT_OK)  return -1;

  p = finger.fingerFastSearch();
  if (p != FINGERPRINT_OK)  return -1;
  
  // found a match!
  Serial.print("Found ID #"); Serial.print(finger.fingerID); 
  Serial.print(" with confidence of "); Serial.println(finger.confidence);
  return finger.fingerID; 
}
// #include "Adafruit_mfGFX.h"
// #include "Adafruit_ILI9341.h"
// #include "Adafruit_DHT.h"
//
// #define DHTPIN 1     // what pin we're connected to
//
// #define DHTTYPE DHT22		// DHT 22 (AM2302)
//
// DHT dht(DHTPIN, DHTTYPE);
// #include "application.h"
// #include "sd-card-library-photon-compat.h"
//
// // set up variables using the SD utility library functions:
// #define SD_SPI_NUMBER 1
// Sd2Card card;
// SdVolume volume;
// SdFile root;
// const uint8_t chipSelect = D5;    // Also used for HARDWARE SPI setup
// const uint8_t mosiPin = D3;
// const uint8_t misoPin = D2;
// const uint8_t clockPin = D4;

// Adafruit_ILI9341 tft = Adafruit_ILI9341(A2, A1, A0);
// double minTemp = 23;
// double actualTemp = -1;
// int cnt1 = 0;
// int tmr1= 3000;
// boolean isOn = false;
//
// void setup() {
//   Spark.function("setTemp", setTemp);
// 	Particle.variable("temp", actualTemp);
//   minTemp = EEPROM.read(0);
// 	pinMode(D0, OUTPUT);
// 	digitalWrite(D0, LOW);
// if (!card.init(mosiPin, misoPin, clockPin, chipSelect)) {
//   Serial.println("initialization failed. Things to check:");
//   Serial.println("* is a card is inserted?");
//   Serial.println("* Is your wiring correct?");
//   Serial.println("* did you change the chipSelect pin to match your shield or module?");
//   return;
// } else {
//  Serial.println("Wiring is correct and a card is present.");
// }
// if (!volume.init(card)) {
//   Serial.println("Could not find FAT16/FAT32 partition.\nMake sure you've formatted the card");
//   return;
// }

// 	tft.begin();
// 	tft.fillScreen(ILI9341_BLACK);
// 	tft.setTextColor(ILI9341_WHITE);
// 	tft.setTextSize(2);
// 	tft.println(dht.getTempCelcius());
// 	tft.println(minTemp);

// }
//
// void checkTemp(void) {
// 	actualTemp = dht.getTempCelcius();
// 	if(actualTemp < minTemp) {
// 		isOn = true;
// 		digitalWrite(D0, HIGH);
// 	} else {
// 		isOn = false;
// 		digitalWrite(D0, LOW);
// 	}
// }
//
// void loop(void) {
// 	cnt1++;
// 	if(cnt1 == 10000) {
// 		checkTemp();
// 		tft.fillScreen(ILI9341_BLACK);
// 	  tft.setTextSize(2);
// 		tft.setCursor(20,20);
// 		tft.println(dht.getTempCelcius());
// 		tft.println(minTemp);
// 		cnt1 = 0;
// 	}
//
//
// }
//
// int setTemp(String command) {
// 	minTemp = command.toInt();
// 	EEPROM.write(0,minTemp);
// 	cnt1 = 9999;
// 	return 1;
// }

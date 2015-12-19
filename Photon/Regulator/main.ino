#include "Adafruit_mfGFX.h"
#include "Adafruit_ILI9341.h"
#include "Adafruit_DHT.h"

// Example testing sketch for various DHT humidity/temperature sensors
// Written by ladyada, public domain

#define DHTPIN 3     // what pin we're connected to

// Uncomment whatever type you're using!
#define DHTTYPE DHT11		// DHT 11
//#define DHTTYPE DHT22		// DHT 22 (AM2302)
//#define DHTTYPE DHT21		// DHT 21 (AM2301)

// Connect pin 1 (on the left) of the sensor to +5V
// Connect pin 2 of the sensor to whatever your DHTPIN is
// Connect pin 4 (on the right) of the sensor to GROUND
// Connect a 10K resistor from pin 2 (data) to pin 1 (power) of the sensor

DHT dht(DHTPIN, DHTTYPE);
Adafruit_ILI9341 tft = Adafruit_ILI9341(A2, A1, A0);
int minTemp = 23;
int actualTemp = -1;
int cnt1 = 0;
int tmr1= 3000;
boolean isOn = false;

void setup() {
	Serial.begin(9600);
	//delay(20000); //Give me a chance to do the "sudo cat /dev/ttyACM0" thingy

	Serial.println("Test!");

  Spark.function("text",showText);
  Spark.function("setTemp",setTemp);

	pinMode(D0, OUTPUT);
	digitalWrite(D0, LOW);
	tft.begin();
	tft.fillScreen(ILI9341_BLACK);
	tft.setTextColor(ILI9341_WHITE);
	tft.setTextSize(2);
	tft.println(dht.getTempCelcius());
	tft.println(minTemp);

//    while (!Serial.available())
//        SPARK_WLAN_Loop();

}

void checkTemp(void) {
	actualTemp = dht.getTempCelcius();
	if(actualTemp < minTemp) {
		isOn = true;
		digitalWrite(D0, HIGH);
	} else {
		isOn = false;
		digitalWrite(D0, LOW);
	}
}

void loop(void) {
	cnt1++;
	if(cnt1 == 10000) {
		checkTemp();
		tft.fillScreen(ILI9341_BLACK);
	  tft.setTextSize(2);
		tft.setCursor(20,20);
		tft.println(dht.getTempCelcius());
		tft.println(minTemp);
		cnt1 = 0;
	}


}

int showText(String command) {

  return 1;
}

int setTemp(String command) {
	minTemp = command.toInt();
	cnt1 = 9999;
	return 1;
}

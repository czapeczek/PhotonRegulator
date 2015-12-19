#include "Adafruit_mfGFX.h"
#include "Adafruit_ILI9341.h"
#include "Adafruit_DHT.h"

#define DHTPIN 1     // what pin we're connected to

#define DHTTYPE DHT22		// DHT 22 (AM2302)

DHT dht(DHTPIN, DHTTYPE);
Adafruit_ILI9341 tft = Adafruit_ILI9341(A2, A1, A0);
double minTemp = 23;
double actualTemp = -1;
int cnt1 = 0;
int tmr1= 3000;
boolean isOn = false;

void setup() {
	Serial.begin(9600);

	Serial.println("Test!");

  Spark.function("text",showText);
  Spark.function("setTemp",setTemp);
	Particle.variable("temp", actualTemp);
  minTemp = EEPROM.read(0);
	pinMode(D0, OUTPUT);
	digitalWrite(D0, LOW);
	tft.begin();
	tft.fillScreen(ILI9341_BLACK);
	tft.setTextColor(ILI9341_WHITE);
	tft.setTextSize(2);
	tft.println(dht.getTempCelcius());
	tft.println(minTemp);

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
	EEPROM.write(0,minTemp);
	cnt1 = 9999;
	return 1;
}

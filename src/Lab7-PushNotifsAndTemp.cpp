/******************************************************/
//       THIS IS A GENERATED FILE - DO NOT EDIT       //
/******************************************************/

#include "Particle.h"
#line 1 "/Users/cademissner/Desktop/IoT/Lab7-PushNotifsAndTemp/src/Lab7-PushNotifsAndTemp.ino"
// Particle: Launch CLI
// particle usb start-listening
// particle serial wifi

#include "oled-wing-adafruit.h"
#include <blynk.h>

void setup();
void loop();
#line 8 "/Users/cademissner/Desktop/IoT/Lab7-PushNotifsAndTemp/src/Lab7-PushNotifsAndTemp.ino"
SYSTEM_THREAD(ENABLED);

OledWingAdafruit display;
bool unit = false;

void setup() {
    Blynk.begin("gev9UlWHupS8yCBJ2wpDXDNm6THMu0oS", IPAddress(167, 172, 234, 162), 8080);

    display.setup();
    display.clearDisplay();
    display.display();
    display.setTextSize(5);
    display.setTextColor(WHITE);
    display.setCursor(0,0);
    Serial.begin(9600);
  
}

void loop() {
    display.loop();

    uint64_t reading = analogRead(A4);
    double voltage = (reading * 3.3) / 4095.0;
    double temperatureC = (voltage - 0.5) * 100;
    double temperatureF = (1.8 * temperatureC) + 32;

    if (display.pressedB()) {
        unit = !unit;
    }

    if (display.pressedA()) {
        display.clearDisplay();
        display.setCursor(6, 6);
        display.setTextSize(2);
        display.setTextColor(WHITE);
        display.println("Push Sent");
        display.display();
        Blynk.notify("AAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAH");
        delay(5000);
    }
    
    display.clearDisplay();
    display.setTextSize(4);
    display.setTextColor(WHITE);
    display.setCursor(5, 5);
    if (unit) {
        display.println(temperatureF);
        Blynk.virtualWrite(V0, temperatureF);
    } else {
        display.println(temperatureC);
        Blynk.virtualWrite(V0, temperatureC);
    }
    display.display();

}

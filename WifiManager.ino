#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include <ESP8266WiFi.h>          //ESP8266 Core WiFi Library (you most likely already have this in your sketch)

#include <DNSServer.h>            //Local DNS Server used for redirecting all requests to the configuration portal
#include <ESP8266WebServer.h>     //Local WebServer used to serve the configuration portal
#include <WiFiManager.h>          //https://github.com/tzapu/WiFiManager WiFi Configuration Magic
 
LiquidCrystal_I2C lcd(0x27,16,2); // set the LCD address to 0x3F for a 16 chars and 2 line display
 
void setup()
{
lcd.init(); // initialize the lcd
lcd.init();
// Print a message to the LCD.
lcd.backlight();
lcd.setCursor(0,0);
lcd.print("Hallo Maus!");
lcd.setCursor(0,1);
lcd.print("Lieb Dich!");

WiFiManager wifiManager;

//first parameter is name of access point, second is the password
wifiManager.autoConnect("AP-NAME");
}
 
void loop()
{
  delay(2500);
  lcd.clear();
  delay(1000);
  lcd.setCursor(0,0);
  lcd.print("WLAN!");
  lcd.setCursor(0,1);
  lcd.print(String(millis()/1000) + "sec");
  
  lcd.setCursor(0,0);
  //lcd.autoscroll();
  lcd.print("Going into deep sleep for 20 seconds");
  //lcd.scrollDisplayRight();
  
  ESP.deepSleep(20e6); // 20e6 is 20 microseconds
}

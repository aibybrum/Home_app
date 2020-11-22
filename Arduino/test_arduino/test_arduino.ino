#include <FastLED.h>
#include <SoftwareSerial.h>

#define LED_PIN 6
#define NUM_LEDS 172
#define LED_TYPE WS2811
#define COLOR_ORDER GRB

CRGB leds[NUM_LEDS];

const String ssid = "Orange-52af7";
const String password = "4255S3rf";

String data;

void setup()  {
  Serial.begin(9600);
  Serial1.begin(115200);
  FastLED.addLeds<LED_TYPE, LED_PIN, COLOR_ORDER>(leds, NUM_LEDS);

  sendToWifi("AT+RST", 500);
  sendToWifi("AT+CWMODE=1", 500);
  sendToWifi("AT+CWJAP=\"" + ssid + "\",\"" + password + "\"", 7000);
  sendToWifi("AT+CIPMUX=1", 500);
  sendToWifi("AT+CIPSERVER=1,80", 500);
  sendToWifi("AT+CIFSR", 500);
}

void loop()  {
  if(Serial1.available() > 0){  
    String str = Serial1.readString();    
    if(str.charAt(11) == '1'){
      for(int i = 0; i < NUM_LEDS; i++){
        leds[i] = CRGB::Green;
        FastLED.show();
      }
    } else if (str.charAt(11) == '0'){
      for(int i = 0; i < NUM_LEDS; i++){
        leds[i] = CRGB::Black;
        FastLED.show();
      }
    }
  }
}

void sendToWifi(String cmd, int waittime) {
  Serial1.println(cmd);
  delay(waittime);
  while(Serial1.available() > 0){
    if (Serial1.find("+CIFSR:STAIP,\"192.168.0.9\"")){
      Serial.println("Wifi connection is running");
      Serial.println("");
      break;
    }else {
      Serial.println("Connecting...");
    }
  }
}

void ledAnimation(){
  int j = 1;
  while(j == 1){
    for(int i = 0; i < NUM_LEDS; i++){
      leds[i] = CRGB::Red;
      FastLED.show();
      delay(10);
      leds[i] = CRGB::Black;
    } 
    for(int i = NUM_LEDS -1; i >= 0; i--){
      leds[i] = CRGB::Red;
      FastLED.show();
      delay(10);
      leds[i] = CRGB::Black;
    } 
  }
}

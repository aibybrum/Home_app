#include <FastLED.h>
#include <SoftwareSerial.h>

#define LED_PIN 6
#define NUM_LEDS 172
#define LED_TYPE WS2811
#define COLOR_ORDER GRB

CRGB leds[NUM_LEDS];

const String ssid = "Orange-52af7";
const String password = "4255S3rf";

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

void sendToWifi(String cmd, int waittime) {
  Serial1.println(cmd);
  delay(waittime);
  while(Serial1.available()){  
    if (Serial1.find("+CIFSR:STAIP")){
      String ip = Serial1.readString();  
      Serial.println("Wifi connection is running on ip address: ");
      Serial.print(ip.substring(2,14));
      break;
    }else {
      Serial.println("Connecting...");
    }
  }
}

void loop()  {
  if(Serial1.available() > 0){  
    String str = Serial1.readString();    
    if(str.charAt(11) == 'b'){
      for(int i = 0; i < NUM_LEDS; i++){
        leds[i] = CRGB::Blue;
        FastLED.show();
      }
    } else if (str.charAt(11) == 'r'){
      for(int i = 0; i < NUM_LEDS; i++){
        leds[i] = CRGB::Red;
        FastLED.show();
      }
    }else if (str.charAt(11) == 'g'){
      for(int i = 0; i < NUM_LEDS; i++){
        leds[i] = CRGB::Green;
        FastLED.show();
      }
    }else if (str.charAt(11) == 'u'){
      for(int i = 0; i < NUM_LEDS; i++){
        leds[i] = CRGB::Black;
        FastLED.show();
      }
    }
  }
}

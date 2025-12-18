#define BLYNK_HEARTBEAT 10

#define BLYNK_TEMPLATE_ID "TMPL6DTZ"
#define BLYNK_TEMPLATE_NAME "Door Security"
#define BLYNK_PRINT Serial

#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>

BlynkTimer timer;
// Your WiFi credentials.
// Set password to "" for open networks.
char ssid[] = "keep your wifi ssd";
char pass[] = "wifi password";

int PIN_1 = D1;
int opened = 0;
int val = 0;
int enabled = 0;

BLYNK_WRITE(V0)
{
  // Set incoming value from pin V0 to a variable
  int val = param.asInt();
  if(val == HIGH)
  {
    enabled = 1;
  }
  else{
    enabled = 0;    
  }
}

BLYNK_CONNECTED() 
{
  Blynk.virtualWrite(V0, 0);
}

void onTick()
{
  //Serial.print("enabled: ");
  //Serial.println(enabled);
  if(enabled == 0)
    return;
  else
    opened = 0;

  val = digitalRead(PIN_1);
  //Serial.println(val);
  val = digitalRead(PIN_1);
  // read pin data and notify if not connected
  if(val == HIGH && opened == 0)
  {
    opened = 1;
    enabled = 0;
    Blynk.logEvent("door_opened", "Your door has been opened!!!");
    Blynk.virtualWrite(V0, 0);
  }
  else if(val == LOW){
    opened = 0;
  }
}

void setup() {
  Serial.begin(115200);
  Blynk.begin(BLYNK_AUTH_TOKEN, ssid, pass, "blynk.cloud", 80);
  
  pinMode(PIN_1, INPUT_PULLUP);
  timer.setInterval(1000L, onTick); 
}

void loop() {
  Blynk.run();
  timer.run();
}

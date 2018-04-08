#define REMOTEXY_MODE__ESP8266WIFI_LIB_POINT
#include <ESP8266WiFi.h> 
#include <RemoteXY.h> 

// RemoteXY connection settings  
#define REMOTEXY_WIFI_SSID "gaurav" 
#define REMOTEXY_WIFI_PASSWORD "12345678" 
#define REMOTEXY_SERVER_PORT 80 


// RemoteXY configurate   
#pragma pack(push, 1) 
uint8_t RemoteXY_CONF[] = 
  { 255,2,0,0,0,28,0,8,24,0,
  2,0,58,24,22,11,2,26,31,31,
  79,78,0,79,70,70,0,4,0,17,
  12,9,38,2,26 }; 
   
// this structure defines all the variables of your control interface  
struct { 

    // input variable
  uint8_t switch_1; // =1 if switch ON and =0 if OFF 
 // int8_t slider_1; // =0..100 slider position 

    // other variable
  uint8_t connect_flag;  // =1 if wire connected, else =0 

} RemoteXY; 
#pragma pack(pop) 

///////////////////////////////////////////// 
//           END RemoteXY include          // 
///////////////////////////////////////////// 

#define PIN_SWITCH_1 13


void setup()  
{ 
  RemoteXY_Init ();  
   
  pinMode (PIN_SWITCH_1, OUTPUT);
   
  digitalWrite(PIN_SWITCH_1,LOW);
  delay(1000);
  if (RemoteXY.switch_1!=0) digitalWrite(PIN_SWITCH_1, HIGH); 
  else digitalWrite(PIN_SWITCH_1, LOW);

 /* int pos = RemoteXY.slider_1; 
  if (pos>50) { // up 
    digitalWrite(PIN_SWITCH_1, HIGH);  
    analogWrite(PIN_SWITCH_1, (pos-50) * 5.11);  
  }  
  else if (pos<50) { // down 
    digitalWrite(PIN_SWITCH_1, LOW);  
    analogWrite(PIN_SWITCH_1, (50-pos) * 5.11);  
  }  
  else { // stop 
    digitalWrite(PIN_SWITCH_1, LOW);  
    analogWrite(PIN_SWITCH_1, 0);  
  }*/  
} 
void loop()  
{  
  RemoteXY_Handler (); 
   
  digitalWrite(PIN_SWITCH_1, (RemoteXY.switch_1==0)?LOW:HIGH);
   
  // TODO you loop code 
  // use the RemoteXY structure for data transfer 


}

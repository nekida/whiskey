#include <ESP8266WiFi.h>
#include <WiFiClient.h>
#include <ESP8266WebServer.h>
#include <ESP8266mDNS.h>

MDNSResponder mdns;

const char* ssid = "******";
const char* password = "******";

const int buf_regular_on[3]       = {1, 0, 0};
const int buf_regular_off[3]      = {2, 0, 0};
int buf_blink_all[3]              = {3, 0, 0};
int buf_up_down_on_all_off[3]     = {4, 0, 0};
int buf_down_up_on_all_off[3]     = {5, 0, 0};
int buf_up_down_on_up_down_off[3] = {6, 0, 0};
int buf_down_up_on_down_up_off[3] = {7, 0, 0};
int buf_up_down_on_down_up_off[3] = {8, 0, 0};
int buf_down_up_on_up_down_off[3] = {9, 0, 0};
int buf_chaos[3]                  = {10, 0, 0};
int buf_round_up[3]               = {11, 0, 0};
int buf_round_down[3]             = {12, 0, 0};

uint16_t _delay = 100;

ESP8266WebServer server(80);

String webPage = "";

void setup(void){
  webPage += "<h1>Night light</h1>";
  webPage += "<p><a href=\"Regular\"><button>Regular</button></a>&nbsp; <a href=\"OFF\"><button>OFF</button></a>&nbsp; <a href=\"Blink\"><button>Blink</button></a>&nbsp; <a href=\"Chaos\"><button>Chaos</button></a></p>";
  webPage += "<p><a href=\"Down_up_on_up_down_off\"><button>Down up on - up down off</button></a>&nbsp; <a href=\"Up_down_on_down_up_off\"><button>Up down on - down up off</button></a><p>";
  webPage += "<p><a href=\"Up_down_on_up_down_off\"><button>Up down on - up down off </button></a>&nbsp;<a href=\"Down_up_on_down_up_off\"><button>Down up on - down up off</button></a><p>"; 
  webPage += "<p><a href=\"Up_down_on_all_off\"><button>Up down on - all off </button></a>&nbsp;  <a href=\"Down_up_on_all_off\"><button>Down up on - all off</button></a><p>";
  webPage += "<p><a href=\"Round_up\"><button>Round up</button></a>&nbsp; <a href=\"Round_down\"><button>Round down</button></a><p>";
  webPage += "<p>Delay <a href=\"Delay10\"><button>10</button></a>&nbsp; <a href=\"Delay50\"><button>50</button></a>&nbsp; <a href=\"Delay100\"><button>100</button></a>&nbsp; <a href=\"Delay250\"><button>250</button></a>&nbsp; <a href=\"Delay500\"><button>500</button></a>&nbsp; <a href=\"Delay1000\"><button>1000</button></a>&nbsp; <a href=\"Delay5000\"><button>5000</button></a>&nbsp; <a href=\"Delay10000\"><button>10000</button></a></p>";

  server.on("/Delay10", [](){
    server.send(200, "text/html", webPage);
    _delay = 10;
    delay(1000);
  });
  server.on("/Delay50", [](){
    server.send(200, "text/html", webPage);
    _delay = 50;
    delay(1000);
  });

  delay(1000);
  Serial.begin(115200);
  WiFi.begin(ssid, password);
  Serial.println("");

  // ждем соединения:
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    //Serial.print(".");
  }
  
  if (mdns.begin("esp8266", WiFi.localIP())) {

  }
  
  server.on("/", [](){
    server.send(200, "text/html", webPage);
  });
///////////////////////////////////////////////////////////// 
  server.on("/Regular", [](){
    server.send(200, "text/html", webPage);
    for(int i = 0; i < 3; i++)
    {
      Serial.write(buf_regular_on[i]);
    }
    delay(1000);
  });
  server.on("/Blink", [](){
    server.send(200, "text/html", webPage);
    buf_blink_all[1] = _delay;
    buf_blink_all[2] = _delay >> 8;
    for(int i = 0; i < 3; i++)
    {
      Serial.write(buf_blink_all[i]);
    }
    delay(1000);
  });
  server.on("/OFF", [](){
    server.send(200, "text/html", webPage);
    for(int i = 0; i < 3; i++)
    {
      Serial.write(buf_regular_off[i]);
    }
    delay(1000); 
  });
  server.on("/Chaos", [](){
    server.send(200, "text/html", webPage);
    buf_chaos[1] = _delay;
    buf_chaos[2] = _delay >> 8;
    for(int i = 0; i < 3; i++)
    {
      Serial.write(buf_chaos[i]);
    }
    delay(1000); 
  });
  server.on("/Down_up_on_up_down_off", [](){
    server.send(200, "text/html", webPage);
    buf_down_up_on_up_down_off[1] = _delay;
    buf_down_up_on_up_down_off[2] = _delay >> 8;
    for(int i = 0; i < 3; i++)
    {
      Serial.write(buf_down_up_on_up_down_off[i]);
    }
    delay(1000);
  });
  server.on("/Up_down_on_down_up_off", [](){
    server.send(200, "text/html", webPage);
    buf_up_down_on_down_up_off[1] = _delay;
    buf_up_down_on_down_up_off[2] = _delay >> 8;
    for(int i = 0; i < 3; i++)
    {
      Serial.write(buf_up_down_on_down_up_off[i]);
    }
    delay(1000);
  });
    server.on("/Up_down_on_up_down_off", [](){
    server.send(200, "text/html", webPage);
    buf_up_down_on_up_down_off[1] = _delay;
    buf_up_down_on_up_down_off[2] = _delay >> 8;
    for(int i = 0; i < 3; i++)
    {
      Serial.write(buf_up_down_on_up_down_off[i]);
    }
    delay(1000);
  });
  server.on("/Down_up_on_down_up_off", [](){
    server.send(200, "text/html", webPage);
    buf_down_up_on_down_up_off[1] = _delay;
    buf_down_up_on_down_up_off[2] = _delay >> 8;
    for(int i = 0; i < 3; i++)
    {
      Serial.write(buf_down_up_on_down_up_off[i]);
    }
    delay(1000);
  });
  server.on("/Up_down_on_all_off", [](){
    server.send(200, "text/html", webPage);
    buf_up_down_on_all_off[1] = _delay;
    buf_up_down_on_all_off[2] = _delay >> 8;
    for(int i = 0; i < 3; i++)
    {
      Serial.write(buf_up_down_on_all_off[i]);
    }
    delay(1000); 
  });
  server.on("/Down_up_on_all_off", [](){
    server.send(200, "text/html", webPage);
    buf_down_up_on_all_off[1] = _delay;
    buf_down_up_on_all_off[2] = _delay >> 8;
    for(int i = 0; i < 3; i++)
    {
      Serial.write(buf_down_up_on_all_off[i]);
    }
    delay(1000); 
  });
  server.on("/Round_up", [](){
    server.send(200, "text/html", webPage);
    buf_round_up[1] = _delay;
    buf_round_up[2] = _delay >> 8;
    for(int i = 0; i < 3; i++)
    {
      Serial.write(buf_round_up[i]);
    }
    delay(1000); 
  });
  server.on("/Round_down", [](){
    server.send(200, "text/html", webPage);
    buf_round_down[1] = _delay;
    buf_round_down[2] = _delay >> 8;
    for(int i = 0; i < 3; i++)
    {
      Serial.write(buf_round_down[i]);
    }
    delay(1000); 
  });
  server.on("/Delay100", [](){
    server.send(200, "text/html", webPage);
    _delay = 100;
    delay(1000);
  });
  server.on("/Delay250", [](){
    server.send(200, "text/html", webPage);
    _delay = 250;
    delay(1000); 
  });
  server.on("/Delay500", [](){
    server.send(200, "text/html", webPage);
    _delay = 500;
    delay(1000);
  });
  server.on("/Delay1000", [](){
    server.send(200, "text/html", webPage);
    _delay = 1000;
    delay(1000); 
  });
  server.on("/Delay5000", [](){
    server.send(200, "text/html", webPage);
    _delay = 5000;
    delay(1000);
  });
  server.on("/Delay10000", [](){
    server.send(200, "text/html", webPage);
    _delay = 10000;
    delay(1000); 
  });
/////////////////////////////////////////////////////////////
  server.begin();
}
 
void loop(void){
  server.handleClient();
}

// Jonathan Balysma
#include <Arduino.h>
#include <WiFi.h>
#include <WiFiUdp.h>

#define ENA 18
#define IN1 4
#define IN2 5
#define ENB 22
#define IN3 19
#define IN4 21

const int buzzer = 23;
const int buzzerChannel = 0;
const int buzzerFreq = 2000; // Hz
const int buzzerResolution = 8; // 8-bit = 0–255
const char* ssid = "SSID HERE";
const char* password = "SSID PASSWORD HERE";

WiFiUDP udp;
const int udp_port = 4210;

char incoming_packet[255];

void forward(){
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, HIGH); 
  digitalWrite(IN4, LOW);
}

void left(){
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);
  digitalWrite(IN3, HIGH); 
  digitalWrite(IN4, LOW);
}

void right(){
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, LOW); 
  digitalWrite(IN4, HIGH);
}

void reverse(){
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);
  digitalWrite(IN3, LOW); 
  digitalWrite(IN4, HIGH);
}

void stop(){
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, LOW); 
  digitalWrite(IN4, LOW);
}

void beep(){
  ledcWrite(buzzerChannel, 50);
  delay(100);
  ledcWrite(buzzerChannel, 0);

}


void setup() {
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);
  pinMode(ENA, OUTPUT);
  pinMode(ENB, OUTPUT);


  WiFi.begin(ssid, password);

  while (WiFi.status() != WL_CONNECTED){
    delay(500);
  }

  udp.begin(udp_port);

  // Buzzer PWM setup
  ledcSetup(buzzerChannel, buzzerFreq, buzzerResolution);
  ledcAttachPin(buzzer, buzzerChannel);

  // Motor Speed
  analogWrite(ENA, 180);
  analogWrite(ENB, 180);
}

void loop() {
  int packet_size = udp.parsePacket();
  
  if (packet_size){
    int len = udp.read(incoming_packet, 255);
    if (len > 0){
      incoming_packet[len] = 0;
    }

    if (incoming_packet[0] == 't'){
      forward();
    }else if (incoming_packet[0] == 'g'){
      reverse();
    }else if (incoming_packet[0] == 'f'){
      left();
    }else if (incoming_packet[0] == 'h'){
      right();
    }else if (incoming_packet[0] == 'x'){
      stop();
    }else if (incoming_packet[0] == 'b'){
      beep();
    }
  }
  delay(10);
}

#include "HID-Project.h"
#include <Rotary.h>

#define pinLed1 9
#define pinLed2 6
#define pinLed3 5
#define pinLed4 3

#define pinBtn1 8
#define pinBtn2 7
#define pinBtn3 4
#define pinBtn4 2

#define pinBtnRotary 21

Rotary r = Rotary(10,16);

unsigned long lastDebounceTimeBtn1 = 0;
unsigned long lastDebounceTimeBtn2 = 0;
unsigned long lastDebounceTimeBtn3 = 0;
unsigned long lastDebounceTimeBtn4 = 0;

unsigned long debounceDelay = 300;

void setup() {

  Serial.begin(9600);
  
  pinMode(pinBtn1, INPUT_PULLUP);
  pinMode(pinBtn2, INPUT_PULLUP);
  pinMode(pinBtn3, INPUT_PULLUP);
  pinMode(pinBtn4, INPUT_PULLUP);

  pinMode(pinBtnRotary, INPUT);

  pinMode(pinLed1,OUTPUT);
  pinMode(pinLed2,OUTPUT);
  pinMode(pinLed3,OUTPUT);
  pinMode(pinLed4,OUTPUT);

  
  todosEncendidos();
}

unsigned long lastChangeLed = 0;
unsigned long timeChangeLed = 500;
boolean estado = false;

void loop() {
    
    
  if(digitalRead(pinBtn1) == LOW) {
    if((lastDebounceTimeBtn1 - millis()) > debounceDelay) {
      lastDebounceTimeBtn1 = millis();
      button1();
    }
  }

  if(digitalRead(pinBtn2) == LOW) {
    if((lastDebounceTimeBtn2 - millis()) > debounceDelay) {
      lastDebounceTimeBtn2 = millis();
      button2();
    }
  }

  if(digitalRead(pinBtn3) == LOW) {
    if((lastDebounceTimeBtn3 - millis()) > debounceDelay) {
      lastDebounceTimeBtn3 = millis();
      button3();
    }
  }

  if(digitalRead(pinBtn4) == LOW) {
    if((lastDebounceTimeBtn4 - millis()) > debounceDelay) {
      lastDebounceTimeBtn4 = millis();
      
      button4();
      
    }
  }

  unsigned char result = r.process();
  if (result == DIR_CW) {
      girarDerecha();
  } else if(result == DIR_CCW) {
      girarIzquierda();

  }

}

void efectos_led_1() {
    cambiarEstadoTodos(false);

    digitalWrite(pinLed4, HIGH);

    for(int i=0;i<85;i++) {
        analogWrite(pinLed1, i);
        delay(3);
    }
    for(int i=85;i<170;i++) {
        analogWrite(pinLed2, i);
        delay(3);
    }
    for(int i=170;i<255;i++) {
        analogWrite(pinLed3, i);
        delay(3);
    }

    cambiarEstadoTodos(false);
}

void todosEncendidos() {
  digitalWrite(pinLed1, HIGH);
  digitalWrite(pinLed2, HIGH);
  digitalWrite(pinLed3, HIGH);
  digitalWrite(pinLed4, HIGH);
}

void cambiarEstadoTodos(boolean estado) {
  digitalWrite(pinLed1, estado);
  digitalWrite(pinLed2, estado);
  digitalWrite(pinLed3, estado);
  digitalWrite(pinLed4, estado);
}

void button1() {
   
}

void button4() {
    Serial.println("yeah");
    efectos_led_1();
}

void button2() {
   
}

void button3() {
  
}


void girarDerecha() {
  Consumer.begin();
  Consumer.write(MEDIA_VOLUME_UP);
  delay(10);
  Consumer.releaseAll();
  Consumer.end();    
}

void girarIzquierda() {
  Consumer.begin();
  Consumer.write(MEDIA_VOLUME_DOWN);
  delay(10);
  Consumer.releaseAll();
  Consumer.end();     
}

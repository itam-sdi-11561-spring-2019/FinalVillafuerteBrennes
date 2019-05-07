#include <SoftwareSerial.h>

int motorPin2  = 2;  // Pin 10 of L293
int motorPin3  = 3; // Pin  7 of L293
int motorPin4 = 4;
int motorPin5 = 5;
SoftwareSerial xbeeSerial(10, 11); // RX, TX
char senal = '0';
void setup(){

    pinMode(motorPin2, OUTPUT);
    pinMode(motorPin3, OUTPUT);
    pinMode(motorPin4, OUTPUT);
    pinMode(motorPin5, OUTPUT);
    xbeeSerial.begin(9600);
}   


void loop(){
    senal = xbeeSerial.read();
      
    if(senal == '0'){
      //Frenar
      digitalWrite(motorPin2, LOW);
      digitalWrite(motorPin3, LOW);
      digitalWrite(motorPin4, LOW);
      digitalWrite(motorPin5, LOW);
    }
    else if(senal == '1'){
      //reversa
      digitalWrite(motorPin2, LOW);
      digitalWrite(motorPin3, HIGH);
      digitalWrite(motorPin4, LOW);
      digitalWrite(motorPin5, HIGH);      
    }
    else if(senal == '2'){
      //Adelante
      digitalWrite(motorPin2, HIGH);
      digitalWrite(motorPin3, LOW);
      digitalWrite(motorPin4, HIGH);
      digitalWrite(motorPin5, LOW);     
    }
    else if(senal == '3'){
      //Vuelta derecha
      digitalWrite(motorPin2, HIGH);
      digitalWrite(motorPin3, LOW);
      digitalWrite(motorPin4, LOW);
      digitalWrite(motorPin5, HIGH);     
    }
    else if(senal == '4'){
      //Vuelta izquierda
      digitalWrite(motorPin2, LOW);
      digitalWrite(motorPin3, HIGH);
      digitalWrite(motorPin4, HIGH);
      digitalWrite(motorPin5, LOW);     
    }

}



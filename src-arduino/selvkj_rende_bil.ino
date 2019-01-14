

/*#include <Servo.h>

//Servo
Servo styring;
const byte styrePin = 9;
int styringPos;

Servo sensorServo;
const byte servoSensor = 44;
int sensorPos;

//Motor
const byte motorPin = 46;
int fart = 0;

//Sensorer
const byte venstreEcho = 7;
const byte venstreTrig = 6;
float durationV, lengdeV;

const byte midtenEcho = 5;
const byte midtenTrig = 4;
float durationM, lengdeM;

const byte hoyreEcho = 3;
const byte hoyreTrig = 2;
float durationH, lengdeH;

void setup() {
  Serial.begin(9600);

  //Start servoer
  styring.attach(styrePin);
  sensorServo.attach(servoSensor);

  //Motor
  pinMode(motorPin, OUTPUT);

  //Sensorer
  pinMode(venstreEcho, INPUT);
  pinMode(venstreTrig, OUTPUT);
  
  pinMode(midtenEcho, INPUT);
  pinMode(midtenTrig, OUTPUT);

  pinMode(hoyreEcho, INPUT);
  pinMode(hoyreTrig, OUTPUT);
}

void loop() {
  malAvstand();
  seEtterHindringer();
  digitalWrite(motorPin, fart);
  Serial.print(lengdeV);
  Serial.print(" ");
  Serial.println(lengdeH);
  Serial.println(styringPos);
}

void malAvstand() {
  //Sensorer
  malMidten();
  malVenstre();
  malHoyre();
}

void seEtterHindringer() {

  /*if (lengdeM <= 100 || (lengdeH <= 100 && lengdeV <= 100)) {
    fart = 0;
    digitalWrite(motorPin, fart);
    seEtterUtvei();
  }*//*
  else if (lengdeH <= 200 || lengdeV <= 200) {
    if (lengdeH > lengdeV) {
      styringPos = (200 - lengdeH) / 2.22222222;
    }
    else {
      styringPos = 50;//(200 - lengdeV) / 2.22222222;
    }
  }*//*
  //Servoer
  if (lengdeV >= 200 && lengdeH >= 200) {
    //Rett frem
    styringPos = 90;
  }
  //Sving Høyre
  else if (lengdeV >= 200 && lengdeH <= 200) {
    styringPos = map(lengdeH, 200, 20, 90, 0);//(200 - lengdeH) / 2.22222222;
  }
  //Sving Venstre
  else if (lengdeV <= 200 && lengdeH >= 200) {
    styringPos = map(lengdeV, 200, 20, 90, 180);//(200 - lengdeV) / 2.22222222;
  }/*
  else if (lengdeV <= 100 && lengdeH <= 100 && lengdeM <= 100) {
    seEtterUtvei();
  }*//*
  styring.write(styringPos);
}

void seEtterUtvei() {
  
  sensorServo.write(sensorPos);
}



void malVenstre() {
  digitalWrite(venstreTrig, LOW);
  delayMicroseconds(2);
  digitalWrite(venstreTrig, HIGH);
  delayMicroseconds(10);
  digitalWrite(venstreTrig, LOW);

  durationV = pulseIn(venstreEcho, HIGH);
  lengdeV = (durationV*.0343)/2;
}
void malMidten() {
  digitalWrite(midtenTrig, LOW);
  delayMicroseconds(2);
  digitalWrite(midtenTrig, HIGH);
  delayMicroseconds(10);
  digitalWrite(midtenTrig, LOW);

  durationM = pulseIn(midtenEcho, HIGH);
  lengdeM = (durationM*.0343)/2;
}
void malHoyre() {
  digitalWrite(hoyreTrig, LOW);
  delayMicroseconds(2);
  digitalWrite(hoyreTrig, HIGH);
  delayMicroseconds(10);
  digitalWrite(hoyreTrig, LOW);
  
  durationH = pulseIn(hoyreEcho, HIGH);
  lengdeH = (durationH*.0343)/2;
}*/


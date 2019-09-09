/*
   Projeto de Iniciação Cientifíca - Construção do Robô Seguidor de Linha: Integração de componentes eletrônicos e da lógica de programação.
   Projeto de Extensão - Robótica educacional: Participação em campeonatos e eventos.
   Escopo algoritmo - Robô seguidor de linha (Aécio Neves).
*/

/*
   Altura do chão para 4.2 cm
*/

#include "HCMotor.h"
#define TRIGGER 13
#define ECHO 12
#define sensorDir A1
#define sensorEsq A0
#define sensorEsqVERDE A3
#define sensorDirVERDE A4
#define INTERVALOPRETO 800
#define INTERVALOVERDE 600
#define INTERVALOSENSORPRETO 250
#define MOTOR_DIREITA 7
#define MOTOR_ESQUERDA 8
#define POTENCIOMETRO A2
#define GAP 800

int Stay = 0, Speed;
int ESQUERDA, ESQUERDAVERDE;
int DIREITA, DIREITAVERDE;
int cont;
float tempo, distancia, range;

HCMotor HCMotor;

void setup() {

  Serial.begin(9600);

  HCMotor.Init();
  HCMotor.attach(0, DCMOTOR, MOTOR_DIREITA);
  HCMotor.attach(1, DCMOTOR, MOTOR_ESQUERDA);

  HCMotor.DutyCycle(0, 100);
  HCMotor.DutyCycle(1, 100);

  //  pinMode(TRIGGER, OUTPUT);
  //  pinMode(ECHO, INPUT);
  //  digitalWrite(TRIGGER, LOW);
  //  delayMicroseconds(10);


}

void loop() {

  Speed = map(analogRead(POTENCIOMETRO), 0, 1024, 0, 100);

  //Leitura();
  Frente();
  
  //Calibragem();
 //range = Distance();


  //if(range < 11)
  //    contorna();

  //Linhapreta();


}

//Robô movimento para frente
void Frente() {
  HCMotor.OnTime(0, Speed);
  HCMotor.OnTime(1, Speed);
}

//Robô movimento no sentido antihorário
void Horario() {
  HCMotor.OnTime(0, Speed);
  HCMotor.OnTime(1, Stay);
}

//Robô movimento no sentido horário
void Antihorario() {
  HCMotor.OnTime(0, Stay);
  HCMotor.OnTime(1, Speed);
}

//Robô permanece em repouso
void Parar() {
  HCMotor.OnTime(0, Stay);
  HCMotor.OnTime(1, Stay);
}

//Função para calculo de distancia
float Distance() {
  digitalWrite(TRIGGER, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIGGER, LOW);
  tempo = pulseIn(ECHO, HIGH);
  distancia = tempo / 29.4 / 4;
  return distancia;
}

//Função para contorno do obstáculo
void contorna() {
  Horario();
  delay(250);
  Frente();
  delay(350);
  Antihorario();
  delay(100);
  Frente();
}

void Calibragem() {

  //Serial.print(range);
 // Serial.println(" SENSOR DISTANCIA");
  //Serial.println("----------------------------");
  Serial.print(DIREITA);
  Serial.print(" : ");
  Serial.print(ESQUERDA);
  Serial.println(" SENSOR FAIXA PRETA");
  Serial.println("----------------------------");
  Serial.print(DIREITAVERDE);
  Serial.print(" : ");
  Serial.print(ESQUERDAVERDE);
  Serial.println(" SENSOR FAIXA VERDE");
  Serial.println("----------------------------");
  delay(1000);

}

void Leitura() {

  ESQUERDA = analogRead(sensorEsq);
  DIREITA = analogRead(sensorDir);
  ESQUERDAVERDE = analogRead(sensorEsqVERDE);
  DIREITAVERDE = analogRead(sensorDirVERDE);

}

void Linhapreta() {

  cont = 0;
  if ((DIREITA > INTERVALOSENSORPRETO) && (ESQUERDA > INTERVALOSENSORPRETO))
    Frente();

  else if (DIREITA < INTERVALOSENSORPRETO) {
    Horario();
    while (1) {
      Leitura();
      //      if (DIREITA < INTERVALOPRETO && ESQUERDA < INTERVALOPRETO && DIREITAVERDE < INTERVALOPRETO && ESQUERDAVERDE < INTERVALOPRETO)
      //        cont++;
      //      if (cont > GAP) {
      //        while (cont-- != 0) {
      //          Antihorario();
      //          Leitura();
      //          if (DIREITA > INTERVALOPRETO || ESQUERDA > INTERVALOPRETO || DIREITAVERDE > INTERVALOPRETO || ESQUERDAVERDE > INTERVALOPRETO) break;
      //        }
      //      }
      if (DIREITA > INTERVALOSENSORPRETO) break;
    }
  }


  else if (ESQUERDA < INTERVALOSENSORPRETO) {
    Antihorario();
    while (1) {
      Leitura();

      //      if (DIREITA < INTERVALOPRETO && ESQUERDA < INTERVALOPRETO && DIREITAVERDE < INTERVALOPRETO && ESQUERDAVERDE < INTERVALOPRETO)
      //        cont++;
      //      if (cont > GAP) {
      //        while (cont-- != 0) {
      //          Horario();
      //          Leitura();
      //          if (DIREITA > INTERVALOPRETO || ESQUERDA > INTERVALOPRETO || DIREITAVERDE > INTERVALOPRETO || ESQUERDAVERDE > INTERVALOPRETO) break;
      //        }
      //      }

      if (ESQUERDA > INTERVALOSENSORPRETO) break;
    }
  }
}

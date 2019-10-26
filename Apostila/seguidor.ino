//Pinagem dos sensores de faixa
#define SENSOR_ESQUERDA A1
#define SENSOR_DIREITA A0
 
//Pinagem para os motores
#define IN1 4
#define IN2 5
#define IN3 6
#define IN4 7
 
#define PWM 3 //Velocidade para o robo
 
int ESQUERDA, DIREITA; //Variaveis responsaveis por receber os valores de leitura dos sensores de faixa
 
int INTERVALO_SENSOR = 150; //Intervalo de cor da faixa para o robo tomar acoes
 
void setup(){
 
    Serial.begin(9600);
    pinMode(PWM, OUTPUT);
    pinMode(IN1, OUTPUT);
    pinMode(IN2, OUTPUT);
    pinMode(IN3, OUTPUT);
    pinMode(IN4, OUTPUT);
 
}
 
void loop(){
       
    Leitura(); //Funcao para leitura de intervalos dos sensores
    //Calibragem(); //Funcao para monitorar a frequencia de leitura dos sensores de faixa
    SeguirFaixa(); //Funcao para o robo seguir faixa
 
}
 
void Calibragem(){
    Serial.print(DIREITA);
    Serial.print(" : ");
    Serial.print(ESQUERDA);
    Serial.print(" TAXA DE VARIACAO DA FAIXA");
    Serial.println("------------------------------------------");
}
 
void Leitura() {
  ESQUERDA = analogRead(SENSOR_ESQUERDA);
  DIREITA = analogRead(SENSOR_DIREITA);
}
 
void SeguirFaixa() {
 
  if (((DIREITA > INTERVALO_SENSOR) && (ESQUERDA > INTERVALO_SENSOR)) || ((DIREITA < INTERVALO_SENSOR) && (ESQUERDA < INTERVALO_SENSOR))) {
    FRENTE();
  }
 
  else if (DIREITA < INTERVALO_SENSOR) {
    ANTIHORARIO();
    while (1) {
      Leitura();
      if (DIREITA > INTERVALO_SENSOR) break;
 
    }
  }
 
  else if (ESQUERDA < INTERVALO_SENSOR) {
    HORARIO();
    while (1) {
      Leitura();
      if (ESQUERDA > INTERVALO_SENSOR) break;
    }
  }
 
}
 
 
void FRENTE(){
    //Ajustando velocidade dos Motores
    analogWrite(PWM, 255);
    //Motor Esquerdo para frente
    digitalWrite(IN1, HIGH);
    digitalWrite(IN2, LOW);
    //Motor Direito para frente
    digitalWrite(IN3, LOW);
    digitalWrite(IN4, HIGH);
}
 
void ANTIHORARIO(){
    analogWrite(PWM, 180);
    //Motor Esquerdo realiza o movimento
    digitalWrite(IN1, HIGH);
    digitalWrite(IN2, LOW);
 
    //Motor Direito fica parado
    digitalWrite(IN3, LOW);
    digitalWrite(IN4, LOW);
}
 
void HORARIO(){
   analogWrite(PWM, 180);
     //Motor Esquerdo fica parado
   digitalWrite(IN1, LOW);
   digitalWrite(IN2, LOW);
     //Motor Direito realiza o movimento
   digitalWrite(IN3, LOW);
   digitalWrite(IN4, HIGH);
}

#define IN1 4
#define IN2 5
#define IN3 6
#define IN4 7

#define PWM 3

void setup(){

	Serial.begin(96000);
	pinMode(PWM, OUTPUT);
	pinMode(IN1, OUTPUT);
	pinMode(IN2, OUTPUT);
	pinMode(IN3, OUTPUT);
	pinMode(IN4, OUTPUT);

}

void loop(){

	FRENTE();
	delay(2000);
	HORARIO();
	delay(1000);
	ANTIHORARIO();
	delay(1000);

}

void FRENTE(){
	//Ajustando velocidade dos Motores
	analogWrite(PWM, 180);
	//Motor Esquerdo para frente
	digitalWrite(IN1, LOW);
	digitalWrite(IN2, HIGH);
	//Motor Direito para frente
	digitalWrite(IN3, LOW);
	digitalWrite(IN4, HIGH);
}

void HORARIO(){
	analogWrite(PWM, 180);
	//Motor Esquerdo realiza o movimento
	digitalWrite(IN1, LOW);
	digitalWrite(IN2, HIGH);
	//Motor Direito fica parado
	digitalWrite(IN3, LOW);
	digitalWrite(IN4, LOW);
}

void ANTIHORARIO(){
   analogWrite(PWM, 180);
	 //Motor Esquerdo fica parado
   digitalWrite(IN1, LOW);
   digitalWrite(IN2, LOW);
	 //Motor Direito realiza o movimento
   digitalWrite(IN3, LOW);
   digitalWrite(IN4, HIGH);
}



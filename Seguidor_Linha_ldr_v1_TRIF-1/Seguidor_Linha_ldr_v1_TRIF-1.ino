
int PWMA = 3; int PWMB = 9;
int AIN1 = 5; int AIN2 = 4;
int BIN1 = 7; int BIN2 = 8;
int STDB = 6;

int SEN1 = A7;  int SEN2 = A6;
int SEN3 = A5;  int SEN4 = A4;
int SEN5 = A3;  int SEN6 = A2;
int SEN7 = A1;  int SEN8 = A0;
int SEN9 = 11;
int Error;
int Error_Ant;
int Error_Anterior;
int P;
int D;
int cont = 0;
float Kp;
float Kd;
float Motor_A;
float Motor_B;
float PD;
static int PWM = 255;
static int Tabela[15][8];

void setup() {
  Serial.begin(9600);

  pinMode(PWMA, OUTPUT);  pinMode(PWMB, OUTPUT);
  pinMode(AIN1, OUTPUT);  pinMode(AIN2, OUTPUT);
  pinMode(BIN1, OUTPUT);  pinMode(BIN2, OUTPUT);
  pinMode(STDB, OUTPUT);

  pinMode(SEN1, INPUT);  pinMode(SEN2, INPUT);
  pinMode(SEN3, INPUT);  pinMode(SEN4, INPUT);
  pinMode(SEN5, INPUT);  pinMode(SEN6, INPUT);
  pinMode(SEN7, INPUT);  pinMode(SEN8, INPUT);
  pinMode(SEN9, INPUT);
  delay(1000);
  Calibracao();
  
  digitalWrite(STDB, HIGH);
  //------------------------------------------
  for (int i = 0; i <= PWM; i = i + 10) {
    analogWrite(PWMA, i);
    digitalWrite(AIN1, HIGH); //Motor A - Lado Esquerdo
    digitalWrite(AIN2, LOW);

    analogWrite(PWMB, i);
    digitalWrite(BIN1, HIGH); //Motor B - Lado Direito
    digitalWrite(BIN2, LOW);
    delay(25);
  }
  Tabela_Error();
  
}

void loop() {
//1 é preto - 0 é branco

  int x = digitalRead(SEN9);
  //Serial.println(x);
  if (x == 0)  {
  delay(45);
    cont = cont + 1;
  //  Serial.println (cont);
    
    if (cont == 5) { ////////alterar aqui o número de cruzamentos
      cont = 0;
      delay(10);
      digitalWrite(STDB, LOW);
      delay(30000);
    }
  }

Read_sensores();

// CÁLCULO DO CONTROLE PROPORCIONAL/DERIVATIVO.
//--------------------------------------------
P = Error;
D = Error - Error_Anterior;
Error_Anterior = Error;
Kp = 80; // Ganho Proporcional. //80
Kd = 5; // Ganho Derivativo. //5
PD = (Kp * P) + (Kd * D); // Cálculo PD.

if (Error >= 0) {
  Motor_A = PWM;
  Motor_B = PWM - PD;
  if (Motor_B < 0) {
    Motor_B = 0;
  }
}
if (Error < 0) {
  Motor_B = PWM;
  Motor_A = PWM + PD;
  if (Motor_A < 0) {
    Motor_A = 0;
  }
}

//--------------------------------------------
analogWrite(PWMA, Motor_A);
digitalWrite(AIN1, HIGH); //Motor A - Lado Esquerdo
digitalWrite(AIN2, LOW);

analogWrite(PWMB, Motor_B);
digitalWrite(BIN1, HIGH); //Motor B - Lado Direito
digitalWrite(BIN2, LOW);
//  Serial.print(Motor_A); Serial.print("  "); Serial.println(Motor_B);
}

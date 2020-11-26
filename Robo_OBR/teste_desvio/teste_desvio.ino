  int ENA = 4; // controle do PWM do motor da esquerda                                                                                     * sensor de cor: frequencia de saida  *
  int IN1 = 5; // motor esquerdo                                                                                                           * L|L|0%                              *
  int IN2 = 6; // motor esquerdo                                                                                                           * L|H|2%                              *
  int IN3 = 7; // motor direito                                                                                                            * H|L|20%                             *
  int IN4 = 8; // motor direito                                                                                                            * H|H|100%                            *
  int ENB = 9; // controle do PWM do motor da direita
  int sharp = A0;  // pino do sensor sharp                                                                                                 * sensor de cor: filtro               *
  int valor_sharp; // valor analogico do sensor sharp                                                                                      * L|L| Vermelho                       *
  int sharp_filtro; // valor do sensor sharp filtrado                                                                                      * L|H| Azul                           *
  int distancia;

void setup() {
  // put your setup code here, to run once:
  pinMode(IN1,OUTPUT);
  pinMode(IN2,OUTPUT);
  pinMode(IN3,OUTPUT);
  pinMode(IN4,OUTPUT);
  pinMode(ENA,OUTPUT);
  pinMode(ENB,OUTPUT);
  pinMode(sharp,INPUT);
  Serial.begin(9600);

}

void loop() {
  sensor_distancia();
  Serial.print(valor_sharp);
  Serial.print("   ");
  Serial.println(distancia);
  Serial.print(" cm ");
  
  if(distancia <= 5){
    desvio();
    sensor_distancia();
  } else {
    freio();
    sensor_distancia();
  }

}

void frente()
  {  
    digitalWrite(IN1,HIGH);
    digitalWrite(IN2,LOW);
    analogWrite(ENA, 122);
    digitalWrite(IN3,LOW);
    digitalWrite(IN4,HIGH);
    analogWrite(ENB,122);
  }

  void atras()
  {
    digitalWrite(IN1,LOW);
    digitalWrite(IN2,HIGH);
    analogWrite(ENA, 122);
    digitalWrite(IN3,HIGH);
    digitalWrite(IN4,LOW);
    analogWrite(ENB,122);
  }

  void esquerda()
  {
    digitalWrite(IN1,HIGH);
    digitalWrite(IN2,LOW);
    analogWrite(ENA, 122);
    digitalWrite(IN3,HIGH);
    digitalWrite(IN4,LOW);
    analogWrite(ENB,122);
  }

  void direita()
  {
    digitalWrite(IN1,LOW);
    digitalWrite(IN2,HIGH);
    analogWrite(ENA, 122);
    digitalWrite(IN3,LOW);
    digitalWrite(IN4,HIGH);
    analogWrite(ENB,122);
  }

  void freio()
  {
    digitalWrite(IN1,HIGH);
    digitalWrite(IN2,HIGH);
    analogWrite(ENA, 255);
    digitalWrite(IN3,HIGH);
    digitalWrite(IN4,HIGH);
    analogWrite(ENB,255);
  }

  void desvio()
  {
    atras();
    delay(500);
    direita();
    delay(250);
    frente();
    delay(500);
    esquerda();
    delay(250);
    frente();
    delay(500);
    esquerda();
    delay(20);
    frente();
    delay(500);
    direita();
    delay(250);
    frente();
    delay(500);
  }
  void sensor_distancia()
  {
    valor_sharp = analogRead(sharp);
    distancia = (13*pow(valor_sharp * 0.0048828125 , -1)-4);
  }

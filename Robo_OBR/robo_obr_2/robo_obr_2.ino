#define  num  20  // numero de amostras para media movel

 
//--------------------------------------pinos ponte h---------------------------------------------------//                                 /**************************************
  int ENA = 4; // controle do PWM do motor da esquerda                                                                                     * sensor de cor: frequencia de saida  *
  int IN1 = 5; // motor esquerdo                                                                                                           * L|L|0%                              *
  int IN2 = 6; // motor esquerdo                                                                                                           * L|H|2%                              *
  int IN3 = 7; // motor direito                                                                                                            * H|L|20%                             *
  int IN4 = 8; // motor direito                                                                                                            * H|H|100%                            *
  int ENB = 9; // controle do PWM do motor da direita                                                                                      **************************************/
 //------------------------------------declaração média movel-------------------------------------------//                                 
  long moving_average(int sig); // variavel do tipo long para função de media movel
  int values[num]; //vetor com num posições, armazena os valores para cálculo da média móvel
//-------------------------------------sensor sharp-----------------------------------------------------//                                 /**************************************
  int sharp = A0;  // pino do sensor sharp                                                                                                 * sensor de cor: filtro               *
  int valor_sharp; // valor analogico do sensor sharp                                                                                      * L|L| Vermelho                       *
  int sharp_filtro; // valor do sensor sharp filtrado                                                                                      * L|H| Azul                           *
  int distancia;    // valor do sensor sharp filtrado e em centimetros                                                                     * H|L| Sem filtro                     *
//-----------------------------------variavel de valor das cores----------------------------------------//                                 * H|H| Verde                          *
  int redD = 0;     //                                                                                                                      **************************************/
  int greenD = 0;  //
  int blueD = 0; //
  int redE = 0;//
  int greenE = 0;  //
  int blueE = 0;  //
//------------------------------------------pinos sensor de cor direito---------------------------------//
  int s0D = 22; // pino de frequencia do sensor
  int s1D = 23; // pino de frequencia do sensor
  int s2D = 24; // pino de filtro de cor
  int s3D = 25; // pino de filtro de cor
  int outD = 26; // saida sensor de cor
//------------------------------------------pinos sensor de cor esquerdo---------------------------------//
  int s0E = 27; // pino de frequencia do sensor
  int s1E = 28; // pino de frequencia do sensor
  int s2E = 29; // pino de filtro de cor
  int s3E = 30; // pino de filtro de cor
  int outE = 31; // saida sensor de cor
  

void setup() {
  pinMode(IN1,OUTPUT);
  pinMode(IN2,OUTPUT);
  pinMode(IN3,OUTPUT);
  pinMode(IN4,OUTPUT);
  pinMode(ENA,OUTPUT);
  pinMode(ENB,OUTPUT);
  pinMode(sharp,INPUT);
  pinMode(s0D, OUTPUT);
  pinMode(s1D, OUTPUT);
  pinMode(s2D, OUTPUT);
  pinMode(s3D, OUTPUT);
  pinMode(outD, INPUT);
  pinMode(s0E, OUTPUT);
  pinMode(s1E, OUTPUT);
  pinMode(s2E, OUTPUT);
  pinMode(s3E, OUTPUT);
  pinMode(outE, INPUT);

  Serial.begin(9600);
  
}

void loop() {
  sensor_distancia();
  sensor_cor();
  
  //Serial.print(valor_sharp);
  //Serial.print("   ");
  //Serial.println(sharp_filtro);
  //Serial.print("   ");
  //Serial.print(distancia);
  //Serial.print(" cm ");
  //Serial.print("Vermelho :");
  //Serial.print(redD, DEC);
  //Serial.print(" Verde : ");
  //Serial.print(greenD, DEC);
  //Serial.print(" Azul : ");
  //Serial.print(blueD, DEC);
  //Serial.println();

  if(distancia <= 5){
    desvio();
    sensor_distancia();
  } else if(((greenD < redD)&&(greenD < blueD))&&((redE||blueE) < greenE)) 
  {
    Serial.println("Verde direita");
    direita();
    
  }else if (((greenE < redE)&&(greenE < blueE))&&((redD||blueD) < greenD))
  {
    Serial.println("Verde esquerda");
    esquerda();
  }else if (((greenD < redD)&&(greenD < blueD))&&((greenE < redE)&&(greenE < blueE))){
    
  }

}



  

}

  void frente()
  {  
    digitalWrite(IN1,HIGH);
    digitalWrite(IN2,LOW);
    analogWrite(ENA, 255);
    digitalWrite(IN3,HIGH);
    digitalWrite(IN4,LOW);
    analogWrite(ENB,255);
  }

  void atras()
  {
    digitalWrite(IN1,LOW);
    digitalWrite(IN2,HIGH);
    analogWrite(ENA, 255);
    digitalWrite(IN3,LOW);
    digitalWrite(IN4,HIGH);
    analogWrite(ENB,255);
  }

  void esquerda()
  {
    digitalWrite(IN1,LOW);
    digitalWrite(IN2,HIGH);
    analogWrite(ENA, 255);
    digitalWrite(IN3,HIGH);
    digitalWrite(IN4,LOW);
    analogWrite(ENB,255);
  }

  void direita()
  {
    digitalWrite(IN1,HIGH);
    digitalWrite(IN2,LOW);
    analogWrite(ENA, 255);
    digitalWrite(IN3,LOW);
    digitalWrite(IN4,HIGH);
    analogWrite(ENB,255);
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
    delay(500);
    frente();
    delay(500);
    esquerda();
    delay(500);
    frente();
    delay(500);
    esquerda();
    delay(500);
    frente();
    delay(500);
    direita();
    delay(500);
    frente();
    delay(500);
  }
  void sensor_distancia()
  {
    valor_sharp = analogRead(sharp);
    sharp_filtro = moving_average(valor_sharp);
    distancia = (13*pow(valor_sharp * 0.0048828125 , -1)-4);
    return 0;
  }
  void sensor_cor()
  {
   //Rotina que le o valor das cores do sensor direito
    digitalWrite(s2D, LOW);
    digitalWrite(s3D, LOW);
    //count OUT, pRed, RED
    redD = pulseIn(outD, digitalRead(outD) == HIGH ? LOW : HIGH);
    digitalWrite(s3D, HIGH);
    //count OUT, pBLUE, BLUE
    blueD = pulseIn(outD, digitalRead(outD) == HIGH ? LOW : HIGH);
    digitalWrite(s2D, HIGH);
    //count OUT, pGreen, GREEN
    greenD = pulseIn(outD, digitalRead(outD) == HIGH ? LOW : HIGH);
  
    //Rotina que le o valor das cores do sensor esquerdo
    digitalWrite(s2E, LOW);
    digitalWrite(s3E, LOW);
    //count OUT, pRed, RED
    redE = pulseIn(outE, digitalRead(outE) == HIGH ? LOW : HIGH);
    digitalWrite(s3E, HIGH);
    //count OUT, pBLUE, BLUE
    blueE = pulseIn(outE, digitalRead(outE) == HIGH ? LOW : HIGH);
    digitalWrite(s2E, HIGH);
    //count OUT, pGreen, GREEN
    greenE = pulseIn(outE, digitalRead(outE) == HIGH ? LOW : HIGH);
 }

long moving_average(int sig)
{
  int i;               //variável auxiliar para iterações
  long acc = 0;        //acumulador
  
  //Desloca o vetor completamente eliminando o valor mais antigo
  for(i = num; i > 0; i--) values[i] = values[i-1];    
  
  values[0] = sig;           //carrega o sinal no primeiro elemento do vetor
  
 // long sum = 0;            //Variável para somatório
  
  for(i = 0; i < num; i++) acc += values[i];
   
  
  return acc / num;         //Retorna a média móvel

} //end moving_average

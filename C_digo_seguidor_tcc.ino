#define num 20  // numero de amostras para media movel
//--------------------------------------pinos ponte h---------------------------------------------------//                                 
  int ENA = 3; // controle do PWM do motor da esquerda                                                                                     
  int IN1 = 4; // motor esquerdo                                                                                                           
  int IN2 = 5; // motor esquerdo                                                                                                           
  int IN3 = 6; // motor direito                                                                                                            
  int IN4 = 7; // motor direito                                                                                                            
  int ENB = 9; // controle do PWM do motor da direita                                                                                      
 //------------------------------------declaração média movel-------------------------------------------//                                 
  long moving_average(int sig); // variavel do tipo long para função de media movel
  int values[num]; //vetor com num posições, armazena os valores para cálculo da média móvel
//-------------------------------------sensor sharp-----------------------------------------------------//                                 
  int sharp = A0;  // pino do sensor sharp                                                                                                 
  int valor_sharp; // valor analogico do sensor sharp                                                                                      
  int sharp_filtro; // valor do sensor sharp filtrado                                                                                      
  int distancia;    // valor do sensor sharp filtrado e em centimetros
//----------------------------------pinos QRE----------------------------------------------------------//
  int QREm = A1;
  int QREd = A2;
  int QREd2 = A3;
  int QREe = A4;
  int QREe2 = A5;
//-------------------------------valores dos QRE's----------------------------------------------------//
  int valM = 0;
  int valD = 0;
  int valD2 = 0;
  int valE = 0;
  int valE2 = 0;
//-------------------------------PID control---------------------------------------------------------//  
   /*int erro = 0;
   int P;
   int I;
   int D;
   int valorPID;
   int erroAnterior;
   int Kp = 25;  // magnitude do movimento 
   int Ki = 0;   // velocidade do movimento
   int Kd = 0;   //estabilidade*/
                                                                       
                               
  void frente();
  void atras();
  void direita();
  void direita90();
  void esquerda();
  void esquerda90();
  void freio();
  void desvio();
  void sensor_distancia();



void frente()
  {  
    digitalWrite(IN1,HIGH);
    digitalWrite(IN2,LOW);
    analogWrite(ENA, 200);
    digitalWrite(IN3,LOW);
    digitalWrite(IN4,HIGH);
    analogWrite(ENB,200);
  }

  void atras()
  {
    digitalWrite(IN1,LOW);
    digitalWrite(IN2,HIGH);
    analogWrite(ENA, 200);
    digitalWrite(IN3,HIGH);
    digitalWrite(IN4,LOW);
    analogWrite(ENB,200);
  }
  void direitasuave()
  {
    digitalWrite(IN1,HIGH);                                                         //high, low, high, low = direita
    digitalWrite(IN2,LOW);
    analogWrite(ENA, 200);
    digitalWrite(IN3,LOW);
    digitalWrite(IN4,HIGH);
    analogWrite(ENB,150);
  }

  void direita()
  {
    digitalWrite(IN1,HIGH);
    digitalWrite(IN2,LOW);
    analogWrite(ENA, 200);
    digitalWrite(IN3,LOW);
    digitalWrite(IN4,HIGH);
    analogWrite(ENB,100);
  }
   void direitaE()
  {
    digitalWrite(IN1,HIGH);
    digitalWrite(IN2,LOW);
    analogWrite(ENA, 200);
    digitalWrite(IN3,HIGH);
    digitalWrite(IN4,LOW);
    analogWrite(ENB,200);
  }
  void direita90()
  {
    digitalWrite(IN1,HIGH);
    digitalWrite(IN2,LOW);
    analogWrite(ENA, 200);
    digitalWrite(IN3,HIGH);
    digitalWrite(IN4,LOW);
    analogWrite(ENB,80);
    
  }
  void esquerdasuave()
  {
    digitalWrite(IN1,HIGH);
    digitalWrite(IN2,LOW);
    analogWrite(ENA, 150);
    digitalWrite(IN3,LOW);
    digitalWrite(IN4,HIGH);
    analogWrite(ENB,200);
  }

  void esquerda()
  {
    digitalWrite(IN1,HIGH);
    digitalWrite(IN2,LOW);
    analogWrite(ENA, 100);
    digitalWrite(IN3,LOW);
    digitalWrite(IN4,HIGH);
    analogWrite(ENB,200);
  }
  void esquerdaE()
  {
    digitalWrite(IN1,LOW);
    digitalWrite(IN2,HIGH);
    analogWrite(ENA, 200);
    digitalWrite(IN3,LOW);
    digitalWrite(IN4,HIGH);
    analogWrite(ENB,200);
  }
   void esquerda90()
  {
    digitalWrite(IN1,LOW);
    digitalWrite(IN2,HIGH);
    analogWrite(ENA, 80);
    digitalWrite(IN3,LOW);
    digitalWrite(IN4,HIGH);
    analogWrite(ENB, 200);
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
   void desvio(){
    direitaE();
    delay(700);
    frente();
    delay(800);
    esquerdaE();
    delay(600);
    frente();
    delay(800);
    esquerdaE();
    delay(700);
    frente();
    delay(1000);
    direitaE();
    delay(700);
    frente();
    delay(600);
   }

  void sensor_distancia()
  {
    valor_sharp = analogRead(sharp);
    sharp_filtro = moving_average(valor_sharp);
    distancia = (13*pow(sharp_filtro * 0.0048828125 , -1));
  }

  void sensor_QRE()
  {
    valM = analogRead(QREm);
    valD = analogRead(QREd);
    valD2 = analogRead(QREd2);
    valE = analogRead(QREe);
    valE2 = analogRead(QREe2);
    
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

/*void calculaPID(){
  P = erro;
  I = I + erro;
  D = erro + erroAnterior;
  valorPID =(Kp*P)+(Ki*I)+(Kd*D);
  erro = erroAnterior;
}*/



void setup() {
  pinMode(IN1,OUTPUT); //seta pinos da ponte h como saida
  pinMode(IN2,OUTPUT);
  pinMode(IN3,OUTPUT);
  pinMode(IN4,OUTPUT);
  pinMode(ENA,OUTPUT);
  pinMode(ENB,OUTPUT);
  pinMode(sharp,INPUT); // seta pino do sensor sharp
  pinMode(QREm, INPUT); // seta pino do sensor QRE
  pinMode(QREd, INPUT);
  pinMode(QREd2, INPUT);
  pinMode(QREe, INPUT);
  pinMode(QREe2, INPUT);


  Serial.begin(9600);

  attachInterrupt(digitalPinToInterrupt(18),desvio,RISING);

}

void loop() {
  sensor_distancia();
  sensor_QRE();

  //sensores QRE´s
  Serial.print("Valor QREm: ");
  Serial.print(valM);
  Serial.println();
  Serial.print("Valor QREd: ");
  Serial.print(valD);
  Serial.println();
  Serial.print("Valor QREd2: ");
  Serial.print(valD2);
  Serial.println();
  Serial.print("Valor QREe: ");
  Serial.print(valE);
  Serial.println();
  Serial.print("Valor QREe2: ");
  Serial.print(valE2);
  Serial.println();

  //sensor distância
  Serial.print("Valor sharp: ");
  Serial.print(distancia);
  Serial.println();
  
  //chamada das funções conforme valor de leitura
  if(distancia<=10){
    digitalWrite(18,HIGH);
  }
  
  if((valE2 >= 500)&&(valE >= 500)&&(valM >= 500)&&(valD >= 500)&&(valD2 >= 500)){
    //0 0 0 0 0
    frente();                                           //descontinuidade na linha
  }                                                                                                                    
  if((valE2 >= 500)&&(valE >= 500)&&(valM <= 500)&&(valD >= 500)&&(valD2 >= 500)){
    //0 0 1 0 0
    //erro = 0;
    frente();
  }
  if((valE2 >= 500)&&(valE >= 500)&&(valM <= 500)&&(valD <= 500)&&(valD2 >= 500)){
    //0 0 1 1 0
    //erro = 1;
    direitasuave();
  }
  if((valE2 >= 500)&&(valE >= 500)&&(valM >= 500)&&(valD <= 500)&&(valD2 >= 500)){
    //0 0 0 1 0
    //erro = 2;
    direita();
  }
  if((valE2 >= 500)&&(valE >= 500)&&(valM >= 500)&&(valD <= 500)&&(valD2 <= 500)){
    //0 0 0 1 1
    //erro = 3;
    direita();
  }
  if((valE2 >= 500)&&(valE >= 500)&&(valM >= 500)&&(valD >= 500)&&(valD2 <= 500)){
    //0 0 0 0 1
    //erro = 4;
    direita90();
  }
  if((valE2 >= 500)&&(valE >= 500)&&(valM <= 500)&&(valD <= 500)&&(valD2 <= 500)){
    //0 0 1 1 1
    //erro = 5;
      freio();
      delay(200);
      frente();
      delay(800);
      direita();
      delay(850);
      atras();
      delay(100);
  }
  if((valE2 >= 500)&&(valE <= 500)&&(valM <= 500)&&(valD >= 500)&&(valD2 >= 500)){
    //0 1 1 0 0
    //erro = -1;
    esquerdasuave();
  }
  if((valE2 >= 500)&&(valE <= 500)&&(valM >= 500)&&(valD >= 500)&&(valD2 >= 500)){
    //0 1 0 0 0
    //erro = -2;
    esquerda();
  }
  if((valE2 <= 500)&&(valE <= 500)&&(valM >= 500)&&(valD >= 500)&&(valD2 >= 500)){
    //1 1 0 0 0
    //erro = -3;
    esquerda();
  }
  if((valE2 <= 500)&&(valE >= 500)&&(valM >= 500)&&(valD >= 500)&&(valD2 >= 500)){
    //1 0 0 0 0
    //erro = -4;
    esquerda90();
  }
  if((valE2 <= 500)&&(valE <= 500)&&(valM <= 500)&&(valD >= 500)&&(valD2 >= 500)){
    //1 1 1 0 0
    //erro = -5;
      freio();
      delay(200);
      frente();
      delay(800);
      esquerda();
      delay(850);
      atras();
      delay(100);
  }
  if((valE2 <= 500)&&(valE <= 500)&&(valM <= 500)&&(valD <= 500)&&(valD2 <= 500)){
    //1 1 1 1 1
    frente();                                                       //encruzilhada
  }
 if((valE2 <= 500)&&(valE <= 500)&&(valM >= 500)&&(valD <= 500)&&(valD2 <= 500)){
    //1 1 0 1 1
    frente();                                                       //encruzilhada
  }
  
}

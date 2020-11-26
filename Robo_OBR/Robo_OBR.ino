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
  int sharp = A3;  // pino do sensor sharp                                                                                                 * sensor de cor: filtro               *
  int valor_sharp; // valor analogico do sensor sharp                                                                                      * L|L| Vermelho                       *
  int sharp_filtro; // valor do sensor sharp filtrado                                                                                      * L|H| Azul                           *
  int distancia;    // valor do sensor sharp filtrado e em centimetros                                                                     * H|L| Sem filtro                     *
//-----------------------------------variavel de valor das cores----------------------------------------//                                 * H|H| Verde                          *
  int redD = 0;     //                                                                                                                     **************************************/
  int greenD = 0;  //
  int blueD = 0; //
  int redE = 0;//
  int greenE = 0;  //
  int blueE = 0;  //
  int totalD = 0; 
  int totalE = 0;
//------------------------------------------pinos sensor de cor direito---------------------------------//
  int s0D = 42; // pino de frequencia do sensor
  int s1D = 43; // pino de frequencia do sensor
  int s2D = 44; // pino de filtro de cor
  int s3D = 45; // pino de filtro de cor
  int outD = 46; // saida sensor de cor
//------------------------------------------pinos sensor de cor esquerdo---------------------------------//
  int s0E = 47; // pino de frequencia do sensor
  int s1E = 48; // pino de frequencia do sensor
  int s2E = 49; // pino de filtro de cor
  int s3E = 50; // pino de filtro de cor
  int outE = 51; // saida sensor de cor
//-----------------------------------------pinos sensores IR-------------------------------------------//
  int IRdir = A2;
  int IResq = A1;
  int IRfrente = A3;
  int valorIRF = 0;
  int valorIRD = 0;
  int valorIRE = 0;

  void frente();
  void atras();
  void direita();
  void direita90();
  void esquerda();
  void esquerda90();
  void freio();
  void desvio();
  void sensor_distancia();
  void sensor_cor();
  void sensor_IR();
  
  

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

  digitalWrite(s0D, LOW);
  digitalWrite(s1D, HIGH);
  digitalWrite(s0E, LOW);
  digitalWrite(s1E, HIGH);
  
}

 void frente()
  {  
    digitalWrite(IN1,HIGH);
    digitalWrite(IN2,LOW);
    analogWrite(ENA, 70);
    digitalWrite(IN3,LOW);
    digitalWrite(IN4,HIGH);
    analogWrite(ENB,70);
  }

  void atras()
  {
    digitalWrite(IN1,LOW);
    digitalWrite(IN2,HIGH);
    analogWrite(ENA, 70);
    digitalWrite(IN3,HIGH);
    digitalWrite(IN4,LOW);
    analogWrite(ENB,70);
  }

  void direita()
  {
    digitalWrite(IN1,HIGH);
    digitalWrite(IN2,LOW);
    analogWrite(ENA, 120);
    digitalWrite(IN3,HIGH);
    digitalWrite(IN4,LOW);
    analogWrite(ENB,120);
  }
  void direita90()
  {
    digitalWrite(IN1,HIGH);
    digitalWrite(IN2,LOW);
    analogWrite(ENA, 150);
    digitalWrite(IN3,HIGH);
    digitalWrite(IN4,LOW);
    analogWrite(ENB,150);
    
  }

  void esquerda()
  {
    digitalWrite(IN1,LOW);
    digitalWrite(IN2,HIGH);
    analogWrite(ENA, 120);
    digitalWrite(IN3,LOW);
    digitalWrite(IN4,HIGH);
    analogWrite(ENB,120);
  }
   void esquerda90()
  {
    digitalWrite(IN1,LOW);
    digitalWrite(IN2,HIGH);
    analogWrite(ENA, 150);
    digitalWrite(IN3,LOW);
    digitalWrite(IN4,HIGH);
    analogWrite(ENB,150);
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
    direita();
    delay(700);
    frente();
    delay(800);
    esquerda();
    delay(600);
    frente();
    delay(800);
    esquerda();
    delay(700);
    frente();
    delay(1000);
    direita();
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
 void sensor_IR(){
  valorIRD = analogRead(IRdir);
  valorIRE = analogRead(IResq);
  valorIRF = analogRead(IRfrente);
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


void loop() { 
  sensor_distancia();
  sensor_cor();
  sensor_IR();

  totalD = ((redD + greenD + blueD)/3);
  totalE = ((redE + greenE + blueE)/3);
  
  Serial.print("valorIRD:  ");
  Serial.print(valorIRD);
  Serial.println();
  //Serial.println(sharp_filtro);
  //Serial.print("   ");
  //Serial.print(distancia);
  //Serial.print(" cm ");
  //Serial.println();*/
  /*Serial.print(" Verde direito : ");
  Serial.print(greenD, DEC);
  Serial.print(" verde esquerdo : ");
  Serial.print(greenE, DEC);
  Serial.println();
  Serial.print(" azul direito : ");
  Serial.print(blueD, DEC);
  Serial.print(" azul esquerdo : ");
  Serial.print(blueE, DEC);
  Serial.println();
  Serial.print(" Vermelho direito : ");
  Serial.print(redD, DEC);
  Serial.print(" vermelho esquerdo : ");
  Serial.print(redE, DEC);
  Serial.println();*/
  Serial.print(totalD);
  Serial.print("/////");
  Serial.println();
  Serial.print(totalE);
  Serial.print("||||");
  Serial.println();

 /* if((distancia <= 8)&&(distancia >= 4)){
    desvio;
    sensor_distancia();
  }else{*/
  if((totalD>=70)&&(totalD<=180)&&((totalE<=70)||(totalE>=70))){
    freio();
    delay(200);
    frente();
    delay(600);
    direita();
    delay(1300);
    sensor_cor();
    sensor_IR();  
  }
 /* if((totalD>=70)&&(totalD<=180)&&((totalE<=70)||(totalE>=70))&&((valorIRE<=600)||(valorIRE>=600))){
    freio();
    delay(200);
    frente();
    delay(600);
    direita();
    delay(1300);
    sensor_cor();
    sensor_IR();  
  }
   if((totalD>=70)&&(totalD<=180)&&((totalE<=70)||(totalE>=70))&&((valorIRD<=600)||(valorIRD>=600))){
    freio();
    delay(200);
    frente();
    delay(600);
    direita();
    delay(1300);
    sensor_cor();
    sensor_IR();  
  }
  if((totalD>=70)&&(totalD<=180)&&((totalE<=70)||(totalE>=70))&&((valorIRD<=600)||(valorIRD>=600))&&((valorIRE<=600)||(valorIRE>=600))){
    freio();
    delay(200);
    frente();
    delay(600);
    direita();
    delay(1300);
    sensor_cor();
    sensor_IR();  
  }*/
  if(((totalE>=70)&&(totalE<=180))&&((totalD<=70)||(totalD>=70))){
    freio();
    delay(200);
    frente();
    delay(600);
    esquerda();
    delay(1300);
    sensor_cor();
    sensor_IR();
  }
  /*if(((totalE>=70)&&(totalE<=180))&&((totalD<=70)||(totalD>=70))&&((valorIRE<=600)||(valorIRE>=600))){
    freio();
    delay(200);
    frente();
    delay(600);
    esquerda();
    delay(1300);
    sensor_cor();
    sensor_IR();

  }
  if(((totalE>=70)&&(totalE<=180))&&((totalD<=70)||(totalD>=70))&&((valorIRD<=600)||(valorIRD>=600))){
    freio();
    delay(200);
    frente();
    delay(600);
    esquerda();
    delay(1300);
    sensor_cor();
    sensor_IR();

  }
   if(((totalE>=70)&&(totalE<=180))&&((totalD<=70)||(totalD>=70))&&((valorIRE<=600)||(valorIRE>=600))&&((valorIRD<=600)||(valorIRD>=600))){
    freio();
    delay(200);
    frente();
    delay(600);
    esquerda();
    delay(1300);
    sensor_cor();
    sensor_IR();

  }*/
  if((totalD <=70)&&(totalE <=70)){
    frente();
    sensor_cor(); 
    sensor_IR();
    
  }
  
  if((totalD >= 70)&&(totalE <=70)){
    direita();
    sensor_cor();
    sensor_IR();
    
    
   
  } 
  
  if((totalD <=70)&&(totalE>=70)){
    esquerda();
    sensor_cor();
    sensor_IR();

    
  }
  if((totalD <=70)&&(totalE>= 180)&&(valorIRD<=600)&&(valorIRE>=800)){
    freio();
    delay(200);
    frente();
    delay(300);
    esquerda();
    delay(1300);
    sensor_cor();
    sensor_IR();

 
  }
  if((totalD >= 180)&&(totalE <=70)&&(valorIRE<=600)&&(valorIRD>=800)){
    freio();
    delay(200);
    frente();
    delay(300);
    direita();
    delay(1300);
    sensor_cor();
    sensor_IR();
    
  }
  /*if((valorIRE<=600)&&(valorIRD>=800)){
    direita90();
    sensor_cor();
    sensor_IR();

    

  }
  if((valorIRD<=600)&&(valorIRE>=800)){
    esquerda90();
    sensor_cor();
    sensor_IR(); 


    
  }
  if((valorIRF>=600)&&(totalE<=70)&&(totalD<=70)){
    frente();
    sensor_cor();
    sensor_IR();
  }*/
  if((valorIRF>=600)&&(valorIRE>=600)&&(valorIRD<=600)){
    frente();
    sensor_cor();
    sensor_IR();
  }
  if((valorIRF>=600)&&(valorIRD>=600)&&(valorIRE<=600)){
    frente();
    sensor_cor();
    sensor_IR();
  }
   if((valorIRF>=600)&&(valorIRD>=600)&&(valorIRE>=600)){
    frente();
    sensor_cor();
    sensor_IR();
  }
  
  
  
 }





 
 


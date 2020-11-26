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
  int IRdir = 10;
  int IResq = 11;
  int IRdir2 = 3;
  int IResq2 = 12;
  int IRfrente = 13;
  int IRfrente2 = 2;
  int valorIRF = 0;
  int valorIRD = 0;
  int valorIRE = 0;
  int valorIRD2 = 0;
  int valorIRE2 = 0;
  int valorIRF2 = 0;

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
  pinMode(IRfrente, INPUT);
  pinMode(IRdir, INPUT);
  pinMode(IRdir2, INPUT);
  pinMode(IResq, INPUT);
  pinMode(IResq2, INPUT);
  pinMode(IRfrente2, INPUT);

  Serial.begin(9600);

  digitalWrite(s0D, HIGH);
  digitalWrite(s1D, LOW);
  digitalWrite(s0E, HIGH);
  digitalWrite(s1E, LOW);
  
}

 void frente()
  {  
    digitalWrite(IN1,HIGH);
    digitalWrite(IN2,LOW);
    analogWrite(ENA, 55);
    digitalWrite(IN3,LOW);
    digitalWrite(IN4,HIGH);
    analogWrite(ENB,55);
  }
  void turbo()
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
    analogWrite(ENA, 200);
    digitalWrite(IN3,HIGH);
    digitalWrite(IN4,LOW);
    analogWrite(ENB, 200);
  }
  void direitasuave()
  {
    digitalWrite(IN1,HIGH);
    digitalWrite(IN2,LOW);
    analogWrite(ENA, 255);
    digitalWrite(IN3,HIGH);
    digitalWrite(IN4,LOW);
    analogWrite(ENB,255);
  }
  
  void direitaforte()
  {
    digitalWrite(IN1,HIGH);
    digitalWrite(IN2,LOW);
    analogWrite(ENA, 255);
    digitalWrite(IN3,HIGH);
    digitalWrite(IN4,LOW);
    analogWrite(ENB,255);
    
  }

  void esquerda()
  {
    digitalWrite(IN1,LOW);
    digitalWrite(IN2,HIGH);
    analogWrite(ENA, 200);
    digitalWrite(IN3,LOW);
    digitalWrite(IN4,HIGH);
    analogWrite(ENB,200);
  }
  void esquerdasuave()
  {
    digitalWrite(IN1,LOW);
    digitalWrite(IN2,HIGH);
    analogWrite(ENA, 255);
    digitalWrite(IN3,LOW);
    digitalWrite(IN4,HIGH);
    analogWrite(ENB,255);
  }
   void esquerdaforte()
  {
    digitalWrite(IN1,LOW);
    digitalWrite(IN2,HIGH);
    analogWrite(ENA, 255);
    digitalWrite(IN3,LOW);
    digitalWrite(IN4,HIGH);
    analogWrite(ENB,255);
  }

  void freio()
  {
    digitalWrite(IN1,LOW);
    digitalWrite(IN2,LOW);
   // analogWrite(ENA, 255);
    digitalWrite(IN3,LOW);
    digitalWrite(IN4,LOW);
   // analogWrite(ENB,255);
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
  valorIRD = digitalRead(IRdir);
  valorIRE = digitalRead(IResq);
  valorIRD2 = digitalRead(IRdir2);
  valorIRE2 = digitalRead(IResq2);
  valorIRF = digitalRead(IRfrente);
  valorIRF2 = digitalRead(IRfrente2);
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
  Serial.print("IRF2    ");
  Serial.print(valorIRF2);
  Serial.print("|    ");   
  Serial.print(valorIRE2);
  //Serial.print("  ");
  Serial.print(valorIRE);
  //Serial.print("  ");
  Serial.print(valorIRF);
 // Serial.print("  ");
  Serial.print(valorIRD);
  //Serial.print("  ");
  Serial.println(valorIRD2);
  //Serial.print("/////");
  //Serial.println();
  //Serial.print(valorIRE);
  //Serial.print("||||");
  //Serial.println();

 /* if((distancia <= 8)&&(distancia >= 4)){
    desvio;
    sensor_distancia();
  }else{*/
  if((valorIRE2==0)&&(valorIRE==0)&&(valorIRF==0)&&(valorIRD==0)&&(valorIRD2==0)){
    turbo();  
    //TUDO BRANCO
  }
   if((valorIRE2==0)&&(valorIRE==0)&&(valorIRF==1)&&(valorIRD==0)&&(valorIRD2==0)&&(valorIRF2==0)){
    frente();
    //SET POINT
   }
  /* if((valorIRE2==1)&&(valorIRF==1)&&(totalE>=650)){
    //VERDEEEE ESQUERDA
    frente();
    delay(800);
    esquerdaforte();
    delay(800);
      
   }*/
 if((valorIRE2==1)&&(valorIRE==1)&&(valorIRF==1)&&(totalE<=650)&&(valorIRF2==0)){
    frente();
    delay(700);
    esquerdaforte();
    delay(850);
    atras();
    delay(200);
    //90º ESQUERDA  
   }
     if((valorIRD2==1)&&(valorIRD==1)&&(valorIRF==1)&&(totalD<=650)&&(valorIRF2==0)){
    frente();
    delay(700);
    direitaforte();
    delay(900);
    atras();
    delay(200);
    //90º direita  
   }
  /*  if((valorIRE2==1)&&(totalE<=650)&&(valorIRF2==1)){
    frente();
    delay(200);
    //T SEM VERDE  
   }
   if((valorIRD2==1)&&(totalD<=650)&&(valorIRF2==1)){
    frente();
    delay(200);
    //T SEM VERDE  
   }*/
   if((valorIRE2==0)&&(valorIRE==1)&&(valorIRF==0)&&(valorIRD==0)&&(valorIRD2==0)){
    esquerda();
    delay(100);  
  }
  if((valorIRE2==0)&&(valorIRE==0)&&(valorIRF==0)&&(valorIRD==1)&&(valorIRD2==0)&&(valorIRF2==0)){
    direita(); 
    delay(100);
     
  } if((valorIRE2==0)&&(valorIRE==0)&&(valorIRF==0)&&(valorIRD==1)&&(valorIRD2==0)&&(valorIRF2==1)){
    frente(); 
    delay(100);
     
  }
   /*if((valorIRD==1)&&(valorIRF==1)&&(totalD>=650)){
    //  VERDEEEEEEEE DIREITA
    frente();
    delay(800);
    direitaforte();
    delay(900);

      
  }
 // if((valorIRD2==1)&&(valorIRD==1)&&(valorIRE==0)&&(totalD<=650)){
  //  frente();
  //  delay(800);
  //  direitaforte();
  //  delay(900);
  //  atras();
   // delay(300);
      
 // }*/
  if((valorIRE==1)&&(valorIRD==1)&&(valorIRF==1)&&(totalD<=650)&&(totalE<=650)){
    frente();
    delay(200);
    //encruzilhada sem verde
  }
   if((valorIRE==1)&&(valorIRD==1)&&(valorIRF==1)&&(totalD>=650)&&(totalE<=650)){
    frente();
    delay(800);
    direitaforte();
    delay(860);
    atras();
    delay(350);
    //encruzilhada com verde na direita
  }
   if((valorIRE==1)&&(valorIRD==1)&&(valorIRF==1)&&(totalD<=650)&&(totalE>=650)){
    frente();
    delay(700);
    esquerdaforte();
    delay(850);
    atras();
    delay(300);
    //encruzilhada com verde na esquerda
  }
   if((valorIRE==1)&&(valorIRD==1)&&(valorIRF==1)&&(totalD>=650)&&(totalE>=650)&&(valorIRF2==0)){
    frente();
    delay(700);
    esquerdaforte();
    delay(1900);
    atras();
    delay(500);
    //encruzilhada com 2 verdE
  }
  /*if((valorIRF2==1)&&(valorIRF==1)&&(valorIRE2==0)&&(valorIRE==0)&&(valorIRD==0)&&(valorIRD2==0)){
    turbo();
  }*/
  if((valorIRF2==1)&&(valorIRF==1)){
    turbo(); 
  }
 /* if((valorIRE2==1)&&(valorIRD2==1)&&(totalD>=650)&&(totalE>=650)){
    frente();
    delay(800);
    direitaforte();
    delay(2000);
  }*/

  /*if((valorIRE2==1)&&(valorIRE==1)&&(valorIRF==1)&&(valorIRD==0)&&(valorIRD2==0)){
    
   esquerdaforte(); 
  }
   if((valorIRE2==0)&&(valorIRE==0)&&(valorIRF==1)&&(valorIRD==1)&&(valorIRD2==1)){
   freio();
   delay(100);
   direitaforte(); 
   }*/

  /*if((valorIRE2>=600)&&(valorIRE>=600)&&(valorIRF>=600)&&(valorIRD>=600)&&(valorIRD2>=600)&&(totalD<=80)&&(totalE<=80)){
     frente();
     delay(100);
  }
   if((valorIRE2>=600)&&(valorIRE>=600)&&(valorIRF>=600)&&(valorIRD>=600)&&(valorIRD2>=600)&&(totalD>=80)&&(totalE<=80)){
     freio();
     delay(200);
     frente();
     delay(600);
     direita();
     delay(1200);
  }
  if((valorIRE2>=600)&&(valorIRE>=600)&&(valorIRF>=600)&&(valorIRD>=600)&&(valorIRD2>=600)&&(totalD<=80)&&(totalE>=80)){
     freio();
     delay(200);
     frente();
     delay(600);
     esquerda();
     delay(1200);
  }
  if((valorIRE2>=600)&&(valorIRE>=600)&&(valorIRF>=600)&&(valorIRD>=600)&&(valorIRD2>=600)&&(totalD>=80)&&(totalE>=80)){
     freio();
     delay(200);
     frente();
     delay(600);
     esquerda();
     delay(2000);
  }
  if((valorIRE2<=600)&&(valorIRE<=600)&&(valorIRF>=600)&&(valorIRD>=600)&&(valorIRD2>=600)&&(totalD<=80)&&(totalE<=80)){
     freio();
     delay(200);
     frente();
     delay(100);
  }
   if((valorIRE2<=600)&&(valorIRE<=600)&&(valorIRF>=600)&&(valorIRD>=600)&&(valorIRD2>=600)&&(totalD>=80)&&(totalE<=80)){
     freio();
     delay(200);
     frente();
     delay(600);
     direita();
     delay(1200);
  }
   if((valorIRE2>=600)&&(valorIRE>=600)&&(valorIRF>=600)&&(valorIRD<=600)&&(valorIRD2<=600)&&(totalD<=80)&&(totalE>=80)){
     freio();
     delay(200);
     frente();
     delay(600);
     esquerda();
     delay(1200);
  }
   if((valorIRE2>=600)&&(valorIRE>=600)&&(valorIRF>=600)&&(valorIRD<=600)&&(valorIRD2<=600)&&(totalD<=80)&&(totalE<=80)){
     freio();
     delay(200);
     frente();
     delay(100);
  }
  
 */}





 
 

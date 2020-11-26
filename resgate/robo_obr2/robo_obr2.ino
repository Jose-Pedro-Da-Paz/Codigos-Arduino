#define  num  20  // numero de amostras para media movel

 
//--------------------------------------pinos ponte h---------------------------------------------------//                                 /**************************************
  int ENA = 9; // controle do PWM do motor da esquerda                                                                                     * sensor de cor: frequencia de saida  *
  int IN1 = 38; // motor esquerdo                                                                                                          * L|L|0%                              *
  int IN2 = 7; // motor esquerdo                                                                                                           * L|H|2%                              *
  int IN3 = 6; // motor direito                                                                                                            * H|L|20%                             *
  int IN4 = 5; // motor direito                                                                                                            * H|H|100%                            *
  int ENB = 4; // controle do PWM do motor da direita                                                                                      **************************************/
 //------------------------------------declaração média movel-------------------------------------------//                                 
  long moving_average(int sig); // variavel do tipo long para função de media movel
  int values[num]; //vetor com num posições, armazena os valores para cálculo da média móvel
//-------------------------------------sensor sharp-----------------------------------------------------//                                 /**************************************
  int sharp = A0;  // pino do sensor sharp                                                                                                 * sensor de cor: filtro               *
  int valor_sharp; // valor analogico do sensor sharp                                                                                      * L|L| Vermelho                       *
  int sharp_filtro; // valor do sensor sharp filtrado                                                                                      * L|H| Azul                           *
  int distancia;    // valor do sensor sharp filtrado e em centimetros                                                                     * H|L| Sem filtro                     *
//-----------------------------------variavel de valor das cores----------------------------------------//                                 * H|H| Verde                          *                                                                                                                     **************************************/
  int greenD = 0;  //
  int greenE = 0;  //
//------------------------------------------pinos sensor de cor direito---------------------------------//
  int s0D = 42; // pino de frequencia do sensor -laranja-
  int s1D = 43; // pino de frequencia do sensor -roxo-
  int s2D = 44; // pino de filtro de cor -verde-
  int s3D = 45; // pino de filtro de cor -amarelo-
  int outD = 46; // saida sensor de cor
//------------------------------------------pinos sensor de cor esquerdo---------------------------------//
  int s0E = 47; // pino de frequencia do sensor -laranja-
  int s1E = 48; // pino de frequencia do sensor -roxo-
  int s2E = 49; // pino de filtro de cor -verde-
  int s3E = 50; // pino de filtro de cor -amarelo-
  int outE = 51; // saida sensor de cor
//-----------------------------------------pinos sensores IR-------------------------------------------//
  int IRdir = 10;
  int IResq = 11;
  int IRdir2 = 13;
  int IResq2 = 12;
  int IRfrente = 3;
  int IRfrente2 = 8;
//---------------------------------------variaveis sensor IR-------------------------------------------//  
  int valorIRF = 0;
  int valorIRD = 0;
  int valorIRE = 0;
  int valorIRD2 = 0;
  int valorIRE2 = 0;
  int valorIRF2 = 0;
//---------------------------------------EXTRAS---------------------------------------------------------//
  int interVD = 18;
  int interVE = 19;
  
  int limVd = 140;
  int limVe = 175;

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
//---------------------------configuração dos pinos como E/S--------------------------------//  
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
//-----------------------------------Porta Serial--------------------------------------//
  Serial.begin(9600);
//-----------------------------------configuração freq. sensor de cor------------------//
  digitalWrite(s0D, LOW);
  digitalWrite(s1D, HIGH);
  digitalWrite(s0E, LOW);
  digitalWrite(s1E, HIGH);

//----------------------------------configuração das Interrupções----------------------// 
  attachInterrupt(digitalPinToInterrupt(interVD),verdeDireita,RISING);
  attachInterrupt(digitalPinToInterrupt(interVE),verdeEsquerda,RISING);
  
}

 void frente(){  
    digitalWrite(IN1,HIGH);
    digitalWrite(IN2,LOW);
    analogWrite(ENA, 50);
    digitalWrite(IN3,LOW);
    digitalWrite(IN4,HIGH);
    analogWrite(ENB,50);
  }
  void turbo()
  {  
    digitalWrite(IN1,HIGH);
    digitalWrite(IN2,LOW);
    analogWrite(ENA, 55);
    digitalWrite(IN3,LOW);
    digitalWrite(IN4,HIGH);
    analogWrite(ENB,55);
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
   void verdeEsquerda(){
       
       
       frente();
       delay(700);
       esquerdaforte();
       delay(800);
       atras();
       delay(200);
       
   }
   void verdeDireita(){
       
       
       frente();
       delay(700);
       direitaforte();
       delay(800);
       atras();
       delay(200);
       
   }

  void sensor_distancia()
  {
    valor_sharp = analogRead(sharp);
    distancia = (13*pow(valor_sharp * 0.0048828125 , -1));
  }
  void sensor_cor()
  {
   //Rotina que le o valor das cores do sensor direito
    digitalWrite(s2D, HIGH);
    digitalWrite(s3D, LOW);
    //count OUT, pGreen, GREEN
    greenD = pulseIn(outD, digitalRead(outD) == HIGH ? LOW : HIGH);
  
    //Rotina que le o valor das cores do sensor esquerdo
    digitalWrite(s2E, HIGH);
    digitalWrite(s3E, LOW);
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
 



void loop(){
  sensor_IR();
  sensor_cor();

  digitalWrite(interVE,LOW);
  digitalWrite(interVD,LOW);
  
  Serial.print(valorIRE2);
  Serial.print(valorIRE);
  Serial.print(valorIRF);
  Serial.print(valorIRD);
  Serial.print(valorIRD2);
  Serial.println();
 /*Serial.print(greenE);
  Serial.print("-------");
  Serial.print(greenD);
  Serial.println();*/
  /*Serial.print("int Dir: ");
  Serial.print(digitalRead(interVD));
  Serial.println();
  Serial.print("int Esq: ");
  Serial.print(digitalRead(interVE));
  Serial.println();*/
  
  
  /*
    01| 0 0 0 0 0   1
    02| 0 0 0 0 1   1
    03| 0 0 0 1 0   1
    04| 0 0 0 1 1   1
    05| 0 0 1 0 0   SETPOINT
    08| 0 0 1 1 1   1
    09| 0 1 0 0 0   1
    17| 1 0 0 0 0   1
    25| 1 1 0 0 0   1
    29| 1 1 1 0 0   1
    32| 1 1 1 1 1   1
    */

    

//---------------------------------APENAS OS 5 IRs ALINHADOS IDENTIFICANDO-----------------------------------------------------------------------  
    
  if((valorIRF2==1)&&(greenE<=50)&&(greenD>=50)){
    
    Serial.println("Interrupção Direita");
    digitalWrite(interVD,HIGH);
    delay(100);
  }
  if((valorIRF2==1)&&(greenE>=50)&&(greenD<=50)){
   
    Serial.println("Interrupção Esquerda");
    digitalWrite(interVE,HIGH);
    delay(100);
  }
  if((greenE<=50)&&(greenD>=50)){
    
    Serial.println("Interrupção Direita");
    digitalWrite(interVD,HIGH);
    delay(100);
  }
  if((greenE>=50)&&(greenD<=50)){
   
    Serial.println("Interrupção Esquerda");
    digitalWrite(interVE,HIGH);
    delay(100);
  }
  /*noInterrupts();
  if(distancia<=10){
    desvio();
    interrupts();
  }else{*/
  if((valorIRE2==0)&&(valorIRE==0)&&(valorIRF==0)&&(valorIRD==0)&&(valorIRD2==0)&&(valorIRF2==0)){
    //GAP(TUDO BRANCO)
    turbo();
  }
  if((valorIRE2==0)&&(valorIRE==0)&&(valorIRF==0)&&(valorIRD==0)&&(valorIRD2==1)&&(valorIRF2==0)){
    //EXTREMO DIREITA

    direitaforte();

  }
  if((valorIRE2==0)&&(valorIRE==0)&&(valorIRF==0)&&(valorIRD==1)&&(valorIRD2==0)&&(valorIRF2==0)){
    //DIREITA
    direitaforte();
  }
  if((valorIRE2==0)&&(valorIRE==0)&&(valorIRF==0)&&(valorIRD==1)&&(valorIRD2==1)&&(valorIRF2==0)){
    //DIREITA E EXTREMO DIREITA

    direitaforte();

  }
  if((valorIRE2==0)&&(valorIRE==0)&&(valorIRF==1)&&(valorIRD==0)&&(valorIRD2==0)&&(valorIRF2==0)){
    //SET POINT
    frente();
  }
  if((valorIRE2==0)&&(valorIRE==0)&&(valorIRF==1)&&(valorIRD==0)&&(valorIRD2==1)&&(valorIRF2==0)){
    //CENTRO EXTREMO DIREITA
    freio();
    delay(200);
    frente();
    delay(800);
    direitaforte();
    delay(1000);
    atras();
    delay(200);
  }
  if((valorIRE2==0)&&(valorIRE==0)&&(valorIRF==1)&&(valorIRD==1)&&(valorIRD2==0)&&(valorIRF2==0)){
    //CENTRO DIREITA

    direitaforte();


  }
  if((valorIRE2==0)&&(valorIRE==0)&&(valorIRF==1)&&(valorIRD==1)&&(valorIRD2==1)&&(valorIRF2==0)){
    //DIREITA 90º
    freio();
    delay(200);
    frente();
    delay(800);
    direitaforte();
    delay(1000);
    atras();
    delay(200);
  }
  if((valorIRE2==0)&&(valorIRE==1)&&(valorIRF==0)&&(valorIRD==0)&&(valorIRD2==0)&&(valorIRF2==0)){
    //ESQUERDA
    esquerdaforte();
  }
  if((valorIRE2==0)&&(valorIRE==1)&&(valorIRF==0)&&(valorIRD==0)&&(valorIRD2==1)&&(valorIRF2==0)){
    //XXXXXXXXXXXXXXXXXXXXXX
    frente();
  }
  if((valorIRE2==0)&&(valorIRE==1)&&(valorIRF==0)&&(valorIRD==1)&&(valorIRD2==0)&&(valorIRF2==0)){
    //XXXXXXXXXXXXXXXXXXXXXX
    frente();
  }
  if((valorIRE2==0)&&(valorIRE==1)&&(valorIRF==0)&&(valorIRD==1)&&(valorIRD2==1)&&(valorIRF2==0)){
    //XXXXXXXXXXXXXXXXXXXXXX
    frente();
  }
  if((valorIRE2==0)&&(valorIRE==1)&&(valorIRF==1)&&(valorIRD==0)&&(valorIRD2==0)&&(valorIRF2==0)){
    //CENTRO ESQUERDA
   
    esquerdaforte();

  }
  if((valorIRE2==0)&&(valorIRE==1)&&(valorIRF==1)&&(valorIRD==0)&&(valorIRD2==1)&&(valorIRF2==0)){
    //XXXXXXXXXXXXXXXXXXXXX
    frente();
  }
  if((valorIRE2==0)&&(valorIRE==1)&&(valorIRF==1)&&(valorIRD==1)&&(valorIRD2==0)){
    //OS TRES DOS CENTROS PRETOS
    frente();
  }
  if((valorIRE2==0)&&(valorIRE==1)&&(valorIRF==1)&&(valorIRD==1)&&(valorIRD2==1)&&(valorIRF2==0)){
    //ENCRUZILHADA COM DEFICIENCIA
    frente();
  }
  if((valorIRE2==1)&&(valorIRE==0)&&(valorIRF==0)&&(valorIRD==0)&&(valorIRD2==0)&&(valorIRF2==0)){
    //ESQUERDA
 
    esquerdaforte();

  }
  if((valorIRE2==1)&&(valorIRE==0)&&(valorIRF==0)&&(valorIRD==0)&&(valorIRD2==1)&&(valorIRF2==0)){
    //EXTREMA ESQUERDA E EXTREMA DIREITA
    frente();
  }
  if((valorIRE2==1)&&(valorIRE==0)&&(valorIRF==0)&&(valorIRD==1)&&(valorIRD2==0)&&(valorIRF2==0)){
    //XXXXXXXXXXXXXXXXXXX
    frente();
  }
  if((valorIRE2==1)&&(valorIRE==0)&&(valorIRF==0)&&(valorIRD==1)&&(valorIRD2==1)&&(valorIRF2==0)){
    //XXXXXXXXXXXXXXXXXXX
    frente();
  }
  if((valorIRE2==1)&&(valorIRE==0)&&(valorIRF==1)&&(valorIRD==0)&&(valorIRD2==0)&&(valorIRF2==0)){
    //CENTRO E EXTREMA ESQUERDA
    freio();
    delay(200);
    frente();
    delay(800);
    esquerdaforte();
    delay(800);
    atras();
    delay(200);
  }
  if((valorIRE2==1)&&(valorIRE==0)&&(valorIRF==1)&&(valorIRD==0)&&(valorIRD2==1)&&(valorIRF2==0)){
    //XXXXXXXXXXXXXXXXXXX
    frente();
  }
  if((valorIRE2==1)&&(valorIRE==0)&&(valorIRF==1)&&(valorIRD==1)&&(valorIRD2==0)&&(valorIRF2==0)){
    //XXXXXXXXXXXXXXXXXXX
    frente();
  }
  if((valorIRE2==1)&&(valorIRE==0)&&(valorIRF==1)&&(valorIRD==1)&&(valorIRD2==1)&&(valorIRF2==0)){
    //XXXXXXXXXXXXXXXXXXX
    frente();
  }
  if((valorIRE2==1)&&(valorIRE==1)&&(valorIRF==0)&&(valorIRD==0)&&(valorIRD2==0)&&(valorIRF2==0)){
    //ESQUERDA E EXTREMA ESQUERDA

    esquerdaforte();
    
  }
  if((valorIRE2==1)&&(valorIRE==1)&&(valorIRF==0)&&(valorIRD==0)&&(valorIRD2==1)&&(valorIRF2==0)){
    //XXXXXXXXXXXXXXXXXXX
    frente();
  }
  if((valorIRE2==1)&&(valorIRE==1)&&(valorIRF==0)&&(valorIRD==1)&&(valorIRD2==0)&&(valorIRF2==0)){
    //XXXXXXXXXXXXXXXXXXX
    frente();
  }
  if((valorIRE2==1)&&(valorIRE==1)&&(valorIRF==0)&&(valorIRD==1)&&(valorIRD2==1)&&(valorIRF2==0)){
    //XXXXXXXXXXXXXXXXXXX
    frente();
  }
  if((valorIRE2==1)&&(valorIRE==1)&&(valorIRF==1)&&(valorIRD==0)&&(valorIRD2==0)&&(valorIRF2==0)){
    //ESQUERDA 90º
    freio();
    delay(200);
    frente();
    delay(800);
    esquerdaforte();
    delay(800);
    atras();
    delay(200);
  }
  if((valorIRE2==1)&&(valorIRE==1)&&(valorIRF==1)&&(valorIRD==0)&&(valorIRD2==1)&&(valorIRF2==0)){
    //XXXXXXXXXXXXXXXXXXX
    frente();
  }
  if((valorIRE2==1)&&(valorIRE==1)&&(valorIRF==1)&&(valorIRD==1)&&(valorIRD2==0)&&(valorIRF2==0)){
    //XXXXXXXXXXXXXXXXXXX
    frente();
  }
  if((valorIRE2==1)&&(valorIRE==1)&&(valorIRF==1)&&(valorIRD==1)&&(valorIRD2==1)&&(valorIRF2==0)){
    //XXXXXXXXXXXXXXXXXXX
    frente();
  }
//------------------------------------- IR AVANÇADO LIGADO------------------------------------------------------------------------
    if((valorIRE2==0)&&(valorIRE==0)&&(valorIRF==0)&&(valorIRD==0)&&(valorIRD2==0)&&(valorIRF2==1)){
    //GAP(TUDO BRANCO)
    turbo();
  }
  if((valorIRE2==0)&&(valorIRE==0)&&(valorIRF==0)&&(valorIRD==0)&&(valorIRD2==1)&&(valorIRF2==1)){
    //EXTREMO DIREITA

    frente();

  }
  if((valorIRE2==0)&&(valorIRE==0)&&(valorIRF==0)&&(valorIRD==1)&&(valorIRD2==0)&&(valorIRF2==1)){
    //DIREITA
    frente();
  }
  if((valorIRE2==0)&&(valorIRE==0)&&(valorIRF==0)&&(valorIRD==1)&&(valorIRD2==1)&&(valorIRF2==1)){
    //DIREITA E EXTREMO DIREITA

   frente();

  }
  if((valorIRE2==0)&&(valorIRE==0)&&(valorIRF==1)&&(valorIRD==0)&&(valorIRD2==0)&&(valorIRF2==1)){
    //SET POINT
    frente();
  }
  if((valorIRE2==0)&&(valorIRE==0)&&(valorIRF==1)&&(valorIRD==0)&&(valorIRD2==1)&&(valorIRF2==1)){
    //CENTRO EXTREMO DIREITA
    frente();
  }
  if((valorIRE2==0)&&(valorIRE==0)&&(valorIRF==1)&&(valorIRD==1)&&(valorIRD2==0)&&(valorIRF2==1)){
    //CENTRO DIREITA

    frente();

  }
  if((valorIRE2==0)&&(valorIRE==0)&&(valorIRF==1)&&(valorIRD==1)&&(valorIRD2==1)&&(valorIRF2==1)){
    //Encruzilhada a direita
    frente();
    delay(300);

  }
  if((valorIRE2==0)&&(valorIRE==1)&&(valorIRF==0)&&(valorIRD==0)&&(valorIRD2==0)&&(valorIRF2==1)){
    //ESQUERDA
    frente();
  }
  if((valorIRE2==0)&&(valorIRE==1)&&(valorIRF==0)&&(valorIRD==0)&&(valorIRD2==1)&&(valorIRF2==1)){
    //XXXXXXXXXXXXXXXXXXXXXX
    frente();
  }
  if((valorIRE2==0)&&(valorIRE==1)&&(valorIRF==0)&&(valorIRD==1)&&(valorIRD2==0)&&(valorIRF2==1)){
    //XXXXXXXXXXXXXXXXXXXXXX
    frente();
  }
  if((valorIRE2==0)&&(valorIRE==1)&&(valorIRF==0)&&(valorIRD==1)&&(valorIRD2==1)&&(valorIRF2==1)){
    //XXXXXXXXXXXXXXXXXXXXXX
    frente();
  }
  if((valorIRE2==0)&&(valorIRE==1)&&(valorIRF==1)&&(valorIRD==0)&&(valorIRD2==0)&&(valorIRF2==1)){
    //CENTRO ESQUERDA
   
    frente();

  }
  if((valorIRE2==0)&&(valorIRE==1)&&(valorIRF==1)&&(valorIRD==0)&&(valorIRD2==1)&&(valorIRF2==1)){
    //XXXXXXXXXXXXXXXXXXXXX
    frente();
  }
  if((valorIRE2==0)&&(valorIRE==1)&&(valorIRF==1)&&(valorIRD==1)&&(valorIRD2==0)&&(valorIRF2==1)){
    //OS TRES DOS CENTROS PRETOS
    frente();
  }
  if((valorIRE2==0)&&(valorIRE==1)&&(valorIRF==1)&&(valorIRD==1)&&(valorIRD2==1)&&(valorIRF2==1)){
    //ENCRUZILHADA COM DEFICIENCIA
    
    freio();
    delay(500);
    frente();
  }
  if((valorIRE2==1)&&(valorIRE==0)&&(valorIRF==0)&&(valorIRD==0)&&(valorIRD2==0)&&(valorIRF2==1)){
    //ESQUERDA
    frente();

  }
  if((valorIRE2==1)&&(valorIRE==0)&&(valorIRF==0)&&(valorIRD==0)&&(valorIRD2==1)&&(valorIRF2==1)){
    //EXTREMA ESQUERDA E EXTREMA DIREITA
    frente();
  }
  if((valorIRE2==1)&&(valorIRE==0)&&(valorIRF==0)&&(valorIRD==1)&&(valorIRD2==0)&&(valorIRF2==1)){
    //XXXXXXXXXXXXXXXXXXX
    frente();
  }
  if((valorIRE2==1)&&(valorIRE==0)&&(valorIRF==0)&&(valorIRD==1)&&(valorIRD2==1)&&(valorIRF2==1)){
    //XXXXXXXXXXXXXXXXXXX
    frente();
  }
  if((valorIRE2==1)&&(valorIRE==0)&&(valorIRF==1)&&(valorIRD==0)&&(valorIRD2==0)&&(valorIRF2==1)){
    //CENTRO E EXTREMA ESQUERDA
    frente();
  }
  if((valorIRE2==1)&&(valorIRE==0)&&(valorIRF==1)&&(valorIRD==0)&&(valorIRD2==1)&&(valorIRF2==1)){
    //XXXXXXXXXXXXXXXXXXX
    frente();
  }
  if((valorIRE2==1)&&(valorIRE==0)&&(valorIRF==1)&&(valorIRD==1)&&(valorIRD2==0)&&(valorIRF2==1)){
    //XXXXXXXXXXXXXXXXXXX
    frente();
  }
  if((valorIRE2==1)&&(valorIRE==0)&&(valorIRF==1)&&(valorIRD==1)&&(valorIRD2==1)&&(valorIRF2==1)){
    //XXXXXXXXXXXXXXXXXXX
    frente();
  }
  if((valorIRE2==1)&&(valorIRE==1)&&(valorIRF==0)&&(valorIRD==0)&&(valorIRD2==0)&&(valorIRF2==1)){
    //ESQUERDA E EXTREMA ESQUERDA

    frente();
    
  }
  if((valorIRE2==1)&&(valorIRE==1)&&(valorIRF==0)&&(valorIRD==0)&&(valorIRD2==1)&&(valorIRF2==1)){
    //XXXXXXXXXXXXXXXXXXX
    frente();
  }
  if((valorIRE2==1)&&(valorIRE==1)&&(valorIRF==0)&&(valorIRD==1)&&(valorIRD2==0)&&(valorIRF2==1)){
    //XXXXXXXXXXXXXXXXXXX
    frente();
  }
  if((valorIRE2==1)&&(valorIRE==1)&&(valorIRF==0)&&(valorIRD==1)&&(valorIRD2==1)&&(valorIRF2==1)){
    //XXXXXXXXXXXXXXXXXXX
    frente();
  }
  if((valorIRE2==1)&&(valorIRE==1)&&(valorIRF==1)&&(valorIRD==0)&&(valorIRD2==0)&&(valorIRF2==1)){
    //ENCRUZILHADA A ESQUERDA
    frente();
    delay(300);
   
  }
  if((valorIRE2==1)&&(valorIRE==1)&&(valorIRF==1)&&(valorIRD==0)&&(valorIRD2==1)&&(valorIRF2==1)){
    //XXXXXXXXXXXXXXXXXXX
    frente();
  }
  if((valorIRE2==1)&&(valorIRE==1)&&(valorIRF==1)&&(valorIRD==1)&&(valorIRD2==0)&&(valorIRF2==1)){
    //XXXXXXXXXXXXXXXXXXX
    frente();
  }
  if((valorIRE2==1)&&(valorIRE==1)&&(valorIRF==1)&&(valorIRD==1)&&(valorIRD2==1)&&(valorIRF2==1)){
    //ENCRUZILHADA CRUZ
    freio();
    delay(500);
    frente();
    delay(300);
  }
 
  
  
  
  
   

}


 

//Declaracion de pines para sensores 
int Sharpfrent = A0;  
int QtrDer = A1; 
int QtrIzq = A2;
int SharpladoDer = A3; 
int SharpladoIzq = A4;

//Declaracion de variables para leer los valores de los sensores  
int Sfrent = 0; 
int SLadoizq = 0;
int SLadoder = 0; 
int Qder = 0; 
int Qizq = 0; 

//Declaracion de pines para los motores 
int Mder1 = 4;
int Mder2 = 5; 
int Mizq1 = 6; 
int Mizq2 = 7; 
 

void setup() { 
  pinMode(Mder1, OUTPUT); 
  pinMode(Mder2, OUTPUT); 
  pinMode(Mizq1, OUTPUT); 
  pinMode(Mizq2, OUTPUT); 
  
  delay(8000); 
  // Tiempo de Seguriadad
}

 // Lectura de Sensores 
  void Sensores (){ 
  Sfrent = analogRead(Sharpfrent); 
  delay(1); 
  SLadoder = analogRead(SharpladoDer); 
  delay(1); 
  SLadoizq = analogRead(SharpladoIzq); 
  delay(1); 
  Qder = analogRead(QtrDer); 
  delay(1); 
  Qizq = analogRead(QtrIzq); 
  delay(1); 
  } 
   
   void adelante(){ 
  digitalWrite(Mder1, LOW); 
  digitalWrite(Mder2, HIGH); 
  digitalWrite(Mizq1, LOW); 
  digitalWrite(Mizq2, HIGH);
  } 
 
  void atras(){ 
    digitalWrite(Mder1, HIGH); 
    digitalWrite(Mder2, LOW);
    digitalWrite(Mizq1, HIGH); 
    digitalWrite(Mizq2, LOW); 
    } 
   
    void parar(){
      digitalWrite(Mder1, LOW); 
      digitalWrite(Mder2, LOW); 
      digitalWrite(Mizq1, LOW); 
      digitalWrite(Mizq2, LOW); 
      } 
      
      void derechasuave(){ 
        digitalWrite(Mder1, LOW); 
        digitalWrite(Mder2, HIGH); 
        digitalWrite(Mizq1, LOW); 
        digitalWrite(Mizq2, LOW);
        } 
        
        void derechafuerte(){ 
          digitalWrite(Mder1, LOW); 
          digitalWrite(Mder2, HIGH); 
          digitalWrite(Mizq1, HIGH); 
          digitalWrite(Mizq2, LOW);
          } 
          
          void izquierdasuave(){ 
            digitalWrite(Mder1, LOW); 
            digitalWrite(Mder2, LOW); 
            digitalWrite(Mizq1, LOW); 
            digitalWrite(Mizq2, HIGH); 
            } 
            
            void izquierdafuerte(){ 
              digitalWrite(Mder1, HIGH); 
              digitalWrite(Mder2, LOW); 
              digitalWrite(Mizq1, LOW); 
              digitalWrite(Mizq2, HIGH); 
            }
void loop() { 
  Sensores ();
  // Estos valores de 300 pueden cambiar dependiendo de cada sensor, cuando es menor a 300 se refiere a que no detecta nada, y mayor a 300 es que el sensor esta detectando algo 
  // sin embargo eso lo debes comprobar tu mismo con tus sensores. 
 
  if((SLadoizq<=250)&&(Sfrent<=250)&&(SLadoder<=250)){
    adelante();
     } 
    // 0 0  0=> elegir entre ir adelante o dar vueltas
 
  if((SLadoizq<=250)&&(Sfrent<=250)&&(SLadoder>=250)){
    derechasuave();
    } 
    // 0 0  1 
  
  if((SLadoizq<=250)&&(Sfrent>=250)&&(SLadoder<=250)){
    adelante();
    } 
    // 0  1 0 
  
  if((SLadoizq>=250)&&(Sfrent<=250)&&(SLadoder<=250)){
    izquierdasuave();
    }
    // 1 0  0 
 
  //Para los sensores QTR los valores menores a 500 indican que detecto la liena blanca, por lo que si cualquiera de los 2 sensores detecta la linea blanca el robot debe regresar 
  // Tu decides si quieres que solo regrese o tambien quieres que gire a la derecha o izquierda 
  
  /*if(Qder<=500){
    izquierdafuerte();
    delay(100);
  } 
  
  if(Qizq<=500){
    derechafuerte();
    delay(100);
    }
  
  if((Qizq<=500)||(Qder<=500)){
    atras();
    delay(100);
    izquierdafuerte();
    delay(100);
    
  }*/
  //el tiempo del delay depende de que tan rapido sea tu robot 
  }
  
  
  
  
  

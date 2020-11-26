int IRdir = A1;
int IResq = A2;
int valorIRD = 0;
int valorIRE = 0;
void setup() {
  pinMode(IRdir,INPUT);
  pinMode(IResq,INPUT);

  Serial.begin(9600);
}

void loop() {
  valorIRD = analogRead(IRdir);
  valorIRE = analogRead(IResq);

  Serial.print(" direito: ");
  Serial.print(valorIRD);
  Serial.println(" ");
  Serial.print(" esquerdo: ");
  Serial.print(valorIRE);
  Serial.println(" ");
  
  

}

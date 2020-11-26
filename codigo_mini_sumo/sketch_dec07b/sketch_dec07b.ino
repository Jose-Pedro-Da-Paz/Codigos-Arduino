int linha = A0;
int leitura = 0;

void setup() {
  pinMode(linha, INPUT);
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  leitura = analogRead(linha);


  
  
  
  
  Serial.println(leitura);
  delay(50);

}


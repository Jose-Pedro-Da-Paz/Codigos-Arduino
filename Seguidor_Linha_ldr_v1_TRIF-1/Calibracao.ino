                
                // CALIBRAÇÃO DOS SENSORES //

int Calibra_valor;
int maior;
int menor;
float Soma_Calibra = 0;
static int Resul_Calibracao;
static int Calibra[20][20];

void Calibracao() {

  for (int i = 0; i < 10; i++) {
    for (int j = 0; j < 10; j++) {
      int Sensor_1 = analogRead(SEN1);  int Sensor_2 = analogRead(SEN2);
      int Sensor_3 = analogRead(SEN3);  int Sensor_4 = analogRead(SEN4);
      int Sensor_5 = analogRead(SEN5);  int Sensor_6 = analogRead(SEN6);
      int Sensor_7 = analogRead(SEN7);  int Sensor_8 = analogRead(SEN8);
//
      /*Serial.println(" ");
      Serial.print(Sensor_1); Serial.print("  "); Serial.print(Sensor_2); Serial.print("  ");
      Serial.print(Sensor_3); Serial.print("  "); Serial.print(Sensor_4); Serial.print("  ");
      Serial.print(Sensor_5); Serial.print("  "); Serial.print(Sensor_6); Serial.print("  ");
      Serial.print(Sensor_7); Serial.print("  "); Serial.println(Sensor_8);*/

      int Sensores[] = {Sensor_1, Sensor_2, Sensor_3, Sensor_4, Sensor_5, Sensor_6, Sensor_7, Sensor_8};
      maior = 0;
      for (int k = 0; k < 8; k++) {
        if (Sensores[k] > maior) {
          maior = Sensores[k];
        }
      }
      menor = maior;
      for (int k = 0; k < 8; k++) {
        if (Sensores[k] < menor) {
          menor = Sensores [k];
        }
      }
      //Serial.print(menor); Serial.print(' '); Serial.println(maior);
      Calibra[i][j] = round((maior + menor) / 2); //Alterar calibração
      Soma_Calibra = Soma_Calibra + Calibra[i][j];
//      Serial.print(Calibra[i][j]);
//      Serial.print("  ");
      delay(25);
    }
//    Serial.println("  ");
  }
  //Serial.println(Soma_Calibra);
  Resul_Calibracao = round(Soma_Calibra / (10 * 10));
/*  Serial.println("\n\n\n");
  Serial.println(Resul_Calibracao);
  Serial.println("\n\n\n");*/
}

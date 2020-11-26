
// Código para leitura dos sensores e quantificação do erro.

// |1| |2| |3| |4| |5| |6| |7| |8| --> Posição dos sensores

// 1--> Preto (Pista de cor preta).
// 0--> Branco (Linha de cor branca).
// 0 1 1 1 1 1 1 1 --> Error = -7
// 0 0 1 1 1 1 1 1 --> Error = -6
// 1 0 1 1 1 1 1 1 --> Error = -5
// 1 0 0 1 1 1 1 1 --> Error = -4
// 1 1 0 1 1 1 1 1 --> Error = -3
// 1 1 0 0 1 1 1 1 --> Error = -2
// 1 1 1 0 1 1 1 1 --> Error = -1
// 1 1 1 0 0 1 1 1 --> Error = 0
// 1 1 1 1 0 1 1 1 --> Error = 1
// 1 1 1 1 0 0 1 1 --> Error = 2
// 1 1 1 1 1 0 1 1 --> Error = 3
// 1 1 1 1 1 0 0 1 --> Error = 4
// 1 1 1 1 1 1 0 1 --> Error = 5
// 1 1 1 1 1 1 0 0 --> Error = 6
// 1 1 1 1 1 1 1 0 --> Error = 7

static int count;

//---------------------------------------------------------

void Read_sensores() {
  int Sensor_1 = analogRead(SEN1);  int Sensor_2 = analogRead(SEN2);
  int Sensor_3 = analogRead(SEN3);  int Sensor_4 = analogRead(SEN4);
  int Sensor_5 = analogRead(SEN5);  int Sensor_6 = analogRead(SEN6);
  int Sensor_7 = analogRead(SEN7);  int Sensor_8 = analogRead(SEN8);
  //
  /*  Serial.println(" ");
    Serial.print(Sensor_1); Serial.print("  "); Serial.print(Sensor_2); Serial.print("  ");
    Serial.print(Sensor_3); Serial.print("  "); Serial.print(Sensor_4); Serial.print("  ");
    Serial.print(Sensor_5); Serial.print("  "); Serial.print(Sensor_6); Serial.print("  ");
    Serial.print(Sensor_7); Serial.print("  "); Serial.println(Sensor_8);*/
//
  int Sensores[] = {Sensor_1, Sensor_2, Sensor_3, Sensor_4, Sensor_5, Sensor_6, Sensor_7, Sensor_8};

  for (int i = 0; i < 8; i++) {
    if (Sensores[i] >= Resul_Calibracao) {
      Sensores[i] = 1;
    }
    else {
      Sensores[i] = 0;
    }

    //Serial.print(Sensores[i]); Serial.print("  ");
  }

  for (int i = 0; i < 15; i++) {
    for (int j = 0; j < 8; j++) {
      if (Sensores[j] == Tabela[i][j]) {
   
        count++;
      }
    }
    if (count == 8) {
      Error = -7 + i;
      Error_Ant = Error;
    }
    else {
      Error = Error_Ant;
    }
    count = 0;
  }
  /*Serial.println(Error);
  delay(100);*/
}


// Código para geração da tabela Error.

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
// ######################################################

void Tabela_Error() {

  for (int i = 0; i < 15; i++) {
    for (int j = 0; j < 8; j++) {
      Tabela[i][j] = 1;
    }
  }

  for (int k = 2; k < 15; k = k + 2) {
    Tabela[0][0] = 0;
    Tabela[1][0] = 0;
    Tabela[k - 1][k / 2] = 0;
    Tabela[k][k / 2] = 0;
    Tabela[k + 1][k / 2] = 0;
  }
/*
  for (int i = 0; i < 15; i++) {
    for (int j = 0; j < 8; j++) {
      Serial.print(Tabela[i][j]);
      Serial.print("  ");
    }
    Serial.print("Error "); Serial.println(-7 + i);
  }*/
}

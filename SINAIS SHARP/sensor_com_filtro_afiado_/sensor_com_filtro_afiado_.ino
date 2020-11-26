void  setup ( )  {
  // // Comunicação séria para 9600 baud
  Serial . begin( 9600 ) ;
}


void  loop ( )  {
  // Nós lemos a média da entrada analógica 0
  int  ADC_SHARP = ADC0_media (20);

  Serial . println ( ADC_SHARP ) ;
  delay ( 10 ) ;
}

int  ADC0_media ( int  n )
{
  int soma = 0 ; 
  for ( int i = 0 ; i < n ; i ++ ) {
    soma = soma + analogRead ( A0 ) ;
  } 
  return ( soma / n ) ;
}


int potencia(int base, int expoente) {
  int resultado = 1;
  for(int i = 0; i < expoente; i++) {
    resultado *= base;
  }

  return resultado;

}
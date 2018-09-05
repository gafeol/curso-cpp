void soma(int* numero, int x, int y) {
  *numero = x + y;
}

int soma(int* numeros, int tam) {
  int total = 0;

  for(int i = 0; i < tam; i++) {
    total += numeros[i];
  }

  return total;
}
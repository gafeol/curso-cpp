#include <cstdio>

int main() {
  int operacao, x, y;
  scanf("%d", &operacao);
  scanf("%d", &x);
  scanf("%d", &y);

  if(operacao == 1) { 
    printf("%d", x + y);
  }
  else if(operacao == 2) { 
    printf("%d", x - y);
  }
  else if(operacao == 3) { 
    printf("%d", x / y);
  }
  else if(operacao == 4) { 
    printf("%d", x * y);
  }
}

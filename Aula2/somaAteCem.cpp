#include <iostream> 
using namespace std;

int main() {
  int soma = 0;
  for(int i = 1; i <= 100; i++) {
    soma = soma + i;
  }

  cout << "A soma eh " << soma;
}

#include <iostream>
using namespace std;

int main() {
  int x;
  int y;

  cout << "Primeiro valor: ";
  cin >> x;

  cout << "Segundo valor: ";
  cin >> y;

  int resultado = x * y;
  cout << "A multiplicacao de " << x << " por " << y << " eh igual a " <<  resultado;
}

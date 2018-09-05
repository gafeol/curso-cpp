#include <iostream> 
using namespace std;

int main() {
  int numero;
  cout << "Qual tabuada você quer? ";
  cin >> numero;

  for(int i = 0; i <= 10; i++) {
    int multiplicacao = numero * i;
    cout << numero << " x " << i << " = " << multiplicacao << endl;
  }
}

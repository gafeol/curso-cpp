#include <iostream> 
using namespace std;

void abertura(int numero){
	cout << "Tabuada do " << numero << endl << endl;
}

int main() {
	int multiplicador = 2;

	abertura(multiplicador);

	for(int i = 1; i<= 10; i++){
		cout << multiplicador << " x " << i << " = " << multiplicador*i << endl;
	}
}
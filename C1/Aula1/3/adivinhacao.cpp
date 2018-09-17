#include <iostream>
using namespace std;

int main(){
	// imprime o cabecalho do nosso jogo
	cout << "******************************************" << endl;
	cout << "* Bem vindo ao nosso jogo de adivinhacao *" << endl;	
	cout << "******************************************" << endl;

	int numero_secreto = 42;

	int chute;

	cout << "Qual e o seu chute? ";
	cin >> chute;
	cout << "Seu chute foi " << chute << endl;
}


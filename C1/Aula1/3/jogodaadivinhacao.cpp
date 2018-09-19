#include <iostream>
using namespace std;

int main(){
	// imprime o cabecalho do nosso jogo
	cout << "******************************************" << endl;
	cout << "* Bem vindo ao nosso jogo de adivinhação *" << endl;	
	cout << "******************************************" << endl;

	int numero_secreto = 42;

	int chute;

	cout << "Qual é o seu chute? ";
	cin >> chute;
	cout << "Seu chute foi " << chute << endl;
}


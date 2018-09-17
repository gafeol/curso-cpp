#include <iostream> 
using namespace std;

int main(){
	// imprime o cabecalho do nosso jogo
	cout << "******************************************" << endl;
	cout << "* Bem vindo ao nosso jogo de adivinhacao *" << endl;	
	cout << "******************************************" << endl;

	const int NUMERO_SECRETO = 42;

	int chute;
	cout << "Qual e o seu chute? ";
	cin >> chute;
	cout << "Seu chute foi " << chute << endl;

	bool acertou = chute == NUMERO_SECRETO;
	bool maior  = chute > NUMERO_SECRETO;

	if(acertou){
		cout << "Parabens! Voce acertou!" << endl;
		cout << "Jogue de novo, voce e um bom jogador!!" << endl;
	}
	else if(maior) {
		cout << "Seu chute foi maior que o numero secreto" << endl;
	}
	else {
		cout << "Seu chute foi menor que o numero secreto" << endl;
	}
}

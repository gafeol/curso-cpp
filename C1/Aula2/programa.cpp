#include <iostream> 
using namespace std;

const int NUMERO_DE_TENTATIVAS = 5;

int main(){
	// imprime o cabecalho do nosso jogo
	cout << "******************************************" << endl;
	cout << "* Bem vindo ao nosso jogo de adivinhacao *" << endl;	
	cout << "******************************************" << endl;

	int numero_secreto = 42;

	int chute;
	int tentativas = 1;

	while(1) {
		cout << "Tentativa " << tentativas << endl;
		cout << "Qual e o seu chute?";

		cin >> chute;
		cout << "Seu chute foi " << chute << endl;

		if(chute < 0) {
			cout << "Voce nao pode chutar numeros negativos" << endl;
			continue;
		}

		bool acertou = chute == numero_secreto;
		bool maior = chute > numero_secreto;

		if(acertou) {
			cout << "Parabens! Voce acertou!" << endl;
			cout << "Jogue de novo, voce e um bom jogador!!" << endl;
			break;
		}
			
		else if(maior) {
			cout << "Seu chute foi maior que o numero secreto" << endl;
		}

		else {
			cout << "Seu chute foi menor que o numero secreto" << endl;
		}

		tentativas++;
	}

	cout << "Fim de jogo." << endl;
	cout << "Voce acertou em " << tentativas << " tentativas" << endl;
}

#include <iostream> 
using namespace std;

int main(){
	// imprime o cabecalho do nosso jogo
	cout << "******************************************" << endl;
	cout << "* Bem vindo ao nosso jogo de adivinhacao *" << endl;	
	cout << "******************************************" << endl;

	const int NUMERO_SECRETO = 42;

	bool nao_acertou = true;
	int tentativas = 0;

	double pontos = 1000.0;

	while(nao_acertou){
		tentativas++;

		int chute;
		cout << "Tentativa " << tentativas << endl;
		cout << "Qual e o seu chute? ";
		cin >> chute;
		cout << "Seu chute foi " << chute << endl;


		bool acertou = chute == NUMERO_SECRETO;
		bool maior = chute > NUMERO_SECRETO;

		if (acertou) {
			cout << "Parabens! Voce acertou!" << endl;
			cout << "Jogue de novo, voce e um bom jogador!!" << endl;
			
			nao_acertou  = false;
		}
		else if (maior) {
			cout << "Seu chute foi maior que o numero secreto" << endl;
		}
		else {
			cout << "Seu chute foi menor que o numero secreto" << endl;
		}

		double pontos_perdidos = abs(chute - NUMERO_SECRETO)/2.0;
		pontos = pontos - pontos_perdidos;
	}

    cout << "Fim de jogo!" << endl;
	cout << "Voce acertou em " << tentativas << " tentativas" << endl;
	cout << "Pontuacao: " << pontos << endl;
	
}

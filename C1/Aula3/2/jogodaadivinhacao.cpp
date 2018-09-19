#include <iostream> 
using namespace std;

int main(){
	// imprime o cabecalho do nosso jogo
	cout << "******************************************" << endl;
	cout << "* Bem vindo ao nosso jogo de adivinhação *" << endl;	
	cout << "******************************************" << endl;

	int numero_de_tentativas;
	cout << "Escolha o nivel de dificuldade:" << endl;
	cout << "(F) Facil (M) Medio (D) Dificil" << endl << endl;

	cout << "Escolha: ";
	char dificuldade;
	cin >> dificuldade;

	if(dificuldade == 'F'){
		numero_de_tentativas = 20;
	}
	else if (dificuldade == 'M'){
		numero_de_tentativas = 15;
	}
	else {
		numero_de_tentativas = 6;
	}


	const int NUMERO_SECRETO = 42;

	bool nao_acertou = true;

	double pontos = 1000.0;

	int tentativas;
	for(tentativas = 1; tentativas <= numero_de_tentativas; tentativas++){
		int chute;
		cout << "Tentativa " << tentativas << endl;
		cout << "Qual é o seu chute? ";
		cin >> chute;
		cout << "Seu chute foi " << chute << endl;


		bool acertou = chute == NUMERO_SECRETO;
		bool maior = chute > NUMERO_SECRETO;

		if (acertou) {
			cout << "Parabens! Você acertou!" << endl;
			cout << "Jogue de novo, voce e um bom jogador!!" << endl;
			nao_acertou  = false;
			break;
		}
		else if (maior) {
			cout << "Seu chute foi maior que o número secreto" << endl;
		}
		else {
			cout << "Seu chute foi menor que o número secreto" << endl;
		}

		double pontos_perdidos = abs(chute - NUMERO_SECRETO)/2.0;
		pontos = pontos - pontos_perdidos;
	}

	cout << "Fim de jogo!" << endl;

	if(nao_acertou){
		cout << "Você perdeu! Tente de novo!" << endl;
	}
	else {
		cout << "Você acertou em " << tentativas << " tentativas" << endl;
		cout.precision(2);
		cout << fixed;
		cout << "Pontuação: " << pontos << endl;
	}
}

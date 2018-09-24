#include <iostream> 
using namespace std;

int main(){
    cout << "          P  /_\\  P                              " << endl;
    cout << "         /_\\_|_|_/_\\                            " << endl;
    cout << "     n_n | ||. .|| | n_n         Bem vindo ao     " << endl;
    cout << "     |_|_|nnnn nnnn|_|_|     Jogo de Adivinhação! " << endl;
    cout << "    |\" \"  |  |_|  |  \" \"|                     " << endl;
    cout << "    |_____| ' _ ' |_____|                         " << endl; 
    cout << "          \\__|_|__/                              " << endl;


	int numero_de_tentativas;
	cout << "Escolha o nível de dificuldade:" << endl;
	cout << "(F) Fácil (M) Médio (D) Dificil" << endl << endl;

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

	srand(time(0));
	const int NUMERO_SECRETO = rand()%100;

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
			cout << "Parabéns! Você acertou!" << endl;
			cout << "Jogue de novo, você é um bom jogador!!" << endl;
			nao_acertou  = false;
			
			break;
		}
		else if (maior)
		{
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

		cout << endl << endl;
		cout << " \\|/ ____ \\|/ " << endl;
		cout << "  @~/ ,. \\~@   " << endl;
		cout << " /_( \\__/ )_\\ " << endl;
		cout << "    \\__U_/     " << endl;
		cout << endl << endl;
	}
	else {
		cout << "Você acertou em " << tentativas << " tentativas" << endl;
		cout.precision(2);
		cout << fixed;
		cout << "Pontuação: " << pontos << endl;

		cout << endl << endl;
		cout << "              OOOOOOOOOOO               " << endl;
		cout << "          OOOOOOOOOOOOOOOOOOO           " << endl;
		cout << "       OOOOOO  OOOOOOOOO  OOOOOO        " << endl;
		cout << "     OOOOOO      OOOOO      OOOOOO      " << endl;
		cout << "   OOOOOOOO  #   OOOOO  #   OOOOOOOO    " << endl;
		cout << "  OOOOOOOOOO    OOOOOOO    OOOOOOOOOO   " << endl;
		cout << " OOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOO  " << endl;
		cout << " OOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOO  " << endl;
		cout << " OOOO  OOOOOOOOOOOOOOOOOOOOOOOOO  OOOO  " << endl;
		cout << "  OOOO  OOOOOOOOOOOOOOOOOOOOOOO  OOOO   " << endl;
		cout << "   OOOO   OOOOOOOOOOOOOOOOOOOO  OOOO    " << endl;
		cout << "    OOOOO   OOOOOOOOOOOOOOO   OOOO      " << endl;
		cout << "      OOOOOO   OOOOOOOOO   OOOOOO       " << endl;
		cout << "         OOOOOO         OOOOOO          " << endl;
		cout << "             OOOOOOOOOOOO               " << endl;
		cout << endl << endl;
	}
}

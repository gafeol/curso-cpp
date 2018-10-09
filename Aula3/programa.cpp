#include <iostream> 
#include <iomanip>
#include <ctime>
using namespace std;

const int NUMERO_DE_TENTATIVAS = 3;

int main() {
    cout << "************************************" << endl;
    cout << "* Bem vindo ao Jogo de Adivinhação *" << endl;
    cout << "************************************" << endl;

    bool nao_acertou = true;
    int tentativas = 1;
    double pontos = 1000.0;

    srand(time(0));
    int numero_secreto = rand() % 100;

    while(nao_acertou) {

		int chute;
        cout << "Qual é o seu " << tentativas << "o. chute? ";
        cin >> chute;

        if(chute < 0) {
            cout << "Você não pode chutar números negativos" << endl;
            continue;
        }

        cout << "Seu " << tentativas << "o. chute foi " << chute << endl;

        bool acertou = chute == numero_secreto;
        bool maior = chute > numero_secreto;

        if(acertou) {
			nao_acertou = 0;
            cout << "Parabéns! Você acertou!" << endl;
        } else if(maior) {
            cout << "Seu chute foi maior do que o número secreto!" << endl;
        } else {
            cout << "Seu chute foi menor do que o número secreto!" << endl;
        }

        tentativas++;

        double pontos_perdidos = abs(chute - numero_secreto) / 2.0;
        pontos = pontos - pontos_perdidos;
    }


    cout.precision(2);  
    cout << fixed;
    // Equivalente ao %.2f

    cout << "Você fez " << pontos << " pontos" << endl;
    cout << "Obrigado por jogar!" << endl;
}

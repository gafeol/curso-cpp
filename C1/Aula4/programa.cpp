#include <cstdio>
#include <cstdlib>
#include <ctime>

const int NUMERO_DE_TENTATIVAS 3

int main() {
    printf("************************************\n");
    printf("* Bem vindo ao Jogo de Adivinhação *\n");
    printf("************************************\n");

    bool nao_acertou = true;
    int tentativas = 1;
    double pontos = 1000.0;

    srand(time(0));
    int numero_secreto = rand() % 100;

    while(nao_acertou) {

		int chute;
        printf("Qual é o seu %do. chute? ", tentativas);
        scanf("%d", &chute);

        if(chute < 0) {
            printf("Você não pode chutar números negativos\n");
            continue;
        }

        printf("Seu %do. chute foi %d\n", tentativas, chute);

        bool acertou = chute == numero_secreto;
        bool maior = chute > numero_secreto;

        if(acertou) {
			nao_acertou = false;
            printf("Parabéns! Você acertou!\n");
        } else if(maior) {
            printf("Seu chute foi maior do que o número secreto!\n");
        } else {
            printf("Seu chute foi menor do que o número secreto!\n");
        }

        tentativas++;

        double pontos_perdidos = abs(chute - numero_secreto) / 2.0;
        pontos = pontos - pontos_perdidos;
    }

    printf("Você fez %.2f pontos\n", pontos);
    printf("Obrigado por jogar!\n");
}

#include <cstdio>
#include <string>
using namespace std;

int main() {

    string palavra_secreta;
    palavra_secreta = "MELANCIA";
    int tamanho_palavra = palavra_secreta.size();

    bool nao_acertou = true;
    bool nao_enforcou = true;

    char chutes[26];
    int tentativas = 0;

    do {

        for(int i = 0; i < tamanho_palavra; i++) {
            bool achou = false;

            for(int j = 0; j < tentativas; j++) {
                if(chutes[j] == palavra_secreta[i]) {
                    achou = true;
                    break;
                }
            }

            if(achou) {
                printf("%c ", palavra_secreta[i]);
            } else {
                printf("_ ");
            }
        }
        printf("\n");

        char chute;
        printf("Qual letra? ");
        scanf(" %c", &chute);

        chutes[tentativas] = chute;
        tentativas++;


    } while (nao_acertou && nao_enforcou);

}
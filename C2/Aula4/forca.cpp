#include <cstdio>
#include <string>
using namespace std;

string palavra_secreta;
char chutes[26];
int tentativas = 0;

void abertura() {
    printf("/****************/\n");
    printf("/ Jogo de Forca */\n");
    printf("/****************/\n\n");
}

void chuta() {
    char chute;
    printf("Qual letra? ");
    scanf(" %c", &chute);

    chutes[tentativas] = chute;
}

int ja_chutou(char letra) {
    bool achou = false;
    for(int j = 0; j < tentativas; j++) {
        if(chutes[j] == letra) {
            achou = true;
            break;
        }
    }
    return achou;
}

void desenha_forca() {

    printf("Você já deu %d chutes\n", tentativas);

    int tamanho_palavra = palavra_secreta.size(); 

    for(int i = 0; i < tamanho_palavra; i++) {
        if(ja_chutou(palavra_secreta[i])) {
            printf("%c ", palavra_secreta[i]);
        } else {
            printf("_ ");
        }

    }
    printf("\n");

}

void escolhe_palavra() {
    palavra_secreta = "MELANCIA";
}

int main() {

    bool nao_acertou = true;
    bool nao_enforcou = true;

    abertura();
    escolhe_palavra();

    do {

        desenha_forca();
        chuta();

        tentativas++;

    } while (nao_acertou && nao_enforcou);

}
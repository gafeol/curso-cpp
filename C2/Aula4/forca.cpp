#include <iostream>
#include <string>
using namespace std;

const string palavra_secreta = "MELANCIA";
char chutes[26];
int tentativas = 0;

void abertura() {
    cout << "/****************/" << endl;
    cout << "/ Jogo de Forca */" << endl;
    cout << "/****************/" << endl << endl;
}

void chuta() {
    char chute;
    cout << "Qual letra? ";
    cin >> chute;

    chutes[tentativas] = chute;
    tentativas++;
}

bool ja_chutou(char letra) {
    for(int j = 0; j < tentativas; j++) {
        if(chutes[j] == letra) {
            return true;
        }
    }
    return false;
}

void desenha_forca() {

    cout << "Você já deu " << tentativas << " chutes" << endl;

    int tamanho_palavra = palavra_secreta.size(); 

    for(int i = 0; i < tamanho_palavra; i++) {
        if(ja_chutou(palavra_secreta[i])) {
            cout << palavra_secreta[i] << " ";
        } else {
            cout << "_ ";
        }

    }
    cout << endl;
}

bool jogo_continua(bool nao_acertou, bool nao_enforcou){
    return (nao_acertou && nao_enforcou);
}

int main() {

    bool nao_acertou = true;
    bool nao_enforcou = true;

    abertura();

    do {

        desenha_forca();
        chuta();

    } while (jogo_continua(nao_acertou, nao_enforcou));

}
#include <iostream>
#include <string>
#include <vector>
using namespace std;

const string PALAVRA_SECRETA = "MELANCIA";
vector<char> chutes;

void abertura() {
    cout << "/****************/" << endl;
    cout << "/ Jogo de Forca */" << endl;
    cout << "/****************/" << endl << endl;
}

void chuta() {
    char chute;
    cout << "Qual letra? ";
    cin >> chute;

    chutes.push_back(chute);
}

bool ja_chutou(char letra) {
    for(int j = 0; j < chutes.size(); j++) {
        if(chutes[j] == letra) {
            return true;
        }
    }
    return false;
}

void desenha_forca() {

    cout << "Você já deu " << chutes.size() << " chutes" << endl;

    for(int i = 0; i < PALAVRA_SECRETA.size(); i++) {
        if(ja_chutou(PALAVRA_SECRETA[i])) {
            cout << PALAVRA_SECRETA[i] << " ";
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
#include <iostream> 
#include <string>
using namespace std;

int main() {

    const string PALAVRA_SECRETA = "MELANCIA";

    bool nao_acertou = true;
    bool nao_enforcou = true;

    char chutes[26];
    int tentativas = 0;

    do {

        for(int i = 0; i < PALAVRA_SECRETA.size(); i++) {
            bool achou = false;

            for(int j = 0; j < tentativas; j++) {
                if(chutes[j] == PALAVRA_SECRETA[i]) {
                    achou = true;
                    break;
                }
            }

            if(achou) {
                cout << PALAVRA_SECRETA[i] << " ";
            } else {
                cout << "_ ";
            }
        }
        cout << endl;

        char chute;
        cout << "Qual letra? ";
        cin >> chute;

        chutes[tentativas] = chute;
        tentativas++;


    } while (nao_acertou && nao_enforcou);

}
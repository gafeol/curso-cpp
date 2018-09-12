#include <iostream> 
#include <string>
#include <vector>
using namespace std;

int main() {

    const string PALAVRA_SECRETA = "MELANCIA";

    bool nao_acertou = true;
    bool nao_enforcou = true;

    vector<char> chutes;

    do {

        for(int i = 0; i < PALAVRA_SECRETA.size(); i++) {
            bool achou = false;

            for(int j = 0; j < chutes.size(); j++) {
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

        chutes.push_back(chute);


    } while (nao_acertou && nao_enforcou);

}
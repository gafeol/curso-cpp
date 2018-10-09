#include <iostream> 
#include <string>
using namespace std;

const string PALAVRA_SECRETA = "MELANCIA";

bool letra_existe(char chute){
    for(int i=0;i < PALAVRA_SECRETA.size();i++){
        if (chute == PALAVRA_SECRETA[i]){
            return true;
        }
    }
    return false;
}

int main() {
    cout << PALAVRA_SECRETA << endl;

    bool nao_ganhou, nao_enforcou;

    do{
        for(int i=0;i<PALAVRA_SECRETA.size();i++){
            if(ja_chutou(PALAVRA_SECRETA[i])){
                cout << PALAVRA_SECRETA[i] << " ";
            }
            else{
                cout << "_ ";
            }
            cout << endl;
        }

        char chute;
        cin >> chute;

        if(letra_existe(chute)){
            cout << "Você acertou! A letra " << chute << " aparece na palavra." << endl;
        }
        else{
            cout << "Você errou! A letra " << chute << " não aparece na palavra." << endl;
        }
    } while(nao_ganhou && nao_enforcou);
}
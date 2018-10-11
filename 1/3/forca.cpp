#include <iostream> 
#include <string>
using namespace std;

const string PALAVRA_SECRETA = "MELANCIA";

bool letra_existe(char chute){
    for(char letra : PALAVRA_SECRETA){
        if (chute == letra){
            return true;
        }
    }
    return false;
}

int main() {
    cout << PALAVRA_SECRETA << endl;

    bool nao_ganhou = true;
    bool nao_enforcou = true;

    while(nao_ganhou && nao_enforcou){
        char chute;
        cout << "Qual letra? ";
        cin >> chute;

        if(letra_existe(chute)){
            cout << "Você acertou! A letra " << chute << " aparece na palavra." << endl;
        }
        else{
            cout << "Você errou! A letra " << chute << " não aparece na palavra." << endl;
        }
    }
}
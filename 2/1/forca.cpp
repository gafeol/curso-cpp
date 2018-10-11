#include <iostream> 
#include <string>
#include <map>
using namespace std;

const string PALAVRA_SECRETA = "MELANCIA";
map<char, bool> chutou;

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
        for(char letra : PALAVRA_SECRETA){
            if(chutou[letra]){
                cout << letra << " ";
            }
            else{
                cout << "_ ";
            }
        }
        cout << endl;

        char chute;
        cout << "Qual letra? ";
        cin >> chute;

        chutou[chute] = true;

        if(letra_existe(chute)){
            cout << "Você acertou! A letra " << chute << " aparece na palavra." << endl;
        }
        else{
            cout << "Você errou! A letra " << chute << " não aparece na palavra." << endl;
        }
    } 
}
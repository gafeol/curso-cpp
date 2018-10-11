#include <iostream> 
#include <string>
#include <map>
#include <vector>
using namespace std;

const string PALAVRA_SECRETA = "MELANCIA";
map<char, bool> ja_chutou;
vector<char> chutes_errados;

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
        cout << "Chutes errados: ";
        for(char letra: chutes_errados){
            cout << letra << " ";
        }
        cout << endl;

        for(int i=0;i<PALAVRA_SECRETA.size();i++){
            if(ja_chutou[PALAVRA_SECRETA[i]]){
                cout << PALAVRA_SECRETA[i] << " ";
            }
            else{
                cout << "_ ";
            }
        }
        cout << endl;

        char chute;
        cout << "Qual letra? ";
        cin >> chute;

        ja_chutou[chute] = true;

        if(letra_existe(chute)){
            cout << "Você acertou! A letra " << chute << " aparece na palavra." << endl;
        }
        else{
            cout << "Você errou! A letra " << chute << " não aparece na palavra." << endl;
            chutes_errados.push_back(chute);
        }
    } 
}
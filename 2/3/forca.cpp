#include <iostream> 
#include <string>
#include <map>
#include <vector>
using namespace std;

const string PALAVRA_SECRETA = "MELANCIA";
map<char, bool> chutou;
vector<char> chutes_errados;

bool letra_existe(char chute){
    for(char letra : PALAVRA_SECRETA){
        if (chute == letra){
            return true;
        }
    }
    return false;
}

bool nao_ganhou(){
    for(char letra : PALAVRA_SECRETA){
        if(!chutou[letra]){
            return true;
        }
    }
    return false;
}


bool nao_enforcou(){
    return chutes_errados.size() < 5;
}

bool jogo_continua(){
    return nao_ganhou() && nao_enforcou();
}

int main() {
    cout << PALAVRA_SECRETA << endl;

    while(jogo_continua()){
        for(int i=0;i<PALAVRA_SECRETA.size();i++){
            if(chutou[PALAVRA_SECRETA[i]]){
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

        chutou[chute] = true;

        if(letra_existe(chute)){
            cout << "Você acertou! A letra " << chute << " aparece na palavra." << endl;
        }
        else{
            cout << "Você errou! A letra " << chute << " não aparece na palavra." << endl;
            chutes_errados.push_back(chute);
        }
    } 

    if(nao_ganhou()){
        cout << endl << "Você perdeu, tente novamente!" << endl;
    }
    else{
        cout << endl << "Parabéns! Você ganhou!" << endl;
    }
}
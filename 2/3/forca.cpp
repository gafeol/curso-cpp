#include <iostream> 
#include <string>
#include <map>
using namespace std;

const string PALAVRA_SECRETA = "MELANCIA";
map<char, bool> ja_chutou;
int erros;

bool letra_existe(char chute){
    for(char letra : PALAVRA_SECRETA){
        if (chute == letra){
            return true;
        }
    }
    return false;
}

bool nao_ganhou(){
    for(int a=0;a<PALAVRA_SECRETA.size();a++){
        if(!ja_chutou[PALAVRA_SECRETA[a]]){
            return true;
        }
    }
    return false;
}


bool nao_enforcou(){
    return erros < 5;
}

bool jogo_continua(){
    return nao_ganhou() && nao_enforcou();
}

int main() {
    cout << PALAVRA_SECRETA << endl;

    while(jogo_continua()){
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
            erros++;
        }
    } 

    if(nao_ganhou()){
        cout << endl << "Você perdeu, tente novamente!" << endl;
    }
    else{
        cout << endl << "Parabéns! Você ganhou!" << endl;
    }
}
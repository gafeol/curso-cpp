#include <iostream> 
#include <string>
#include <map>
#include <fstream>
using namespace std;

string palavra_secreta;
map<char, bool> chutou;
int erros;

bool letra_existe(char chute){
    for(int i=0;i < palavra_secreta.size();i++){
        if (chute == palavra_secreta[i]){
            return true;
        }
    }
    return false;
}

bool nao_ganhou(){
    for(int a=0;a<palavra_secreta.size();a++){
        if(!chutou[palavra_secreta[a]]){
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

void escolhe_palavra(){
    ifstream arquivo_input;
    arquivo_input.open("palavras.txt");

    if (arquivo_input.is_open()) {
        int quantidade_palavras;
        arquivo_input >> quantidade_palavras;

        srand(time(NULL));
        int linha_escolhida = rand() % quantidade_palavras;
        string palavra_lida;
        for (int i = 0; i <= linha_escolhida; i++)
        {
            arquivo_input >> palavra_lida;
        }
        palavra_secreta = palavra_lida;
        arquivo_input.close();
    }
    else{
        cout << "Não foi possível abrir o banco de palavras!" << endl;
        exit(0);
    }
}

int main() {
    escolhe_palavra();

    cout << palavra_secreta << endl;

    while(jogo_continua()){
        for(int i=0;i<palavra_secreta.size();i++){
            if(chutou[palavra_secreta[i]]){
                cout << palavra_secreta[i] << " ";
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
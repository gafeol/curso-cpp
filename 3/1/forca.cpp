#include <iostream> 
#include <map>
#include <vector>
#include <fstream>
#include <cstdlib>
#include <ctime>
using namespace std;

string palavra_secreta;
map<char, bool> chutou;
vector<char> chutes_errados;

bool letra_existe(char chute){
    for(char letra : palavra_secreta){
        if (chute == letra){
            return true;
        }
    }
    return false;
}

bool nao_ganhou(){
    for(char letra : palavra_secreta){
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

vector<string> le_arquivo(){
    ifstream arquivo;
    arquivo.open("palavras.txt");

    vector<string> palavras_no_arquivo;

    int quantidade_palavras;
    arquivo >> quantidade_palavras;

    string palavra_lida;
    for(int i=0;i < quantidade_palavras;i++){
        arquivo >> palavra_lida;

        palavras_no_arquivo.push_back(palavra_lida);
    }

    arquivo.close();

    return palavras_no_arquivo;
}

void sorteia_palavra(){
    vector<string> palavras = le_arquivo();

    srand(time(NULL));
    int indice_sorteado = rand() % palavras.size();

    palavra_secreta = palavras[indice_sorteado];
}

int main() {
    sorteia_palavra();

    while(jogo_continua()){
        cout << "Chutes errados: ";
        for(char letra: chutes_errados){
            cout << letra << " ";
        }
        cout << endl;

        for(char letra : palavra_secreta){
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
#include <iostream>
#include <string>
#include <ctime>
#include <fstream>
#include <vector>
#include "forca.hpp"
using namespace std;

string palavra_secreta;
vector<char> chutes;

void abertura() {
    cout << "/****************/" << endl;
    cout << "/ Jogo de Forca */" << endl;
    cout << "/****************/" << endl << endl;
}

void chuta() {
    char chute;
    cout << "Qual letra? ";
    cin >> chute;

    chutes.push_back(chute);
}

bool chutou(char letra) {
    for(int j = 0; j < chutes.size(); j++) {
        if(chutes[j] == letra) {
            return true;
        }
    }
    return false;
}

bool nao_chutou(char letra) {
    return !chutou(letra);
}

void desenha_forca() {

    cout << "Você já deu " << chutes.size() << " chutes" << endl;


    for(int i = 0; i < palavra_secreta.size(); i++) {
        if(chutou(palavra_secreta[i])) {
            cout << palavra_secreta[i] << " ";
        } else {
            cout << "_ ";
        }

    }
    cout << endl;
}

bool enforcou() {
    int erros = 0;

    for(int i = 0; i < chutes.size(); i++) {

        int nao_existe = 1;

        for(int j = 0; j < palavra_secreta.size(); j++) {
            if(chutes[i] == palavra_secreta[j]) {
                nao_existe = 0;
                break;
            }
        }

        if (nao_existe) {
            erros++;
        }
    }

    return erros >= 5;
}

bool nao_enforcou() {
    return !enforcou();
}

bool ganhou() {
    for(int i = 0; i < palavra_secreta.size(); i++) {
        if(nao_chutou(palavra_secreta[i])) {
            return false;
        }
    }

    return true;
}

bool nao_ganhou() {
    return !ganhou();
}

bool jogo_continua(){
    return nao_ganhou() && nao_enforcou();
}

void escolhe_palavra() {
    ifstream arquivo_input;
    arquivo_input.open(ARQUIVO_PALAVRAS);

    if (arquivo_input.is_open()) {

        int quantidade_palavras;
        arquivo_input >> quantidade_palavras;

        srand(time(0));
        int aleatorio = rand() % quantidade_palavras;

        for (int i = 0; i <= aleatorio; i++) {
            arquivo_input >> palavra_secreta;
        }
        arquivo_input.close();
    }
    else {
        cout << "Banco de dados de palavras não disponível" << endl << endl;
    }
}


void adiciona_palavra() {
    cout << "Você deseja adicionar uma nova palavra no jogo (S/N)? "; 
    char resposta;
    cin >> resposta;

    if(resposta == 'S') {
        cout << "Digite a nova palavra, em letras maiúsculas: ";
        string nova_palavra;
        cin >> nova_palavra;

        fstream arquivo;
        arquivo.open("palavras.txt", ios::in | ios::out);
        if(arquivo.is_open()){
            int numero_palavras = 0;
            arquivo >> numero_palavras;

            numero_palavras++;

            arquivo.seekp(0, ios_base::beg);
            arquivo << numero_palavras << endl;

            arquivo.seekp(0, ios_base::end);
            arquivo << nova_palavra << endl;

            arquivo.close();
        }
        else{
            cout << "Banco de dados de palavras não disponível" << endl << endl;
        }
    }
}

int main() {

    abertura();
    escolhe_palavra();

    do {
        desenha_forca();
        chuta();

    } while (jogo_continua());

    adiciona_palavra();
}
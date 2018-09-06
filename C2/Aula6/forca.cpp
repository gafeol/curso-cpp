#include <iostream>
#include <string>
#include <ctime>
#include <fstream>
#include "forca.hpp"
using namespace std;

string palavra_secreta;
char chutes[26];
int chutes_dados = 0;

void abertura() {
    cout << "/****************/" << endl;
    cout << "/ Jogo de Forca */" << endl;
    cout << "/****************/" << endl << endl;
}

void chuta() {
    char chute;
    cout << "Qual letra? ";
    cin >> chute;

    chutes[chutes_dados] = chute;
    chutes_dados++;
}

bool ja_chutou(char letra) {
    for(int j = 0; j < chutes_dados; j++) {
        if(chutes[j] == letra) {
            return true;
        }
    }
    return false;
}

void desenha_forca() {

    cout << "Você já deu " << chutes_dados << " chutes" << endl;

    int tamanho_palavra = palavra_secreta.size(); 

    for(int i = 0; i < tamanho_palavra; i++) {
        if(ja_chutou(palavra_secreta[i])) {
            cout << palavra_secreta[i] << " ";
        } else {
            cout << "_ ";
        }

    }
    cout << endl;
}

bool enforcou() {
    int erros = 0;

    for(int i = 0; i < chutes_dados; i++) {

        int existe = 0;

        int tamanho_palavra = palavra_secreta.size();
        for(int j = 0; j < tamanho_palavra; j++) {
            if(chutes[i] == palavra_secreta[j]) {
                existe = 1;
                break;
            }
        }

        if(!existe) erros++;
    }

    return erros >= 5;
}

bool ganhou() {
    int tamanho_palavra = palavra_secreta.size();
    for(int i = 0; i < tamanho_palavra; i++) {
        bool nao_chutou = !ja_chutou(palavra_secreta[i]);
        if(nao_chutou) {
            return false;
        }
    }

    return true;
}

bool jogo_continua(){
    bool nao_ganhou = !ganhou();
    bool nao_enforcou = !enforcou();
    return nao_ganhou && nao_enforcou;
}


void escolhe_palavra() {
    ifstream arquivo_input;
    arquivo_input.open("palavras.txt");

    if (arquivo_input.is_open()) {

        int quantidade_palavras;
        arquivo_input >> quantidade_palavras;

        srand(time(0));
        int randomico = rand() % quantidade_palavras;

        for (int i = 0; i <= randomico; i++) {
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
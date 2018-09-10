#include <iostream>
#include <string>
#include <ctime>
#include <fstream>
#include "forca.hpp"
using namespace std;

string palavra_secreta;
char chutes[26];
int chutes_dados = 0;

bool letra_existe(char letra) {
    for(int j = 0; j < palavra_secreta.size(); j++) {
        if(letra == palavra_secreta[j]) {
            return true;
        }
    }
    return false;
}

int chutes_errados() {
    int erros = 0;

    for(int i = 0; i < chutes_dados; i++) {

        if(!letra_existe(chutes[i])) {
            erros++;
        }
    }

    return erros;
}

bool enforcou() {
    return chutes_errados() >= 5;
}

bool nao_enforcou() {
    return !enforcou();
}

bool ganhou() {
    for(int i = 0; i < palavra_secreta.size(); i++) {
        if(!ja_chutou(palavra_secreta[i])) {
            return false;
        }
    }
    return true;
}

bool nao_ganhou(){
    return !ganhou();
}

void abertura() {
    cout << "/****************/" << endl;
    cout << "/ Jogo de Forca */" << endl;
    cout << "/****************/" << endl << endl;
}

void mensagem_acerto (char chute) {
    cout << endl << "Você acertou: a palavra tem a letra " << chute << endl << endl;
}

void mensagem_erro (char chute) {
    cout << endl << "Você errou: a palavra NÃO tem a letra " << chute << endl << endl;
}

void chuta() {
    char chute;
    cout << "Qual letra? ";
    cin >> chute;

    if(letra_existe(chute)) {
        mensagem_acerto(chute);
    } 
    else {
        mensagem_erro(chute);
    }

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

bool nao_chutou(char letra){
    return !ja_chutou(letra);
}

void desenha_forca() {

    int erros = chutes_errados();

    printf("  _______       \n");
    printf(" |/      |      \n");
    printf(" |      %c%c%c  \n", (erros>=1?'(':' '), (erros>=1?'_':' '), (erros>=1?')':' '));
    printf(" |      %c%c%c  \n", (erros>=3?'\\':' '), (erros>=2?'|':' '), (erros>=3?'/': ' '));
    printf(" |       %c     \n", (erros>=2?'|':' '));
    printf(" |      %c %c   \n", (erros>=4?'/':' '), (erros>=4?'\\':' '));
    printf(" |              \n");
    printf("_|___           \n");
    printf("\n\n");

    for(int i = 0; i < palavra_secreta.size(); i++) {
        if(ja_chutou(palavra_secreta[i])) {
            cout << palavra_secreta[i] << " ";
        } else {
            cout << "_ ";
        }

    }
    cout << endl;

}


void escolhe_palavra() {
    ifstream arquivo_input;
    arquivo_input.open(BANCO_PALAVRAS);

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
    cout << endl << "Você deseja adicionar uma nova palavra no jogo (S/N)? "; 
    char resposta;
    cin >> resposta;

    if(resposta == 'S') {
        cout << "Digite a nova palavra, em letras maiúsculas: ";
        string nova_palavra;
        cin >> nova_palavra;

        fstream arquivo;
        arquivo.open(BANCO_PALAVRAS, ios::in | ios::out);
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

bool jogo_continua(){
    return nao_ganhou() && nao_enforcou();
}

int main() {

    abertura();
    escolhe_palavra();

    do {

        desenha_forca();
        chuta();

    } while (jogo_continua());

    if(ganhou()) {
        cout << endl << "Parabéns, você ganhou!" << endl << endl;

        cout << "       ___________      " << endl;
        cout << "      '._==_==_=_.'     " << endl;
        cout << "      .-\\:      /-.    " << endl;
        cout << "     | (|:.     |) |    " << endl;
        cout << "      '-|:.     |-'     " << endl;
        cout << "        \\::.    /      " << endl;
        cout << "         '::. .'        " << endl;
        cout << "           ) (          " << endl;
        cout << "         _.' '._        " << endl;
        cout << "        '-------'       " << endl << endl;

    } else {
        cout << endl << "Puxa, você foi enforcado!" << endl << endl;
        cout << "A palavra era **" << palavra_secreta << "**" << endl << endl;

        cout << "    _______________        " << endl;
        cout << "   /               \\      " << endl;
        cout << "  /                 \\     " << endl;
        cout << "//                   \\/\\ " << endl;
        cout << "\\|   XXXX     XXXX   | /  " << endl;
        cout << " |   XXXX     XXXX   |/    " << endl;
        cout << " |   XXX       XXX   |     " << endl;
        cout << " |                   |     " << endl;
        cout << " \\__      XXX      __/    " << endl;
        cout << "   |\\     XXX     /|      " << endl;
        cout << "   | |           | |       " << endl;
        cout << "   | I I I I I I I |       " << endl;
        cout << "   |  I I I I I I  |       " << endl;
        cout << "   \\_             _/      " << endl;
        cout << "     \\_         _/        " << endl;
        cout << "       \\_______/          " << endl;
    }

    adiciona_palavra();
}
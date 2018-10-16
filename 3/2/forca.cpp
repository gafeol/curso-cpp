#include <iostream> 
#include <map>
#include <fstream>
#include <vector>
#include <string> 
using namespace std;

string palavra_secreta;
map<char, bool> chutou;
vector<char> chutes_errados;
const string ARQUIVO_PALAVRAS = "palavras.txt";

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
    vector<string> palavras;

    ifstream arquivo;
    arquivo.open(ARQUIVO_PALAVRAS);

    if (arquivo.is_open()) {
        int quantidade_palavras;
        arquivo >> quantidade_palavras;

        string palavra_lida;
        for (int i = 0; i < quantidade_palavras; i++){
            arquivo >> palavra_lida;
            palavras.push_back(palavra_lida);
        }
        arquivo.close();

        return palavras;
    }
    else{
        cout << "Não foi possível abrir o banco de palavras!" << endl;
        exit(0);
    }
}

void sorteia_palavra(){
    vector<string> palavras = le_arquivo();

    srand(time(NULL));
    int linha_escolhida = rand() % palavras.size();

    palavra_secreta = palavras[linha_escolhida];
}


void salva_arquivo(vector<string> palavras){
    ofstream arquivo;
    arquivo.open(ARQUIVO_PALAVRAS);
    if(arquivo.is_open()){
        arquivo << palavras.size() << endl;

        for(string palavra : palavras){
            arquivo << palavra << endl;
        }

        arquivo.close();
    }
    else{
        cout << "Banco de dados de palavras não disponível" << endl << endl;
        exit(0);
    }
}

void adiciona_palavra(){
    cout << "Você deseja adicionar uma nova palavra ao banco (S/N)? ";
    char resposta;
    cin >> resposta;
    if(resposta == 'S'){
        cout << "Digite a nova palavra, em letras maiúsculas: ";
        string nova_palavra;
        cin >> nova_palavra;

        vector<string> palavras = le_arquivo();
        palavras.push_back(nova_palavra);
        salva_arquivo(palavras);
    }
}

void imprime_chutes_errados(){
    if (!chutes_errados.empty()){
        cout << "Chutes errados: ";
        for (char letra : chutes_errados){
            cout << letra << " ";
        }
        cout << endl;
    }
}

void imprime_palavra(){
    for(char letra : palavra_secreta){
        if(chutou[letra]){
            cout << letra << " ";
        }
        else{
            cout << "_ ";
        }
    }
    cout << endl;
}

void chuta(){
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

int main() {
    sorteia_palavra();

    while(jogo_continua()){
        imprime_chutes_errados();

        imprime_palavra();

        chuta();
    } 

    if(nao_ganhou()){
        cout << endl << "Você perdeu, tente novamente!" << endl;
    }
    else{
        cout << endl << "Parabéns! Você ganhou!" << endl;
        adiciona_palavra();
    }
}
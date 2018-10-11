#include <iostream> 
#include <map>
#include <fstream>
#include <vector>
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

void escolhe_palavra(){
    ifstream arquivo_input;
    arquivo_input.open(ARQUIVO_PALAVRAS);

    if (arquivo_input.is_open()) {
        int quantidade_palavras;
        arquivo_input >> quantidade_palavras;

        srand(time(NULL));
        int linha_escolhida = rand() % quantidade_palavras;
        string palavra_lida;
        for (int i = 0; i <= linha_escolhida; i++){
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

void adiciona_palavra(){
    cout << "Você deseja adicionar uma nova palavra ao banco (S/N)? ";
    char resposta;
    cin >> resposta;
    if(resposta == 'S'){
        cout << "Digite a nova palavra, em letras maiúsculas: ";
        string nova_palavra;
        cin >> nova_palavra;

        fstream arquivo;
        arquivo.open(ARQUIVO_PALAVRAS, ios::in | ios::out);
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
            exit(0);
        }
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
    escolhe_palavra();

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
#include <iostream>
#include <map>
using namespace std;

int main (){
    map<string, string> dicionario;

    dicionario["programacao"] = "acao ou resultado de programar";
    dicionario["programar"] = "elaborar programa de computador";
    dicionario["escola"] = "estabelecimento público ou privado destinado a ensino coletivo";

    cout << endl << "=== Dicionario ===" << endl;
    cout << "Definicao de programacao: " << dicionario["programacao"] << endl;
    cout << "Definicao de programar: " << dicionario["programar"] << endl;
    cout << "Definicao de escola: " << dicionario["escola"] << endl;


    map<string, double> precos;

    precos["bolacha"] = 3.50;
    precos["pao"] = 5.2;
    precos["tv"] = 1000;

    cout << endl << "=== Mercadinho Alura ===" << endl;
    cout << "Preco da bolacha no mercado alura: " << precos["bolacha"] << endl;
    cout << "Preco da pao no mercado alura: " << precos["pao"] << endl;
    cout << "Preco da tv no mercado alura: " << precos["tv"] << endl;
    cout << endl;


    map<char, int> numero_de_tentativas;

    cout << endl << "=== Numero de tentativas ===" << endl;
    numero_de_tentativas['F'] = 20;
    numero_de_tentativas['M'] = 15;
    numero_de_tentativas['D'] = 6;

    char nivel = 'F';
    cout << "Numero de tentativas no nivel " << nivel << ": " << numero_de_tentativas[nivel] << endl;
    nivel = 'M';
    cout << "Numero de tentativas no nivel " << nivel << ": " << numero_de_tentativas[nivel] << endl;
    nivel = 'D';
    cout << "Numero de tentativas no nivel " << nivel << ": " << numero_de_tentativas[nivel] << endl;
    cout << endl;
}
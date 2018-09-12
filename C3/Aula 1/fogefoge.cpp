#include <iostream>
#include <fstream>
#include "fogefoge.hpp"
using namespace std;

char** mapa;
int linhas;
int colunas;

void le_mapa() {
	ifstream mapa_input;

	mapa_input.open(ARQUIVO_MAPA);
	if(mapa_input.is_open()) {

		mapa_input >> linhas >> colunas;
		aloca_mapa();

		for (int i = 0; i < linhas; i++) {
			for(int j = 0; j < colunas; j++){
				mapa_input >> mapa[i][j];
			}
		}

		mapa_input.close();
	}
	else {
		cout << "Erro na leitura do mapa" << endl;
		exit(1);
	}
}

void aloca_mapa() {
	mapa = new char*[linhas];
	for(int i = 0; i < linhas; i++) {
		mapa[i] = new char[colunas];
	}
}

void libera_mapa() {
	for(int i = 0; i < linhas; i++) {
		delete(mapa[i]);
	}
	delete(mapa);
}

void imprime_mapa() {
	for(int i=0;i<linhas;i++){
		for(int j=0;j<colunas;j++){
			cout << mapa[i][j];
		}
		cout << endl;
	}
}

int main() {
	
	le_mapa();

	imprime_mapa();

	libera_mapa();
}
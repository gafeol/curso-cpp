#include <iostream>
#include <fstream>
#include "mapa.hpp"
using namespace std;

void le_mapa(Mapa* mapa) {
	ifstream mapa_input;

	mapa_input.open(ARQUIVO_MAPA);
	if(mapa_input.is_open()) {
		mapa_input >> mapa->linhas >> mapa->colunas;
		aloca_mapa(mapa);

		for (int i = 0; i < mapa->linhas; i++) {
			for(int j=0; j < mapa->colunas; j++){
				mapa_input >> mapa->matriz[i][j];
			}
		}

		mapa_input.close();
	}
	else {
		cout << "Erro na leitura do mapa" << endl;
		exit(1);
	}
}

void aloca_mapa(Mapa* mapa) {
	mapa->matriz = (char**) malloc(sizeof(char*) * mapa->linhas);
	for(int i = 0; i < mapa->linhas; i++) {
		mapa->matriz[i] = (char*) malloc(sizeof(char) * mapa->colunas);
	}
}

void libera_mapa(Mapa* mapa) {
	for(int i = 0; i < mapa->linhas; i++) {
		free(mapa->matriz[i]);
	}
	free(mapa->matriz);
}

void imprime_mapa(Mapa* mapa) {
	for(int i = 0; i < mapa->linhas; i++) {
		for(int j = 0; j < mapa->colunas; j++) {
			cout << mapa->matriz[i][j];
		}
		cout << endl;
	}
}

// depois vira funcao que retorna booleano dizendo se encontrou ou nao
void encontra_caractere(Mapa* mapa, Posicao* posicao, char caractere) {
	for(int i = 0; i < mapa->linhas; i++) {
		for(int j = 0; j < mapa->colunas; j++) {
			if(mapa->matriz[i][j] == caractere) {
				posicao->x = i;
				posicao->y = j;
				return;
			}
		}
	}
}
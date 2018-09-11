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
		mapa->matriz[i] = (char*) malloc(sizeof(char) * mapa->colunas + 1);
	}
}

void copia_mapa(Mapa* destino, Mapa* origem) {
	destino->linhas = origem->linhas;
	destino->colunas = origem->colunas;
	aloca_mapa(destino);

	for(int i = 0;i < origem->linhas; i++) {
		for(int j = 0;j < origem->colunas;j++) {
			destino->matriz[i][j] = origem->matriz[i][j];
		}
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

bool encontra_caractere(Mapa* mapa, Posicao* posicao, char caractere) {
	for(int i = 0; i < mapa->linhas; i++) {
		for(int j = 0; j < mapa->colunas; j++) {
			if(mapa->matriz[i][j] == caractere) {
				posicao->x = i;
				posicao->y = j;
				return true;
			}
		}
	}
	return false;
}

bool pode_andar(Mapa* mapa, char personagem, int x, int y) {
	return 
		eh_valida(mapa, x, y) && 
		!eh_parede(mapa, x, y) &&
		!eh_personagem(mapa, personagem, x, y);
}

bool eh_valida(Mapa* mapa, int x, int y) {
	if(x >= mapa->linhas) 
		return false;
	if(y >= mapa->colunas) 
		return false;

	return true;	
}

bool eh_personagem(Mapa* mapa, char personagem, int x, int y) {
	return
		mapa->matriz[x][y] == personagem;
}

bool eh_parede(Mapa* mapa, int x, int y) {
	return 
		mapa->matriz[x][y] == PAREDE_VERTICAL ||
		mapa->matriz[x][y] == PAREDE_HORIZONTAL;
}


void move_personagem(Mapa* mapa, int x_origem, int y_origem, 
	int x_destino, int y_destino) {

	char personagem = mapa->matriz[x_origem][y_origem];
	mapa->matriz[x_destino][y_destino] = personagem;
	mapa->matriz[x_origem][y_origem] = VAZIO;

}
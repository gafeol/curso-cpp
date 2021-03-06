#include <iostream>
#include <fstream>
using namespace std;
#include "mapa.hpp"

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
	mapa->matriz = new char*[mapa->linhas];
	for(int i = 0; i < mapa->linhas; i++) {
		mapa->matriz[i] = new char[mapa->colunas];
	}
}

void libera_mapa(Mapa* mapa) {
	for(int i = 0; i < mapa->linhas; i++) {
		delete(mapa->matriz[i]);
	}
	delete(mapa->matriz);
}

void copia_mapa(Mapa* destino, Mapa* origem) {
	destino->linhas = origem->linhas;
	destino->colunas = origem->colunas;
	aloca_mapa(destino);
	for(int i = 0; i < origem->linhas; i++) {
		for (int j = 0; j < origem->colunas; j++) {
			destino->matriz[i][j] = origem->matriz[i][j];
		}
	}
}

bool encontra_caractere(Mapa* mapa, Posicao* posicao, char caractere) {

	for(int i = 0; i < mapa->linhas; i++) {
		for(int j = 0; j < mapa->colunas; j++) {
			if(mapa->matriz[i][j] == caractere) {
				posicao->linha = i;
				posicao->coluna = j;
				return true;
			}
		}
	}

	return false;
}

bool pode_andar(Mapa* mapa, char personagem, int linha, int coluna) {
	return 
		eh_valida(mapa, linha, coluna) && 
		!eh_parede(mapa, linha, coluna) &&
		!eh_personagem(mapa, personagem, linha, coluna);
}

bool eh_valida(Mapa* mapa, int linha, int coluna) {
	if(linha >= mapa->linhas) 
		return false;
	if(coluna >= mapa->colunas) 
		return false;

	return true;	
}

bool eh_personagem(Mapa* mapa, char personagem, int linha, int coluna) {
	return mapa->matriz[linha][coluna] == personagem;
}

bool eh_parede(Mapa* mapa, int linha, int coluna) {
	return 
		mapa->matriz[linha][coluna] == PAREDE_VERTICAL ||
		mapa->matriz[linha][coluna] == PAREDE_HORIZONTAL;
}


void move_personagem(Mapa* mapa, int linha_origem, int coluna_origem, 
	int linha_destino, int coluna_destino) {

	char personagem = mapa->matriz[linha_origem][coluna_origem];
	mapa->matriz[linha_destino][coluna_destino] = personagem;
	mapa->matriz[linha_origem][coluna_origem] = VAZIO;

}
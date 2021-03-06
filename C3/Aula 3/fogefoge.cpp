#include <iostream>
using namespace std;

#include "fogefoge.hpp"
#include "mapa.hpp"
#include "jogo.hpp"

Mapa mapa;
Posicao heroi;

bool direcao_invalida(char direcao) {
	return
		direcao != ESQUERDA && 
		direcao != CIMA &&
		direcao != BAIXO &&
		direcao != DIREITA;
}

void move(char direcao) {

	if(direcao_invalida(direcao))	
		return;

	int linha_alvo = heroi.linha;
	int coluna_alvo = heroi.coluna;

	switch(direcao) {
		case ESQUERDA:
			coluna_alvo--;
			break;
		case CIMA:
			linha_alvo--;
			break;
		case BAIXO:
			linha_alvo++;
			break;
		case DIREITA:
			coluna_alvo++;
	}

	if (pode_andar(&mapa, HEROI, linha_alvo, coluna_alvo)) {
		move_personagem(&mapa, heroi.linha, heroi.coluna, linha_alvo, coluna_alvo);
		heroi.linha = linha_alvo;
		heroi.coluna = coluna_alvo;
	}
}

bool movimento_fantasma(int linha_atual, int coluna_atual, 
	int* linha_destino, int* coluna_destino) {

	int opcoes[4][2] = { 
		{ linha_atual   , coluna_atual+1 }, 
		{ linha_atual+1 , coluna_atual   },  
		{ linha_atual   , coluna_atual-1 }, 
		{ linha_atual-1 , coluna_atual   }
	};

	for(int i = 0; i < 10; i++) {
		int posicao = rand() % 4;

		if(pode_andar(&mapa, FANTASMA, opcoes[posicao][0], opcoes[posicao][1])) {
			*linha_destino = opcoes[posicao][0];
			*coluna_destino = opcoes[posicao][1];
			return true;
		}
	}

	return false;
}

void fantasmas() {
	Mapa copia;

	copia_mapa(&copia, &mapa);

	for(int i = 0; i < copia.linhas; i++) {
		for(int j = 0; j < copia.colunas; j++) {
			if(copia.matriz[i][j] == FANTASMA) {

				int linha_destino;
				int coluna_destino;


				// fazer funcao movimenta fantasma

				bool vai_andar = movimento_fantasma(i, j, &linha_destino, &coluna_destino);

				if(vai_andar) {
					move_personagem(&mapa, i, j, linha_destino, coluna_destino);
				}
			}
		}
	}

	libera_mapa(&copia);
}

int main() {
	inicializa_aleatorio();
	
	le_mapa(&mapa);
	encontra_caractere(&mapa, &heroi, HEROI);

	do {
		imprime_mapa(&mapa);

		char comando;
		cin >> comando;

		move(comando);
		fantasmas();

	} while (nao_acabou(&mapa));

	libera_mapa(&mapa);
}
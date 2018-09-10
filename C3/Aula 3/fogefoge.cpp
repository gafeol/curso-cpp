#include <iostream>
using namespace std;

#include "fogefoge.hpp"
#include "mapa.hpp"

Mapa mapa;
Posicao heroi;


bool perdeu(){
	Posicao posicao;
	return !encontra_caractere(&mapa, &posicao, HEROI);
}

bool ganhou() {
	Posicao posicao;
	return !encontra_caractere(&mapa, &posicao, FANTASMA);
}

bool acabou() {
	return ganhou() || perdeu();
}

bool nao_acabou() {
	return !acabou();
}

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

	int proximo_x = heroi.x;
	int proximo_y = heroi.y;

	switch(direcao) {
		case ESQUERDA:
			proximo_y--;
			break;
		case CIMA:
			proximo_x--;
			break;
		case BAIXO:
			proximo_x++;
			break;
		case DIREITA:
			proximo_y++;
			break;
	}

	if(!pode_andar(&mapa, HEROI, proximo_x, proximo_y))
		return;

	move_personagem(&mapa, heroi.x, heroi.y, proximo_x, proximo_y);
	heroi.x = proximo_x;
	heroi.y = proximo_y;
}

bool movimento_fantasma(int x_atual, int y_atual, 
	int* x_destino, int* y_destino) {

	int opcoes[4][2] = { 
		{ x_atual   , y_atual+1 }, 
		{ x_atual+1 , y_atual   },  
		{ x_atual   , y_atual-1 }, 
		{ x_atual-1 , y_atual   }
	};

	srand(time(0));
	for(int i = 0; i < 10; i++) {
		int posicao = rand() % 4;

		if(pode_andar(&mapa, FANTASMA, opcoes[posicao][0], opcoes[posicao][1])) {
			*x_destino = opcoes[posicao][0];
			*y_destino = opcoes[posicao][1];
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

				int x_destino;
				int y_destino;


				// fazer funcao movimenta fantasma

				bool vai_andar = movimento_fantasma(i, j, &x_destino, &y_destino);

				if(vai_andar) {
					move_personagem(&mapa, i, j, x_destino, y_destino);
				}
			}
		}
	}

	libera_mapa(&copia);
}

int main() {
	
	le_mapa(&mapa);
	encontra_caractere(&mapa, &heroi, HEROI);

	do {
		imprime_mapa(&mapa);

		char comando;
		cin >> comando;

		move(comando);
		fantasmas();

	} while (nao_acabou());

	libera_mapa(&mapa);
}
#include <iostream>
using namespace std;
#include "mapa.hpp"
#include "fogefoge.hpp"

Mapa mapa;
Posicao heroi;
bool tem_pilula = false;


bool movimento_fantasma(int x_atual, int y_atual, 
	int* x_destino, int* y_destino) {

	int opcoes[4][2] = {
		{ x_atual, y_atual+1},
		{ x_atual+1, y_atual},
		{ x_atual, y_atual-1},
		{ x_atual-1, y_atual}
	};

	for(int i = 0; i < 10; i++) {
		int direcao = rand() % 4;

		if(pode_andar(&mapa, FANTASMA, opcoes[direcao][0], opcoes[direcao][1])) {
			*x_destino = opcoes[direcao][0];
			*y_destino = opcoes[direcao][1];

			return true;
		}
	}
	return false;
}

void fantasmas() {
	Mapa copia;

	copia_mapa(&copia, &mapa);

	for(int i = 0; i < mapa.linhas; i++) {
		for(int j = 0; j < mapa.colunas;j++) {

			if(copia.matriz[i][j] == FANTASMA) {

				int x_destino;
				int y_destino;

				bool vai_andar = movimento_fantasma(i, j, 
					&x_destino, &y_destino);

				if(vai_andar) {
					move_personagem(&mapa, i, j, x_destino, y_destino);
				}
			}

		}
	}

	libera_mapa(&copia);
}

bool nao_acabou() {
	Posicao pos;
	return encontra_caractere(&mapa, &pos, HEROI);
}

bool direcao_invalida(char direcao) {
	return 
		direcao != ESQUERDA &&
		direcao != CIMA &&
		direcao != BAIXO &&
		direcao != DIREITA;
}

void move(char direcao) {

	if(direcao_invalida(direcao)){
		return;
	}

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

	if (pode_andar(&mapa, HEROI, proximo_x, proximo_y)) {
		if (eh_personagem(&mapa, PILULA, proximo_x, proximo_y)) {
			tem_pilula = true;
		}

		move_personagem(&mapa, heroi.x, heroi.y,
						proximo_x, proximo_y);
		heroi.x = proximo_x;
		heroi.y = proximo_y;
	}
}

void explode_pilula() {
	if(tem_pilula){
		explode_pilula_recursivo(heroi.x, heroi.y, 0, 1, 3);
		explode_pilula_recursivo(heroi.x, heroi.y, 0, -1, 3);
		explode_pilula_recursivo(heroi.x, heroi.y, 1, 0, 3);
		explode_pilula_recursivo(heroi.x, heroi.y, -1, 0, 3);

		tem_pilula = false;
	}
}

bool explode_posicao(Mapa* mapa, int x, int y){
	if(!eh_valida(mapa, x, y))
		return false;
	if(eh_parede(mapa, x, y))
		return false;
	return true;
}

void explode_pilula_recursivo(int x, int y, int soma_x, int soma_y, int qtd) {

	if (qtd > 0) {

		int novo_x = x + soma_x;
		int novo_y = y + soma_y;

		if (explode_posicao(&mapa, novo_x, novo_y)) {
			mapa.matriz[novo_x][novo_y] = VAZIO;
			explode_pilula_recursivo(novo_x, novo_y, soma_x, soma_y, qtd - 1);
		}
	}
}

void inicializa_aleatorio(){
	srand(time(0));
}

int main() {
	inicializa_aleatorio();
	
	le_mapa(&mapa);
	encontra_caractere(&mapa, &heroi, HEROI);

	do {

		cout << "Tem pilula: " << (tem_pilula ? "SIM" : "NAO") << endl;
		imprime_mapa(&mapa);

		char comando;
		cin >> comando;

		if(comando == BOMBA){
			explode_pilula();
		}
		else {
			move(comando);
		}

		fantasmas();

	} while(nao_acabou());

	libera_mapa(&mapa);
}
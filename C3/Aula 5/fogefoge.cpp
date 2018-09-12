#include <iostream>
using namespace std;

#include "fogefoge.hpp"
#include "mapa.hpp"
#include "ui.hpp"
#include "jogo.hpp"

Mapa mapa;
Posicao heroi;
bool tem_pilula = false;

bool eh_direcao(char direcao) {
	return
		direcao == ESQUERDA || 
		direcao == CIMA ||
		direcao == BAIXO ||
		direcao == DIREITA;
}

void move_heroi(char direcao) {

	int proxima_linha = heroi.linha;
	int proxima_coluna = heroi.coluna;

	switch(direcao) {
		case ESQUERDA:
			proxima_coluna--;
			break;
		case CIMA:
			proxima_linha--;
			break;
		case BAIXO:
			proxima_linha++;
			break;
		case DIREITA:
			proxima_coluna++;
	}

	if (pode_andar(&mapa, HEROI, proxima_linha, proxima_coluna)) {

		if (eh_personagem(&mapa, PILULA, proxima_linha, proxima_coluna)) {
			tem_pilula = true;
		}

		move_personagem(&mapa, heroi.linha, heroi.coluna, proxima_linha, proxima_coluna);
		heroi.linha = proxima_linha;
		heroi.coluna = proxima_coluna;
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
		int direcao = rand() % 4;

		if(pode_andar(&mapa, FANTASMA, opcoes[direcao][0], opcoes[direcao][1])) {
			*linha_destino = opcoes[direcao][0];
			*coluna_destino = opcoes[direcao][1];
			return true;
		}
	}

	return false;
}

void move_fantasmas() {
	Mapa copia;

	copia_mapa(&copia, &mapa);

	for(int i = 0; i < copia.linhas; i++) {
		for(int j = 0; j < copia.colunas; j++) {
			if(copia.matriz[i][j] == FANTASMA) {

				int linha_destino;
				int coluna_destino;

				bool vai_andar = movimento_fantasma(i, j, &linha_destino, &coluna_destino);

				if(vai_andar) {
					move_personagem(&mapa, i, j, linha_destino, coluna_destino);
				}
			}
		}
	}

	libera_mapa(&copia);
}

bool explode_posicao(Mapa* mapa, int linha, int coluna){
	if(!eh_valida(mapa, linha, coluna))
		return false;
	if(eh_parede(mapa, linha, coluna))
		return false;
	return true;
}

void explode_pilula_recursivo(int linha, int coluna, int soma_linha, int soma_coluna, int qtd) {

	if(qtd > 0) {
		int nova_linha = linha + soma_linha;
		int nova_coluna = coluna + soma_coluna;

		if (explode_posicao(&mapa, nova_linha, nova_coluna)) {
			mapa.matriz[nova_linha][nova_coluna] = VAZIO;
			explode_pilula_recursivo(nova_linha, nova_coluna, soma_linha, soma_coluna, qtd - 1);
		}
	}
}

void explode_pilula() {
	if(tem_pilula) {
		explode_pilula_recursivo(heroi.linha, heroi.coluna, 0, 1, 3);
		explode_pilula_recursivo(heroi.linha, heroi.coluna, 0, -1, 3);
		explode_pilula_recursivo(heroi.linha, heroi.coluna, 1, 0, 3);
		explode_pilula_recursivo(heroi.linha, heroi.coluna, -1, 0, 3);

		tem_pilula = false;
	}
}

int main() {
	inicializa_aleatorio();
	
	le_mapa(&mapa);
	encontra_caractere(&mapa, &heroi, HEROI);

	do {
		cout << "Pílula: " << (tem_pilula ? "SIM" : "NÃO") <<  endl;
		imprime_mapa(&mapa);

		char comando;
		cin >> comando;

		if(comando == BOMBA) {
			explode_pilula();
		}
		else if(eh_direcao(comando)) {
			move_heroi(comando);
		}

		move_fantasmas();

	} while (nao_acabou(&mapa));

	libera_mapa(&mapa);
}
#include <iostream>
#include "fogefoge.hpp"
#include "mapa.hpp"
using namespace std;

Mapa mapa;
Posicao heroi;

bool nao_acabou() {
	return true;
}

void move(char direcao) {

	mapa.matriz[heroi.linha][heroi.coluna] = '.';

	switch(direcao) {
		case 'a':
			mapa.matriz[heroi.linha][heroi.coluna-1] = '@';
			heroi.coluna--;
			break;
		case 'w':
			mapa.matriz[heroi.linha-1][heroi.coluna] = '@';
			heroi.linha--;
			break;
		case 's':
			mapa.matriz[heroi.linha+1][heroi.coluna] = '@';
			heroi.linha++;
			break;
		case 'd':
			mapa.matriz[heroi.linha][heroi.coluna+1] = '@';
			heroi.coluna++;
	}
	
}

int main() {
	
	le_mapa(&mapa);
	encontra_caractere(&mapa, &heroi, '@');

	do {
		imprime_mapa(&mapa);

		char comando;
		cin >> comando;

		move(comando);

	} while (nao_acabou());

	libera_mapa(&mapa);
}
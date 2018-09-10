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

	mapa.matriz[heroi.x][heroi.y] = '.';

	switch(direcao) {
		case 'a':
			mapa.matriz[heroi.x][heroi.y-1] = '@';
			heroi.y--;
			break;
		case 'w':
			mapa.matriz[heroi.x-1][heroi.y] = '@';
			heroi.x--;
			break;
		case 's':
			mapa.matriz[heroi.x+1][heroi.y] = '@';
			heroi.x++;
			break;
		case 'd':
			mapa.matriz[heroi.x][heroi.y+1] = '@';
			heroi.y++;
			break;
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
#include "mapa.hpp"

bool perdeu(Mapa* mapa){
	Posicao posicao;
	return !encontra_caractere(mapa, &posicao, HEROI);
}

bool ganhou(Mapa* mapa) {
	Posicao posicao;
	return !encontra_caractere(mapa, &posicao, FANTASMA);
}

bool acabou(Mapa* mapa) {
	return ganhou(mapa) || perdeu(mapa);
}

bool nao_acabou(Mapa* mapa) {
	return !acabou(mapa);
}

void inicializa_aleatorio() {
	srand(time(0));
}

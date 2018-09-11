#include <iostream>
#include <string>
using namespace std;
#include "ui.hpp"
#include "mapa.hpp"

string desenho_parede[4] = {
	{"......" },
	{"......" },
	{"......" },
	{"......" }
};

string desenho_fantasma[4] = {
	{" .-.  " },
	{"| OO| " },
	{"|   | " },
	{"'^^^' " }
};

string desenho_heroi[4] = {
	{" .--. "  },
	{"/ _.-'"  },
	{"\\  '-." },
	{" '--' "  }
};

string desenho_pilula[4] = {
	{"      "},
	{" .-.  "},
	{" '-'  "},
	{"      "}
};

string desenho_vazio[4] = {
	{"      "},
	{"      "},
	{"      "},
	{"      "}
};

void imprime_parte(string desenho[4], int parte) {
	cout << desenho[parte];
}

void imprime_mapa(Mapa* mapa) {
	for(int i = 0; i < mapa->linhas; i++) {

		for(int parte = 0; parte < 4; parte++) {
			for(int j = 0; j < mapa->colunas; j++) {

				switch(mapa->matriz[i][j]) {
					case FANTASMA:
						imprime_parte(desenho_fantasma, parte);
						break;
					case HEROI:
						imprime_parte(desenho_heroi, parte);
						break;
					case PILULA:
						imprime_parte(desenho_pilula, parte);
						break;
					case PAREDE_VERTICAL:
					case PAREDE_HORIZONTAL:
						imprime_parte(desenho_parede, parte);
						break;
					case VAZIO:
						imprime_parte(desenho_vazio, parte);
						break;
				}
				
			}
			cout << endl;
		}

	}
}
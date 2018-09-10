#include <string>
using namespace std;

const string ARQUIVO_MAPA = "mapa.txt";

struct Mapa {
	char** matriz;
	int linhas;
	int colunas; 
};


void aloca_mapa(Mapa* mapa);
void le_mapa(Mapa* mapa);
void libera_mapa(Mapa* mapa);
void imprime_mapa(Mapa* mapa);

struct Posicao {
	int x;
	int y;
};

void encontra_caractere(Mapa* mapa, Posicao* posicao, char caractere);
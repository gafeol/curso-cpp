#include <string>
using namespace std;

const string ARQUIVO_MAPA = "mapa.txt";

const char HEROI = '@';
const char FANTASMA = 'F';
const char VAZIO = '.';
const char PAREDE_VERTICAL = '|';
const char PAREDE_HORIZONTAL = '-';
const char PILULA = 'P';

struct Mapa {
	char** matriz;
	int linhas;
	int colunas;
};


struct Posicao {
	int x;
	int y;
};



void libera_mapa(Mapa* mapa);
void le_mapa(Mapa* mapa);
void aloca_mapa(Mapa* mapa);
void imprime_mapa(Mapa* mapa);
bool encontra_caractere(Mapa* mapa, Posicao* posicao, char caractere);

bool eh_valida(Mapa* mapa, int x, int y);
void move_personagem(Mapa* mapa, int x_origem, int y_origem, 
	int x_destino, int y_destino);

void copia_mapa(Mapa* destino, Mapa* origem);

bool pode_andar(Mapa* mapa, char personagem, int x, int y);

bool eh_personagem(Mapa* mapa, char personagem, 
	int x, int y);

bool eh_parede(Mapa* mapa, int x, int y);
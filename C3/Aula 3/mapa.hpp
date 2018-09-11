#include <string>
using namespace std;

const string ARQUIVO_MAPA = "mapa.txt";

const char HEROI = '@';
const char VAZIO = '.';
const char PAREDE_VERTICAL = '|';
const char PAREDE_HORIZONTAL = '-';
const char FANTASMA = 'F';

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
	int linha;
	int coluna;
};

bool encontra_caractere(Mapa* mapa, Posicao* posicao, char caractere);

bool eh_valida(Mapa* mapa, int linha, int coluna);
bool eh_parede(Mapa* mapa, int linha, int coluna);
bool eh_personagem(Mapa* mapa, char personagem, int linha, int coluna);

void move_personagem(Mapa* mapa, int linha_origem, int coluna_origem, 
	int linha_destino, int coluna_destino);

void copia_mapa(Mapa* destino, Mapa* origem);

bool pode_andar(Mapa* mapa, char personagem, int linha, int coluna);
const char CIMA = 'w';
const char BAIXO = 's';
const char DIREITA = 'd';
const char ESQUERDA = 'a';
const char BOMBA = 'b';


void move_heroi(char direcao);

bool direcao_invalida(char direcao);

void move_fantasmas();

bool movimento_fantasma(int linha_atual, int coluna_atual, 
	int* linha_destino, int* coluna_destino);

void explode_pilula();
bool explode_posicao(Mapa* mapa, int linha, int coluna);
void explode_pilula_recursivo(int linha, int coluna, int soma_linha, int soma_coluna, int qtd);
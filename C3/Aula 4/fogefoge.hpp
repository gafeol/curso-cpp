const char CIMA = 'w';
const char BAIXO = 's';
const char DIREITA = 'd';
const char ESQUERDA = 'a';
const char BOMBA = 'b';


void move(char direcao);

bool ganhou();
bool perdeu();
bool nao_acabou();

bool direcao_invalida(char direcao);

void fantasmas();

bool movimento_fantasma(int x_atual, int y_atual, 
	int* x_destino, int* y_destino);

void explode_pilula();
bool explode_posicao(Mapa* mapa, int x, int y);
void explode_pilula_recursivo(int x, int y, int soma_x, int soma_y, int qtd);
void inicializa_aleatorio();
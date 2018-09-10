const char CIMA = 'w';
const char BAIXO = 's';
const char DIREITA = 'd';
const char ESQUERDA = 'a';

bool ganhou();
bool perdeu();
bool acabou();
bool nao_acabou();
void move(char direcao);
 
bool direcao_invalida(char direcao);
void fantasmas();
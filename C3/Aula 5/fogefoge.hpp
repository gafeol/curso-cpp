#ifndef _FOGEFOGE_H_
#define _FOGEFOGE_H_

const char CIMA = 'w';
const char BAIXO = 's';
const char DIREITA = 'd';
const char ESQUERDA = 'a';
const char BOMBA = 'b';

bool ganhou();
bool perdeu();
bool nao_acabou();
void move(char direcao);
 
bool eh_direcao(char direcao);
void fantasmas();
void explode_pilula();
void explode_pilula_recursivo(int x, int y, int soma_x, int soma_y, int qtd);
void inicializa_aleatorio();


#endif
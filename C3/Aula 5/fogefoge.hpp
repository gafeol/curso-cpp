#ifndef _FOGEFOGE_H_
#define _FOGEFOGE_H_

const char CIMA = 'w';
const char BAIXO = 's';
const char DIREITA = 'd';
const char ESQUERDA = 'a';
const char BOMBA = 'b';

void move_heroi(char direcao);
 
bool eh_direcao(char direcao);
void move_fantasmas();
void explode_pilula();
void explode_pilula_recursivo(int linha, int coluna, int soma_linha, int soma_coluna, int qtd);


#endif
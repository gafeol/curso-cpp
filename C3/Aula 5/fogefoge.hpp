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
void explode_pilula_recursivo(int linha, int coluna, int soma_linha, int soma_coluna, int qtd);
void inicializa_aleatorio();


#endif
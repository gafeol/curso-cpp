#ifndef _JOGO_H_
#define _JOGO_H_

bool ganhou(Mapa* mapa);
bool perdeu(Mapa* mapa);
bool acabou(Mapa* mapa);
bool nao_acabou(Mapa* mapa);
void inicializa_aleatorio();

#endif
#include <string> 
using namespace std;

const string BANCO_PALAVRAS = "palavras.txt";
const int TAMANHO_MAXIMO = 20;

void abertura();
void chuta();
void desenha_forca();
void escolhe_palavra();
bool acertou();
bool ganhou();
bool nao_ganhou();
bool enforcou();
bool nao_enforcou();
bool ja_chutou(char letra);
bool nao_chutou(char letra);
bool letra_existe(char letra);
int chutes_errados();
#include <string> 
using namespace std;

const string ARQUIVO_PALAVRAS = "palavras.txt";

void abertura();
void chuta();
void desenha_forca();
void escolhe_palavra();
bool acertou();
bool nao_acertou();
bool enforcou();
bool nao_enforcou();
bool ja_chutou(char letra);
bool nao_chutou(char letra);
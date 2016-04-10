
typedef struct arvore_huffman ArvoreHuff;

ArvoreHuff init();

ArvoreHuff new(char valor, ArvoreHuff *left, ArvoreHuff *right);

char * pre_order(ArvoreHuff *root);

int folha(ArvoreHuff *arvore);


typedef struct arvore_huffman ArvoreHuff;

ArvoreHuff * newArvore(char valor, ArvoreHuff *left, ArvoreHuff *right);

void pre_order(ArvoreHuff *root, char c[]);

int folha(ArvoreHuff *arvore);

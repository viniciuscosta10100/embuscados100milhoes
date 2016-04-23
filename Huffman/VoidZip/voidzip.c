#include "funcoes_huffman.h"

int main(){
	int opcao;
	char endereco[50];
	printf("1- Compactar\n2- Descompactar\nOpc: ");
	scanf("%d", &opcao);
	switch(opcao){
		case 1:
			printf("Digite o endereco do arquivo a ser compactado: ");
			scanf("%s", endereco);
			compactar(endereco);
			break;
		case 2:
			printf("Digite o endereco do arquivo .huff: ");
			scanf("%s", endereco);
			descompactar(endereco);
			break;
		default:
			printf("Opcao invalida!");
			break;
	}
	//compactar("tmp/oi.txt");
	//descompactar("meu-arquivo.huff");
	return 0;
}

#include "huffman.h"

int main(){
	int opcao;
	char nomearquivo[50];
	printf("1- Compactar\n2- Descompactar\nOpc: ");
	scanf("%d", &opcao);
	switch(opcao){
		case 1:
			printf("Digite o endereco do arquivo a ser compactado: ");
			scanf("%s", nomearquivo);
			printf("Iniciando processo...\n");
			compactar(nomearquivo);
			break;
		case 2:
			printf("Digite o endereco do arquivo de saida: ");
			scanf("%s", nomearquivo);
			printf("Iniciando processo...\n");
			descompactar(nomearquivo);
			break;
		default:
			printf("Opcao invalida!");
			break;
	}
	//compactar("tmp/oi.txt");
	//descompactar("meu-arquivo.huff");
	return 0;
}

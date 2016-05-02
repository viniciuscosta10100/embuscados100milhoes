#include<bits/stdc++.h>
#include"pilha.h"
#include"interface.h"
#include"Reduce.h"
int main()
{

    FILE* arq = fopen("entrada.txt","r");

    char entrada[100];
    char escolha='w';
    fscanf(arq,"%s",entrada);

    Arvore* BDD = (Ler_entrada(entrada));
    Arvore* copia=copiar_arvore(BDD);

    printf("%s\n",entrada);

    iniciar_terminais();
    C1(BDD);
    while(continuar)
    {
        continuar=0;
        BDD=C3(BDD);
        BDD=C2(BDD);
    }

    while(escolha!='s'&&escolha!='S'&&escolha!='n'&&escolha!='N')
    {
        printf("Vamos testar nossos dados, Usar RBDD s/n\n");
        scanf("%c",&escolha);

        if(escolha=='s'||escolha=='S')
            interface(BDD);
        else if(escolha=='n'||escolha=='N')
            interface(copia);
        else
            printf("digito errado, aperte s ou n\n");

    }
    return 0;
}
END_OF_MAIN();

#include<bits/stdc++.h>

using namespace std;
int continuar=1;

#include"f_booleanas.cpp"
#include"arvore.cpp"
#include"ROBDD.cpp"
#include"pilha.cpp"
#include"imprimir_largura.cpp"
#include"f_ExprToArvore.c"


int main(){

    FILE* arq = fopen("entrada.txt","r");

    char entrada[100];

    fscanf(arq,"%s",entrada);

    Arvore* BDD = (funcaomaster(entrada));

    printf("%s\n",entrada);
    imprimir_preOrdem(BDD);
    printf("\n\n");

    iniciar_terminais();
    C1(BDD);
    while(continuar)
    {
        continuar=0;
        BDD=C3(BDD);
        BDD=C2(BDD);
    }
    imprimir_preOrdem(BDD);
    printf("\n");
    usar_ROBDD(BDD);
    return 0;
}

#include"ROBDD.cpp"
/*
 para os que n�o conhece C++ , map � uma hash e vector � uma lista duplamente encadeada
para mais detalhes acesse ROBDD.h
*/
int main(){
    string arvore;
    //caso va motificar o arquivo entrada.txt coloque so variaveis com um caracter, ainda estou trabalhando na fun��o de leitura desse arquivo
    ifstream entrada ("entrada.txt");//essa duas linhas pega a primeira linha do arquivo entrada.txt e coloca na variavel arvore
    entrada>>arvore;


    struct arvore* BDD =criar_arvore(arvore);
    iniciar_terminais();//terminais 1 e 0

    imprimir(BDD);//imprimi BDD
    printf("\n");

    RTD(BDD);//remover terminais dublicados

    BDD=RnTD(BDD);//remover n�o-terminais dublicados

    BDD=RTR(BDD);//remover teste redundantes

    imprimir(BDD);//imprimi ROBDD
    printf("\n");

    usar_ROBDD(BDD);//coloque os valores das variaveis e obtenha o resultado da expres�o

   return 0;
}




char somaArvore(char V1,char V2, char sinal)
{
    if(sinal=='&')
        return AND(V1,V2);
    else if(sinal=='|')
        return OU(V1,V2);
    else if(sinal=='>')
        return Implica(V1,V2);
    else if(sinal=='=')
        return equivale(V1,V2);
}
void somar_arvore_part2(Arvore** avr1,Arvore** avr2,Arvore* sinal){
    if((*avr2)->esq!=NULL && (*avr2)->dir!=NULL)
    {
        somar_arvore_part2(avr1,&(*avr2)->esq,sinal);
        somar_arvore_part2(avr1,&(*avr2)->dir,sinal);
    }
    else
    {
        (*avr2)->variavel=somaArvore((*avr1)->variavel,(*avr2)->variavel,sinal->variavel);
    }
}
void somar_arvore_part1(Arvore** avr1,Arvore** avr2,Arvore* sinal){

    if((*avr1)->esq!=NULL && (*avr1)->dir!=NULL){

        somar_arvore_part1(&(*avr1)->esq,avr2,sinal);
        somar_arvore_part1(&(*avr1)->dir,avr2,sinal);
    }
    else{
        Arvore*aux=copiar_arvore(*avr2);
        somar_arvore_part2(avr1,&aux,sinal);
        *avr1=aux;
    }
}
void desempilharArvore(Pilha** Topo)
{
    Arvore* aux1=desempilhar(Topo)->avr;//primeira variavel
    Arvore* aux2=desempilhar(Topo)->avr;//sinal

    if(aux2->variavel=='('){
        *Topo=empilhar((*Topo),aux1);
    }
    else {
        Arvore* aux3=desempilhar(Topo)->avr;//segunda variavel

        somar_arvore_part1(&aux1,&aux3,aux2);

        *Topo=empilhar(*Topo,aux1);
        desempilharArvore(Topo);
    }
}
Arvore* funcaomaster(char* entrada){
    Pilha* MyPilha=criar_pilha();
    int i=0;
    int tam=strlen(entrada);
    while(i<tam)
    {
         if(entrada[i]==')')
        {
            desempilharArvore(&MyPilha);
        }
        else
        {
            Arvore* aux=novo_node_nao_folha(entrada[i]);
            MyPilha=empilhar(MyPilha,aux);
        }
        i++;
    }
    while(tamanho(MyPilha)>1)
    {
        desempilharArvore(&MyPilha);
    }
    return MyPilha->avr;
}


vector<struct arvore*> lista_node;//
map<char,int> variaveis;
map<char,int> valores;
map<int,int> hash_table;
int inicio=0;
Arvore* verdadeiro;
Arvore* falso ;

Arvore* criar_terminal(char saida){//criar terminais do tipo 1 e 0
    Arvore* terminal = (Arvore*) malloc(sizeof(Arvore));
    terminal->variavel=saida;
    terminal->dir=NULL;
    terminal->esq=NULL;
    return terminal;
}
void iniciar_terminais(){
     verdadeiro=criar_terminal('1');
     falso = criar_terminal('0');
}
Arvore* C1(Arvore* BDD){//remover terminais duplicados

    if(BDD->variavel!='1'&&BDD->variavel!='0'){
            BDD->esq=C1(BDD->esq);
            BDD->dir=C1(BDD->dir);
            return BDD;
    }
    else if(BDD->variavel=='1'){
        free(BDD);
        return verdadeiro;
    }
    else if(BDD->variavel=='0'){
        free(BDD);
        return falso;
    }
}
int comparar_nodes(Arvore* node1,Arvore* node2){
    if(node1!=NULL||node2!=NULL){
        if(node1!=NULL&&node2!=NULL){
            if(node1->variavel==node2->variavel){
                return comparar_nodes(node1->esq,node2->esq) & comparar_nodes(node1->dir,node2->dir);
            }
        }
        return 0;
    }
    return 1;
}
Arvore* BuscarNodeLista(Arvore* node){
    vector<Arvore*>::iterator it=lista_node.begin();

    for(it;it!=lista_node.end();++it){
        if(comparar_nodes(node,*it)){
            return *it;
        }
    }
    lista_node.push_back(node);
    return node;
}
Arvore* C3(Arvore* BDD){ ///remover n�o-terminais duplicados
    if(BDD!=NULL){
        Arvore* aux;
        aux=BuscarNodeLista(BDD);//verificar se ja n�o teve um node igual ao BDD e o retorna se n�o retotorna o BDD
        if(aux!=BDD){
            continuar=1;
            free(BDD);
            return aux;
        }
        BDD->esq=C3(BDD->esq);
        BDD->dir=C3(BDD->dir);
        return BDD;
    }
}
Arvore* C2(Arvore* node){//remover testes reduntantes
    if(node!=verdadeiro&&node!=falso){
        if(node->esq==node->dir){
            Arvore* aux=node->esq;
            continuar=1;
            free(node);
            return aux;
        }
        else{
            node->esq=C2(node->esq);
            node->dir=C2(node->dir);
            return node;
        }
    }
}
char percorrer_ROBDD(Arvore* BDD){
    if(BDD!=verdadeiro&&BDD!=falso){
        if(valores[BDD->variavel]==1)
                return percorrer_ROBDD(BDD->dir);
        else if(valores[BDD->variavel]==0)
                return percorrer_ROBDD(BDD->esq);
        else
            printf("erro de valores na variaveis\n");
    }
    else {
        return BDD->variavel;
    }
}
void carregarvariaveis(Arvore* BDD){
    if(BDD!=verdadeiro&&BDD!=falso)
    {
        variaveis[BDD->variavel]=1;
        carregarvariaveis(BDD->esq);
        carregarvariaveis(BDD->dir);
    }
}
void usar_ROBDD(Arvore* BDD){
    int aux;
    char aux2;
    carregarvariaveis(BDD);
    map<char,int>::iterator it;
    printf("encontrar valores com ROBDD criado? S/N");
    scanf("%c",&aux2);
    while(aux2=='S'){
        for(it=variaveis.begin();it!=variaveis.end();++it){
            printf("valor de %c?\n", it->first);
            scanf("%d",&aux);
            valores[it->first]=aux;
        }
        printf("resultado %c\n",percorrer_ROBDD(BDD));
        valores.clear();
        printf("encontrar valores com ROBDD criado? S/N");
        getchar();
        scanf("%c",&aux2);
    }
}



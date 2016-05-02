using namespace std;
vector<struct arvore*> lista_node;
map<char,int> variaveis;
map<char,int> valores;
map<int,int> hash_table;
int inicio=0;
Arvore* verdadeiro;
Arvore* falso ;

Arvore* criar_terminal(char saida){
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
Arvore* C1(Arvore* BDD){

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
Arvore* C3(Arvore* BDD){
    if(BDD!=NULL){
        Arvore* aux;
        aux=BuscarNodeLista(BDD);
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
Arvore* C2(Arvore* node){
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


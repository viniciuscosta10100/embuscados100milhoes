typedef struct pontos
{
    int x;
    int y;
} Local;
typedef struct lista_de_nodes
{
    Arvore* node;
    int prioridade;

} Nodes;


map<Nodes*,Local> Hash_nodesBDD;
vector<Nodes*> Lista_nodesBDD;
map<int,int> Hash_NodesPorLinha;
map<Arvore*,Nodes*> Hash_aux;
map<Arvore*,int> visited;
int x_inicial;
int y_inicial=500;
int raio_bolas=20;


Nodes* criar_node(Arvore* avr,int prioridade)
{
    Nodes* novo=(Nodes*) malloc(sizeof(Nodes));
    novo->node=avr;
    novo->prioridade=prioridade;
    return novo;
}
void put_Lista_nodesBDD(Nodes* node)
{
    Hash_NodesPorLinha[node->prioridade]++;

    vector<Nodes*>:: iterator it=Lista_nodesBDD.begin();
    if(Lista_nodesBDD.size()>0)
        while(it!=Lista_nodesBDD.end()&&node->prioridade<=(*it)->prioridade)
        {

            it++;

        }
    Lista_nodesBDD.insert(it,node);
}
int  profundidade=1;
void put_Lista(Arvore* BDD)
{
    if(BDD!=NULL)
    {

        profundidade++;
        put_Lista(BDD->esq);
        put_Lista(BDD->dir);
        profundidade--;

        if(!visited[BDD])
        {

            visited[BDD]=1;
            Nodes* node_novo=criar_node(BDD,profundidade);

            Hash_aux[BDD]=node_novo;
            put_Lista_nodesBDD(node_novo);
        }
        else
        {
            //verificar profundidade

            if(profundidade>Hash_aux[BDD]->prioridade)
            {
                vector<Nodes*>::iterator it=Lista_nodesBDD.begin();
                while(*it!=Hash_aux[BDD])it++;
                Lista_nodesBDD.erase(it);
                Hash_aux.erase(Hash_aux.find(BDD));

                Nodes* node_novo=criar_node(BDD,profundidade);
                Hash_aux[BDD]=node_novo;
                put_Lista_nodesBDD(node_novo);

            }

        }
    }
}
void ligar_nodes(Local p1, Local p2,string cor)
{
    if(cor=="esq")
        line(screen,p1.x,p1.y+raio_bolas,p2.x,p2.y-raio_bolas,makecol(255,0,0));
    else if(cor=="dir")
        line(screen,p1.x,p1.y+raio_bolas,p2.x,p2.y-raio_bolas,makecol(0,0,255));
    else if(cor=="percorrer")
        line(screen,p1.x,p1.y+raio_bolas,p2.x,p2.y-raio_bolas,makecol(0,255,0));
}
vector<Nodes*>::iterator it_lista;
void preencher_locais()
{
    if(it_lista!=Lista_nodesBDD.end())
    {
        int profundidade=((*it_lista)->prioridade);
        int quant_linha=Hash_NodesPorLinha[profundidade];
        if(quant_linha%2!=0) //impar
        {
            int aux=quant_linha-((quant_linha/2)+1);
            x_inicial=100-((aux)*4*raio_bolas);
        }
        else
        {
            int aux=quant_linha/2;
            x_inicial=100-aux;
        }
        Local local;

        while(it_lista!=Lista_nodesBDD.end()&&((*it_lista)->prioridade)==profundidade)
        {
            local.x=x_inicial;
            local.y=y_inicial;
            Hash_nodesBDD[(*it_lista)]=local;
            it_lista++;
            x_inicial+=2*raio_bolas;
        }
        y_inicial-=100;
        preencher_locais();
    }

}
void printar()
{
    vector<Nodes*>::iterator it=Lista_nodesBDD.begin();
    while(it!=Lista_nodesBDD.end())
    {
        circlefill(screen,Hash_nodesBDD[*it].x,Hash_nodesBDD[*it].y,raio_bolas,makecol(255,255,255));
        textout_centre_ex(screen,font, &(*it)->node->variavel, Hash_nodesBDD[*it].x, Hash_nodesBDD[*it].y, makecol(100,100,100),-1);
        if((*it)->node->esq!=NULL)
            ligar_nodes(Hash_nodesBDD[*it],Hash_nodesBDD[Hash_aux[(*it)->node->esq]],"esq");
        if((*it)->node->dir!=NULL)
            ligar_nodes(Hash_nodesBDD[*it],Hash_nodesBDD[Hash_aux[(*it)->node->dir]],"dir");

        it++;
    }
}
void desenhar()
{
    it_lista=Lista_nodesBDD.begin();
    preencher_locais();
    printar();


}


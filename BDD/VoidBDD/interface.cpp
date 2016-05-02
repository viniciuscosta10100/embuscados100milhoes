void interface(Arvore* BDD)
{
    allegro_init();
    install_timer();
    install_keyboard();
    set_color_depth(32);
    set_gfx_mode(GFX_AUTODETECT_WINDOWED, 800, 600, 0, 0);
    set_window_title("Tutorial 1 - Instalacao");

    put_Lista(BDD);
    desenhar();
    Arvore* aux=BDD;
    while(!key[KEY_ESC])
    {
        if(aux->variavel!='0'&&aux->variavel!='1'){
        if(key[KEY_0])
        {
            key[KEY_0]=0;
            ligar_nodes(Hash_nodesBDD[Hash_aux[aux]],Hash_nodesBDD[Hash_aux[aux->esq]],"percorrer");
            aux=aux->esq;
        }
        else if(key[KEY_1])
        {
            key[KEY_1]=0;
            ligar_nodes(Hash_nodesBDD[Hash_aux[aux]],Hash_nodesBDD[Hash_aux[aux->dir]],"percorrer");
            aux=aux->dir;
        }
        }
    }

}



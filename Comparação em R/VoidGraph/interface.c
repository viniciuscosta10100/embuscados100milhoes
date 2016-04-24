#include "interface.h"
#define MENU_1 1
#define MENU_21 21
#define MENU_22 22
int main(){
	int saida = 0;
	int menuAtual = 1;
	while(!saida){
        if (menuAtual == MENU_1){
            menuAtual = menu1();
        }
        else if (menuAtual == MENU_21){
            menuAtual = menu21();
        }
        else if (menuAtual == MENU_22){
            menuAtual = menu22();
        }
        else{
            saida = 1;
        }
	}
	return 1;
}

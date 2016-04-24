#include "interface_menus.h"
#define CIMA 72
#define BAIXO 80
#define DIREITA 77
#define ESQUERDA 75
#define MENU_1 1
#define MENU_21 21
#define MENU_22 22
#include <stdio.h>
#include <stdlib.h>

int menu1(){
    int saida = 0;
    int gatilho = 1;
    int nextmenu;
    int chamada;
    arrow *arrowobject;
    arrowobject = setArrow();
    //system("pause");
    while(!saida){
        setScreen1();
		drawArrowinScreen(arrowobject);
		drawScreen();
		chamada = getch();
		if (chamada == ESQUERDA){
			saida = 1;
			nextmenu = 0;
		}
		else if (chamada == BAIXO){
			arrowDown(arrowobject,gatilho);
		}
		else if (chamada == CIMA){
			arrowUp(arrowobject,gatilho);
		}
		else if (chamada == DIREITA){
            saida = 1;
            if (arrowobject->posY == 7){
                nextmenu = MENU_21;
            }
            else if(arrowobject->posY == 9){
                nextmenu = MENU_22;
            }

		}
		system("cls");
	}
	return nextmenu;
}

int menu21(){
    int saida = 0;
    int gatilho = MENU_21;
    int escolhido = 0;
    int num_de_elementos=-1;
    char num_de_elementos_str[100];
    int chamada;
    int nextmenu;
    arrow *arrowobject;
    arrowobject = setArrow();
    while(!saida){
        if (num_de_elementos == -1){
            barsetScreen(escolhido,num_de_elementos_str);
            drawbarScreen();
            scanf("%d",&num_de_elementos);
            itoa(num_de_elementos,num_de_elementos_str,10);
            escolhido = 1;
        }
        system("cls");
        barsetScreen(escolhido,num_de_elementos_str);
        drawArrowinScreen(arrowobject);
        drawScreen();
        chamada = getch();
		if (chamada == ESQUERDA){
			saida = 1;
			nextmenu = MENU_1;
		}
		else if (chamada == BAIXO){
			arrowDown(arrowobject,gatilho);
		}
		else if (chamada == CIMA){
			arrowUp(arrowobject,gatilho);
		}
		else if (chamada == DIREITA){
            if(arrowobject->posY == 9){
                num_de_elementos=-1;
                escolhido = 0;
                arrowobject->posY = 7;
            }
            else if (arrowobject->posY == 7){
            	//system("pause");
                saida = 1;
                nextmenu = MENU_1;
                loadingScreen();
                system("cls");
                drawScreen();
                gerandoComparacoesBarPlot(num_de_elementos);
                system("BARPLOT.R");
            }
		}
		system("cls");
	}
	return nextmenu;
}

int menu22(){
	int nextmenu;
	int gatilho = 22;
	int saida = 0;
	int escolhido = 0;
	int num_de_elementos = -1;
	char num_de_elementos_str[100];
	int chamada;
	arrow *arrowobject;
    arrowobject = setArrow();
	while(!saida){
		linesetScreen(escolhido,num_de_elementos_str);
		if(num_de_elementos == -1){
            drawlineScreen();
            scanf("%d",&num_de_elementos);
            itoa(num_de_elementos,num_de_elementos_str,10);
            escolhido = 1;
		}
		system("cls");
		linesetScreen(escolhido,num_de_elementos_str);
        drawArrowinScreen(arrowobject);
        drawScreen();
		chamada = getch();
		if (chamada == ESQUERDA){
			saida = 1;
			nextmenu = MENU_1;
		}
		else if (chamada == BAIXO){
			arrowDown(arrowobject,gatilho);
		}
		else if (chamada == CIMA){
			arrowUp(arrowobject,gatilho);
		}
		else if (chamada == DIREITA){
            if(arrowobject->posY == 9){
                num_de_elementos=-1;
                escolhido = 0;
            }
            else if (arrowobject->posY == 7){
                saida = 1;
                nextmenu = MENU_1;
                loadingScreen();
                system("cls");
                drawScreen();
                gerandoComparacoesLinePlot(num_de_elementos);
                system("PLOTLINE.R");
            }
		}
		system("cls");

	}
	return nextmenu;

}

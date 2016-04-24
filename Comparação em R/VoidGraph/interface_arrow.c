#include "interface_arrow.h"
//#define arrowTam 3
#define MENU_1 1
#define MENU_21 21
#define MENU_22 22

arrow* setArrow(){
	arrow* newar = (arrow*) malloc(sizeof(arrow));
	strcpy(newar->myarrow,"->");
	newar->posX = 3;
	newar->posY = 7;
	return newar;
}
void arrowDown(arrow* seta,int gatilho){
	if (seta->posY+2 <= 9 && gatilho == MENU_1){
		seta->posY+=2;
	}
	else if(seta->posY+2 <= 9 && gatilho == MENU_21){
        seta->posY+=2;
	}
	else if (seta->posY+2 <= 9 && gatilho == MENU_22){
        seta->posY+=2;
	}
}

void arrowUp(arrow* seta,int gatilho){
	if (seta->posY-2 >= 7 && gatilho == MENU_1){
		seta->posY-=2;
	}
	else if (seta->posY-2 >= 7 && gatilho == MENU_21){
        seta->posY-=2;
	}
	else if (seta->posY-2 >=7 && gatilho == MENU_22){
        seta->posY-=2;
	}
}


#ifndef INTERFACE_ARROW_H__
#define INTERFACE_ARROW_H__

/*you header file can have declarations here*/
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#define arrowTam 3

struct Arrow{
	char myarrow[arrowTam];
	int posX;
	int posY;
};
typedef struct Arrow arrow;
//typedef struct arrow arrow;
arrow* setArrow();
void arrowUp(arrow* seta,int gatilho);
void arrowDown(arrow* seta,int gatilho);


#endif /* INTERFACE_ARROW_H__*/

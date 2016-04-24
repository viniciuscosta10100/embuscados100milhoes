#ifndef INTERFACE_SCREENS_H__
#define INTERFACE_SCREENS_H__

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "interface_arrow.h"

void setScreen1();
void barsetScreen(int escolhido,char *num_de_elementos_str);
void linesetScreen(int escolhido,char *num_de_elementos_str);
void loadingScreen();
void drawScreen();
void drawbarScreen();
void drawlineScreen();
void drawArrowinScreen(arrow *seta);
/*you header file can have declarations here*/

#endif /* INTERFACE_SCREENS_H__*/

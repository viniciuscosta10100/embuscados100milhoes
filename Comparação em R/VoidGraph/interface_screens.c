#include "interface_screens.h"
#define MAXY 24
#define MAXX 78
static char screen[MAXY][MAXX];

void setScreen1(){
    memset(screen,' ',sizeof(screen));
	strcpy(screen[2],"                          BUBBLESORT VS HEAPSORT");
	strcpy(screen[5],"       Escolha o tipo de grafico que deseja:");
	strcpy(screen[7],"       Grafico de barras");
	strcpy(screen[9],"       Grafico de curvas");
}
void barsetScreen(int escolhido,char *num_de_elementos_str){
    memset(screen,' ',sizeof(screen));
	strcpy(screen[2],"                         BUBBLESORT VS HEAPSORT");
    strcpy(screen[5],"       Digite o numero de elementos no array que deseja:");
    if (escolhido){
    	strcat(screen[5],num_de_elementos_str);
    	strcpy(screen[7],"       Gerar grafico");
    	strcpy(screen[9],"       Digitar outro valor");
    }
}
void linesetScreen(int escolhido,char *num_de_elementos_str){
	memset(screen,' ',sizeof(screen));
	strcpy(screen[2],"                         BUBBLESORT VS HEAPSORT");
	strcpy(screen[5],"       Digite o numero de elementos limite no array:");
    if (escolhido){
    	strcat(screen[5],num_de_elementos_str);
    	strcpy(screen[7],"       Gerar grafico");
    	strcpy(screen[9],"       Digitar outro valor");
    }
}
void loadingScreen(){
	memset(screen,' ',sizeof(screen));
	strcpy(screen[2],"                         BUBBLESORT VS HEAPSORT");
	strcpy(screen[5],"       Gerando dados, por favor, aguarde...");
}
void drawArrowinScreen(arrow *seta){
	int x,y;
	int i;
	y = seta->posY;
	for (x = seta->posX,i=0 ; i < 2 ; x++,i++){
		screen[y][x] = seta->myarrow[i];
	}

}
void drawScreen(){
	int x,y;
	for (x=0 ; x < MAXY; x++){
		for(y=0 ; y < MAXX ; y++){
			printf("%c",screen[x][y]);
		}
		printf("\n");
	}
}
void drawbarScreen(){
    int x,y;
	for (x=0 ; x < MAXY; x++){
		for(y=0 ; y < MAXX ; y++){
			printf("%c",screen[x][y]);
            if (x ==5 && y == 55)
                return;
		}
		printf("\n");
	}
}
void drawlineScreen(){
    int x,y;
	for (x=0 ; x < MAXY; x++){
		for(y=0 ; y < MAXX ; y++){
			printf("%c",screen[x][y]);
            if (x ==5 && y == 52)
                return;
		}
		printf("\n");
	}
}


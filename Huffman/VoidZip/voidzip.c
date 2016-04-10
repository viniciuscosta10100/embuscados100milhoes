#include <stdio.h>

int main(){
	FILE *fp;
	char buffer[256];
	fp = fopen("tmp/teste.txt", "r");
	while(fgets(buffer, 255, fp))
		printf("Read Buffer: %s\n", buffer );

	fclose(fp);
	return 0;
}

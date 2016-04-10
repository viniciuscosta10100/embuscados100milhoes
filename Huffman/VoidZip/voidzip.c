#include <stdio.h>
#include "util.h"
#include "hashtable_frequency.h"

int main(){
	FILE *fp;
	HTable *htable = initHTable();
	char buffer[256];
	fp = fopen("tmp/teste.txt", "r");
	while(fgets(buffer, 255, fp)){
		printf("Buffer: %s\n", buffer );
		quicksort(buffer);
		addFrequency(htable, buffer);
		//printf("Buffer ordenado: %s\n", buffer );
	}

	fclose(fp);
	return 0;
}

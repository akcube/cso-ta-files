#include <stdio.h>
#include <string.h>

int main(void){
	const char *pw = "SriramWon'tGraduateThisYear";
	char buff[9000];
	int plen = strlen(pw);
	fgets(buff, plen + 1, stdin);
	for(int i=0; i < plen; i++)
		if(buff[i] != pw[i]){
			puts("Failure: Bomb was blown\n");
			return 0;
		}
	puts("Success: Bomb defused\n");
}
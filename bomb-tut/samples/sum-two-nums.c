#include <stdio.h>

int main(void){
	int a, b; scanf("%d %d", &a, &b);
	if(a + b == 42) puts("Success: Bomb defused\n");
	else puts("Failure: Bomb was blown\n");
}
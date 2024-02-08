#include <stdio.h>

int main(void){
	int a, b, x; scanf("%d %d %d", &a, &b, &x);
	if(((x<<2)&b) == a) puts("Success: Bomb defused\n");
	else puts("Failure: Bomb was blown\n");
}
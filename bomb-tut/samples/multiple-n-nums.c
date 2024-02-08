#include <stdio.h>

int main(void){
	int n; scanf("%d", &n);
	int ans = 1;
	for(int i=0; i < n; i++){
		int t; scanf("%d", &t);
		ans *= t;
	}
	if(ans == 58008) puts("Success: Bomb defused\n");
	else puts("Failure: Bomb was blown\n");
}
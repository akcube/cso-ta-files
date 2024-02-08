#include <stdio.h>

int fac(int i){
	if(i <= 1) return 1;
	else return i * fac(i-1);
}

int main(void){
	int n; scanf("%d", &n);
	printf("%d\n", fac(n));
}
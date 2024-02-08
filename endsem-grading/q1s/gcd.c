#include<stdio.h>

long long int gcd(long long int a, long long int b){
	if(b == 0) return a;
	return gcd(b, a % b);
}

int main(void){
	long long int a, b; scanf("%Ld %Ld", &a, &b);
	printf("%Ld\n", gcd(a, b));
}
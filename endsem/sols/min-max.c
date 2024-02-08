#include <stdio.h>

long long int min(long long int a, long long int b){ return (a < b) ? a : b; }
long long int max(long long int a, long long int b){ return (a > b) ? a : b; }

int main(void){

	long long int a, b, c, d, e;
	scanf("%Ld %Ld %Ld %Ld %Ld", &a, &b, &c, &d, &e);

	int mi = min(a, min(b, min(c, min(d, e))));
	int ma = max(a, max(b, max(c, max(d, e))));
	printf("%Ld %Ld\n", mi, ma);
}

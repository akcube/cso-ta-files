#include <bits/stdc++.h>
using namespace std;

int main(void){

	auto rng = std::mt19937(std::random_device()());
	for(int i=1; i <= 5; i++) cout << rng() << '\n';

}
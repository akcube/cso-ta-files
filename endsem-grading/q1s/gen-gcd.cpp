#include<bits/stdc++.h>
using namespace std;

int main(void){

	auto rng = std::mt19937(std::random_device()());
	cout << rng() + 1 << " " << rng() + 1 << '\n';

}
#include<bits/stdc++.h>
using namespace std;

int main(void){
	
	int n; cin >> n;
	cout << n << '\n';
	if (std::cin.fail()) exit(0);

	int a, b, c; 
	cin >> a;
	if (std::cin.fail()) exit(0);
	cin >> b;
	if (std::cin.fail()) exit(0);
	cin >> c;
	if (std::cin.fail()) exit(0);
	cout << a << ' ' << b << ' ' << c << '\n';

	string s; cin >> s;
	if (std::cin.fail()) exit(0);
	cout << s << '\n';

	int iters; cin >> iters;
	if (std::cin.fail()) exit(0);
	cout << iters << ' ';
	for(int i=0; i < iters; i++){
		int val; cin >> val;
		if (std::cin.fail()) exit(0);
		cout << val << ' ';
	}
	cout << '\n';

	for(int i=0; i < 8; i++){
		int val; cin >> val;
		if (std::cin.fail()) exit(0);
		cout << val << ' ';
	}
	cout << '\n';

}
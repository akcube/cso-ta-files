#include<bits/stdc++.h>
using namespace std;

int main(void){
	
	char c; cin >> c;
	if (std::cin.fail()) exit(0);
	cout << c << '\n';

	string s; cin >> s;
	if (std::cin.fail()) exit(0);
	cout << s << '\n';

	for(int i=0; i < 13; i++){
		int val; cin >> val;
		if (std::cin.fail()) exit(0);
		cout << val << ' ';
	}
	cout << '\n';

}
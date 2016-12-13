#include <bits/stdc++.h>
using namespace std;

int main(){
	string e;
	char a;
	unsigned long long i;
	
	cin >> i;
	for(unsigned long long int j=2;j<sqrt(i);j++){
		if(i%j==0){
			cout << "S\n";
			return 0;
		}
	}
		cout << "N\n";
}

#include  <bits/stdc++.h>
using namespace std;

int fat[11]={1,1,2,6,4,2,2,4,2,8,8};
long long fatorial(int n){
	if(n<=10) return fat[n];
	return ((n/10)%2==1?4:6)*fatorial(n/5)*fatorial(n%10);
}

main(){

	int n, count = 1;
	
	while(cin >> n){
		cout << "Instancia " << count++ << endl << fatorial(n)%10 << "\n\n";
	}
}

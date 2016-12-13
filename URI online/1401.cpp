#include <bits/stdc++.h>
using namespace std;

main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n;
	string entrada;

	cin >> n;

	for(int i=0;i<n;i++){
		cin >> entrada;
		sort(entrada.begin(),entrada.end());
		do{
			cout << entrada << endl;
		}while(next_permutation(entrada.begin(),entrada.end()));
		cout << endl;
	}
}

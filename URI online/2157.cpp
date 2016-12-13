#include <bits/stdc++.h>
using namespace std;
void inverso(int n){
	int i,aux;
	while(n>0){
		cout << n%10;
		n/=10;
	}
}

main(){
	int n,ini,fim,i,j;

	cin >> n;
	for(i=0;i<n;i++){
		cin >> ini >> fim;
		for(j=ini;j<=fim;j++){
			cout << j;
		}
		for(j=fim;j>=ini;j--){
			inverso(j);
		}
		cout << endl;
	}
}
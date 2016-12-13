#include <bits/stdc++.h>

using namespace std;

main(){

	int n, v,saida;

	cin >> n;
	while(n!=0){		
		for(int i=0;i<n;i++){
			cin >> v;
			if(v%2==0){
				v-=2;
				saida = (v*2)+2;
			}
			else{
				v-=1;
				saida = (v*2)+1;
			}
			cout << saida << endl;
		}
		cin >> n;
	}
}
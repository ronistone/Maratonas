#include <bits/stdc++.h>

using namespace std;

main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n;
	int qt,s,j,i,o,p=1000;
	int verifica=0,aux,auxi=-1;
	cin >> n;

	for(i=0;i<n;i++){
		cin >> qt >> s;
		for(j=0,verifica=0,auxi=0,p=10000;j<qt;j++){
			cin >> o;
			if(o == s && verifica == 0){
				verifica = 1;
				auxi = j+1;
			}
			else if(verifica==0){
				aux = o - s;
				if(aux < 0)
					aux *= -1;
				if(aux<p){
					p = aux;
					auxi = j+1;
				}
			}
		}
		cout << auxi << endl;
	}
}
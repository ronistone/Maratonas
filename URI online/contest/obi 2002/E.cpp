#include <bits/stdc++.h>
using namespace std;

main(){
	vector<int> v,s;
	int aux,ini,fim,soma;
	int i,j,n,m,cont=1;
	
	while(cin >> n >> m and n and m){
		for(i=0;i<n;i++){
			cin >> aux;
			v.push_back(aux);
		}
		ini = 0;
		fim = m;
		while(fim!=v.size()+1){
			for(i=ini,soma = 0;i<fim;i++){
				soma += v[i];
			}
			soma/=m;
			s.push_back(soma);
			ini++;
			fim++;
		}
		sort(s.begin(),s.end());
		cout << "Teste " << cont << endl;
		cout << s[0] << " " << s[s.size()-1] << endl << endl;
		cont++;
		s.clear();
		v.clear();
	}
}

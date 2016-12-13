#include <bits/stdc++.h>
using namespace std;

main(){
	int n,x,i,j,k,l;
	int total,faltas;
	bool reprove;
	string nomes,presenca;
	std::vector<string> v;
	cin >> n;

	for(i=0;i<n;i++){
		cin >> x;
		for(j=0;j<x;j++){
			cin >> nomes;
			v.push_back(nomes);
		}
		reprove = false;
		for(j=0;j<x;j++){
			total = faltas = 0;
			cin >> presenca;
			for(k=0;k<presenca.size();k++){
				if(presenca[k]=='A'){
					total++;
					faltas++;
				}
				else if(presenca[k]=='P')
					total++;
			}
			float final = (100/total) *faltas;
			if(final>=26){
				if(reprove)
					cout << " ";
				cout << v[j];
				reprove = true;
			}

		}
		cout << endl;
		v.clear();
		nomes.clear();
		presenca.clear();
	}
}
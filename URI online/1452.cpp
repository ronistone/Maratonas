#include <bits/stdc++.h>
using namespace std;

main(){
	int n,m,z,i,j,k,cont;
	string a;
	map<string,bool> aux;
	vector<map <string,bool> > s;
	map<string,bool>::iterator it,it1;
	
	
	while(cin >> n >> m and n and m){
		cont = 0;
		for(i=0;i<n;i++){
			cin >> z;
			for(j=0;j<z;j++){
				cin >> a;
				aux[a] = true;
			}
			s.push_back(aux);
			aux.clear();
		}
		for(i=0;i<m;i++){
			cin >> z;
			for(j=0;j<z;j++){
				cin >> a;
				aux[a] = true;
			}
			for(j=0;j<s.size();j++){
				for(it=aux.begin();it!=aux.end();it++){
					if(s[j][it->first] == true){
						cont++;
						break;
					}
				}
			}
			aux.clear();
		}
		cout << cont << endl;
		s.clear();
	}
}

#include <bits/stdc++.h>
using namespace std;

main(){
	int n,m,z,i,j,k,x;
	string e,a;
	map<string, string> mapa;
	bool achou;
	cin >> n;
	
	for(i=0;i<n;i++){
		cin >> m >> z;
		cin.ignore();
		for(j=0;j<m;j++){
			getline(cin,e);
			getline(cin,a);
			mapa[e] = a;
		}
		for(j=0;j<z;j++){
			getline(cin,e);
			achou = false;
			a.clear();
			for(k=0;k<=e.size();k++){
				if(e[k]==' ' or e[k]=='\0'){
					//a+='\0';
//					cout << "Olha la";
					if(achou)
						cout << " ";
					cout << (mapa[a].size()!=0 ? mapa[a] : a);
					x = 0;
					achou = true;
					a.clear();
				}
				else
					a += e[k];
			}
			cout << endl;
		}
		cout << endl;
		mapa.clear();
	}

}

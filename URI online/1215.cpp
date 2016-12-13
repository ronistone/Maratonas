#include <bits/stdc++.h>
using namespace std;

main(){
	string entrada,aux;
	vector<string> v;
	int i,j;
	j=0;
	while(getline(cin,entrada)){
		aux.clear();
		for(i=0;i<entrada.size() and j<5000;i++){
			if(isalpha(entrada[i])){
				aux+=tolower(entrada[i]);
			}
			else if(aux.size()>0){
				if(find(v.begin(),v.end(),aux)==v.end()){
					v.push_back(aux);
					j++;
				}
				aux.clear();
			}
		}	
	}
	sort(v.begin(),v.end());
	for(i=0;i<v.size();i++)
		cout << v[i] << endl;
	v.clear();
}*/
#include <bits/stdc++.h>
using namespace std;

map<string,bool> mapa;
map<string,bool>::iterator it;

int main() {
	string texto, aux;

	while( getline( cin, texto ) ) {
		aux.clear();
		for( int i=0; i<texto.size(); i++ )
			if( isalpha( texto[i] ) )
				aux += tolower( texto[i] );
			else if( !aux.empty() ) {
				if( !mapa[ aux ] )
					mapa[ aux ] = true;
				aux.clear();
			}

		if( !aux.empty() && !mapa[ aux ] )
			mapa[ aux ] = true;
	}
	for( it=mapa.begin(); it!=mapa.end(); it++ )
		cout << it->first << endl;

	return 0;
}

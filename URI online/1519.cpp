#include <bits/stdc++.h>
using namespace std;

main(){
	string entrada,aux,a;
	int i,j,k,cont;
	map<string,string> mapa;
	map<string,string>::iterator it;
	vector<string> v;
	
	while(getline(cin,entrada) and entrada!="."){
		for(i=0,cont = 0,aux.clear();i<=entrada.size();i++){
			if(entrada[i]==' ' or entrada[i]=='\0'){
				if(aux.size()>2){
					a +=aux[0];				
					a += '.';
					cont++;
				}
				else
					a = aux;
				vector<string>::iterator rear = find(v.begin(),v.end(),a);
				
				if(mapa[a].size()!=0)
					cont--;
				if(rear == v.end()){
					v.push_back(a);
					mapa[a] = aux;
				}
				else{
					if(mapa[a].size()<aux.size()){
						*rear = mapa[*rear];
						mapa[*rear] = *rear;
						v.push_back(a);
						mapa[a] = aux;
					}
					else if(mapa[a] == aux){
						v.push_back(aux);
						mapa[a] = aux;
						//cout << "entrou"  << a << " " << aux<< endl;
					}
					else{
						v.push_back(aux);
						//cont--;
						}
				}
	//			if(mapa[a].size()!=0)
//					cont--;
					
				aux.clear();
				a.clear();
			}
			else
				aux+=entrada[i];
		}
		for(i=0;i<v.size();i++){
			if(i!=0)
				cout << " ";
			cout << v[i];
		}
		sort(v.begin(),v.end());
		cout << endl << cont << endl;
		for(i=0;i<v.size();i++){
			if(v[i]!= mapa[v[i]] and v[i].size()<mapa[v[i]].size())
				cout << v[i] << " = " << mapa[v[i]] << endl;
		}
		mapa.clear();
		v.clear();
	}
}

#include <bits/stdc++.h>
using namespace std;

main(){
	string e;
	list<char> saida;
	stack<char> aux;
	int i,j;
	while(getline(cin,e)){
		bool fim = true;
		for(i=0;i<e.size();i++){
			if(e[i]=='[')
				fim = false;
			else if(e[i]==']'){
				fim = true;
				while(!aux.empty()){
					saida.push_front(aux.top());
					aux.pop();
				}
			}
			else if(fim){
				saida.push_back(e[i]);
			}
			else if(!fim){
				aux.push(e[i]);
			}
		}
		while(!aux.empty()){
			saida.push_front(aux.top());
			aux.pop();
		}
		while(!saida.empty()){
			cout << saida.front();
			saida.pop_front();
		}
		cout << endl;
		saida.clear();
	}
}
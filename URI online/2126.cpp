#include <bits/stdc++.h>

using namespace std;

main(){
	int i=0;

		string a;
		string b;
	while(cin >> a >> b){
		i++;
		size_t found = 0;
		int achou = 0,j =0;
		int tam = a.size();
		int fim = b.rfind(a);
		while(found!=string::npos){	
			found = b.find(a);
			if(found!=string::npos){
				achou ++;
				if(b.size()!=0){
					for(j=0;j<(found+a.size());j++)
						b.erase(b.begin());
				}
			}
		}
		if(achou>0){
			cout << "Caso #" << i << ":" << endl;
			cout << "Qtd.Subsequencias: " << achou << endl;
			cout << "Pos: " << fim+1 << endl;
		}
		else{
			cout << "Caso #" << i << ":" << endl;
			cout << "Nao existe subsequencia" << endl;
		}
		cout << endl;
		a.clear();
		b.clear();
	}
}
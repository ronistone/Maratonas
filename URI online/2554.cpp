#include <bits/stdc++.h>
using namespace std;

main(){
	string e;
	
	int n,d,aux;
	bool falha,achou;
	
	while(cin >> n >> d){
		cin.ignore();
		achou = false;
		for(int i=0;i<d;i++){
			cin >> e;
			falha = false;
			for(int j=0;j<n;j++){
				cin >> aux;
				if(aux == 0)
					falha = true;
			}
			if(!falha and !achou){
				cout << e << endl;
				achou = true;
			}
		}
		if(!achou)
			cout << "Pizza antes de FdI" << endl;
		
	
	}
	
	
}

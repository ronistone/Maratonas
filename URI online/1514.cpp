#include <bits/stdc++.h>
using namespace std;

main(){
	int n, m,i,j;
	cin >> n >> m;

	while(n!=0 && m!=0){
		bool comp[n][m],todos,nada,extodos,exnada,f1=false,f2=false,f3=false,f4=false;
		for(i=0;i<n;i++){
			todos=true;
			nada = true;
			for(j=0;j<m;j++){
				cin >> comp[i][j];
				if(comp[i][j]==false)
					todos = false;
				else
					nada = false;
			}
			if(todos)
				f1 = true;
			if(nada)
				f2 = true;
		}
		for(j=0;j<m;j++){
			extodos = true;
			exnada = true;
			for(i=0;i<n;i++){
				if(comp[i][j]==false)
					extodos = false;
				else
					exnada = false;
			}
			if(extodos)
				f3 = true;
			if(exnada)
				f4 = true;
		}
		int final = 0;
		if(!f1){
			final++;
		}
		if(!f2){
			final++;
		}
		if(!f3){
			final++;
		}
		if(!f4){
			final++;
		}
		cout << final << endl;

		cin >> n >> m;
	}
}
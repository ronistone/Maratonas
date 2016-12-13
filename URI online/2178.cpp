#include <bits/stdc++.h>
using namespace std;

main(){
	int a,p,i,j;
	int n,voltas=0,temp,aux=0,ant;
	cin >> a >> p;
	for(i=0;i<a;i++){
		cin >> n;
		for(j=0,temp=1;j<n;j++){
			cin >> aux;
			if(i==0)
				ant = aux;
			else{
				 if((aux<ant and aux != 0) or ant == 0){
					temp++;
			 	}
			 	ant = aux;
			 }
		}
		if(temp>voltas)
			voltas = temp;
	}
		cout << voltas << endl;
}

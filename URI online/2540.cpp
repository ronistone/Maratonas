#include <bits/stdc++.h>
using namespace std;

main(){
	int n,sum,aux;
	
	while(cin >> n){
		sum = 0;
		for(int i=0;i<n;i++){
			cin >> aux;
			sum += aux;
		}
		if((double)sum/(double)n >= 2.0/3.0)
			cout << "impeachment" << endl;
		else
			cout << "acusacao arquivada" << endl;
	}
}

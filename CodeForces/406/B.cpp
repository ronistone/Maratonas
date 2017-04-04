#include <bits/stdc++.h>
using namespace std;


main(){
	int n,m;
	int z;
	int sum,at,aux;
	
	while(cin >> n >> m){
		cin >> z;
		sum = 0;
		for(int j=0;j<z;j++){
			cin >> aux;
			sum += aux;
		}
		bool achou = false;
		for(int i=1;i<m;i++){
			cin >> z;
			at = 0;
			for(int j=0;j<z;j++){
				cin >> aux;
				at+= aux;
			}
			if(at < sum)
				achou = true;
			sum = at;
		}
		if(!achou)
			cout  << "YES\n";
		else
			cout << "NO\n";	
	}
}

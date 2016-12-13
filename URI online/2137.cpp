#include <bits/stdc++.h>
using namespace std;

bool verifica(int i,int j){return i<j;}

main(){
	int n,i,j;
	while(cin >> n){
		std::vector<int> v;
		int aux;
		for(i=0;i<n;i++){
			cin >> aux;
			v.push_back(aux);
		}
		sort(v.begin(),v.end(),verifica);
		for(i=0;i<n;i++){
			if(v[i]>=0 && v[i]<10)
				cout << "000";
			else if(v[i]>=10 && v[i]<100)
				cout << "00";
			else if(v[i]>=100 && v[i]<1000)
				cout << "0";
			cout << v[i] << endl;
		}
	}
}
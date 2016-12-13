#include <bits/stdc++.h>
using namespace std;

bool verifica(pair<double,int> i, pair<double,int> j){
		if(i.first>j.first)
			return true;
		else if(i.second<j.second)
			return true;
	return false;
}

main(){
	int n,i,j;
	double aux;
	vector<pair<double,int> > v;
	int cont = 1;
	while(cin >> n){
		for(i=0;i<10;i++){
			cin >> aux;
			v.push_back({aux,i});
		}
		sort(v.begin(),v.end(),verifica);
		cout << "Caso " << cont << ": ";
		for(i=0;i<n;i++){
			cout << v[i].second;
		}
		cout << endl;
		cont++;
		v.clear();
	}

}

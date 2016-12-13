#include <bits/stdc++.h>
using namespace std;

main(){
	int n;
	vector<pair<int, int> > v;
	pair<int,int> p;
	int a,b,cont=1,i;

	while(cin >> n && n>0){
		int maior = -10000;
		for(i=0;i<n;i++){
			cin >> a >> b;
			p.first = a;
			p.second = b;
			if(b > maior)
				maior = b;
			v.push_back(p);
		}
		bool print = false;
		cout << "Turma "  << cont << endl;
		for(i=0;i<n;i++){
			if(v[i].second==maior){
				//if(print)
				cout << v[i].first;
				cout << " ";
				//print = true;
			}
		}
		cout << endl << endl;
		cont++;
		v.clear();
	}
}
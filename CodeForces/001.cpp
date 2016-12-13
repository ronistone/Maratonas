#include <bits/stdc++.h>
using namespace std;

main(){

	int i,j,k,aux,pn,sn,n;
	int saida =0;
	vector<int> s,p,ps,ss,paux,saux;
	
	cin >> n >> pn >> sn;
	
	for(i=0;i<n;i++){
		cin >> aux;
		p.push_back(aux);
	}
	for(i=0;i<n;i++){
		cin >> aux;
		s.push_back(aux);
	}
	paux = p;
	saux = s;
	int pmax = 0;
	int smax = 0;
	for(i=0;i<ps.size();i++){
		if(ps[i]>ps[pmax])
			pmax = i;
	}
	for(i=0;i<ss.size();i++){
		if(ss[i]>ss[smax])
			smax = i;
	}
	while(ps.size()<pn){
		int posi=0;
		for(i=1;i<paux.size();i++){
			if(paux[i]>paux[posi] and paux[i]!=smax){
				posi = i;
			}
		}
		paux[posi] = INT_MIN;
		saux[posi] = INT_MIN;
		ps.push_back(posi+1);
		saida+=p[posi];
	}
	while(ss.size()<sn){
		int posi=0;
		for(i=1;i<saux.size();i++){
			if(saux[i]>saux[posi] and saux[i]!=pmax){
				posi = i;
			}
		}
		saux[posi]= INT_MIN;
		ss.push_back(posi+1);
		saida+=s[posi];
	}
	sort(ss.begin(),ss.end());
	sort(ps.begin(),ps.end());
	cout << saida << endl;
	for(i=0;i<ps.size();i++){
		if(i!=0)
			cout << " ";
		cout << ps[i];
	}
	cout << endl;
	for(i=0;i<ss.size();i++){
		if(i!=0)
			cout << " ";
		cout << ss[i];
	}
	cout << endl;
}

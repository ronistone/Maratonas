#include <bits/stdc++.h>

using namespace std;

bool verificamaior(int i,int j){return i>j;}
bool verificamenor(int i,int j){return i<j;}

main(){

	int n ,q,i;

	cin >> n;
	int aux;
	std::vector<int> impar,par;
	for(i=0;i<n;i++){
		cin >> aux;
		if(aux%2==0)
			par.push_back(aux);
		else
			impar.push_back(aux);
	}
	sort(impar.begin(),impar.end(),verificamaior);
	sort(par.begin(),par.end(),verificamenor);
	for(i=0;i<impar.size();i++){
		par.push_back(impar[i]);
	}
	for(i=0;i<n;i++){
		cout << par[i] << endl;
	}
}
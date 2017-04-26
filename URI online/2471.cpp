#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;

ll linhas[55];
ll colunas[55];
ll A[55][55];

main(){
	int n,aux,m;
	map<ll,int> x;
	map<ll,int>::iterator it;
	memset(linhas,0,sizeof(linhas));
	memset(colunas,0,sizeof(colunas));
	cin >> n;
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			cin >> A[i][j];
			linhas[i] += A[i][j];
			colunas[j] += A[i][j];
			if(i==n-1)
				x[colunas[j]]++;
			if(j==n-1)
				x[linhas[i]]++;
			
		}
	}
	int y;
	for(it = x.begin();it!=x.end();it++){
		if(it->second == 2){
			 y = it->first;
		}
		else{
			m = it->first;
		}
	}
	int l,c;
	for(int i=0;i<n;i++){
		if(linhas[i]==y)
			l = i;
		if(colunas[i] == y)
			c = i;
	}
	cout << A[l][c] - (y-m) << " " << A[l][c] << endl;
}

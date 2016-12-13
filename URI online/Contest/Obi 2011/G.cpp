#include <bits/stdc++.h>
using namespace std;

main(){
	ios_base::sync_with_stdio(0);
	int i,j,d = 0,n;
	cin >> n;
	map<long long int,bool> mapa;
	long long int M[n][n],l;
	bool falha = false;
	for(i=0;i<n;i++){
		for(j=0;j<n;j++){
			cin >> M[i][j];
			if(mapa[M[i][j]])
				falha = true;
			else
				mapa[M[i][j]] = true;
			if(i==j)
				d+=M[i][j];
		}
	}
	if(!falha){
		long long int c[n]; 
		memset(c,0,sizeof(c));
		for(i=0;i<n;i++){
			l = 0;
			for(j=0;j<n;j++){
				l+=M[i][j];
				c[j]+=M[i][j];
			}
			if(l!=d){
				falha = true;
				break;
			}
		}
		if(!falha){
			for(i=0;i<n;i++){
				if(c[i]!=d){
					falha = true;
					break;
				}
			}
		}
	}
	if(!falha)
		cout << d << endl;
	else
		cout << 0 << endl;
	
}

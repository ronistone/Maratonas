#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll wt[101],val[101];
int W,n;
ll knapSack(){
	ll K[n+1][W+1];
	
	for(int i=0;i<=n;i++){
		for(int j=0;j<=W;j++){
			if(i==0 or j==0)
				K[i][j]=0;
			else if(wt[i-1]<=j)
				K[i][j] = max(K[i-1][j],val[i-1]+K[i-1][j-wt[i-1]]);
			else
				K[i][j] = K[i-1][j];
		}
	}
	return K[n][W];
}



main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int i,j,z;
	ll hp;
	
	cin >> z;
	for(j=0;j<z;j++){
		cin >> n;
		for(i=0;i<n;i++){
			cin >> val[i] >> wt[i];
		}
		cin >> W;
		cin >> hp;
		if(knapSack()>=hp)
			cout <<  "Missao completada com sucesso\n";
		else
			cout << "Falha na missao\n";
	}
}

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll wt[101],val[101];
int W=50,n;
ll K[101][101];
void knapSack(){
	
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
}

void print_knapSack(){
	ll total_b = 0;
	ll total_w = 0;
	for(int i=n,j=W;i>0;i--){
		if(K[i][j] !=K[i-1][j]){
			total_w +=wt[i-1];
			total_b++;
			j-=wt[i-1];
		}
	}
	cout << K[n][W] << " brinquedos\n";
	cout << "Peso: " << total_w << " kg\n";
	cout << "sobra(m) " << n-total_b << " pacote(s)\n\n";

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
		knapSack();
		print_knapSack();
	}
}

#include <bits/stdc++.h>
using namespace std;

string e;
typedef long long int ll;
//ll dp[5000][5000][5000]
int A[5100][5100];
int ans[5100];

main(){
	int n;
	cin >> e;
	n = e.size();
	
	for(int i=0;i<n;i++){
		A[i][i] = 1;
		ans[1]++;
	}
	bool fail;
	for(int k=2;k<=n;k++){
		for(int i=2;i<n;i++){
			for(int j=0;j<n-i;j++){
				fail = false;
				for(int z=j;z<=(j+floor(i/2)) and !fail;z++)
					if(e[z]!=e[z+floor(i/2)])
						fail = true;
				if(fail){
					continue;
				}
				else if(A[j][j+((int)i/2)]>=k){
					ans[k]++;
					A[j][j+i-1] = k;
				}
			}
		}
	}
	for(int i=1;i<=n;i++){
		if(i!=1)
			cout << " ";
		cout << ans[i];
	}
	cout << endl;
	
	

}

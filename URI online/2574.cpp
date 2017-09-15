#include <bits/stdc++.h>
using namespace std;
typedef int ll;
ll M[2050][2050];

main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	ll n,g,sum,at;
	bool fail;
	memset(M,0,sizeof M);
	cin >> n >> g;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			cin >> M[i][j];
			if(i>1) M[i][j] += M[i-1][j];
			if(j>1) M[i][j] += M[i][j-1];
			if(i>1 and j>1) M[i][j] -= M[i-1][j-1];
		}
	}
	
	for(int z=1;z<=n;z*=2){
		sum = 0;
		fail = false;
		for(int i=0;i<n and !fail;i+=z){
			for(int j=0;j<n and !fail;j+=z){
				at = M[i+z][j+z];
				if(i>1) at -= M[i][j+z];
				if(j>1) at -= M[i+z][j];
				if(j>1 and i>1) at += M[i][j];
				if(at < g){
					fail = true;
					sum = 0;
				}
				else{
					sum++;
				}
				
			}
		}
		if(!fail)
			break;
	}
	cout << sum << endl;
}

#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;

main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	ll n,m,k,z;
	
	cin >> z;
	
	for(int q=0;q<z;q++){
		
		cin >> n >> m >> k;
		ll M[n][m];
		for(int i=0;i<n;i++){
			for(int j=0;j<m;j++){
				cin >> M[i][j];
				if(i>0) M[i][j] += M[i-1][j];
				if(j>0) M[i][j] += M[i][j-1];
				if(i>0 and j>0) M[i][j] -= M[i-1][j-1];
			}
		}
		
		
		ll ans = 10e17;
		ll xi=-1,yi=-1,xf=-1,yf=-1;
		for(int i=0;i<n;i++){
			for(int j=0;j<m;j++){
				for(int x=i;x<n;x++){
					for(int y=j;y<m;y++){
						ll at = M[x][y];
						
						if(i>0) at -= M[i-1][y];
						if(j>0) at -= M[x][j-1];
						if(j>0 and i>0) at += M[i-1][j-1];
						
						if(at <= k){
							ll dist_T = (xf-xi+1)*(yf-yi+1);
							ll dist_A = (x-i+1)*(y-j+1);
							if(dist_T < dist_A or (dist_T==dist_A and at <= ans)){
								ans = at;
								if(ans == at)
									xi=i; yi=j; xf=x; yf=y;
							}
						}
					}
				}
			}
		}
		if(xf==-1 or xi==-1 or yf==-1 or yi==-1)
			cout << "Case #" << q+1 << ": " << 0 << " " << 0 << endl;
		else
			cout << "Case #" << q+1 << ": " << (xf-xi+1)*(yf-yi+1) << " " << ans << endl;
	
	}


}

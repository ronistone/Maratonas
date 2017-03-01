#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;


main(){
	int n,m,q,t,i,j,k,ti,tj;
	bool ans;
	ll at;
	scanf("%d %d",&n,&m);
	ll A[n][m],aux;
	
	
	for(i=0;i<n;i++){
		for(j=0;j<m;j++){
			scanf("%lld",&aux);
			aux==0? A[i][j]=0:A[i][j]=1;
			if(i>0) A[i][j] += A[i-1][j];
			if(j>0) A[i][j] += A[i][j-1];
			if(i>0 and j>0) A[i][j] -= A[i-1][j-1];
		}
		
	}
	scanf("%d",&q);
	for(k=0;k<q;k++){
		scanf("%d",&t);
		
		ans = false;
		for(i=0;i<n;i++){
			ti = i+t-1;
			if(ti>=n) break;
			at = 0;
			for(j=0;j<m;j++){
				tj = j+t-1;
				if(tj>=m) break;
				at = A[ti][tj];
				if(i>0) at -= A[i-1][tj];
				if(j>0) at -= A[ti][j-1];
				if(i>0 and j>0) at += A[i-1][j-1];
				if(at==t*t){ans = true; break;}
			}
			if(ans) break;
		}
		
		if(ans)
			printf("yes\n");
		else
			printf("no\n");
	}
	
}

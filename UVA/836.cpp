#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;

main(){
	int n,m,z;
	char S[50][50];
	ll M[50][50];
	scanf("%d",&z);
	char lixo[1000];
	gets(lixo);
	gets(lixo);
	for(int k=0;k<z;k++){
		n = 0;
		while(gets(S[n])){
			if(strlen(S[n])==0){
				//getchar();
				break;
			}
			m = strlen(S[n]);
			for(int i=0;i<m;i++){
				M[n][i] = S[n][i]=='0'? -10e15:(int)S[n][i] - '0';
				
				if(n>0) M[n][i] += M[n-1][i];
				if(i>0) M[n][i] += M[n][i-1];
				if(n>0 and i>0) M[n][i] -= M[n-1][i-1];
			}
			n++;
		}
		ll ans = -10e10;
		for(int i=0;i<n;i++){
			for(int j=0;j<m;j++){
					for(int x=i;x<n;x++){
						for(int y=j;y<m;y++){
							ll at = M[x][y];
							if(i>0) at -= M[i-1][y];
							if(j>0) at -= M[x][j-1];
							if(i>0 and j>0) at += M[i-1][j-1];
							ans = max(at,ans);
						}
					}
			}
		}
		if(k!=0)
			cout << endl;
		if(ans<0)
			cout << 0 << endl;
		else
			cout << ans << endl;
	}

}

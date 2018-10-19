#include<bits/stdc++.h>
using namespace std;

typedef int llu;
llu eu, opo;

llu mod = 1e9 +7; //1000000007;

llu mat[2100][2100], mat2[2100][2100], K, M;
llu dp(llu x, llu y){
	//cout << x << " " << y << endl;
	
	if(mat[x][y]!=0) return mat[x][y];
	if(x==1 && y==0) return mat[x][y] = 1;
	
	llu p1=0, p2=0;
	if(x>1 && x-1>y) p1 = dp(x-1, y) % mod;
	if(y>0) p2 = dp(x, y-1) % mod;
	
	return mat[x][y] = (p1+p2)%mod;
}

llu dp2(llu x, llu y){
	if(mat2[x][y]!=0) return mat2[x][y];
	if(x==1 && y == 0) return mat2[x][y] = 1;
	
	llu p1 = 0, p2 = 0;
	
	if(x>y) p1 = dp2(x-1, y)%mod;
	if(y>0) p2 = dp2(x, y-1)%mod;
	
	return mat2[x][y] = (p1+p2)%mod;
}


int main()
{
	int t, casos = 1;
	cin >> t;
	
	
	
	mat[1][0] = 1;
	mat2[1][0] = 1;
	
	while(t--){
		
		cin >> eu;
		cin.ignore();
		cin >> opo;
		//scanf("%l64-%l64d", &eu, &opo);
		//cout << eu << " --- " << opo << endl;
		
		cout << "Case #" << casos << ": " << dp(eu, opo) << " " << dp2(opo, eu) << endl;		
		//printf("Case #%d: %l64d %l64d\n", casos, dp(eu, opo), dp2(opo,opo-1));
		casos++;
	}
}

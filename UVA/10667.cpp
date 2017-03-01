#include <bits/stdc++.h>
using namespace std;
#define pb push_back


typedef long long int ll;

typedef struct no{
	no(ll a,ll b,ll c,ll d){
		 r1=a; c1=b; r2=c; c2=d;
	}
	ll r1,c1,r2,c2;
	bool cont(int x, int y){
		if(x>=r1 and x<=r2 and y>=c1 and y<=c2) return true;
		return false;
	}
}block;
typedef vector<block> vb;


main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	ll M[200][200];
	ll n,m,s,b,z,r1,c1,r2,c2;
	vb blocks;
	cin >> z;
	
	for(int k=0;k<z;k++){
	
		cin >> s >> b;
		
		for(int i=0;i<b;i++){
			cin >> r1 >> c1 >> r2 >> c2;
			//if(k==25)
				//cout << r1 << "   " << c1 << "   " << r2 << "   " << c2 << endl;
			blocks.pb(block(r1-1,c1-1,r2-1,c2-1));
		}
		
		for(int i=0;i<s;i++){
			for(int j=0;j<s;j++){
				M[i][j] = 1LL;
				for(int l =0;l<blocks.size();l++){
					if(blocks[l].cont(i,j)){
						M[i][j] = -10e10;
						break;
					}	
				}
				if(i>0) 		M[i][j] += M[i-1][j];
				if(j>0) 		M[i][j] += M[i][j-1];
				if(i>0 and j>0) M[i][j] -= M[i-1][j-1];
			}
		}
		ll ans = -10e11;
		for(int i=0;i<s;i++){
			for(int j=0;j<s;j++){
				for(int x=i;x<s;x++){
					for(int y=j;y<s;y++){
						ll at = M[x][y];
						if(i>0)			at -= M[i-1][y];
						if(j>0)			at -= M[x][j-1];
						if(i>0 and j>0) at += M[i-1][j-1];
						ans = max(at,ans);
					}
				}
			}
		}
		if(ans < 0)
			cout << 0 << endl;
		else
			cout << ans << endl;
		//if(k==25)
			//cout << ans << endl;
		
		blocks.clear();
	}
	
}

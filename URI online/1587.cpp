#include <bits/stdc++.h>
using namespace std;

#define A 0
#define B 1
#define N 2000001

int BIT[2][N+10];
int a[2552000],b[2552000];

int query(int team,int i){
	int ans = 0;
	for(;i>0;i-=(i&(-i)))
		ans += BIT[team][i];
	return ans;
}
void update(int team,int i,int value){
	for(;i<=N;i+=(i&(-i)))
		BIT[team][i]+=value;
}

main(){
	
	int n,q,ans1,ans2,x,y,aux;
	bool impedimento;
	char e,z;
	
	while(cin >> n >> q and (n or q)){
			ans1 = 0;
			ans2 = 0;
			impedimento = false;
			memset(BIT,0,sizeof BIT);
			for(int i=1;i<=n/2;i++){
				cin >> a[i];a[i]++;
				update(A,a[i],1);
			}
			for(int i=1;i<=n/2;i++){
				cin >> b[i];b[i]++;
				update(B,b[i],1);
			}
			for(int i=0;i<q;i++){
				cin >> e;
				if(e=='I' or e=='P'){
					cin >> z >> x;
					if(z=='A'){
						aux = query(B,N) - query(B,a[x]);
						if((double)aux/n < 2.0/11.0)
							impedimento = true;
					}
					else if(z=='B'){
						aux = query(A,b[x]-1);
						if((double)aux/n < 2.0/11.0)
							impedimento = true;
					}
				}
				else if(e=='M'){
					cin >> e >> x >> y;y++;
					if(e=='A'){
						update(A,a[x],-1);
						update(A,y,1);
						a[x] = y;
					}
					else if(e=='B'){
						update(B,b[x],-1);
						update(B,y,1);
						a[x] = y;
					}
				}
				else if(e=='G'){
					cin >> e;
					if(e=='A' and !impedimento)
						ans2++;
					else if(e=='B' and !impedimento)
						ans1++;
					impedimento = false;
				}
				else if(e=='S'){
					impedimento = false;
				}
			}
			cout << ans1 << " X " << ans2 << endl;
	}
}

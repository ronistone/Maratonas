#include <bits/stdc++.h>
using namespace std;
#define F first
#define S second
#define pb push_back
#define mp make_pair


typedef long long int ll;
typedef pair<ll,ll> ii;
typedef pair<ll,ii> iii;
typedef vector<iii> viii;

viii matriz;
int n,m;
unordered_map<int,ii> P;

void mapear(){
	P[0] = mp(0,0);
	P[1] = mp(0,1);
	P[2] = mp(0,2);
	P[3] = mp(0,3);
	P[4] = mp(0,4);
	P[5] = mp(1,0);
	P[6] = mp(1,1);
	P[7] = mp(1,2);
	P[8] = mp(1,3);
	P[9] = mp(1,4);
	P[10] = mp(2,0);
	P[11] = mp(2,1);
	P[12] = mp(2,2);
	P[13] = mp(2,3);
	P[14] = mp(2,4);
	P[15] = mp(3,0);
	P[16] = mp(3,1);
	P[17] = mp(3,2);
	P[18] = mp(3,3);
	P[19] = mp(3,4);
	P[20] = mp(4,0);
	P[21] = mp(4,1);
	P[22] = mp(4,2);
	P[23] = mp(4,3);
	P[24] = mp(4,4);
}



main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int z;
	mapear();
	ll x,y,v;
	cin >> z;
	
	for(int k=0;k<z;k++){
			cin >> n;
			
			for(int i=0;i<n;i++){
					cin >> x >> y >> v;
					matriz.pb(mp(v,mp(x,y)));
			}
			ll ans[] = {0,1,2,3,4};
			ll minimo = 1000000000;
			for(int a=0;a<21;a++){
				for(int b=a+1;b<22;b++){
					for(int c=b+1;c<23;c++){
						for(int d=c+1;d<24;d++){
							for(int e=d+1;e<25;e++){
								ll v1=0,v2=0,v3=0,v4=0,v5=0;
								ll dist_sum = 0;
								for(int i=0;i<matriz.size();i++){
									v1 = (abs(P[a].F-matriz[i].S.F)+abs(P[a].S-matriz[i].S.S));
									v2 = (abs(P[b].F-matriz[i].S.F)+abs(P[b].S-matriz[i].S.S));
									v3 = (abs(P[c].F-matriz[i].S.F)+abs(P[c].S-matriz[i].S.S));
									v4 = (abs(P[d].F-matriz[i].S.F)+abs(P[d].S-matriz[i].S.S));
									v5 = (abs(P[e].F-matriz[i].S.F)+abs(P[e].S-matriz[i].S.S));
									ll temp = min(v1,min(v2,min(v3,min(v4,v5))));
									temp *= matriz[i].F;
									dist_sum+=temp;
								}
								if(dist_sum < minimo){
										minimo = dist_sum;
										ans[0] = a;
										ans[1] = b;
										ans[2] = c;
										ans[3] = d;
										ans[4] = e;
								}
							}
						}
					}
				}
			}
			cout << ans[0];
			for(int i=1;i<5;i++){
					cout << " " << ans[i];
			}
			cout << endl;
			matriz.clear();
	}
	
}

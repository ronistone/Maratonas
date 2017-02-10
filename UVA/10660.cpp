#include <bits/stdc++.h>
using namespace std;
#define mp make_pair
#define pb push_back
#define F first
#define S second

typedef long long int ll;
typedef pair<ll,ll> ii;
typedef pair<ll,ii> iii;
typedef vector<iii> viii;
typedef vector<ii> vii;
typedef vector<ll> vi;

viii matriz;

map<int,ii> posi;
void mapear(){
	posi[0] = mp(0,0);
	posi[1] = mp(0,1);
	posi[2] = mp(0,2);
	posi[3] = mp(0,3);
	posi[4] = mp(0,4);
	posi[5] = mp(1,0);
	posi[6] = mp(1,1);
	posi[7] = mp(1,2);
	posi[8] = mp(1,3);
	posi[9] = mp(1,4);
	posi[10] = mp(2,0);
	posi[11] = mp(2,1);
	posi[12] = mp(2,2);
	posi[13] = mp(2,3);
	posi[14] = mp(2,4);
	posi[15] = mp(3,0);
	posi[16] = mp(3,1);
	posi[17] = mp(3,2);
	posi[18] = mp(3,3);
	posi[19] = mp(3,4);
	posi[20] = mp(4,0);
	posi[21] = mp(4,1);
	posi[22] = mp(4,2);
	posi[23] = mp(4,3);
	posi[24] = mp(4,4);
}
ll va,vb,vc,vd,ve;
ll minimo;

void calcula(ll a, ll b, ll c, ll d, ll e){
	ll ans = 0, m1 = 100000000,m2=100000000,m3=100000000,m4=100000000,m5=100000000;
	ll ta,tb,tc,td,te,dist;
	//ii temp = posi[a];
	for(int i=0;i<matriz.size();i++){
		//printf("%lld %lld %lld %lld %lld\n",a,b,c,d,e);
		//cout << matriz[i].F << "  : (" << matriz[i].S.F << "," << matriz[i].S.S << ")\n";
		//dist
		m1 = min(m1,(abs(posi[a].F-matriz[i].S.F)+abs(posi[a].S-matriz[i].S.S))*matriz[i].F);
		//m1 = max(m1,dist);
		//m1 += dist;
		//dist
		m2 = min(m2,(abs(posi[b].F-matriz[i].S.F)+abs(posi[b].S-matriz[i].S.S))*matriz[i].F);
		//m2 = max(m2,dist);
		//m2 += dist;
		//dist
		m3 = min(m3,(abs(posi[c].F-matriz[i].S.F)+abs(posi[c].S-matriz[i].S.S))*matriz[i].F);
		//m3 = max(m3,dist);
		//m3 += dist;
		//dist
		m4 = min(m4,(abs(posi[d].F-matriz[i].S.F)+abs(posi[d].S-matriz[i].S.S))*matriz[i].F);
		//m4 = max(m4,dist);
		//m4 += dist;
		//dist
		m5 = min(m5,(abs(posi[e].F-matriz[i].S.F)+abs(posi[e].S-matriz[i].S.S))*matriz[i].F);
		//m5 = max(m5,dist);
		//m5 += dist;
	}
	ans = m1 + m2 + m3 + m4 + m5;
	/*
	temp = posi[b];
	for(int i=0;i<matriz.size();i++){
		ll dist = (abs(temp.F-matriz[i].S.F)+abs(temp.S-matriz[i].S.S))*matriz[i].F;
		mini = max(mini,dist);
	}
	ans += mini;
	temp = posi[c];
	for(int i=0;i<matriz.size();i++){
		ll dist = (abs(temp.F-matriz[i].S.F)+abs(temp.S-matriz[i].S.S))*matriz[i].F;
		mini = max(mini,dist);
	}
	ans += mini;
	temp = posi[d];
	for(int i=0;i<matriz.size();i++){
		ll dist = (abs(temp.F-matriz[i].S.F)+abs(temp.S-matriz[i].S.S))*matriz[i].F;
		mini = max(mini,dist);
	}
	ans += mini;
	temp = posi[e];
	for(int i=0;i<matriz.size();i++){
		ll dist = (abs(temp.F-matriz[i].S.F)+abs(temp.S-matriz[i].S.S))*matriz[i].F;
		mini = max(mini,dist);
	}
	ans += mini;
	*/
	if(minimo > ans){
		minimo = ans;
		va = a;
		vb = b;
		vc = c;
		vd = d;
		ve = e;
	}
}

main(){
	mapear();
	ll n,z,x,y,v;
	
	cin >> z;
	
	for(int k=0;k<z;k++){
			cin >> n;
			minimo = 100000000;
			va = 0;
			vb = 1;
			vc = 2;
			vd = 3;
			ve = 4;
			for(int i=0;i<n;i++){
					cin >> x >> y >> v;
					matriz.pb(mp(v,mp(x,y)));
			}
			for(int a=0;a<21;a++){
				for(int b=a+1;b<22;b++){
					for(int c=b+1;c<23;c++){
						for(int d=c+1;d<24;d++){
							for(int e=d+1;e<25;e++){
								calcula(a,b,c,d,e);
							}
						}
					}
				}
			}
			printf("%lld %lld %lld %lld %lld\n",va,vb,vc,vd,ve);
			matriz.clear();
	}
}

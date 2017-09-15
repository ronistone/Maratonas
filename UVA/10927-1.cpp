#include <bits/stdc++.h>
using namespace std;

#define EPS 10e-11
#define F first
#define S second
#define pb push_back
#define mp make_pair

typedef long long int ll;
struct point{
	ll x,y,z;
	point(){}
	point(ll a, ll b, ll c): x(a), y(b), z(c){}
	point(ll a, ll b): x(a), y(b){}
	bool operator <(point other);
};
struct vec{
	ll x,y;
	vec(){}
	vec(ll a, ll b): x(a), y(b){}
};

point o = point(0,0,0);
vector<point> ans;
point P[100010];

inline bool cmp(point a, point b){
	return (a.x==b.x)? a.y<b.y:a.x<b.x;
}


inline vec toVec(point a, point b){
	return vec(b.x-a.x,b.y-a.y);
}

inline ll cross(vec a, vec b){
	return a.x*b.y - a.y*b.x;
}


inline bool same(vec a, vec b){
	return cross(a,b) == 0;
}


inline ll dist(point a, point b){
	return (a.x - b.x)*(a.x - b.x) + (a.y - b.y)*(a.y - b.y);
}

bool point::operator <(point other){
		if(same(toVec(o,*this),toVec(o,other)))
			return dist(*this,o) < dist(other,o);
		else
			return this->x*other.y < this->y*other.x;
}


main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n,cont = 1;
	while(cin >> n and n){
		ans.clear();
		for(int i=0;i<n;i++){
			cin >> P[i].x >> P[i].y >> P[i].z;
		}
		sort(P,P+n);
		
		ll maxZ = P[0].z,atZ;
		point maxP = P[0];
		for(int i=1;i<n;i++){
			if(same(toVec(o,maxP),toVec(o,P[i]))){
				if(P[i].z <= maxZ){
						ans.pb(P[i]);
				}
				else{
					maxZ = P[i].z;
				}
			}
			else{
				maxZ = P[i].z;
				maxP = P[i];
			}
		}
		
		sort(ans.begin(),ans.end(),cmp);
		cout << "Data set " << cont++ << ":" << endl;
		if(!ans.size())
			cout << "All the lights are visible." << endl;
		else{
			cout << "Some lights are not visible:" << endl;
			for(int i=0;i<ans.size();i++){
				cout << "x = " << ans[i].x << ", y = " << ans[i].y << (i==ans.size()-1?".":";")<< endl;
			}
		}
	}
	
}

#include <bits/stdc++.h>
using namespace std;
#define PI 3.141592653589793115997963468544185161590576171875
#define F first
#define S second
#define EPS 10e-10

typedef long long int ll;
struct point{
	double x,y,z;
	point(){}
	point(double _x, double _y, double _z): x(_x), y(_y), z(_z){}
	point(double _x, double _y): x(_x), y(_y){}
	inline bool operator <(point b){ return this->x==b.x? this->y<b.y:this->x < b.x;}
};
struct vec{
	double x,y;
	vec(){}
	vec(double _x, double _y): x(_x), y(_y){}
};
inline bool cmp(pair<pair<double,int>,int> a, pair<pair<double,int>,int> b){
	if(fabs(a.F.F - b.F.F) < EPS){
		if(a.F.S == b.F.S) return a.S < b.S;
		else 			   return a.F.S < b.F.S;
	}
	else
		return a.F.F < b.F.F;
}

point P[100100],o = point(0,0,0);
pair<pair<double,ll>,int> dist[100100];
vector<point> ans;
map<ll,vector<int> > M;
map<ll,vector<int> >::iterator it;

inline vec toVec(point a, point b){ return vec(b.x-a.x,b.y-a.y); }
inline double dot(vec a, vec b){ return (a.x*b.x + a.y*b.y); }
inline double norm_sq(vec a){ return (a.x*a.x+a.y*a.y); }
inline double dista(point a, point b){ return sqrt((b.x-a.x)*(b.x-a.x)+(b.y-a.y)*(b.y-a.y)); }

inline double angle(point a){
	vec oa  = toVec(o,a);
	vec oa1 = toVec(o,point(1000000.0,0.0));
	return acos(dot(oa,oa1)/sqrt(norm_sq(oa) * norm_sq(oa1)));
}
inline double cross(vec a, vec b){ return a.x*b.y - a.y*b.x; }
inline bool collinear(point a,point b,point c){ return cross(toVec(a,b),toVec(a,c)) < EPS;}

main(){
	int n;
	ll at,idx;
	int cont = 1;
	P[0] = point(12345678,87654321,0);
	while(cin >> n and n){
		M.clear();
		ans.clear();
		for(int i=1;i<=n;i++){
			cin >> P[i].x >> P[i].y >> P[i].z;
			if(P[i].y > 0) dist[i] = make_pair(make_pair(dista(o,P[i]),(ll)((360.0 - (angle(P[i])*(180.0/PI)))*10000000)),i);
			else 		   dist[i] = make_pair(make_pair(dista(o,P[i]),(ll)((angle(P[i])*(180.0/PI))*10000000)),i);
		}
		sort(dist+1,dist+n+1,cmp);
		for(int i=1;i<=n;i++){
			M[dist[i].F.S].push_back(dist[i].S);
		}
		for(it=M.begin();it!=M.end();it++){
			at = 0;
			idx = 0;
			for(int i=0;i<it->second.size();i++){
				if(idx and at >= P[it->second[i]].z and collinear(o,P[it->second[i]],P[idx])) ans.push_back(P[it->second[i]]);
				else{ at = P[it->second[i]].z; idx = it->second[i];}
			}
		}
		sort(ans.begin(),ans.end());
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


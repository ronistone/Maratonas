#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;

struct point{
	ll x,y;
	point(){}
	point(ll a, ll b): x(a), y(b) {}
	inline bool operator <(point b) const{
		if(this->x==b.x) return this->y > b.y;
		return this->x < b.x;
	}
};
struct vec{
	ll x,y;
	vec(){}
	vec(point a, point b){
		x = b.x - a.x;
		y = b.y - a.y;
	}
};

inline ll cross(vec a, vec b){
	return a.x*b.y - a.y*b.x;
}
inline double cross(point o, point a, point b){
	return (a.x - o.x) * (b.y - o.y) - (a.y - o.y) * (b.x - o.x);
}


main(){
	vector<point> P;
	int n,x,y;
	cin >> n;
	
	for(int i=0;i<n;i++){
		cin >> x >> y;
		P.push_back(point(x,y));
	}
	
	sort(P.begin(),P.end());
	vector<point> ans(2*n);
	int k = 0;
	for(int i=0;i<n;i++){
		while(k>=2 and cross(ans[k-2],ans[k-1],P[i]) >= 0) k--;
		ans[k++] = P[i];
	}
	cout << k-1 << endl;
}

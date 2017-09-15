#include <bits/stdc++.h>
using namespace std;

#define DEG_TO_RAD(a) (a*(M_PI/180.0))
#define pb push_back
#define EPS 10e-7

struct point{
	double x,y;
	point(){}
	point(double a, double b): x(a), y(b) {}
};
struct ret{
	point a,b,c,d;
	ret(point x, point y, point z, point w): a(x), b(y), c(z), d(w){}
};

inline point rotate(point p, double ang){
	ang = (ang*(M_PI/180.0));
	return point(p.x * cos(ang) - p.y * sin(ang),
				 p.x * sin(ang) + p.y * cos(ang));
}
inline double cross(point o, point a, point b){
	return (a.x - o.x) * (b.y - o.y) - (a.y - o.y) * (b.x - o.x);
}
vector<point> P;

inline bool cmp(point a, point b){
	return fabs(a.x-b.x) < EPS? a.y < b.y:a.x < b.x;
}

inline vector<point> convex_hull(){
	vector<point> ans(2*P.size());
	int k = 0;
	sort(P.begin(),P.end(),cmp);
	
	for(int i=0;i<P.size();i++){
		while(k >=2 and cross(ans[k-2],ans[k-1],P[i]) <= EPS) k--;
		ans[k++] = P[i];
	}
	
	for(int i=P.size()-2, t = k+1; i>=0; i--){
		while(k>=t and cross(ans[k-2],ans[k-1],P[i]) <= EPS) k--;
		ans[k++] = P[i];
	}
	ans[k] = ans[0];
	ans.resize(k);
	return ans;
}
inline double area(vector<point> poli){
	double ans = 0.00000000;
	for(int i=0;i<poli.size()-1;i++){
		ans += (poli[i].x*poli[i+1].y - poli[i+1].x*poli[i].y);
	}
	return fabs(ans)/2.000;
}	


main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int z,n;
	point p;
	double w,h,a,h1,w1,ans,retA;
	cin >> z;
	
	for(int k=0;k<z;k++){
		cin >> n;
		retA = 0.0000000;
		P.clear();
		for(int i=0;i<n;i++){
			cin >> p.x >> p.y >> w >> h >> a;
			w1 = w/2.0;
			h1 = h/2.0;
			a = 360.0 - a;
			ret aux = ret(rotate(point(-w1,h1),a), rotate(point(w1,h1),a),
						  rotate(point(-w1,-h1),a), rotate(point(w1,-h1),a));
			aux.a.x += p.x;
			aux.a.y += p.y;
			aux.b.x += p.x;
			aux.b.y += p.y;
			aux.c.x += p.x;
			aux.c.y += p.y;
			aux.d.x += p.x;
			aux.d.y += p.y;
			P.pb(aux.a);
			P.pb(aux.b);
			P.pb(aux.c);
			P.pb(aux.d);
			retA += w*h;
		}
		
		
		cout << fixed << setprecision(1) << ((retA/area(convex_hull()))*100) << " %" << endl;
		
		
		
	}
}

#include <bits/stdc++.h>
using namespace std;

#define EPS 10e-10

struct point{
	double x,y,z;
	point(){}
	point(double a, double b, double c): x(a), y(b), z(c){}
	inline bool operator <(point b) const {
		return fabs(this->x-b.x) < EPS? this->y < b.y: this->x < b.x;
	}
};
struct vec{
	double x,y,z;
	vec(){}
	vec(double a, double b, double c): x(a), y(b), z(c){}
};

vector<point> P;

inline vec toVec(point a, point b){
	return vec(b.x-a.x, b.y-a.y, b.z-a.z);
}
inline double cross(point o, point a, point b){
	return (a.x-o.x) * (b.y-o.y) - (a.y-o.y) * (b.x-o.x);
}
inline vec scaled(vec v, double u){
	return vec(v.x*u,v.y*u,v.z*u);
}
inline point translate(point a, vec v){
	return point(a.x+v.x,a.y+v.y,a.z+v.z);
}

inline vector<point> convex(){
	vector<point> ans(2*P.size());
	
	int k=0;
	sort(P.begin(),P.end());
	
	for(int i=0;i<P.size();i++){
		while(k>=2 and cross(ans[k-2],ans[k-1],P[i]) <= EPS) k--;
		ans[k++] = P[i];
	}
	
	for(int i=P.size()-2, t = k+1; i>=0;i--){
		while(k>=t and cross(ans[k-2],ans[k-1],P[i]) <= EPS) k--;
		ans[k++] = P[i];
	}
	ans[k] = ans[0];
	ans.resize(k);
	
	return ans;	
}

inline double area(vector<point> C){
	double ans = 0.0;
	
	for(int i=0;i<C.size()-1;i++){
		ans += (C[i].x * C[i+1].y - C[i].y * C[i+1].x);
	}
	return fabs(ans)/2.0;
}

main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	vec at;
	point pa,ini;
	double u;
	int n;
	
	
	while(cin >> n and n){
		cin >> ini.x >> ini.y >> ini.z;
		P.clear();
		for(int i=0;i<n;i++){
			cin >> pa.x >> pa.y >> pa.z;
			at = toVec(ini,pa);
			u = - ini.z/at.z;
			P.push_back(translate(ini,scaled(at,u)));
		}
		
		cout << fixed << setprecision(2) << area(convex()) << endl;
	}

}

#include <bits/stdc++.h>
using namespace std;

#define EPS 10e-6

struct point{
	double x,y;
	inline bool operator < (point v){ return this->x==v.x? this->y > v.y: this->x < v.x; }
	point(){}
	point(double _x, double _y): x(_x), y(_y){}
};
struct line{
	double a,b,c;
};

inline line toLine(point a, point b){
	line l;
	if(fabs(a.x-b.x) < EPS){
		l.a = 1.0; l.b = 0.0; l.c = -a.x;
	}
	else{
		l.a = -(double)(a.y-b.y)/(a.x - b.x);
		l.b = 1.0;
		l.c = -(double)(l.a*a.x) - a.y;
	}
	return l;
}
inline double dist(point a, point b){ return sqrt((b.x-a.x)*(b.x-a.x) + (b.y-a.y)*(b.y-a.y)); }
inline bool areParallel(line a, line b){ return (fabs(a.a-b.a) < EPS and fabs(a.b-b.b) < EPS); }
inline bool intersect(line a, line b, point *p){
	if(areParallel(a,b)) return false;
	
	(*p).x = (b.b*a.c - a.b*b.c)/ (b.a*a.b - a.a*b.b);
	
	if(fabs(a.b) > EPS) (*p).y = -(a.a * (*p).x + a.c);
	else				(*p).y = -(b.a * (*p).x + b.c);
	return true;
}




main(){
	int c,n;
	point P[105];
	cin >> c;
	
	for(int k=0;k<c;k++){
		
		cin >> n;
		
		for(int i=0;i<n;i++)
			cin >> P[i].x >> P[i].y;
		sort(P,P+n);
		
		point at = P[n-1],aux;
		int idx = n-1;
		double ans = 0.0;
		for(int i=n-2;i>=0;i--){
			if(P[i].y > at.y){
				if(idx == i+1)
					ans += dist(at,P[i]);
				else{
					intersect(toLine(point(-10,at.y),at), toLine(P[i],P[i+1]),&aux);
					ans += dist(point(aux.x,at.y),P[i]);
				}
				at = P[i];
			}
		}
		cout << fixed  << setprecision(2) << ans << endl;
	}
}

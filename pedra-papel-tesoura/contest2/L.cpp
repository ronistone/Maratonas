#include <bits/stdc++.h>
using namespace std;

#define EPS 10e-3
#define M_PI 3.14159265358979323846

struct Point{
	double x, y;
	Point(){}
	Point(double _x, double _y): x(_x), y(_y){}
};

struct Query{
	double ang;
	int dist;
	int n;
	Query(){}
};

inline Point scaled(Point v, double s){
	return Point(v.x*s, v.y*s);
}
inline Point translate(Point p, Point v){
	return Point(p.x+v.x, p.y+v.y);
}
inline Point rotate(Point p, double ang){
	ang = ang*(3.14159265358979323846/180.0);
	return Point(
		p.x * cos(ang) - p.y * sin(ang),
		p.x * sin(ang) + p.y * cos(ang)
	);
}
inline double norm_sq(Point v){
	return (v.x*v.x + v.y*v.y);
}
inline double dot(Point a, Point b){
	return (a.x*b.x + a.y*b.y);
}

inline double angle(Point a, Point o, Point b){
	Point oa = Point(a.x-o.x,a.y-o.y), ob = Point(b.x-o.x,b.y-o.y);
	return acos(dot(oa,ob)/sqrt(norm_sq(oa)*norm_sq(ob)));
}
inline double diff(double ang){
	int n = ang/360;
	return ang - (360*n);
}

int main(){
	Point p1(0,0), p2(0,1), vet(0,1);
	double ang = 0;
	Query query;
	
	
	while(scanf("rotacione %lf ande %d repita %d", &query.ang, &query.dist, &query.n)!=EOF){
		setbuf(stdin,NULL);
		for(int i=0;i<query.n;i++){
			vet = Point(0,1);
			p2 = Point(0,1);
			p2 = rotate(p2, -diff(ang+query.ang));
			p2 = scaled(p2, query.dist);
			p1 = translate(p1, p2);
			
			ang += query.ang;
			
		}
		
	}
	
	if(fabs(p1.x) < EPS)
		p1.x = 0;
	if(fabs(p1.y) < EPS)
		p1.y = 0;
	
	cout << fixed << setprecision(2) << p1.x << " " << p1.y << endl;
	
}

#include <bits/stdc++.h>
using namespace std;

#define EPS 10e-8

struct point{
	double x,y;
	point(){}
	point(double _x, double _y): x(_x), y(_y){}
	inline bool operator < (point b) { return this->x==b.x? this->y < b.y:this->x < b.x;}
};
struct vec{
	double x,y;
	vec(){}
	vec(double _x, double _y): x(_x), y(_y){}
};
struct line{
	double a,b,c;
	line(){}
	line(double _a, double _b, double _c): a(_a), b(_b), c(_c){}
};

inline line   toLine(point a, point b){
	line l;
	
	if(fabs(a.x - b.x) < EPS){
		l.a = 1.0; l.b = 0.0; l.c = -a.x;
	}
	else{
		l.a = -(double)(a.y-b.y)/(a.x - b.x);
		l.b = 1.0;
		l.c = -(double)(l.a*a.x) - a.y;
	}
	return l;
}
inline vec    toVec(point a, point b){ return vec(b.x-a.x,b.y-a.y); }
inline double dist(point a, point b){ return sqrt((a.x-b.x)*(a.x-b.x) + (a.y-b.y)*(a.y-b.y)); }
inline double cross(vec a,vec b){ return a.x*b.y - a.y*b.x; }
inline bool	  collinear(point a, point b, point c){ return fabs(cross(toVec(a,b),toVec(a,c))) < EPS;}
inline double dot(vec a, vec b){ return a.x*b.x + a.y*b.y; }
inline double norm_sq(vec v){ return v.x*v.x + v.y*v.y; }
inline point  translate(point a, vec v){ return point(a.x + v.x, a.y + v.y); }
inline vec	  scaled(vec v, double u){ return vec(v.x*u,v.y*u); }
inline bool	  areParallel(line a, line b){ return (fabs(a.a-b.a) < EPS and fabs(a.b-b.b) < EPS); }
inline double distToSegment(point p,point a, point b){
	vec ap = toVec(a,p);
	vec ab = toVec(a,b);
	
	double u = dot(ap,ab)/ norm_sq(ab);
	
	if(u < 0)
		return dist(p,a);
	else if(u > 1)
		return dist(p,b);
	else
		return dist(p,translate(a,scaled(ab,u)));
}
inline bool intersect(line a, line b, point *p){
	if(areParallel(a,b)) return false;
	
	(*p).x = (b.b*a.c - a.b*b.c)/(b.a*a.b - a.a*b.b);
	if(fabs(a.b) > EPS) (*p).y = -(a.a * (*p).x + a.c);
	else 				(*p).y = -(b.a * (*p).x + b.c);

	return true;
}

int main(){
	
	point P[8];
	
	for(int i=1;i<8;i++){
		cin >> P[i].x >> P[i].y;
	}
	if(!(dot(toVec(P[1],P[2]),toVec(P[1],P[3])) > EPS)){
		cout << "N" << endl;
		return 0;
	}
	if(!(fabs(dist(P[1],P[2]) - dist(P[1],P[3])) < EPS and fabs(dist(P[4],P[6]) - dist(P[5],P[7])) < EPS)){
		cout << "N" << endl;
		return 0;
	}
	if(!(collinear(P[2],P[3],P[4]) and collinear(P[2],P[3],P[5]))){
		cout << "N" << endl;
		return 0;
	}
	if(!(fabs((P[2].x+P[3].x)/2.0 - (P[4].x+P[5].x)/2.0) < EPS and fabs((P[2].y+P[3].y)/2.0 - (P[4].y+P[5].y)/2.0) < EPS)){
		cout << "N" << endl;
		return 0;
	}
	if(!(dist(P[2],P[3]) > dist(P[4],P[5]))){
		cout << "N" << endl;
		return 0;
	}
	if(!(fabs(dot(toVec(P[4],P[6]),toVec(P[2],P[3]))) < EPS and fabs(dot(toVec(P[5],P[7]),toVec(P[2],P[3]))) < EPS )){
		cout << "N" << endl;
		return 0;
	}
	point aux;
	if(!(intersect(toLine(P[1],P[6]),toLine(P[2],P[3]),&aux) and fabs(distToSegment(aux,P[1],P[6])) < EPS and fabs(distToSegment(aux,P[2],P[3])) < EPS)){
		cout << "N" << endl;
		return 0;
	}
	
	cout << "S" << endl;
}

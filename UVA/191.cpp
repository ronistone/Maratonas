#include <bits/stdc++.h>
using namespace std;

#define EPS 10e-7

struct point{
	double x,y;
	point(double _x, double _y): x(_x), y(_y) {}
	point(){}
};
struct vec{
	double x,y;
	vec(double _x, double _y): x(_x), y(_y) {}
	vec(){}
};
struct line{
	double a,b,c;
	vec v;
	point p1,p2;
};

inline vec toVec(point a, point b){ return vec(b.x-a.x,b.y-a.y); }
inline line toLine(point a, point b){
	line l;
	
	if(fabs(a.x-b.x) < EPS){
		l.a = 1.0 ; l.b = 0.0; l.c = -a.x;
	}
	else{
		l.a = -(double)(a.y - b.y)/(a.x-b.x);
		l.b = 1.0;
		l.c = -(double)(l.a*a.x) - a.y;
	}
	l.v = toVec(a,b);
	l.p1 = a;
	l.p2 = b;
	return l;
}
inline bool areParallel(line a, line b){ return (fabs(a.a-b.a) < EPS and fabs(a.b-b.b) < EPS); }
inline bool intersect(line a, line b, point *p){
	if(areParallel(a,b)) return false;
	(*p).x = (b.b*a.c - a.b * b.c) / (b.a*a.b - a.a * b.b);
	if(fabs(a.b) > EPS) 
		(*p).y = -(a.a * (*p).x + a.c);
	else
		(*p).y = -(b.a * (*p).x + b.c);
		
	return true;
}
inline point  translate(point a, vec v){ return point(a.x + v.x, a.y+v.y); }
inline double dot(vec a, vec b){ return (a.x*b.x + a.y*b.y); }
inline vec    scaled(vec a, double u){ return vec(a.x*u, a.y*u); }
inline double dist(point a, point b){ return sqrt((a.x-b.x)*(a.x-b.x) + (a.y-b.y)*(a.y-b.y)); }
inline double norm_sq(vec a){ return (a.x*a.x + a.y*a.y); }

inline double distToSegment(point p, point a, point b){
	vec ap = toVec(a,p);
	vec ab = toVec(a,b);
	
	double u = dot(ap,ab) / norm_sq(ab);
	point c;
	if(u < 0.0){
		c = a;
	}
	else if(u > 1.0)
		c = b;
	else
		c = translate(a, scaled(ab,u));
	
	return dist(p,c);
}


main(){
	point A[4],l1,l2,aux;
	line V[4],VL;
	bool fail;
	int n;
	cin >> n;
	
	for(int k=0;k<n;k++){
		cin >> l1.x >> l1.y >> l2.x >> l2.y >> A[0].x >> A[0].y >> A[3].x >> A[3].y;
		if(A[3].x < A[0].x or (A[0].x==A[3].x and A[3].y > A[0].y)){
			swap(A[3],A[0]);
		}
		if(A[3].x > A[0].x and A[3].y > A[0].y){
			swap(A[3].y,A[0].y);
		}
		A[1].x = A[3].x;
		A[1].y = A[0].y;
		A[2].x = A[0].x;
		A[2].y = A[3].y;
		
		V[0] = toLine(A[0],A[1]);
		V[1] = toLine(A[1],A[3]);
		V[2] = toLine(A[3],A[2]);
		V[3] = toLine(A[2],A[0]);
		VL = toLine(l1,l2);
		
		fail = true;
		for(int i=0;i<4 and fail;i++){
			if(intersect(V[i],VL,&aux) and fabs(distToSegment(aux,l1,l2)) < EPS and fabs(distToSegment(aux,V[i].p1,V[i].p2)) < EPS){
				fail = false;
				break;
			}
		}
		if(fail and l1.x >=A[0].x and l1.x <= A[3].x and l1.y<=A[0].y and l1.y>=A[3].y){
			fail = false;
		}
		if(!fail)
			cout << "T" << endl;
		else
			cout << "F" << endl;
	}

}

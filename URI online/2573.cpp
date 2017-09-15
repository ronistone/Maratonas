#include <bits/stdc++.h>
using namespace std;
#define EPS 10e-10
struct point{
	double x,y;
	
	point(){}
	point(double a, double b): x(a), y(b){}
	
	inline bool operator ==(point b){
		if(fabs(this->x-b.x) < EPS and fabs(this->y - b.y) < EPS) return true;
		return false;
	}
};
struct vec{
	double x,y;
	
	vec();
	vec(double a, double b): x(a), y(b){}
};

vec toVec(point a, point b){
	return vec(b.x-a.x,b.y-a.y);
}
point translate(point a, vec v){
	return point(a.x+v.x,a.y+v.y);
}
vec scaled(vec v, double u){
	return vec(v.x*u,v.y*u);
}
double cross(vec a, vec b){
	return (a.x * b.y  - a.y * b.x);
}
point lineIntersectSeg(point p, point q, point A, point B){
	double a = B.y - A.y;
	double b = A.x - B.x;
	double c = B.x * A.y - A.x * B.y;
	double u = fabs(a * p.x + b * p.y + c);
	double v = fabs(a * q.x + b * q.y + c);
	return point((p.x*v + q.x*u)/(u+v), (p.y * v + q.y * u)/(u+v));
}
vector<point> cutPolygon(point a, point b, vector<point> Q){
	vector<point> P;
	for(int i=0;i<Q.size();i++){
		double left1 = cross(toVec(a,b),toVec(a,Q[i])), left2 = 0;
		if(i!=Q.size()-1) left2 = cross(toVec(a,b), toVec(a,Q[i+1]));
		if(left1 > -EPS) P.push_back(Q[i]);
		if(left1 * left2 < -EPS){
			point p1 = lineIntersectSeg(Q[i],Q[i+1],a,b);
			P.push_back(p1);
		}
	}
	if(!P.empty() and !(P.back()==P.front()))
		P.push_back(P.front());
		
	return P;
}
double areaP(vector<point> P){
	double ans = 0.0;
	for(int i=0;i<P.size()-1;i++){
		ans += (P[i].x * P[i+1].y - P[i].y * P[i+1].x);
	}
	return fabs(ans)/2.0;
}


main(){
	
	point A,B;
	int l,a;
	double area,areaT;
	
	
	cin >> l >> a;
	areaT = l*a;
	cin >> A.x >> A.y;
	cin >> B.x >> B.y;
	
	vec AB = toVec(A,B);
	point M = translate(A,scaled(AB,0.500000000));
	point M1 = translate(M,scaled(vec(-AB.y,AB.x),100));
	vec MC = toVec(M, M1);
	
	vector<point> P;
	P.push_back(point(0,0));
	P.push_back(point(l,0));
	P.push_back(point(l,a));
	P.push_back(point(0,a));
	P.push_back(point(0,0));
	
	area = areaP(cutPolygon(M,M1,P));
	
	if(cross(MC,toVec(M,A)) > -EPS)
		area = areaT - area;
	
	cout << fixed << setprecision(6) << (areaT - area)/areaT << " " << area/areaT << endl;

}

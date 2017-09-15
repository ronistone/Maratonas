#include <bits/stdc++.h>
using namespace std;

#define EPS 10e-6


struct vec{
	double x,y;
	vec(double _x,double _y): x(_x),y(_y) {}
};
struct point{
	double x,y;
	point(double _x,double _y): x(_x),y(_y) {}
	point(){}
};

vec toVec(point a,point b){	return vec(b.x-a.x,b.y-a.y); }

double dot(vec a, vec b){ return (a.x*b.x + a.y*b.y); }
double norm_sq(vec v){ return (v.x*v.x + v.y*v.y); }
vec scale(vec v, double a){ return vec(v.x*a,v.y*a);}
double dist(point a, point b){ return sqrt(((a.x - b.x)*(a.x - b.x)) + ((a.y - b.y)*(a.y - b.y))); }
point translate(point p, vec v){ return point(p.x+v.x,p.y+v.y); }

// c = a + (u * ab)
double distPointToLine(point p, point a, point b, point *c){
	vec ap = toVec(a,p);
	vec ab = toVec(a,b);
	
	double u = dot(ap,ab)/norm_sq(ab);
	if(u < 0){
		(*c) = a;
		return dist(p,a);
	}
	if(u > 1){
		(*c) = b;
		return dist(p,b);
	}
	(*c) = translate(a,scale(ab,u));
	
	return dist(p,(*c));
}


main(){
	double px,py,x,y,ax,ay,aux;
	int n;
	point c, ansp;
	
	while(cin >> px >> py){
		cin >> n;
		point p(px,py);
		double ans = 10000000.0;
		for(int i=0;i<=n;i++){
			cin >> x >> y;
			if(i!=0){
				aux = distPointToLine(p,point(ax,ay),point(x,y),&c);
				if(ans > aux){
					ans = aux;
					ansp = c;
				}
			}
			ax = x;
			ay = y;
		}
		//cout << ans << endl;
		cout << fixed << setprecision(4) << ansp.x << endl << ansp.y << endl;
	}
}


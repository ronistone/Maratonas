#include <bits/stdc++.h>
using namespace std;

#define EPS 10e-10
typedef long long int ll;

struct point{
	double x,y;
	inline bool operator <(point b){
		if(this->y == b.y)
			return this->x < b.x;
		return this->y < b.y;
	}
	point(){}
	point(double a, double b): x(a),y(b){}
};
struct seg{
	point maior, menor;
	int p;
	
	inline bool operator <(seg b){
		return b.menor < this->maior;
	}
	seg(point a, point b): maior(a), menor(b) {}
	seg(point a, point b,int _p): maior(a), menor(b), p(_p) {}
};
struct vec{
	double x,y;
	vec(double a, double b): x(a), y(b) {}
};
struct line{
	double a,b,c;
};
inline line pointToLine(point a, point b){
	line l;
	if(fabs(a.x-b.x) < EPS){
		l.a = 1.0; l.b = 0.0; l.c = -a.x;
	}
	else{
		l.a = -(double)(a.y-b.y)/(a.x-b.x);
		l.b = 1.0;
		l.c = -(double)(l.a*a.x) - a.y;
	}
	return l;
}

vector<seg> S;


inline vec toVec(point a, point b){
	return vec(b.x-a.x,b.y-a.y);
}

inline bool areParallel(line l1, line l2){
	return (fabs(l1.a-l2.a) < EPS and fabs(l1.b-l2.b) < EPS);
}

inline double dot(vec a, vec b){
	return a.x*b.x + a.y*b.y;
}
inline double norm_sq(vec a){
	return a.x*a.x+a.y*a.y;
}
inline double dist(point a, point b){
	return hypot(a.x-b.x,a.y-b.y);
}
inline point translate(point a, vec v){
	return point(a.x+v.x,a.y+v.y);
}
inline vec scaled(vec v, double u){
	return vec(v.x*u,v.y*u);
}

inline double distToLine(point p, point a, point b){
	vec ap = toVec(a,p);
	vec ab = toVec(a,b);
	
	double u = dot(ap,ab)/norm_sq(ab);
	//cout << u << endl;
	if(u < 0.0)
		return dist(p,a);
	else if(u > 1.0)
		return dist(p,b);
	//cout << translate(a,scaled(ab,u)).x << " , " << translate(a,scaled(ab,u)).y << endl;
	return dist(p,translate(a,scaled(ab,u)));
}


inline bool intersect(line l1, line l2, point v,seg s){
	if(areParallel(l1,l2)) return false;
	point p;
	p.x = (l2.b*l1.c - l1.b * l2.c)	/ (l2.a * l1.b - l1.a * l2.b);
	if(fabs(l1.b) > EPS) p.y = -(l1.a*p.x+l1.c);
	else 				 p.y = -(l2.a*p.x+l2.c);
	
	
	if(v.y > p.y and fabs(v.x-p.x) < EPS){
		//cout << p.x << " , " << p.y << endl;
		//cout << "dist: " << distToLine(p,s.maior,s.menor) << endl;
		if(distToLine(p,s.maior,s.menor) < EPS){
			return true;
		}
	}
	return false;
}

main(){
	point a1,a2;
	int n,m,t;
	cin >> t;
	
	for(int k=0;k<t;k++){
		if(k)
			cout << endl;
		cin >> n;
		S.clear();
		for(int i=0;i<n;i++){
			cin >> a1.x >> a1.y >> a2.x >> a2.y;
			if(a2.y > a1.y)
				swap(a1,a2);
			S.push_back(seg(a1,a2,i+1));
		}
		sort(S.begin(),S.end());
		cin >> m;
		int ans;
		for(int i=0;i<m;i++){
			cin >> a1.x >> a1.y;
			ans = a1.x;
			for(int j=0;j<S.size();j++){
				//cout << "Seg[" << S[j].p << "]" << endl;
				if(intersect(pointToLine(a1,point(a1.x,0)),pointToLine(S[j].maior,S[j].menor),a1,S[j])){
					ans = S[j].menor.x;
					a1 = S[j].menor;
					//cout << "X: " << a1.x << endl;
				}
			}
			cout << ans << endl;
		}
	}
	
}

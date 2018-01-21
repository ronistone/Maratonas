#include <bits/stdc++.h>
using namespace std;

struct point{
	double x,y;
	point(){}
	point(double a, double b): x(a), y(b){}
	inline point operator - (point b){
		return point(b.x - x, b.y - y);
	}
};

struct line{
	double a,b,c;
};
inline line toLine(point a, point b){
	// Equação geral da reta utilizando dois pontos
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

inline double cross(point a, point b){
	return a.x * b.y - a.y * b.x;
}
inline bool areParallel(line a, line b){
	return (fabs(a.a-b.a) < EPS and fabs(a.b-b.b) < EPS);
}

inline bool intersect(line a, line b, point *p){
	if(areParallel(a,b)) return false;
	
	(*p).x = (b.b*a.c - a.b*b.c)/ (b.a*a.b - a.a*b.b);
	
	if(fabs(a.b) > EPS) (*p).y = -(a.a * (*p).x + a.c);
	else				(*p).y = -(b.a * (*p).x + b.c);
	return true;
}


struct tri{
	point p1, p2, ph;
	double areaT = 0;
	inline tri(){}
	inline tri(double x1, double x2, double h){
		p1 = point(x1, 0.0);
		p2 = point(x2, 0.0);
		ph = point((x1+x2)/2.0, h);
		areaT = 0.0;
	}
	inline double area(){
		areaT = (abs(p2.x - p1.x) * ph.y)/2.0;
		return areaT;
	}
	inline double areaIntersec(tri t){
		double ans = 0.0;
		
		if(cross(p1-ph,p1-t.ph) < 0.0 and cross(p2-ph,p2-t.ph) > 0.0)
			ans = t.areaT;
		else if(cross(t.p1-t.ph,t.p1-ph) < 0.0 and cross(t.p2-t.ph,t.p2-ph) > 0.0)	
			ans = areaT;
		else{
			point a1;
			if(intersect(toLine(p1,p2),toLine(t.p1,t.p2),&a1)){
					
			}
			
		}
		return ans;
	}
};


main(){
	double ans = 0,x1,x2,h;
	int n;
	vector<tri> T;
	while(cin >> n and n!=-1){
		ans = 0.0;
		T.clear();
		for(int i=0;i<n;i++){
			cin >> x1 >> x2 >> h;
			T.push_back(tri(x1,x2,h));
			ans += T[i].area();
		}
		for(int i=0;i<n;i++){
			for(int j=0;j<n;j++){
				ans -= T[i].areaIntersec(T[j]);
			}
		}
		
		cout << fixed << setprecision(2) << ans << endl;
		
	}
}

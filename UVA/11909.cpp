#include <bits/stdc++.h>
using namespace std;

struct point{
	double x,y;
	point(){}
	point(double a, double b): x(a), y(b){}
};

inline point rotate(point p, long double ang){
	ang = ang * (M_PI/180.0);
	return point(p.x * cos(ang) - p.y * sin(ang),
				 p.x * sin(ang) + p.y * cos(ang));
}
inline double area(vector<point> P){
	double ans = 0.0;
	for(int i=0;i<P.size()-1;i++){
		ans += (P[i].x * P[i+1].y - P[i].y * P[i+1].x);
	}
	return fabs(ans)/2.00;
}
inline double dist(point a, point b){
	return hypot(a.x - b.x, a.y - b.y);
}


main(){
	int l,w,h,teta;
	double alt;
	vector<point> P(3);
	while(cin >> l >> w >> h >> teta){
		P[0] = point(0,0);
		P[1] = rotate(point(0,l),teta);
		P[2] = point(0,l);
		alt = dist(P[1],point(P[1].x,0.0));
		cout << alt << endl;
		cout << fixed << setprecision(3) << (l*w*h) - ((alt*(l*w))/3) << " mL" << endl;
	}
	
}

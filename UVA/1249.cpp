#include <bits/stdc++.h>
using namespace std;

#define A 0
#define B 1
#define C 2
#define D 3
#define E 4
#define F 5
#define G 6
#define H 7
#define EPS 10e-10

struct point{
	double x,y;
	point(){}
	point(double a, double b): x(a), y(b){}
	inline bool operator ==(point b){
		return (fabs(this->x - b.x) < EPS and fabs(this->y -b.y) < EPS);
	}
	inline bool operator !=(point b){
		return (fabs(this->x - b.x) > EPS or fabs(this->y -b.y) > EPS);
	}
};
struct vec{
	double x,y;
	vec(){}
	vec(double a, double b): x(a), y(b){}
};

/*
		A -- P[0]
		B -- P[1]
		C -- P[2]
		D -- P[3]
		E -- P[4]
		F -- P[5]
		CALULAR
		G -- P[6]
		H -- P[7]
	*/
	point P[8];


inline vec toVec(point a, point b){
	return vec(b.x-a.x,b.y-a.y);
}
inline double cross(vec a, vec b){
	return a.x*b.y - a.y*b.x;
}
inline point mid(point a, point b){
	return point((a.x+b.x)/2,(a.y+b.y)/2);
}
inline double diff(point medio, double def){
	return fabs(fabs(cross(toVec(P[A],medio),toVec(P[A],P[B]))) - def);
}
inline double diff1(vec medio, double def){
	return fabs(cross(medio,toVec(P[A],P[B])));
}
inline point translate(point a, vec v){
	return point(a.x+v.x,a.y+v.y);
}
inline vec scaled(vec v, double u){
	return vec(v.x*u,v.y*u);
}

main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	double def,ini,fim,mid;
	int i;
	vec ac;
	bool stop;
	
	while(1){
		stop = true;
		for(i=0;i<6;i++){
			cin >> P[i].x >> P[i].y;
			if(P[i].x > EPS or P[i].y > EPS)
				stop = false;
		}
		if(stop)
			break;
		def = fabs(cross(toVec(P[D],P[E]),toVec(P[D],P[F]))/2);
		ini = 0.0;
		fim = 5000.0;
		ac = toVec(P[A],P[C]);
		
		for(i=0;i<500;i++){
			mid = (ini+fim)/2.0;
			if(fabs(diff1(scaled(ac,mid),def)) < EPS)
				break;
			else if(diff1(scaled(ac,mid),def) < def){
				ini = mid + 0.000001;
			}
			else{
				fim = mid - 0.000001;
			}
		}
		P[H] = translate(P[A],scaled(ac,mid));
		P[G] = translate(P[H],toVec(P[A],P[B]));
				
		cout << fixed << setprecision(3) << P[G].x << " " << P[G].y << " " << P[H].x << " " << P[H].y << endl;
	}

}

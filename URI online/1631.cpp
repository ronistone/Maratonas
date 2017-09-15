#include <bits/stdc++.h>
using namespace std;

struct point{
	double x, y;
	point(double _x, double _y): x(_x),y(_y){}
	point(){}
};

struct segment{
	point a,b;
	segment(point _a, point _b): a(_a), b(_b){}
	segment(){}
};
struct vec{
	double x,y;
	vec(double _x, double _y): x(_x),y(_y){}
};

inline vec    toVec(point a, point b){	return vec(b.x-a.x,b.y-a.y); }
inline double dot(vec a, vec b){ return (a.x*b.x + a.y*b.y); }
inline double norm_sq(vec v){ return v.x*v.x + v.y*v.y; }
inline double dist(point a, point b){ return sqrt(((a.x-b.x)*(a.x-b.x)) + ((a.y-b.y)*(a.y-b.y))); }
inline point  translate(point a, vec v){ return point(a.x+v.x,a.y+v.y); }
inline vec    scaled(vec v, double l){ return vec(v.x*l,v.y*l); }
inline double cross(vec a, vec b){ return a.x * b.y - a.y*b.x; }

inline double distToLine(point p,segment a, point *c){
	vec ap = toVec(a.a,p);
	vec ab = toVec(a.a,a.b);
	double u = dot(ap,ab)/ norm_sq(ab);
	(*c) = translate(a.a,scaled(ab,u));
	return dist(p,(*c));
}

main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n,ls,idx,i,j;
	double left,right,at,cr,ans;
	segment linhas[10000],seg;
	point A[105];
	while(scanf("%d",&n) and n){
		ls = 0;
		for(i=0;i<n;i++){
			scanf("%lf%lf",&A[i].x,&A[i].y);
			//cin >> A[i].x >> A[i].y;
			if(i!=0){
				for(j=0;j<i;j++){
					//if(i!=j)
						linhas[ls++] = segment(A[i],A[j]);
				}	
			}
		}

		point aux;
		ans = 13123312.0;
		for(i=0;i<ls;i++){
			left = right = 0.0;
			for(j=0;j<n;j++){
				at = distToLine(A[j],linhas[i],&aux);
				cr = cross(toVec(linhas[i].a,linhas[i].b),toVec(linhas[i].a,A[j]));
				if(cr > 0)
					right += at;
				else if(cr < 0)
					left += at;
			}
			
			ans = min(ans,fabs(left-right));
		}
		printf("%.3lf\n", ans);
		//cout << fixed << setprecision(3) << ans << endl;
	}

}

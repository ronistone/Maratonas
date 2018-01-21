#include <bits/stdc++.h>
using namespace std;

#define EPS 10e-10
typedef long long int ll;
struct point{
	
	double x,y;
	
	point(){}
	point(double a, double b): x(a), y(b){}
};
struct vec{
	
	double x,y;
	
	vec(){}
	vec(double a, double b): x(a), y(b){}
	vec(point a, point b){
		x = b.x - a.x;
		y = b.y - a.y;
	}
};
struct seg{
	point a, b;
	
	seg(){}
	seg(point x, point y): a(x), b(y){}
};


inline double dist_sq(point a, point b){
	return (b.x - a.x)*(b.x - a.x) + (b.y - a.y) * (b.y - a.y);
}
inline double norm_sq(vec a){
	return a.x*a.x + a.y*a.y;
}
inline point translate(point a, vec v){
	return point(a.x+v.x,a.y+v.y);
}
inline vec scaled(vec v, double u){
	return vec(v.x*u,v.y*u);
}
inline double dot(vec a, vec b){
		return a.x*b.x + a.y*b.y;
}
inline double distToseq(seg a, point p){
	vec ap(a.a,p);
	vec ab(a.a,a.b);
	double u = dot(ap,ab)/norm_sq(ab);
	
	if(u < 0.0)
		return dist_sq(a.a,p);
	else if(u > 1.0)
		return dist_sq(a.b,p);
	else
		return dist_sq(translate(a.a,scaled(ab,u)),p);
}

main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	seg S[1100];
	int yi,x,y,L,H,n,i;
	double ans;
	while(scanf("%d",&n)!=EOF){
		
		scanf("%d %d",&L,&H); // Esquerda (0,X)
							  // Direita	(L,X)	
		ans = INT_MAX;
		for(i=0;i<n;i++){
			scanf("%d %d %d", &yi, &x, &y);
			if(i%2==0){		// ESQUERDA
				S[i] = seg(point(0,yi),point(x,y));
				ans = min(ans,dist_sq(S[i].b,point(L,S[i].b.y)));
			}
			else{			// DIREITA
				S[i] = seg(point(L,yi),point(x,y));
				ans = min(ans,dist_sq(S[i].b,point(0,S[i].b.y)));
			}

			if(i!=0)
				ans = min(ans,distToseq(S[i],S[i-1].b));
		}
		printf("%.2lf\n", sqrt(ans));
	}
}

#include <bits/stdc++.h>
using namespace std;
#define EPS 10e-10
#define pb push_back

struct point{
	double x,y;
	
	point(){}
	point(double a, double b): x(a), y(b){}
	
	inline bool operator <(point b){
		if(fabs(this->y-b.y) < EPS)
			return this->x < b.x;
		return this->y < b.y;
	}
	inline bool operator >(point b){
		if(fabs(this->y-b.y) < EPS)
			return this->x > b.x;
		return this->y > b.y;
	}
};
struct vec{
	double x,y;
	
	vec(double a, double b): x(a),y(b){}
	vec(){}
};

inline double cross(vec a, vec b){
	return a.x*b.y - a.y*b.x;
}

inline vec toVec(point a, point b){
	return vec(b.x-a.x,b.y-a.y);
}

struct seg{
	point maior, menor;
	
	seg(){}
	seg(point a, point b): maior(a), menor(b){}
	
	inline bool operator <(seg b) const{
		return b.menor < this->maior;
	}
	inline bool operator >(seg b) const{
		return b.menor > this->maior;
	}
};
struct line{
	double a,b,c;
};
// ----------- GEOMETRIA ------------

inline line toLine(point a, point b){
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

inline double dot(vec a, vec b){
	return a.x*b.x + a.y*b.y;
}

inline double norm_sq(vec a){
	return a.x*a.x+a.y*a.y;
}

inline double dist(point a, point b){
	return hypot(a.x-b.x, a.y-b.y);
}

inline point translate(point a, vec v){
	return point(a.x+v.x,a.y+v.y);
}

inline vec scaled(vec v, double u){
	return vec(v.x*u, v.y*u);
}
inline double distToLine(point p, point a, point b){
	vec ap = toVec(a,p);
	vec ab = toVec(a,b);
	
	double u = dot(ap,ab)/norm_sq(ab);
	
	if(u < 0.0)
		return dist(p,a);
	else if(u > 1.0)
		return dist(p,b);
	return dist(p,translate(a,scaled(ab,u)));
}


inline bool areParallel(line l1, line l2){
	return (fabs(l1.a-l2.a) < EPS and fabs(l1.b-l2.b) < EPS);
}


inline bool intersect(line l1, line l2, point v, seg s,int *I){
	point p;
	if(areParallel(l1,l2)) return false;
	
	p.x = (l2.b*l1.c - l1.b * l2.c)	/ (l2.a * l1.b - l1.a * l2.b);
	
	if(fabs(l1.b) > EPS) p.y = -(l1.a*p.x+l1.c);
	else 				 p.y = -(l2.a*p.x+l2.c);
		
	if(fabs(v.x-p.x) < EPS){
		if(distToLine(p,s.maior,s.menor) < EPS){
			*I = p.x;
			return true;
		}
	}
	return false;
}

// ----------------------------------


// ------------- GRAFO ----------------

int parent[100010];
int xi[100010];
vector<seg> S;

inline int build(int x, point M,int xant,int iant){
	
	if(parent[x]!=x or (S[x].maior.y==S[x].menor.y)){xi[iant] = xant; return parent[x]; }
	int ans = parent[x];
	int p = -INT_MAX;
	for(int i=x-1;i>=0;i--){
		if(parent[i]!=i and intersect(toLine(M,point(M.x,10000000.0)),toLine(S[i].maior,S[i].menor),M,S[i],&p)){
			ans = build(i,S[i].maior,p,x);
			break;
		}
	}
	return parent[x] = ans;
}


// --------------------------------------
main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n,q,x,v;
	point a1,a2;
	
	while(cin >> n >> q){
		S.clear();	
		for(int i=0;i<n;i++){
			cin >> a1.x >> a1.y >> a2.x >> a2.y;
			if(a2.y > a1.y)
				swap(a1,a2);
			S.pb(seg(a1,a2));
		
			parent[i] = i;
			xi[i] = -INT_MAX;
		}
		sort(S.begin(),S.end());
		
		for(int i=S.size()-1;i>=0;i--){
			if(parent[i]!=i){
				build(i,S[i].maior,-INT_MAX,i);
			}
		}
		
		for(int i=0;i<q;i++){
			cin >> x;
			bool fail = true;
			for(int j=S.size()-1;j>=0;j--){
				if(intersect(toLine(point(x,0),point(x,10000000.0)),toLine(S[j].maior,S[j].menor),point(x,0),S[j],&v)){
					if(S[parent[j]].maior.y != S[parent[j]].menor.y)
						cout << S[parent[j]].maior.x << endl;
					else{
						cout << (xi[j]==-INT_MAX? v:xi[j]) << " " << S[parent[j]].maior.y << endl;
					}
					fail = false;
					break;
				}
			}
			if(fail)
				cout << x << endl;
		}
		
	}
}

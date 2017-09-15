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
	inline bool operator <(point b){
		if(fabs(this->x-b.x) < EPS) return this->y < b.y;
		return this->x < b.x; 
	}
};

struct vec{
	double x,y;
	vec(){}
	vec(double a, double b): x(a), y(b){}
};

struct line{
	double a,b,c;
};
vector<point> P; // Vetor de pontos = poligno
//------------ Retas/Pontos/Vetores ----------
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

inline vec toVec(point a,point b){
	return vec(b.x-a.x,b.y-a.y);
}

inline double dot(vec a, vec b){
	// produto escalar
	return (a.x*b.x + a.y*b.y);
}

inline double cross(vec a, vec b){
	/*	produto vetorial
		negativo ponto a esquerda do vetor
		positivo ponto a direita do vetor
		zero pontos colineares
	*/
	return (a.x * b.y - a.y * b.x);
}
inline double cross(point o, point a, point b){
	return (a.x - o.x) * (b.y - o.y) - (a.y - o.y) * (b.x - o.x);
}

inline double norm_sq(vec v){
	// normal ao quadrado
	return (v.x*v.x + v.y*v.y);
}

inline vec scaled(vec v, double a){
	return vec(v.x*a,v.y*a);
}

inline point translate(point p, vec v){
	return point(p.x+v.x,p.y+v.y);
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

inline double dist(point a, point b){
	// Distância euclidiana
	return sqrt((b.x-a.x)*(b.x-a.x) + (b.y-a.y)*(b.y-a.y));
	// ou return hypot(a.x-b.x,a.y-b.y);
}

inline double distToLine(point p, point a, point b){
	// distancia de ponto para um segmento de linha
	vec ap = toVec(a,p);
	vec ab = toVec(a,b);
	
	double u = dot(ap,ab)/norm_sq(ab);
	if(u < 0.0)
		return dist(p,a);
	else if(u > 1.0)
		return dist(p,b);
	return dist(p,translate(a,scaled(ab,u)));
}

inline point mid(point a, point b){
	// ponto médio
	return point((a.x+b.x)/2,(a.y+b.y)/2);
}

inline point rotate(point p, double ang){
	// Rotaciona o ponto em relação a origem
	// translade a origem para o ponto (0,0) pra utiliza-lo
	ang = (ang*(M_PI/180.0));
	return point(p.x * cos(ang) - p.y * sin(ang),
				 p.x * sin(ang) + p.y * cos(ang));
}
double angle(point a, point o, point b) { // returns angle aob in rad
	vec oa = toVec(o, a), ob = toVec(o, b);
	return acos(dot(oa, ob) / sqrt(norm_sq(oa) * norm_sq(ob)));
}

// Para rotacionar um vetor em 90 graus
// dado o vetor u = (a,b) o vetor rotacionado
// em 90 graus é o vetor u' = (-b,a)
// e u'' = (b,-a) para rotacionar em -90 graus
//---------------------------------

//--------- Polignos --------------

inline vector<point> convex_hull(){
	vector<point> ans(2*P.size());
	int k = 0;
	sort(P.begin(),P.end());
	
	for(int i=0;i<P.size();i++){
		while(k >=2 and cross(ans[k-2],ans[k-1],P[i]) <= EPS) k--;
		ans[k++] = P[i];
	}
	
	for(int i=P.size()-2, t = k+1; i>=0; i--){
		while(k>=t and cross(ans[k-2],ans[k-1],P[i]) <= EPS) k--;
		ans[k++] = P[i];
	}
	ans[k] = ans[0];
	ans.resize(k);
	return ans;
}

inline double area(vector<point> poli){
	double ans = 0.00000000;
	for(int i=0;i<poli.size()-1;i++){
		ans += (poli[i].x*poli[i+1].y - poli[i+1].x*poli[i].y);
	}
	return fabs(ans)/2.000;
}

inline double perimetro(vector<point> C){
	double ans = 0.00000;
	
	for(int i=0;i<C.size()-1;i++){
		ans += dist(C[i],C[i+1]);
	}
	return ans;
}

//----------------------------------------------

main(){
}

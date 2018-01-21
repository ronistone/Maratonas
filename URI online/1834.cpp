#include <bits/stdc++.h>
using namespace std;

typedef int ll;

struct point{
	ll x,y;
	point(){}
	point(ll a, ll b): x(a), y(b){}
};

struct vec{
	ll x,y;
	vec(){}
	vec(ll a, ll b): x(a), y(b){}
	vec(point a, point b){
		x = b.x-a.x;
		y = b.y-a.y;
	}
};

inline double dist(point a, point b){
	return hypot(a.x-b.x,a.y-b.y);
}

inline ll cross(vec a, vec b){
	return a.x * b.y - a.y * b.x;
}

main(){
	point A,B;
	vec AB;
	int x,y,w,n;
	cin >> x >> y;
	
	A = point(x,y);
	
	cin >> x >> y;
	B = point(x,y);
	
	AB = vec(A,B);
	
	cout << "Relatorio Vogon #35987-2" << endl;
	cout << fixed << setprecision(2) << "Distancia entre referencias: " << dist(A,B) << " anos-luz" << endl;
	
	cin >> n;
	
	int left = 0, right = 0, mid = 0;
	int habL = 0, habR = 0, habM = 0;
	for(int i=0;i<n;i++){
		cin >> x >> y >> w;
		point p(x,y);
		int c = cross(vec(A,p),AB);
		if(!c){
			mid++;
			habM += w;
		}
		else if(c < 0){
			left++;
			habL += w;
		}
		else if(c > 0){
			right++;
			habR += w;
		}
	}
	
	cout << "Setor Oeste:" << endl;
	cout << "- " << left << " planeta(s)" << endl;
	cout << "- " << habL << " bilhao(oes) de habitante(s)" << endl;
	cout << "Setor Leste:" << endl;
	cout << "- " << right << " planeta(s)" << endl;
	cout << "- " << habR << " bilhao(oes) de habitante(s)" << endl;
	cout << "Casualidades: " << mid << " planeta(s)" << endl;
	
}

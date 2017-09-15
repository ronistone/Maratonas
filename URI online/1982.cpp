#include <bits/stdc++.h>
using namespace std;

#define EPS 10e-10

struct point{
	int x,y;
	point(){}
	point(int a, int b): x(a), y(b){}
	inline bool operator <(point b) const {
		return this->x == b.x? this->y < b.y: this->x < b.x;
	}
};
typedef long long int ll;
vector<point> P;

inline ll cross(point o, point a, point b){
	return (a.x-o.x) * (b.y-o.y) - (a.y-o.y) * (b.x-o.x);
}
inline double dist(point a, point b){
	return hypot(a.x-b.x,a.y-b.y);
}

inline vector<point> convex_hull(){
	vector<point> ans(2*P.size());
	int k=0;
	sort(P.begin(),P.end());
	
	for(int i = 0;i<P.size();i++){
		while(k>=2 and cross(ans[k-2],ans[k-1],P[i]) <= 0) k--;
		ans[k++] = P[i];
	}
	
	for(int i=P.size()-2, t = k+1;i>=0;i--){
		while(k>=t and cross(ans[k-2],ans[k-1],P[i]) <= 0) k--;
		ans[k++] = P[i];
	}
	
	ans[k] = ans[0];
	ans.resize(k);
	return ans;
}

inline double perimetro(vector<point> C){
	double ans = 0.00000;
	
	for(int i=0;i<C.size()-1;i++){
		ans += dist(C[i],C[i+1]);
	}
	return ans;
}

main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n,x,y;
	while(cin >> n and n){
		P.clear();
		for(int i=0;i<n;i++){
			cin >> x >> y;
			P.push_back(point(x,y));
		}
		cout << fixed << setprecision(2) 
			 << "Tera que comprar uma fita de tamanho " 
			 << perimetro(convex_hull()) << "." << endl;
	}

}

#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;

struct point{
	int x,y;
	point(){}
	point(int a, int b): x(a), y(b){}
};

vector<point> P;

inline ll cross(point o, point a, point b){
	return (a.x - o.x) * (b.y - o.y) - (a.y - o.y) * (b.x - o.x);
}
inline vector<point> convex(){
	int k = 0;
	vector<point> ans(2*P.size());
	
	for(int i=0;i<P.size();i++){
		while(k >= 2 and cross(ans[k-2], ans[k-1], P[i]) <= 0) k--;
		ans[k++] = P[i];
	}
	
	for(int i=P.size()-2, t = k+1;i>=0;i--){
		while(k >= t and cross(ans[k-2], ans[k-1], P[i]) <= 0) k--;
		ans[k++] = P[i];
	}
	ans[k] = ans[0];
	ans.resize(k);
	
	return ans;
}
inline double area(vector<point> C){
	double ans = 0.000;
	
	for(int i=0;i<C.size()-1;i++){
		ans += (C[i].x * C[i+1].y - C[i].y * C[i+1].x);
	}
	return ans/2.0;
}





main(){
	int x,y,n;
	while(cin >> n){
		for(int i=0;i<n;i++){
			cin >> x >> y;
			P.push_back(point(x,y));
		}
		cout << area(convex()) << endl;
	}
}

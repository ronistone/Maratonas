#include <bits/stdc++.h>
using namespace std;

struct point{
	double x,y,r;
	point(double _x,double _y,double _r): x(_x),y(_y),r(_r){}
	
	inline double dist(point b){
		return sqrt(((x-b.x)*(x-b.x)) + ((y-b.y)*(y-b.y)));
	}
};

main(){

	vector<point> P;
	
	int n;
	double x,y,r;
	cin >> n;
	
	for(int i=0;i<n;i++){
		cin >> x >> y >> r;
		P.push_back(point(x,y,r));
	}
	int ans =0;
	for(int i=0;i<n;i++){
		bool falha = false;
		for(int j=0;j<n;j++){
			if(i!=j and P[i].dist(P[j]) <= (P[i].r+P[j].r)){
				falha = true;
				break;
			}
		}
		if(!falha)
			ans++;
	}
	cout << ans << endl;
}

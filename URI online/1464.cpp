#include <bits/stdc++.h>
using namespace std;

#define EPS 10e-10
typedef long long int ll;

struct point{
	int x,y;
	bool active;
	int posi;
	point(){}
	point(int a, int b): x(a),y(b){ this->active = true; }
	inline bool operator <(point b) const{
		return this->x==b.x? this->y < b.y: this->x < b.x;
	}
};

vector<point> P;


inline ll cross(point o, point a, point b){
	return (a.x - o.x) * (b.y - o.y) - (a.y - o.y) * (b.x - o.x);
}
inline bool convex(){
	vector<point> ans(2*P.size());
	map<int,bool> eliminado;
	int camada = 0,k,size = P.size();
	sort(P.begin(),P.end());
	
	while(size > 2){
		k = 0;
		for(int i=0;i<P.size();i++){
			P[i].posi = i;
			if(P[i].active){
				while(k>=2 and cross(ans[k-2],ans[k-1],P[i]) < 0) k--;
				ans[k++] = P[i];
			}
		}
		for(int i=P.size()-2, t = k+1; i>=0;i--){
			if(P[i].active){
				while(k>=t and  cross(ans[k-2], ans[k-1], P[i]) < 0) k--;
				ans[k++] = P[i];
			}
		}
		
		
		for(int i=0;i<k-1;i++){
			if(!eliminado[ans[i].posi]){
				P[ans[i].posi].active = false;
				size--;
				eliminado[ans[i].posi] = true;
			}
		}
		camada++;
	}
	if(camada%2==0 or size > 0)
		return false;
	else
		return true;
}


main(){
	int n,i,x,y;
	
	while(cin >> n and n){
		P.clear();
		for(int i=0;i<n;i++){
			cin >> x >> y;
			P.push_back(point(x,y));
		}
		
		if(convex()){
			cout << "Take this onion to the lab!" << endl;
		}
		else{
			cout << "Do not take this onion to the lab!" << endl;
		}
	}

}

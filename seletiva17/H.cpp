#include <bits/stdc++.h>
using namespace std;

struct point{
	int x,y;
	point(){}
	point(int a, int b): x(a), y(b){}
	inline bool operator <(point b) const{
		return this->y == b.y? this->x < b.x: this->y < b.y;
	}
};
struct vec{
	int x,y;
	vec(){}
	vec(int a, int b): x(a), y(b){}
};

typedef long long int ll;

inline vec toVec(point a, point b){
	return vec(b.x-a.x, b.y-a.y);
}
inline ll cross(vec a, vec b){
	return a.x*b.y - a.y*b.x;
}

ll dp[110][110],n,xa,xb;
point A,B;
vector<point> P(110);

ll solve(int current, int ant){
	
	if(current >= n) return 0LL;
	
	if(dp[current][ant+1]!= -1) return dp[current][ant+1];
	ll ans = 0LL;
	
	if(ant!=-1){
		vec AP = toVec(A,P[current]), Aant = toVec(A,P[ant]);
		vec BP = toVec(B,P[current]), Bant = toVec(B,P[ant]);
		if(cross(AP,Aant) < 0 and cross(BP,Bant) > 0)
			ans = solve(current+1,current)+1LL;
	}
	else{
		ans = solve(current+1,current)+1LL;
	}
	ans = max(ans,solve(current+1,ant));
	return dp[current][ant+1] = ans;
}


main(){
	
	cin >> n >> xa >> xb;
	P.resize(n);
	for(int i=0;i<n;i++){
		cin >> P[i].x >> P[i].y;
	}
	A = point(xa,0);
	B = point(xb,0);
	
	sort(P.begin(),P.begin()+n);
	
	for(int i=0;i<105;i++){
		for(int j=0;j<105;j++)
			dp[i][j] = -1;
	}
	
	cout << solve(0,-1) << endl;

}

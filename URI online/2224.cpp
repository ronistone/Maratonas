#include <bits/stdc++.h>
using namespace std;
#define mp make_pair
#define pb push_back
#define F first
#define S second

double A[17][17];
int n;
double dp[17][1 << 17];
vector<pair<double,double> > vertices;
inline double calc(pair<double,double> a, pair<double,double> b){
	return sqrt(((a.F-b.F)*(a.F-b.F)) + ((a.S-b.S)*(a.S-b.S)));
}
double solve(int current,int mask,bool pegar){
	
	if(mask == ((1 << n)-1)) return 0.0;
	if(dp[current][mask]!=-1) return dp[current][mask];
	
	double ans = 101010.0;
	for(int i=0;i<n;i++){
		if(!(mask & (1 << i))){
			if(pegar){
				ans = min(ans,solve(i,(mask | (1 << i)),false)+A[current][i]);
			}
			else{
				ans = min(ans,solve(i,(mask | (1 << i)),true));
			}
		}
	}
	return dp[current][mask] = ans;
}

main(){
	int z;
	double x,y;
	cin >> z;
	
	for(int i=0;i<z;i++){
		cin >> n;
		for(int i=0;i<n;i++){
			cin >> x >> y;		
			vertices.pb(mp(x,y));
		}
		for(int i=0;i<n;i++){
			for(int j=0;j<(1 << (n+1));j++){
				dp[i][j] = -1;
			}
		}
		for(int i=0;i<n;i++){
			for(int j=0;j<n;j++)
				A[i][j] = calc(vertices[i],vertices[j]);
		}
		cout << fixed << setprecision(2) << solve(0,1,true) << endl;
		vertices.clear();
	}
}
/*
#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
typedef int ll;
vector< pair<ll, ll> >coord;
ll n;
double dp[18][(1 << 18)];

inline void reset()
{
	coord.clear();
	
	for(ll i = 0; i <= n; i++)
		for(ll j = 0; j <= (1 << (n+1)); j++)
			dp[i][j] = -1;
}

inline double dist(ll x1, ll y1, ll x2, ll y2){
	return sqrt( (x1-x2)*(x1-x2) + (y1-y2)*(y1-y2) );
}

inline double solve(ll current, ll mask)
{	
	if(mask == (1LL << n)-1)
		return 0;
		
	if(dp[current][mask] != -1)
		return dp[current][mask];
	
	if(mask & (1LL << current)){
		return dp[current][mask] = solve(current+1, mask);
	}
		
	double ans = 10555555;
	
	mask |= (1LL << current);
	for(ll i = current+1; i < n; i++)
	{
		if(i == current) continue;
		if(!(mask & (1 << i)))
		{
			ll opt = mask | (1LL << i);
			ans = min(ans, solve(current+1, opt) + 
				dist(coord[current].first, coord[current].second, coord[i].first, coord[i].second));
		}
		
	}
	
	return dp[current][mask] = ans;
}

main()
{
	ll t, x, y;
	scanf("%d", &t);
	
	while(t--)
	{
		scanf("%d", &n);
		reset();
		
		for(ll i = 0 ; i < n; i++)
		{
			scanf("%d %d", &x, &y);
			coord.push_back( {x, y} );
		}	
		
		double res = solve(0, 0);
		printf("%.2lf\n", res);
	}
}

*/

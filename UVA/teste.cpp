#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
typedef long long int ll;
ll dist[105][105];

main()
{
	ll n, r, u, v, p, s, d, t, cases=1;
	
	while(cin >> n >> r && (n+r))
	{
		for(ll i = 0 ; i <= n; i++)
			for(ll j = 0; j <= n; j++)
				dist[i][j] = i == j ? 0 : -1;
		
		for(ll i = 0 ;i < r; i++)
		{
			cin >> u >> v >> p;
			dist[u][v] = dist[v][u] = p;
		}
		
		cin >> s >> d >> t;
		
		for(ll k = 1; k <= n; k++)
			for(ll i = 1; i <= n; i++)
				for(ll j = 1; j<= n; j++)
					dist[i][j] = max(dist[i][j], min(dist[i][k], dist[k][j]));
					
		//cout << dist[s][d] << " " << t << endl;
		ll res = ceil((double)t/(double)(dist[s][d]-1));
			
		cout << "Scenario #" << cases++ << endl;
		cout << "Minimum Number of Trips = " << res << endl;
		cout << endl;
	}
}                        

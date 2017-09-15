#include <bits/stdc++.h>
using namespace std;

main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n,m,k,a,i,j;
	
	cin >> n >> m >> k;
	pair<int,int> c[m+1],l[n+1];
	for(i=1;i<=m;i++) c[i].first = 4;
	for(i=1;i<=n;i++) l[i].first = 4;
	char x;
	int v = 0;
	for(i=0;i<k;i++){
		cin.ignore();
		cin >> x >> a;
		if(x=='L'){
			l[a].first = v;
			l[a].second = i;
		}
		else if(x=='C'){
			c[a].first = v;
			c[a].second = i;
		}
		v++;
		if(v==4)
			v = 0;
	}
	int ans[5];
	memset(ans,0,sizeof ans);
	for(i=1;i<=n;i++){
		for(j=1;j<=m;j++){
			if(l[i].first==4)
				ans[c[j].first]++;
			else if(c[j].first==4)
				ans[l[i].first]++;
			else{
				if(l[i].second > c[j].second)
					ans[l[i].first]++;
				else
					ans[c[j].first]++;
			}
		}
	}
	cout << "R" << ans[0] << " H" << ans[1] << " C" << ans[2] << " P" << ans[3] << endl;

}

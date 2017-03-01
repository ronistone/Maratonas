#include <bits/stdc++.h>
using namespace std;
#define F first
#define S second
#define mp make_pair
#define pb push_back


typedef long long int ll;


ll sum[20005];
ll n,s;


main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> n;
	
	for(int k=0;k<n;k++){
		cin >> s;
		ll ans = 0,ansx=1,ansy=1;
		ll at = 0;
		int from=1,to=1;
		for(int i=0;i<s-1;i++){
			cin >> sum[i];
			at += sum[i];
			if(at >= ans){
				if(at > ans or (ansy-ansx < i+2-from) or (ansy-ansx == i+2-from and from <= ansx)){
					ansx = from;
					ansy = i+2;
				}
				ans = at;
			}
			if(at<0){
				at = 0;
				from = i+2;
			}
		}
		if(ans > 0)
			cout << "The nicest part of route " << k+1 << " is between stops " << ansx << " and " << ansy << endl;
		else
			cout << "Route " << k+1 << " has no nice parts" << endl;
	}


}

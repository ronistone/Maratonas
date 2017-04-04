#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
vector<ll> num;

ll CeilIndex(ll L,ll R,ll value){	
	while(R-L > 1){
		ll mid = L+(R-L)/2;
		if(num[mid] >= value)
			R = mid;
		else
			L = mid;
	}
	return R;
}
main(){
	ll aux;
	while(cin >> aux){
		num.push_back(aux);
	}
	vector<ll> tail(num.size(),0);
	vector<ll> ant(num.size(),-1);
	ll ans = 1;
	
	for(ll i=1;i<num.size();i++){
		if(num[i] < num[tail[0]])
			tail[0] = i;
		//else if(num[i] < tail[ans-1] and num[i] > tail[ans-2])
		//	tail[ans++] = num[i];
		else if(num[i] > num[tail[ans-1]]){
			ant[i] = tail[ans-1];
			tail[ans++] = i;
		}
		else{
			ll temp = CeilIndex(-1,ans-1,num[i]);
			ant[i] = ant[temp-1];
			tail[temp] = i;//min(num[i],tail[temp]);
		}	
	}
	cout << ans << endl
		 << "-" << endl;
	for(int i=0;i<ans;i++){
		cout << num[tail[i]] << endl;
	}
}







/*main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	vector<ll> num,a;
	vector<vector<ll> > lis;
	ll aux,n;
	while(cin >> aux){
		num.push_back(aux);
		lis.push_back(a);
		lis[num.size()-1].push_back(1);
	}
	n = num.size();
	ll ult[n];
	ll ans = -10e17;
	ll p = 0;
	for(int i=1;i<n;i++){
		for(int j=0;j < i;j++){
			if(num[i] > num[j] and lis[i][0] < lis[j][0]+1){
				lis[i][0] = lis[j][0]+1;
				lis[i].push_back(num[j]);
				ult[i] = num[i];
				ans = max(ans,lis[i][0]);
				if(ans==lis[i][0])
					p = i;
			}
		}
	}
	cout << ans << endl
		 << "-" << endl;
	for(int i=1;i<lis[p].size();i++){
		cout << lis[p][i] << endl;
	}
	cout << ult[p] << endl;
}*/

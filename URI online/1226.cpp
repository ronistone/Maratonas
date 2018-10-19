#include <bits/stdc++.h>
using namespace std;


typedef unsigned long long int ll;

ll dp[20][2][2];
string e;

ll solve(int p, bool match, bool isOne){
	if(p == e.size()) return 1LL;
	if(dp[p][match][isOne] != 0LL) return dp[p][match][isOne];
	ll ans = 0LL;
	if(match){
		for(int i=0;i<(e[p]-'0');i++){
			if(i==4 or (isOne and i==3)) continue;
				ans += solve(p+1,false, (i==1));
		}
		if(not(e[p]=='4' or (isOne and e[p]=='3'))){
			ans += solve(p+1,true, (e[p]=='1'));
		}
	}else{
		for(int i=0;i<10;i++){
			if(i==4 or (isOne and i==3)) continue;
			ans += solve(p+1, false, (i==1));
		}
	}
	return dp[p][match][isOne] = ans;
}

void clear(){
	for(int i=0;i<20;i++)
		for(int j=0;j<2;j++)
			for(int w=0;w<2;w++)
				dp[i][j][w] = 0LL;
}



ll bs(string n){
	
	ll lo=0,hi=10e18, mid;
	ll ans;
	ll num = stoll(n);
	while(lo<=hi){
		mid = lo+((hi-lo)/2);
		e = to_string(mid);
		clear();
		ans = solve(0,true,false)-1;
		if(num > ans){
			lo = mid+1;
		}else if(num <= ans){
			hi = mid-1;
		}
	}
	mid += num-ans;
		return mid;
}

main(){
	string n;
	while(cin >> n){
		e = n;
		clear();
	
		cout << bs(n) << endl;
	
	}


}

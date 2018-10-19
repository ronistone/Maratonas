#include <bits/stdc++.h>
using namespace std;

main(){
	string a,b;
	map<char,int> m, get;
	string ans;
	
	
	while(getline(cin, a)){
		getline(cin,b);
		
		ans.clear();
		m.clear();
		get.clear();
		for(auto c: a){
			m[c]++;
		}
		for(auto c: b){
			if(m[c]){
				ans += c;
				m[c]--;
			}
		}
		
		sort(ans.begin(), ans.end());
		
		cout << ans << endl;
	}
	
}

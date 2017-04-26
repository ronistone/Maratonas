#include <bits/stdc++.h>
using namespace std;

main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n,d,i;
	string e,a,ans;
	unordered_map<char,int> M;
	while(cin >> n >> d and (n and d)){
		cin.ignore();
		getline(cin,e);
		a = e;
		sort(a.begin(),a.end());

		for(i=0;i<e.size();i++){
			M[e[i]]++;
		}
		for(i=0;i<d;i++){
			M[a[i]]--;
		}
		for(i=e.size()-1;i>=0;i--){
			if(M[e[i]]){
				ans += e[i];
				M[e[i]]--;
			}
		}
		cout << string(ans.rbegin(),ans.rend()) << endl;
		ans.clear();
	}


}

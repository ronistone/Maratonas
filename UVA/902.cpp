#include <bits/stdc++.h>
using namespace std;

main(){
	int n, ansNum;
	string e, ans;
	map<string, int> count;
	map<string, int>::iterator it;
	while(cin >> n >> e){
		count.clear();
		for(int i=0;i<e.size()-n;i++){
			count[e.substr(i,n)]++;
		}
		ansNum = 0;
		ans = "";
		for(it=count.begin();it!=count.end();it++){
			if(it->second > ansNum){
				ansNum = it->second;
				ans = it->first;
			}
		}
		cout << ans << endl;
	}
	cout << ((int)'\n') << endl;
}

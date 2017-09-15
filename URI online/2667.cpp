#include <bits/stdc++.h>
using namespace std;

main(){
	string e;
	int ans=0;
	getline(cin,e);
	
	for(int i=0;i<e.size();i++){
		ans+= e[i]-'0';
	}
	cout << ans%3 << endl;
}

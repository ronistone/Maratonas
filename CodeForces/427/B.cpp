#include <bits/stdc++.h>
using namespace std;


string e;
long long int n,A,current,ans;


main(){
	
	cin >> n;
	cin.ignore();
	cin >> e;
	sort(e.begin(),e.end());
	A = 0;
	for(int i=0;i<e.size();i++){
		A += ((int)e[i]) -48;
	}
	current = A;
	ans = 0;
	for(int i=0;i<e.size() and current < n;i++){
		current -= (e[i]-48);
		current += 9;
		if(e[i]=='9')
			break;
		ans++;
	}
	if(current < n)
		ans = 0;
	cout << ans << endl;
}

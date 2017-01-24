#include <bits/stdc++.h>
using namespace std;

const string B = "Bulbasaur";

main(){
	string s;
	int i,j,k;
	int saida;
	cin >> s;

	int v[400];
	memset(v,0,sizeof(v));
	
	for (int i = 0; i < s.size(); ++i)
		++v[s[i]];
		
	v['a'] >>= 1;
	v['u'] >>= 1;
	
	int ans = 1000000000;
	
	for (int i = 0; i < B.size(); ++i)
		ans = min (ans, v[B[i]]);
	cout << ans << '\n';
}




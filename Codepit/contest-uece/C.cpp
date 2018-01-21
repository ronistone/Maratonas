#include <bits/stdc++.h>

using namespace std;

main(){
	
	int n,m,a,k;
	string e;
	
	cin >> n >> m >> a >> k;
	
	cin >> e;
	
	n-=e.size();
	for(int i=0;i<e.size();i++){
		if(e[i] >= 'a' and e[i] <= 'z') m--;
		if(e[i] >= 'A' and e[i] <= 'Z') a--;
		if(e[i] >= '0' and e[i] <= '9') k--;
	}
	
	if(n <= 0 and m <= 0 and a <= 0 and k <= 0)
		cout << "Ok =/" << endl;
	else
		cout << "Ufa :)" << endl;

}

#include <bits/stdc++.h>
using namespace std;

main(){
	int i,n,j,x;
	string e;
	
	cin >> n;
	cin.ignore();
	x = 0;
	for(i=0;i<n;i++){
		getline(cin,e);
		if((e=="x++" or e=="++x") or (e=="X++" or e=="++X"))
			x++;
		else if((e=="x--" or e=="--x") or (e=="X--" or e=="--X"))
			x--;
	}
	cout << x <<"\n";
}

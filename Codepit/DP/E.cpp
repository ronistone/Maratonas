#include <bits/stdc++.h>
using namespace std;

main(){
	string e;
	int i,j,cont=0;
	
	getline(cin,e);
	bool fail = false;
	for(i=0;i<e.size();i++){
		if(e[i]=='7' or e[i]=='4'){
			cont++;
		}
	}
	if(cont==7 or cont==4)
		cout << "YES\n";
	else
		cout << "NO\n";
}

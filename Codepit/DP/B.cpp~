#include <bits/stdc++.h>
using namespace std;

main(){
	int n,i,j;
	string e;
	cin >> n;
	cin.ignore();
	for(i=0;i<n;i++){
		getline(cin,e);
		bool fail = false;
		for(j=0;j<e.size();j++){
			if((j!=0 and tolower(e[j-1])>=tolower(e[j])) or (j!=e.size()-1 and tolower(e[j])>=tolower(e[j+1]))){
				fail = true;
				break;
			}
		}
		if(!fail)
			cout << e << ": O\n";
		else
			cout << e << ": N\n";
	}
}

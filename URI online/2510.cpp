#include <bits/stdc++.h>
using namespace std;

main(){
	string e;
	int n;
	cin >> n;
	cin.ignore();
	for(int i=0;i<n;i++){
		getline(cin,e);
		if(e=="Batmain" or e == "batmain")
			cout << "N" << endl;
		else
			cout << "Y" << endl;
	}

}

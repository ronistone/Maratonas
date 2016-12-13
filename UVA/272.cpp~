#include <bits/stdc++.h>
using namespace std;

main(){
	string E,S;
	int i,j;
	bool abriu = false;
	while(getline(cin,E)){
		for(i=0;i<E.size();i++){
			if(E[i]=='\"' and !abriu){
				S+="``";
				abriu = true;
			}
			else if(E[i]=='\"' and abriu){
				S+="''";
				abriu = false;
			}
			else
				S+=E[i];
		}
		cout << S << endl;
		S.clear();
	}

}

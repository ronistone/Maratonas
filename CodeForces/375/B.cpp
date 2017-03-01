#include <bits/stdc++.h>
using namespace std;


main(){
	int n;
	string e;
	
	while(cin >> n){
		e.clear();
		cin >> e;
		
		int maxL = 0,maxP=0;
		
		bool abriu = false;
		int tamAT = 0;
		int LATOUT = 0;
		for(int i=0;i<n+1;i++){
			if(e[i]=='_' or e[i]=='(' or i==n){
				maxL = max(maxL,LATOUT);
				LATOUT = 0;
			}
			if(e[i]=='('){
				abriu = true;
			}
			else if(abriu){
				if((e[i]>='a' and e[i] <='z') or (e[i]>='A' and e[i] <='Z')){
					tamAT++;
				}
				else if(e[i]=='_' or e[i]==')'){
					if(tamAT)
						maxP++;
					tamAT = 0;
					if(e[i]==')')
						abriu = false;
				}
				
			}
			else if((e[i]>='a' and e[i] <='z') or (e[i]>='A' and e[i] <='Z')){
				LATOUT++;
			}
			
		}
		cout << maxL << " " << maxP << endl;
	}
}

#include <bits/stdc++.h>
using namespace std;

main(){
	string entrada;
	int i,j;

	while(getline(cin,entrada)){
		for(i=0;i<entrada.size();i++){
			if(entrada[i]>='a' && entrada[i]<='z'){
				if(entrada[i]>'z'-13){	
					entrada[i]-=26;
				}
				entrada[i]+=13;
			}
			else if(entrada[i]>='A' && entrada[i]<='Z'){
				if(entrada[i]>'Z'-13)
					entrada[i]-=26;
				entrada[i]+=13;

			}
		}
		cout << entrada << endl;
		entrada.clear();
	}
}
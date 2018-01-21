#include <bits/stdc++.h>
using namespace std;


main(){
	bool m[30],abre,print;
	char a;
	int i;
	string e;
	
	while(getline(cin,e)){
		memset(m,false,sizeof m);
		for(i=0;i<e.size();i++){
			if(e[i]>='a' and e[i] <='z')
				m[e[i]-'a'] = true;
		}
		abre = false;
		print = false;
		for(i=0;i<=26;i++){
			if(m[i] and !abre){
				abre = true;
				a = i+'a';
			}
			else if(!m[i] and abre){
				if(print) cout << ", ";
				cout << a << ":" << (char)((i-1)+'a');
				print = true;
				abre = false;
			}
		}
		cout << endl;
	}
}

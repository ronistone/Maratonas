#include <bits/stdc++.h>
using namespace std;


main(){

	string ans,aux,e;
	list<char> a;
	list<char>::iterator it;
	/*while(cin >> e){
		//cin.ignore();
		ans.clear();
		aux.clear();
		bool ini = false;
		for(int i=0;i<e.size();i++){
			if(e[i]=='['){
				ini = true;
				//continue;
			}
			else if(e[i]==']'){
				ini = false;
				ans = aux + ans;
				aux.clear();
				//continue;
			}
			else if(ini)
				aux += e[i];
			else
				ans += e[i];
		}
		ans = aux+ans;
		cout << ans << endl;
		e.clear();
	}*/
	
	while(cin >> e){
		a.clear();
		it = a.end();
		for(int i=0;i < e.size();i++){
			if(e[i]=='[')
				it = a.begin();
			else if(e[i]==']')
				it = a.end();
			else{
				a.insert(it,e[i]);
			}
		}
		for(it = a.begin();it!=a.end();it++)
			cout << *it;
		cout << endl;
	}
	
}

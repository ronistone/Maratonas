#include <bits/stdc++.h>
using namespace std;

main(){
	stack<char> P;
	string e;
	int n,i,j;

	cin >> n;
	cin.ignore();
	for(i=0;i<n;i++){
		bool falha = false;
		getline(cin,e);
		for(j=0;j<e.size();j++){
			if(e[j]=='[' or e[j]=='{' or e[j]== '(')
				P.push(e[j]);
			else if(e[j]==']'){
				if(P.size()!=0 and P.top()=='[')
					P.pop();
				else{
					falha = true;
					break;
				}
			}
			else if(e[j]=='}'){
				if(P.size()!=0 and P.top()=='{')
					P.pop();
				else{
					falha = true;
					break;
				}
			}
			else if(e[j]==')'){
				if(P.size()!=0 and P.top()=='(')
					P.pop();
				else{
					falha = true;
					break;
				}
			}
		}
		if(P.size()!=0)
			falha = true;

		if(!falha)
			cout << "S" << endl;
		else
			cout << "N" << endl;
		while(P.size()!=0)
			P.pop();
	}
}
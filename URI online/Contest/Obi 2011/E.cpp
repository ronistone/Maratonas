#include <bits/stdc++.h>
using namespace std;

main(){
	int n,i,j;
	string e;
	stack<char> s;
	bool falha;
	
	cin >> n;
	cin.ignore();
	for(i=0;i<n;i++){
		getline(cin,e);
		falha = false;
		for(j=0;j<e.size();j++){
			if(e[j]=='{' or e[j]=='[' or e[j]=='(')
				s.push(e[j]);
			else if(s.empty() or (e[j]=='}' and s.top()!='{')){
				falha = true;
				break;
			}
			else if(s.empty() or (e[j]==']' and s.top()!='[')){
				falha = true;
				break;
			}
			else if(s.empty() or (e[j]==')' and s.top()!='(')){
				falha = true;
				break;
			}
			else
				s.pop();
			
		}
		if(!falha and s.empty())
			cout << "S\n";
		else
			cout << "N\n";
		while(!s.empty())
			s.pop();
	}
}

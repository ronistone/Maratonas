#include <bits/stdc++.h>
using namespace std;

main(){
	string l,e,q;
	map<char,bool> good;
	int n;
	cin >> l;
	cin.ignore();
	for(int i=0;i<l.size();i++)
		good[l[i]] = true;
	cin >> e;
	cin.ignore();
	cin >> n;
	cin.ignore();
	bool fail;
	for(int k=0;k<n;k++){
		getline(cin,q);
		fail = false;
		for(int j=0,i=0;j<q.size() and !fail;i++,j++){
			if(e[i]=='?' and !good[q[j]])
				fail = true;
			else if(e[i]=='*' and good[q[j]]){
				if((e[i+1]!='?') or (e[i+1]=='?' and good[q[j+1]]))
					i++;
				else
					fail = true;
			}
			else if(e[i]!=q[j] and e[i]!='?' and e[i]!='*')
				fail = true;
		}
		if(!fail)
			cout << "YES" << endl;
		else
			cout << "NO" << endl;
	}
	
}

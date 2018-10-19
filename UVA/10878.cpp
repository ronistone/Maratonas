#include <bits/stdc++.h>
using namespace std;

string endS = "___________";

main(){
	string e;
	vector<string> m;
	vector<int> d;
	int shift;
	int let;
	
	
	getline(cin, e);
	m.push_back(e);
	
	while(getline(cin, e) and e!=endS)
		m.push_back(e);
		
	for(int i=1;i<m.size();i++){
		shift = 0;
		let = 0 ;
		for(int j=m[i].size()-1; j>0;j--){
			if(m[i][j]=='o')
				let |= (1<<shift);
			if(m[i][j]=='o' or m[i][j]==' ')
				shift++;
		}
		cout << ((char) let);
		if(let==((int)'\n'))
			d.push_back(i);
	}
}

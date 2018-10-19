#include <bits/stdc++.h>
using namespace std;


main(){
	
	map<string, vector<string> > map;
	string a, b;
	int n, m;
	
	cin >> n >> m;
	cin.ignore();
	for(int i=0;i<n;i++){
		cin >> a >> b;
		cin.ignore();
		map[a].push_back(b);
	}
	for(int i=0;i<m;i++){
		cin >> a >> b;
		cin.ignore();
		if(find(map[a].begin(), map[a].end(), b)!=map[a].end())
			cout << "Nao e a mamae" << endl;
		else
			cout << "nao e o Nao e a mamae" << endl;
	}

}

#include <bits/stdc++.h>
using namespace std;

main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n,i,j;
	string entrada;
	vector<string> v;
	
	while(cin >> n){
		for(i=0;i<n;i++){
			cin >> entrada;
			v.push_back(entrada);
		}
		sort(v.begin(),v.end());
		long long saida = 0;
		for(i=1;i<v.size();i++){
			for(j=0;j<v[i].size() and j<v[i-1].size();j++){
				if(v[i][j]==v[i-1][j])
					saida++;
				else
					break;
			}
		}
		cout << saida << endl;
		v.clear();
	}

}

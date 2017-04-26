#include <bits/stdc++.h>
using namespace std;




main(){
	int n,m,aux;
	bool ca[1010],cb[1010];
	vector<int> a,b,a1,b1;

	while(cin >> n >> m and (n and m)){
		memset(a,false,sizeof a);
		memset(b,false,sizeof b);
		for(int i=0;i<n;i++){
			cin >> aux;
			if(!ca[aux]){
				a.push_back(aux);
				ca[aux] = true;
			}
		}
		for(int i=0;i<m;i++){
			cin >> aux;
			if(!cb[aux]){
				b.push_back(aux);
				cb[aux] = true;
				if(!ca[aux])
					b1.push_back(aux);
			}
		}
		for(int i=0;i<a.size();i++){
			if(!cb[a[i]])
				a1.push_back(a[i]);
		}
		cout << min(a1.size(),b1.size()) << endl;
		a.clear();
		b.clear();
		a1.clear();
		b1.clear();
	}

}

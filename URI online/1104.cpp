#include <bits/stdc++.h>
using namespace std;




main(){
	int n,m,aux,a1,b1;
	bool ca[100100],cb[100100];
	vector<int> a,b;

	while(cin >> n >> m and (n and m)){
		memset(ca,false,sizeof ca);
		memset(cb,false,sizeof cb);
		a1=0;
		b1=0;
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
					b1++;
			}
		}
		for(int i=0;i<a.size();i++){
			if(!cb[a[i]])
				a1++;
		}
		cout << min(a1,b1) << endl;
		a.clear();
		b.clear();
	}

}

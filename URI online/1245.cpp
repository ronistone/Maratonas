#include <bits/stdc++.h>
using namespace std;

main(){
	int n,i,j,aux;

	while(cin >> n){
		std::vector<int> v;
		char pe[n];
		int count =0;
		for(i=0;i<n;i++){
			cin >> aux >> pe[i];
			v.push_back(aux);
		}
		for(i=0;i<n;i++){
			for(j=0;j<n;j++){
				if(j!=i && v[i]==v[j] &&  v[i]!=0 && v[j]!=0 && ((pe[i]=='D' && pe[j]=='E') || (pe[i]=='E' && pe[j]=='D'))){
					v[i] = 0;
					v[j] = 0;
					count++;
				}
			}
		}
		cout << count << endl;
	}
}
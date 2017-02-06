#include <bits/stdc++.h>
using namespace std;

main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n,m;
	
	cin >> n;
	
	for(int k=0;k<n;k++){
		cin >> m;
		int num[m+1];
		for(int i=0;i<m;i++){
			cin >> num[i];
		}
		int ans = 0,cont;
		for(int i=0;i<m;i++){
			cont=0;
			for(int j=0;j<i;j++){
				if(num[i]>=num[j])
					cont++;
			}
			ans+=cont;
		}
		cout << ans << endl;
		
	}
}

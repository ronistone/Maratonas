#include <bits/stdc++.h>
using namespace std;

main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int i,j,k,n,q,qu,cas=0;
	int num[1005];
	while(cin >> n and n){
		cas++;
		cout << "Case " << cas << ":" << endl;
		for(i=0;i<n;i++){
			cin >> num[i];
		}
		cin >> q;
		for(k=0;k<q;k++){
			cin >> qu;
			int x1,x2,dif=100000000,sum;
			for(i=0;i<n;i++){
				for(j=0;j<n;j++){
					int temp = abs((num[i]+num[j]) - qu);
					if(i!=j and temp <= dif ){
						sum = num[i]+num[j];
						dif = temp;
					}
				}
			}
			cout << "Closest sum to " << qu << " is " << sum << "." << endl;
		}
	}
}

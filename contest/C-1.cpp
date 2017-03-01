#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;

ll D[300];
int n,L;
main(){
	int z;
	cin >> z;
	
	for(int i=0;i<z;i++){
		cin >> n >> L;
		
		for(int j=0;j<n;j++){
			cin >> D[j];
		}
		ll maior = -100000000000000000;
		for(int i=0;i<n-L+1;i++){
			ll sum = 0;
			ll sum_n = 0;
				for(int j=i;j<i+L;j++){
					sum+=D[j];
				}
			if(sum > maior){
				maior = sum;
			}
		}
		cout << maior << endl;
	}
}

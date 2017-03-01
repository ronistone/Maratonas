#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;


ll D[10100];
ll n,num,X,mid;

ll binary_search(ll lo, ll hi){
	mid = (lo+hi)/2;
	if(lo > hi or mid == X) return -1;
	if(num==D[mid]) return mid;
	else if(num < D[mid]) return binary_search(lo,mid-1);
	else if(num > D[mid]) return binary_search(mid+1,hi);
}

main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	ll y,ans,ans1,aux;
	
	while(cin >> n){
		for(int i=0;i<n;i++){
			cin >> D[i];
		}
		cin >> y;
		sort(D,D+n);
		ans = -1;
		ans1 = -1;
		for(X=0;X<n;X++){
			num = y - D[X];
			aux = -1;
			if(num < D[X])
				aux = binary_search(0,X-1);
			if(aux !=-1){
				if(ans==-1){
					ans = aux;
					ans1 = X;
				}
				else{
					if(abs(D[X]-D[aux]) < abs(D[ans]-D[ans1])){
							ans = aux;
							ans1 = X;
					}
				}
			}
		}
		if(ans <= ans1)
			cout << "Peter should buy books whose prices are " << D[ans] << " and " << D[ans1] << "." << endl;
		else
			cout << "Peter should buy books whose prices are " << D[ans1] << " and " << D[ans] << "." << endl;
		cout << endl;
	}
}

#include <bits/stdc++.h>
using namespace std;


typedef long long int ll;

main(){

	ll z, A[1100],sum,n;
	double media,ans;
	cin >> z;
	
	
	for(int k=0;k<z;k++){
		sum = 0;
		cin >> n;
		
		for(int i=0;i<n;i++){
			cin >> A[i];
			sum += A[i];
		}
		
		media = sum /n;
		ans = 0;
		for(int i=0;i<n;i++){	
			if(A[i] > media)
				ans++;
		}
		
		cout << fixed << setprecision(3) << (double)(ans/n)*100 << "%" << endl;
	
	}


}

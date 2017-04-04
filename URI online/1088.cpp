#include <bits/stdc++.h>
using namespace std;

vector<int> A(100010);
vector<int> B(100010);

main(){
	int n,aux,i,ans,j;
	while(cin >> n and n){
		ans = 0;
		for(i=0;i<n;i++){
			cin >> A[i];
			B[i] = A[i];
		}
		sort(B.begin(),B.end());
		for(i=0;i<n;i++){
			if(A[i]!=B[i])
				ans++;
		}
		if(ans%2==0)
			cout << "Carlos" << endl;
		else
			cout << "Marcelo" << endl;
			
		for(i=0;i<n;i++)
			cout << A[i] << " ";
		cout << endl;
		for(i=0;i<n;i++)
			cout << B[i] << " ";
		cout << endl;
	}

}

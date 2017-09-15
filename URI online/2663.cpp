#include <bits/stdc++.h>
using namespace std;


main(){
	int n,k,aux,ans=0;
	map<int,int> A;
	map<int,int>::reverse_iterator it;
	
	cin >> n >> k;
	
	for(int i=0;i<n;i++){
		cin >> aux;
		A[aux]++;
	}
	for(it = A.rbegin(); it != A.rend();it++){
		ans += it->second;
		if(ans >= k) break;
	}
	
	cout << ans << endl;
	
	/*
	sort(A,A+n);
	cout << A[0] << endl;
	int i,x,j;
	for(i=n-1, x=0;i>=0 and x<k;i--,x++);
	j=i++;
	while(j>=0 and A[j]==A[i] and x++ and j--);
	*/
}

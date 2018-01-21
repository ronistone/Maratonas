#include <bits/stdc++.h>
using namespace std;

main(){
	
	int n,x,A[100100],p;
	cin >> n >> x;
	
	for(int i=0;i<n;i++){
		cin >> A[i];
	}
	
	bool falhou = false;
	for(int k=0;k<10;k++){
		p = k;
		for(int i=0;i<n and !falhou;i++){
			if(i!=n-1)
				p += A[i]+1;
			else
				p += A[i];
			if(p > x) falhou = true;
		}
		if(falhou and k == 1){
			cout << "YES" << endl;
			break;
		}
		else if((!falhou and k > 0) or (falhou and k==0)){
			cout << "NO" << endl;
			break;
		}
			
	}
}

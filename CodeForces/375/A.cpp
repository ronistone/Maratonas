#include <bits/stdc++.h>
using namespace std;


main(){

	int A[3];
	
	for(int i=0;i<3;i++){
		cin >> A[i];
	}
	sort(A,A+3);
	
	int d = 10e6;
	int	ans= -1;
	
	for(int i=A[0];i<=A[2];i++){
		int t = abs(i-A[0])+abs(i-A[1])+abs(i-A[2]);
		if(t < d){
			d = t;
		}
	}
	cout << d << endl;

}

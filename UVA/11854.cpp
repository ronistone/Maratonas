#include <bits/stdc++.h>
using namespace std;

main(){
	int A[3];
	while(cin >> A[0] >> A[1] >> A[2] and (A[0] or A[1] or A[2])){
		
		sort(A,A+3);
		if(A[2]*A[2] == (A[1]*A[1])+(A[0]*A[0]))
			cout << "right" << endl;
		else
			cout << "wrong" << endl;
	
	}

}

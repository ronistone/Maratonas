#include <bits/stdc++.h>
using namespace std;
#define F first
#define S second
#define mp make_pair
#define pb push_back

typedef long long int ll;


main(){
	int A[4][4];
	
	for(int i=0;i<4;i++){
		for(int j=0;j<4;j++){
			cin >> A[i][j];
		}
	}
	bool falha = false;
	if(A[0][3]){
		if(!(!A[0][0] and !A[0][1] and !A[0][2] and !A[1][0] and !A[2][1] and !A[3][2]))
			falha = true;
	}
	if(A[1][3] and !falha){
		if(!(!A[1][0] and !A[1][1] and !A[1][2] and !A[0][2] and !A[2][0] and !A[3][1]))
			falha = true;
	}
	if(A[2][3] and !falha){
		if(!(!A[2][0] and !A[2][1] and !A[2][2] and !A[0][1] and !A[1][2] and !A[3][0]))
			falha = true;
	}
	if(A[3][3] and !falha){
		if(!(!A[3][0] and !A[3][1] and !A[3][2] and !A[0][0] and !A[1][1] and !A[2][2]))
			falha = true;
	}
	if(!falha)
		cout << "NO" << endl;
	else
		cout << "YES" << endl;
	

}

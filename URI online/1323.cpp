#include <bits/stdc++.h>
using namespace std;

int calcula(int n){
	if(n==1)
		return 1;
	return calcula(n-1)+(n*n);
}

main(){
	int n;
	cin >> n;
	while(n!=0){
		cout << calcula(n) << endl;
		cin >> n;
	}
}
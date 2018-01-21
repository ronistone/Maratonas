#include <bits/stdc++.h>
using namespace std;


main(){
	string e;
	int n,k;
	cin >> n >> k;
	
	cin >> e;
	
	k = (k)%n;
	for(int i=n-k;i<n;i++){
		cout << e[i];
	}
	for(int i=0;i<n-k;i++)
		cout << e[i];
		
	cout << endl;

}

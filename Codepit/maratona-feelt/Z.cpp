#include <bits/stdc++.h>
using namespace std;

main(){
	
	double sum = 0;
	int n;
	
	cin >> n;
	
	for(int i=1;i<=n;i++){
		sum += log10(i);
	}
	
	cout << (int)(sum + 1) << endl;
	
}

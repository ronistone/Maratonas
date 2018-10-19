#include <bits/stdc++.h>
using namespace std;

main(){
	
	int n,a;
	cin >> n;
	
	for(int i=0;i<n;i++){
		cin >> a;
		if(i!=0)
			cout << " ";
		if(a%2){
			cout << a;
		}else{
			cout << a-1;
		}
		
	}
	cout << endl;
	
}

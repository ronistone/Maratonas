#include <bits/stdc++.h>
using namespace std;


main(){
	int n;
	cin  >> n;
		
	for(int i=0;i<(1<<n);i++){
		for(int k=n-1;k>=0;k--){
			if((1<<k)&i)
				cout << 1;
			else
				cout << 0;
			if(k!=0)
				cout << " ";
		}
		cout << endl;
	}
	
}

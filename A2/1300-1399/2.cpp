#include <bits/stdc++.h>
using namespace std;

main(){
	int a;
	for(int i=0;i<5;i++){
		for(int j=0;j<5;j++){
			cin >> a;
			if(a==1){
				cout << abs(i-2)+abs(j-2) << endl;
			}
		}
	}
	
}

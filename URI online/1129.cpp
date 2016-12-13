#include <bits/stdc++.h>
using namespace std;

main(){
	int n, a[5], i, j,posi;
	bool acha,falha;
	cin >> n;
	while(n!=0){
		for(i=0;i<n;i++){
			acha = falha = false;
			for(j=0;j<5;j++){
				cin >> a[j];
				if(!acha && a[j]<=127){
					acha = true;
					posi = j;
				}
				else if(acha && a[j]<=127)
					falha = true;
			}
			if(falha || !acha)
				cout << "*" << endl;
			else if(posi ==0)
				cout << "A" << endl;
			else if(posi ==1)
				cout << "B" << endl;
			else if(posi ==2)
				cout << "C" << endl;
			else if(posi ==3)
				cout << "D" << endl;
			else if(posi ==4)
				cout << "E" << endl;


		}

		cin >> n;
	}
}
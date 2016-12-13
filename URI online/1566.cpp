#include <bits/stdc++.h>
using namespace std;

main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int n,i,j,z;
	short int aux;
	int m[240];
	bool achou;
	cin >> n;
	for(i=20;i<=230;i++)
		m[i]=0;
	for(i=0;i<n;i++){
		cin >> z;
		for(j=0;j<z;j++){
			cin >> aux;
			m[aux]++;
		}
		int x;
		for(j=20,achou = false,x=0;j<231 and x<z;j++){
			for(int q=0;q<m[j];q++,x++){
				if(achou)
					cout << " ";
				cout << j;
				achou = true;
			}
			m[j] = 0;
		}
		cout << endl;
	}

}

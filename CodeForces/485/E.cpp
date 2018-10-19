#include <bits/stdc++.h>
using namespace std;

int a[10000], g[10000],t;


void print(){
	for(int i=0;i<t;i++){
		cout << g[i] << "  ";
	}
	cout << endl;
}


main(){

	int ans=0;
	cin >> t;
	
	for(int i=0;i<t;i++){
		cin >> a[i];
		a[i]--;
		g[a[i]] = i;
	}
	
	for(int i=0;i<t;i++){
		if(g[i]!=i){
			g[a[i]] = g[i];
			print();
			ans++;
		}
	}
	
	//if(a%2==1)
		//cout << "Petr" << endl;
	//else
		//cout << "Um_nik" << endl;
	
}

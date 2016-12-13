#include <bits/stdc++.h>
using namespace std;
vector <unsigned long long> fat;


unsigned long long fatorial(unsigned long long n){
	unsigned long long saida = 1;
	int i;
	if(fat.size()>n){
		return fat[n]; 
	}
	else{
		for(i=fat.size(),saida = fat[i-1];i<=n;i++){
			saida *= i;
		}
		return saida;
	}
}


main(){
	
	int n,z,i,j;
	unsigned long long saida;
	cin >> n;
	
	for(i=0;i<n;i++){
		cin >> z;
		for(j=0,saida = 0;j<z;j++){
			saida+= pow(2,j);
		}
		cout << saida << endl;
	}
}

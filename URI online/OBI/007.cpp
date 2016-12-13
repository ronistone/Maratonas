#include <iostream>

using namespace std;

int main(){
	int n,i,j,verifica = 1;
	cin >> n;
	int v[n],posi[n];
	for(i=0;i<n;i++){
		cin >> v[i];
		posi[i]= i+1;
	}
	for(i=0;verifica==1;i++){
		verifica = 0;
		for(j=0;j<n;j++){
			posi[j]=v[(posi[j]-1)];
			if(posi[j]!=j+1){
				verifica=1;
			}
		}
	}
	cout << i << endl;
return 0;
}
#include <iostream>

using namespace std;

int main(){
	int n;
	cin >> n;
	int i, x[n],y[n],aux;

	for(i=0;i<n;i++){
		cin >> x[i] >> y[i];
	}
	for(i=0;i<n;i++){
		if(y[i]<x[i]){
			aux = x[i];
			x[i] = y[i] ;
			y[i] = aux;
		}
		aux=0;
		for(x[i]++;x[i]<y[i];x[i]++){
			if(x[i]%2!=0){
				aux+=x[i];
			}
		}
		cout << aux << endl;
	}
return 0;
}
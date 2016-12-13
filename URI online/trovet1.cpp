#include <iostream>

using namespace std;

int main(){
	int v[20],i,j=19,aux;

	for(i=0;i<20;i++)
		cin >> v[i];
	
	for(i=0;i<10;i++){
		aux = v[i];
		v[i] = v[j];
		v[j] = aux;
		j--;
	}
	for(i=0;i<20;i++){
		cout << "N[" << i << "] = " << v[i] << endl;
	}
return 0;
}
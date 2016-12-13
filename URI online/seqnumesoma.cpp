#include <iostream>
#include <cstdlib>

using namespace std;

int main(){
	int m[2000], n[2000],i,aux,soma,j;
	for(i=2;;i++){
		cin >> m[i] >> n[i];
		if(m[i]<=0 || n[i]<=0)
			break;
		if(n[i]>m[i]){
			aux = n[i] ;
			n[i] = m[i] ;
			m[i] = aux;
		}
	}
	aux = i;
	for(j=2;j<i;j++){
		soma=0;
		for(;n[j]<=m[j];n[j]++){
			cout << n[j] << " ";
			soma += n[j];
		}
		cout << "Sum=" << soma << endl;
	}
return 0;
}
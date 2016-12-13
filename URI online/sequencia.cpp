#include <iostream>

using namespace std;

/*int conta(int n){
	if(n=0)
		return 1;
	else
		return n+conta(n-1);
}*/

int main(){
	int n,i,j=0,c=1,aux;

	while(cin >> n){
		aux=0;
		for(i=0;i<=n;i++){
			if(i==0)
				aux++;
			else
			for(j=0;j<i;j++){
				aux++;
			}
		}
		if(aux<=1)
			cout << "Caso " << c << ": " << aux << " numero" << endl;
		else
			cout << "Caso " << c << ": " << aux << " numeros" << endl;
		for(i=0;i<=n;i++){
			if(i==0)
				cout << i <<" ";
			else
			for(j=0;j<i;j++){
				cout << i <<" ";
			}
		}
		c++;
	}

return 0;
}
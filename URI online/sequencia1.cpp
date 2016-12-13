#include <iostream>

using namespace std;

int conta(int n){
	if(n==0)
		return 1;
	else
		return n+conta(n-1);
}

int main(){
	int n,i,j=0,c=1,aux;

	while(cin >> n){
		aux=0;
		aux = conta(n);
		if(aux<=1)
			cout << "Caso " << c << ": " << aux << " numero" << endl;
		else
			cout << "Caso " << c << ": " << aux << " numeros" << endl;
		for(i=0;i<=n;i++){
			if(i!=0)
				for(j=0;j<i;j++){
					cout << i;
					if(i!=n)
						cout << " ";
					if(i==n && j!=i-1)
						cout << " ";
				}
			else{
				cout << i;
				if(i!=n)
					cout << " ";
			}

		}
		cout << endl << endl;
		c++;
	}

return 0;
}
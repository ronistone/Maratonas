#include <iostream>

using namespace std;

int main(){
	float i, j=1,x,aux=1;

	for(i=0;i<=2.2;i+=0.2){
		for(x=0;x<3;x++){
			cout << "I=" << i << " J=" << j << endl;
			j++;

		}
		aux+=0.2;
		j=aux;

	}
return 0;
}
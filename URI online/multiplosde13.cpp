#include <iostream>

using namespace std;

int main(){
	int x,y,aux;

	cin >> x >> y;

	if(x>y){
		aux=x;
		x=y;
		y=aux;
	}
	aux=0;
	for(;x<=y;x++){
		if(x%13!=0){
			aux+=x;
		}
	}
	cout << aux << endl;
return 0;
}
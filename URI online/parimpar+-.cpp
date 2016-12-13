#include <iostream>

using namespace std;

int main(){
	int n[5],i,par=0,impar=0,positivo=0,negativo=0;
	
	for(i=0;i<5;i++){
		cin >> n[i];
		if(n[i]%2==0)
			par++;
		if(n[i]%2!=0)
			impar++;
		if(n[i]>0)
			positivo++;
		if(n[i]<0)
			negativo++;
	}
	cout << par << " valor(es) par(es)\n";
	cout << impar << " valor(es) impar(es)\n";
	cout << positivo << " valor(es) positivo(s)\n";
	cout << negativo << " valor(es) negativo(s)\n";
return 0;
}
#include <iostream>
#include <cstdio>

using namespace std;

int main(){
	float x[2];
	int i=0, o=0;
do{
	for(;;){
		if(i==2)
			break;
		cin >> x[i];
		if(x[i]>=0 && x[i]<=10)
			i++;
		else
			cout << "nota invalida\n";
	}
	i=0;
	x[0] += x[1];
	x[0] /= 2;
	printf("media = %.2f\n", x[0]);
	for(o=0;;){
	cout << "novo calculo (1-sim 2-nao)\n";
	cin >> o;
	if(o==1 || o==2)
		break;
	}
}while(o!=2);
return 0;
}
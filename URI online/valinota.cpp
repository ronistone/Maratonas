#include <iostream>
#include <cstdio>

using namespace std;

int main(){
	float x[2];
	int i=0;

	for(;;){
		if(i==2)
			break;
		cin >> x[i];
		if(x[i]>=0 && x[i]<=10)
			i++;
		else
			cout << "nota invalida\n";
	}
	x[0] += x[1];
	x[0] /= 2;
	printf("media = %.2f\n", x[0]);
return 0;
}
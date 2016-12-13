#include <iostream>
#include <cstdio>

using namespace std;

int main(){

	double v,dia,raio,ab,al,h,pi=3.14,area;

	while(cin >> v >> dia){
		raio = dia/2;
		ab = (pi*((raio)*(raio)));
		h = v/ab;
		al = (2*pi*raio)*h;
		area = al + (2*ab);
		printf("ALTURA = %.2lf\nAREA = %.2lf\n", h,ab);
	}
return 0;
}
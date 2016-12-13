#include <iostream>
#include <cstdio>

using namespace std;

int main (){
	float s, f, p;

	cin >> s;

	if((s >= 0) && (s <= 400))
		p = 0.15;
	else if((s >= 400.01) && (s <= 800))
		p = 0.12;
	else if((s >= 800.01) && (s <= 1200))
		p = 0.10;
	else if((s >= 1200.01) && (s <= 2000))
		p = 0.07;
	else if(s > 2000)
		p =	0.04;

	f = s * (1+p);
	s = s * p;
	p = p * 100;
	printf("Novo salario: %.2f\nReajuste ganho: %.2f\nEm percentual: %.0f",f,s,p);
	cout << " %\n";

return 0;
}
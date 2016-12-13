#include <iostream>
#include <cstdio>

using namespace std;

int main()
{
	float n[3],r=0;
	int i;
	for(i=0;i<3;i++)
		cin >> n[i];
	if(( (n[0] + n[1]) > n[2]) && ((n[1]+n[2]) > n[0]) && ((n[2]+n[0]) > n[1])){
		r = n[0] + n[1] + n[2];
		printf("Perimetro = %.1f\n", r);
	}
	else{
		r = ( (n[0] + n[1])/2 ) * n[2];
		printf("Area = %.1f\n", r);
	}
	return 0;
}
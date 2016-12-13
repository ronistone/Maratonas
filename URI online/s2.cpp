#include <iostream>
#include <cstdio>

using namespace std;

int main(){

	float c=3,b,i,s=1;

	for(i=2;c<=39;i=i*2){
		s+= c/i;
		c+=2;
	}
	printf("%.2f\n", s);
return 0;
}
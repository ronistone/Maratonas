#include <iostream>
#include <cstdio>

using namespace std;

int main(){
	int n,cod,x,i;
	float s=0;
	cin >> x;

	for(i=0;i<x;i++){
		cin >> cod >> n;
		if(cod==1001)
			s += n* 1.50;
		else if(cod==1002)
			s += n* 2.50;
		else if(cod==1003)
			s += n* 3.50;
		else if(cod==1004)
			s += n* 4.50;
		else if(cod==1005)
			s += n* 5.50;
	}
	printf("%.2f\n", s);
return 0;
}
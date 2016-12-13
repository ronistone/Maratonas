#include <iostream>
#include <cstdio>

using namespace std;

int main(){
	
	double x,y,num;

	cin >> x >> y;

	if(x!=0 && y==0)
		num = -100;
	else if(x<y)
		num = (((y/x)-1)*100);
	else
		num = (((x/y)-1)*100);

	printf("%.2lf", num);
	cout << "%\n";
return 0;
}
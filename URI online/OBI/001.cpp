#include <iostream>

using namespace std;

int main(){
	int a,b,c,d;

	cin >> a >> b >> c;

	d = a+b+c;
	if(d > 23){
		d-=24;
		if(d<0)
			d = -d;
	}
	else if(d < 0){
		d +=24;	
	}
	cout << d << "\n";

return 0;
}
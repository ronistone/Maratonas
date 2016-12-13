#include <iostream>

using namespace std;

int main(){
	int x,z,i,s=0,c=0;

	cin >> x >> z;
	while(z<=x)
		cin >> z;

	for(i=x;;i++){
		s+=i;
		c++;
		if(s>=z)
			break;
	}
	cout << c << endl;
return 0;
}
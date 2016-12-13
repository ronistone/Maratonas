#include <iostream>

using namespace std;

int main(){
	int c1,c2, c3;

	cin >> c1 >> c2;

	if(c1==c2)
		c3 = c1;
	else{
		if(c1>c2)
			c3 = c1;
		else
			c3 = c2;
	}
	cout << c3 << endl;

return 0;
}
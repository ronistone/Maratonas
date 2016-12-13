#include <iostream>

using namespace std;

int main(){
	float v,t,d,a;
	int i;

	while(cin >> v >> t){
		a = v/t;
		t *= 2;
		d = 0;
		v = 0;
		for(i=0;i<t;i++){
			v += a;
			d += v;
		}
		cout << d << endl;
	}

return 0;
}
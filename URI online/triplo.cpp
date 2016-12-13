#include <iostream>

using namespace std;

int main(){
	double x, y;
	while(cin >> x){
		y = x*x*x;
		cout << "Triplo de " << x << " é: " <<y << endl;
	}
return 0;
}
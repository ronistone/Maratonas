#include <iostream>

using namespace std;

int main(){
	int o, i, n[5], aux=0;

	cin >> o;

	for(i=0;i<5;i++){
		cin >> n[i];
		if(n[i]==o)
			aux++;
	}
	cout << aux << endl;
return 0;
}
#include <iostream>

using namespace std;

int main(){
	int v[10],i;

	cin >> v[0];

	for(i=1;i<10;i++){
		v[i]= v[i-1] *2;
	}
	for(i=0;i<10;i++)
		cout << "N[" << i << "] = " << v[i] << endl;
return 0;
}
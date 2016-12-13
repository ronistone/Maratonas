#include <iostream>

using namespace std;

int main(){
	int n[6],i;
	n[5]=0;
	for(i=0;i<5;i++){
		cin >> n[i];
		if(n[i]%2==0)
			n[5]++;
	}
	cout << n[5] << " valores pares\n";
return 0;
}
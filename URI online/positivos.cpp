#include <iostream>

using namespace std;

int main(){
	float n[6];
	int i,c=0;

	for(i=0;i<6;i++){
		cin >> n[i];
		if(n[i]>0)
			c++;
	}
	cout << c << " valores positivos\n";
return 0;
}
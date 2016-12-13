#include <iostream>

using namespace std;

int main(){
	int i, j,x;

	for(i=1;i<=9;i+=2){
		j=7;
		for(x=0;x<3;x++){
			cout << "I=" << i << " J=" << j << endl;
			j--;

		}
	}
return 0;
}
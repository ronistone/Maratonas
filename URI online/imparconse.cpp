#include <iostream>

using namespace std;

int main() {
	int x,i,count=0;
	cin >> x;

	for(i=x;count<6;i++){
		if(i%2!=0){
			cout << i << endl;
			count++;
		}
	}
	return 0;
}
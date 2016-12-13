#include <iostream>

using namespace std;

int main(){
	float x;
	int i,n,j;

	cin >> n;
	for(i=0;i<n;i++){
		cin >> x;
		for(j=0;x>1;j++){
			x /=2;
		}
		cout << j << " dias" << endl;
	}

return 0;
}
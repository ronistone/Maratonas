#include <iostream>

using namespace std;

int main(){
	int pum=0,i,n,j;

		cin >> n;

		for(i=0;i<n;i++){
			for(j=0;j<3;j++){
				pum++;
				cout << pum << " ";
			}
			cout << "PUM\n";
			pum++;
		}
return 0;
}
#include <iostream>

using namespace std;

int main(){
	int n[100],i,maior= -1000,posi= -1000;

	for(i=0;i<100;i++){
		cin >> n[i];
		if(n[i]>maior){
			maior = n[i];
			posi = i;
		}
	}
	cout << maior << endl << posi+1 <<endl;
return 0;
}
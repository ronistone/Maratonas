#include <iostream>

using namespace std;

int main(){
	int n,i,j,v=0;
	cin >> n;
	int mat[n];
	float nota[n],x;

	for(i=0;i<n;i++){
		cin >> mat[i] >> nota[i];
	}
		x = nota[0];
		for(i=0;i<n;i++){
			if(nota[i]>x && nota[i]>=8){
				x = nota[i];
				j = i;
				v = 1;
			}
		}
		if(v==1)
			cout << mat[j] << endl;
		else
			cout << "Minimum note not reached" << endl;
return 0;
}
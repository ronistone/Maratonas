#include <iostream>

using namespace std;

int main(){
	float n[6],m=0;
	int i,j=0,c=0;

	for(i=0;i<6;i++){
		cin >> n[i];
		if(n[i]>0){
			c++;
			m += n[i];
			j++;
		}
	}
	m /= c;
	cout << c << " valores positivos\n" << m << endl;
return 0;
}
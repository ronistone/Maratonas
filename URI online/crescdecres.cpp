#include <iostream>

using namespace std;

int main(){
	int x[2000],y[2000],i,j;
		for(i=0;;i++){
			cin >> x[i] >> y[i];
			if(x[i]==y[i])
				break;
		}
		for(j=0;j<i;j++){
			if(x[j]>y[j])
				cout << "Decrescente" << endl;
			else if(x[j]<y[j])
				cout << "Crescente" << endl;
		}
return 0;
}
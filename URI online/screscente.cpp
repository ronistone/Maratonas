#include <iostream>

using namespace std;

int main(){
	int i,o;
	do{
		cin >> o;
		if(o!=0){
			for(i=1;i<=o-1;i++)
				cout << i << " ";
			cout << o << endl;
		}
	}while(o!=0);

return 0;
}
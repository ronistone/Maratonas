#include <iostream>

using namespace std;

int main(){
	int x, y;

	for(;;){
		cin >> x >> y;
		if(x==0 || y==0)
			break;
		if(x>0 && y>0)
			cout << "primeiro\n";
		else if(x<0 && y>0)
			cout << "segundo\n";
		else if(x<0 && y<0)
			cout << "terceiro\n";
		else if(x>0 && y<0)
			cout << "quarto\n";
	}
return 0;
}
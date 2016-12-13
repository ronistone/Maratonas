#include <iostream>

using namespace std;

int main(){
	int a=0,g=0,d=0,o=0;
	while(o!=4){
		cin >> o;

		switch(o){
			case 1:
				a++;
			break;
			case 2:
				g++;
			break;
			case 3:
				d++;
		}
	}
	cout << "MUITO OBRIGADO\nAlcool: " << a << "\nGasolina: " << g << "\nDiesel: " << d << endl;
return 0;
}
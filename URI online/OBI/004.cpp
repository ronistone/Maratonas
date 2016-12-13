#include <iostream>

using namespace std;

int main(){
	int p,j1,j2,r,a,jr;
	cin >> p >> j1 >> j2 >> r >> a;

	jr = j1+j2;

	if(p==1){
		if(jr%2==0){
			if(r==1 && a==1){
				cout << "Jogador 2 ganha!\n";
			}
			else
				cout << "Jogador 1 ganha!\n";
		}
		else{
			if(r == 1 && a==0)
				cout << "Jogador 1 ganha!\n";
			else
				cout << "Jogador 2 ganha!\n";
		}
	}
	else{
		if(jr%2==0){
			if(r==1 && a==0){
				cout << "Jogador 1 ganha!\n";
			}
			else
				cout << "Jogador 2 ganha!\n";
		}
		else{
			if(r == 1 && a==1)
				cout << "Jogador 2 ganha!\n";
			else
				cout << "Jogador 1 ganha!\n";
		}
	}
return 0;
}
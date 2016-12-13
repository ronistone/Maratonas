#include <iostream>
#include <cstdio>

using namespace std;

int main(){
	int h,m,tempo;

	while(scanf("%d:%d", &h,&m)!=EOF){
		tempo = h + 1;
		tempo *=60;
		tempo += m;
		if(tempo>=480){
			tempo -=480;
			cout << "Atraso maximo: " << tempo << endl;
		}
		else
			cout << "Atraso maximo: 0" << endl;

	}
return 0;
}
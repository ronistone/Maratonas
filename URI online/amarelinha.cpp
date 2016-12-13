#include <iostream>
#include <string.h>

using namespace std;

int main(){
	
	long int i, n, v1,v2,p[2];
	char nome1[50], nome2[50], escolha1[10],escolha2[10];
	cin >> n;

	for(i=0;i<n;i++){
		cin >> nome1 >> escolha1 >> nome2 >> escolha2;
		cin >> v1 >> v2;

		if(strcmp(escolha1,"PAR")==0){
			p[0]=1;
		}
		else
			p[1]=1;
		if(strcmp(escolha2,"PAR")==0){
			p[0]=2;
		}
		else
			p[1]=2;

		if((v1+v2)%2==0){
			if(p[0]==1)
				cout << nome1 << endl;
			else
				cout << nome2 << endl;
		}
		else
			if(p[1]==1)
				cout << nome1 << endl;
			else
				cout << nome2 << endl;
	}	




return 0;
}
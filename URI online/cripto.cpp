#include <iostream>
#include <string.h>
#include <cstdio>

using namespace std;

int main(){
	char p[1001],aux[1001];
	int i,n,x,j,tam;

	scanf("%d", &n);
	getchar();
	for(i=0;i<n;i++){
		gets(p);
		setbuf(stdin,NULL);
		tam = strlen(p);
		x = tam -1;
		for(j=0;j<tam;j++){
			if((p[j]>64 && p[j]<91) || (p[j]>96 && p[j]<123))
				p[j]+=3;
		}
		for(j=0;j<tam && x>=0;j++){
			aux[j] = p[x];
			x--;
		}
		aux[j]='\0';
		for(j=(tam/2);p[j]!='\0';j++){
			aux[j]--;
		}
	cout << aux << endl;
	}



return 0;
}
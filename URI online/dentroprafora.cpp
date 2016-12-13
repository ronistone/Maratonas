#include <iostream>
#include <string.h>
#include <cstdio>

using namespace std;

int main(){
	int n,i,j,tam,w;
	char s[101],f[101];

	scanf("%d", &n);
	getchar();

	for(i=0;i<n;i++){
		gets(s);
		setbuf(stdin,NULL);
		tam = strlen(s);
		w=0;
		for(j=(tam/2)-1;j>=0;j--){
			f[w]=s[j];
			w++;
		}
		for(j=tam-1;j>=tam/2;j--){
			if(j==tam/2 && s[j]==' ')
				continue;
			f[w]=s[j];
			w++;
		}
		f[w]='\0';
		printf("%s\n",f);
	}

return 0;
}
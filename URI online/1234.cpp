/*#include <bits/stdc++.h>

using namespace std;

main(){
	char linha[55];
	int i,count;

	while(fgets(linha,55,stdin)!=NULL){
		setbuf(stdin,NULL);
		count = 0;
		for(i=0;i<strlen(linha);i++){
			if(linha[i]!=' ' && ((linha[i]>='A' && linha[i]<='z') || (linha[i]>='a' && linha[i]<='z'))){
				if(count%2==0){
					linha[i] = toupper(linha[i]);
				}
				else
					linha[i] = tolower(linha[i]);
				count++;
			}
			else
				count = 0;
		}
		cout << linha;
	}
	puts("");
}*/


#include <stdio.h>
#include <string.h>

int main() {

    int i, n, x;
    char c[100];
    while(gets(c)){
        x=0;
        for(i=0;i<strlen(c);i++){
            if(x==0&&c[i]<123&&c[i]>96) { c[i]=c[i]-32; x=1; }
            else if(x==1&&c[i]<91&&c[i]>64) { c[i]=c[i]+32; x=0; }
            else if((c[i]>=64&&c[i]<91)||(c[i]>=96&&c[i]<123)){ c[i]=c[i]; if(x==0) x=1; else x=0;}
            else c[i]=c[i];
        }
        printf("%s\n", c);
    }
    puts("");
    return 0;
}


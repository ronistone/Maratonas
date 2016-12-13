//#include <bits/stdc++.h>
//using namespace std;
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

main(){
	int n,i,j,x;
	char c;
	char entrada[100];
	//string saida;
	//string entrada;
	//char entrada[100];
	//cin >> n;
	scanf("%d", &n);
	for(i=0;i<n;i++){
		char saida[100];
		//saida.clear();
		int ler = 1;
		setbuf(stdin,NULL);
		//fflush(stdin);
		//getchar();
		fgets(entrada,100,stdin);
		//getline(cin,entrada);
		for(j=0, x = 0;j<strlen(entrada);j++){
			if(entrada[j]!=' ' && ler && entrada[j]!='\n' && entrada[j]>='a' && entrada[j]<='z'){
				//c = entrada[j];
				//saida.push_back(c);
				saida[x] = entrada[j];
				x++;
				ler = 0;
			}
			else if(entrada[j]==' ')
				ler = true;
		}
		saida[x] = '\0';
		printf("%s\n",saida);
		//cout << saida << endl;
		//saida.clear();	
	}
}

/*4
compete online design event rating
  u    r i  o    n l  i    n  e   
 
round  elimination during  onsite  contest*/
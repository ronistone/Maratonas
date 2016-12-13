#include <bits/stdc++.h>
using namespace std;
int letras[30];

main(){
	int n,i,j;
	char l;
	int tempo,count,final;
	char palavra[20];

	while(cin >> n and n){
		count = 0;
		final = 0;
		for(i=0;i<30;i++){letras[i]=0;}
		for(i=0;i<n;i++){
			cin >> l >> tempo >> palavra;
			l -=65;
			if(strcmp(palavra,"incorrect")==0)
				letras[l]++;
			else if(strcmp(palavra,"correct")==0){
				count++;
				final += (letras[l]*20)+tempo;
			}
		}
		cout << count << " " << final << endl;
	}
}
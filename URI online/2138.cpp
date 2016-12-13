#include <bits/stdc++.h>
using namespace std;

main(){
	string entrada;
	int n,maior,temp,i,j,jmaior;
	while(cin >> entrada){
		setbuf(stdin,NULL);
		int verifica[] = {0,0,0,0,0,0,0,0,0,0};
		for(i=0;i<entrada.size();i++){
			verifica[entrada[i]-48]++;
		}
		maior =0;
		for(i=0;i<10;i++){
			for(j=i+1;j<10;j++){
				if(verifica[i]==verifica[j]){
					for(int x=0;x<entrada.size();x++){
						if(entrada[x]-48==i){
							verifica[j]--;
							break;
						}
						else if(entrada[x]-48==j){
							verifica[i]--;
							break;
						}
					}
				}
			}
		}
		for(i=0;i<10;i++){
			if(verifica[i]>maior){
				maior = verifica[i];
				j = i;
			}
			else if(verifica[i]==maior){
				for(int x=0;x<entrada.size();x++){
					if(entrada[x]-48==i){
						j = i;
						break;
					}
					else if(entrada[x]-48==j)
						break;
				}
			}
		}
		cout << j << endl;
		entrada.clear();
	}
}
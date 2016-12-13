#include <bits/stdc++.h>
using namespace std;

main(){
	int s,n,i,j;
		cin >> n;
	char entrada[50],aux[5];
	for(int i=0;i<n;i++){
		cin >> entrada;
		for(j=0;j<n;j++){
			aux[j] = entrada[j];
			if(entrada[j+1]=='!')
				break;
		}
		aux[j+1] = '\0';
		int count= 0;
		for(j=0;j<n;j++){
			if(entrada[j]=='!')
				count++;
		}
		s = atoi(aux);
		int k = count;
		int mult = 1;
		int fact = s;
		while(true){
			if((s-(mult*k))<1)
				break;
			else{
				fact *= s -(mult*k);
				mult +=1;
			}
		}
		cout << fact << endl;
	}
}
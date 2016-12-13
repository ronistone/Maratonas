#include <bits/stdc++.h>

using namespace std;

main(){
	int notas[] = {2,5,10,20,50,100};
	int n,m,i,j,z,troco;
	cin >> n >> m;

	while(n!=0 || m!=0){
		bool possivel = false,duas = false;
		troco = m - n;
		for(i=0;i<6 && possivel==false;i++){
			z = 0;
			z+=notas[i];
			for(j=0;j<6 && possivel==false;j++){
				if(i!=j){
					z+=notas[j];
				}
				if(z==troco && i!=j){
					possivel = true;
					duas = true;
					break;
				}
				else
					z-=notas[j];
			}
		}
		if(possivel && duas)
			cout << "possible" << endl;
		else
			cout << "impossible" << endl;
		cin >> n >> m;
	}
}
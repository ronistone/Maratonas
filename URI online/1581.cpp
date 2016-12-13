#include <bits/stdc++.h>
using namespace std;

main(){
	int n,z,i,j;

	char entrada[30],anterior[30];
	bool ingles;
	cin >> n;

	for(i=0;i<n;i++){
		cin >> z;
		ingles = false;
		for(j=0;j<z;j++){
			cin >> entrada;
			getchar();
			//setbuf(stdin,NULL);
			if(j!=0 and !(strcmp(entrada,anterior)==0)){
				ingles = true;
			}
			strcpy(anterior,entrada);
		}
		if(ingles)
			cout << "ingles" << endl;
		else
			cout << entrada << endl;
	}
}
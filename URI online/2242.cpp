#include <bits/stdc++.h>
using namespace std;

main(){
		string entrada,aux,reverse;
		getline(cin,entrada);
		for(int i=0;i<entrada.size();i++){
				if(entrada[i]== 'a' or entrada[i]=='e' or entrada[i]=='i'
					or entrada[i]=='o' or entrada[i]=='u')
					aux+=entrada[i];
		}
		for(int i = aux.size()-1;i>=0;i--)
			reverse+=aux[i];
		
		if(aux==reverse)
			cout << "S" << endl;
		else
			cout << "N" << endl;
}

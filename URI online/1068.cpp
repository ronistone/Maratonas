/*#include <bits/stdc++.h>

using namespace std;

main(){
	int i,n;
	char entrada[1010];

	cin >> n;
	int abre,j,fecha;
	for(i=0;i<n;i++){
		cin >> entrada;
		for(j=0,abre=0,fecha=0;j<strlen(entrada);j++){
			if(entrada[j]=='<')
				abre++;
			else if(entrada[j]=='>')
				fecha++;
		}
		if(abre>fecha)
			abre= fecha;

		cout << abre << endl;
	}
}*/
#include <bits/stdc++.h>

using namespace std;

void clear(stack<char> *pilha){
	while(!pilha->empty()){
		pilha->pop();
	}
}

	main(){
		stack<char> pilha;
		int j,i,diamantes,n;
		char entrada[1010];
		while(cin >> entrada){
			for(j=0,diamantes=0;j<strlen(entrada);j++){
				if(entrada[j]=='(')
					pilha.push(entrada[j]);
				else if(entrada[j]==')'){
					if(!pilha.empty()){
						pilha.pop();
						diamantes++;
					}
					else{
						diamantes = 0;
						break;
					}
				}
			}
			if(!pilha.empty()){
				diamantes =0;
			}
			clear(&pilha);
			if(diamantes==0)
				cout << "incorrect" << endl;
			else
				cout << "correct" << endl;
		}
	}
#include <iostream>
#include <string.h>

using namespace std;


int main(){
	int n,m,i;
	char acao[10];
	cin >> n >> m;
	int abas = n;
	for(i=0;i<m;i++){
		cin >> acao;
		if(!strcmp(acao,"fechou"))
			abas++;
		else if(!strcmp(acao,"clicou"))
			abas--;
	}
	cout << abas << endl;

return 0;
}
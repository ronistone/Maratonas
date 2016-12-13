#include <iostream>

using namespace std;

int main(){
	int inter, gremio,o,i=0,g=0,e=0,j=0;

	do{
		cin >> inter >> gremio;
		j++;
		if(inter>gremio)
			i++;
		else if(inter<gremio)
			g++;
		else
			e++;
		for(o=0;;){
			cout << "Novo grenal (1-sim 2-nao)\n";
			cin >> o;
			if(o==1 || o==2)
				break;
		}
	}while(o!=2);
	cout << j << " grenais\n" << "Inter:" << i << "\nGremio:" << g << "\nEmpates:" << e;
	if(i>g)
		cout << "\nInter venceu mais\n";
	else if(g>i)
		cout << "\nGremio venceu mais\n";
	else
		cout << "\nNao houve vencedor\n";

return 0;
}
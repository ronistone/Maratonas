#include <iostream>
#include <cstdio>

using namespace std;

int main(){
	float n,q,sapo=0,rato=0,coelho=0,ps,pr,pc,total;
	char c;
	int i;

	cin >> n;

	for(i=0;i<n;i++){
		cin >> q >> c;

		switch (c){
			case 'C':
				coelho += q;
			break;
			case 'R':
				rato += q;
			break;
			case 'S':
				sapo += q;
			break;
		}
	}
	total = sapo + coelho + rato;
	ps = (sapo / total) * 100;
	pc = (coelho / total) * 100;
	pr = (rato / total) * 100;
	cout << "Total: " << total << " cobaias\n";
	cout << "Total de coelhos: " << coelho << "\nTotal de ratos: " << rato << "\nTotal de sapos: " << sapo ;
	printf("\nPercentual de coelhos: %.2f ",pc);
	cout << "%";
	printf("\nPercentual de ratos: %.2f ",pr);
	cout << "%";
	printf("\nPercentual de sapos: %.2f ",ps);
	cout << "%" << endl;
	
return 0;
}
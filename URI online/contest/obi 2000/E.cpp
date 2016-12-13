#include <bits/stdc++.h>
using namespace std;

int num_moedas(vector<int>& moedas, int troco)
{
	int qte_moedas = 0;
	int tam_moedas = moedas.size();
	
	for(int i = tam_moedas - 1; i >= 0; i--)
	{
		int aux_moedas = troco / moedas[i];
		troco -= aux_moedas * moedas[i];
		qte_moedas += aux_moedas;
	}
	
	return qte_moedas;
}

int main(){
	
}
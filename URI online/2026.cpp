#include <bits/stdc++.h>
using namespace std;


int knapsack(int W, int wt[], int b[], int n)
{
	// tabela que será preenchida
	int V[n + 1][W + 1];

	// inicializando a primeira linha e primeira coluna com 0
	for(int w = 0; w <= W; w++)
		V[0][w] = 0;
	for(int i = 1; i <= n; i++)
		V[i][0] = 0;

	for(int i = 1; i <= n; i++)
	{
		for(int w = 1; w <= W; w++)
		{	
			// elemento pode fazer parte da solução
			if(wt[i - 1] <= w)
			{
				// max...
				if((b[i - 1] + V[i - 1][w - wt[i - 1]]) > V[i - 1][w])
					V[i][w] = b[i - 1] + V[i - 1][w - wt[i - 1]];
				else
					V[i][w] = V[i - 1][w];
			}
			else
				V[i][w] = V[i - 1][w]; // wi > w
		}
	}

	// retorna o valor máximo colocado na mochila
	return V[n][W];
}

int main()
{

	int n,peso,z,i,j;
	cin >> z;

	while(z!=0){
		cin >> peso;
		int wt[z],b[z];
		for(j=0;j<z;j++){
			cin >> b[j] >> wt[j];
		}
		int max_valor = knapsack(peso, wt, b, z);
		cout  << max_valor << " min." << endl;
		cin >> z;
	}
	/*// capacidade máxima da mochila: W
	int W = 20;

	// número de elementos
	int n = 5;

	// vetor com os valores (benefício) de cada elemento
	int b[] = {3, 5, 8, 4, 10};

	// vetor com os pesos de cada elemento
	int wt[] = {2, 4, 5, 3, 9};

	// obtém o máximo valor que pode ser colocado na mochila
	*/	

	return 0;
}
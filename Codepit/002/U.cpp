/*#include <bits/stdc++.h>
using namespace std;

int inverte(int n){
	int i,x;
	char saida[15];
	for(i=0;i<15 and n>0;i++){
		saida[i] = (char)(n%10 +48);
		n = n / 10;
	}
	saida[i] = '\0';
	return atoi(saida);
}

main(){
	int i,j,entrada,saida,n;

	cin >> n;

	for(i=0;i<n;i++){
		cin >> entrada >> saida;
		for(j=0;j<saida;j++,entrada++){
			if(entrada==saida){
				cout << j << endl;
				break;
			}
			else if(inverte(entrada)==saida){
				cout << j << endl;
				break;
			}
		}
	}
}*/
// Grafos - BFS (busca em largura)

#include <iostream>
#include <list>
#include <queue> // fila para usar na BFS

using namespace std;

class Grafo
{
	int V; // número de vértices
	list<int> *adj; // ponteiro para um array contendo as listas de adjacências

public:
	Grafo(int V); // construtor
	void adicionarAresta(int v1, int v2); // adiciona uma aresta no grafo

	// faz uma BFS a partir de um vértice
	void bfs(int v);
};

Grafo::Grafo(int V)
{
	this->V = V; // atribui o número de vértices
	adj = new list<int>[V]; // cria as listas
}

void Grafo::adicionarAresta(int v1, int v2)
{
	// adiciona vértice v2 à lista de vértices adjacentes de v1
	adj[v1].push_back(v2);
}

void Grafo::bfs(int v)
{
	queue<int> fila;
	bool visitados[V]; // vetor de visitados

	for(int i = 0; i < V; i++)
		visitados[i] = false;

	cout << "Visitando vertice " << v << " ...\n";
	visitados[v] = true; // marca como visitado

	while(true)
	{
		list<int>::iterator it;
		for(it = adj[v].begin(); it != adj[v].end(); it++)
		{
			if(!visitados[*it])
			{
				cout << "Visitando vertice " << *it << " ...\n";
				visitados[*it] = true; // marca como visitado
				fila.push(*it); // insere na fila
			}
		}

		// verifica se a fila NÃO está vazia
		if(!fila.empty())
		{
			v = fila.front(); // obtém o primeiro elemento
			fila.pop(); // remove da fila
		}
		else
			break;
	}
}

int main()
{
	int V = 8;

	Grafo grafo(V);

	// adicionando as arestas
	grafo.adicionarAresta(0, 1);
	grafo.adicionarAresta(0, 2);
	grafo.adicionarAresta(1, 3);
	grafo.adicionarAresta(1, 4);
	grafo.adicionarAresta(2, 5);
	grafo.adicionarAresta(2, 6);
	grafo.adicionarAresta(6, 7);

	grafo.bfs(0);

	return 0;
}
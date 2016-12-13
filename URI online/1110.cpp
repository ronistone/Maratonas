#include <bits/stdc++.h>

using namespace std;
void push_back(stack<int> *baralho, int back){
	stack<int> aux;
	int a;
	while(!baralho->empty()){
		a = baralho->top();
		aux.push(a);
		baralho->pop();
	}
	baralho->push(back);
	while(!aux.empty()){
		a = aux.top();
		baralho->push(a);
		aux.pop();
	}
}

main(){

	int i,n,aux;
	cin >> n;

	while(n!=0){	
		stack<int> baralho;
		for(i=n;i>0;i--){
			baralho.push(i);
		}
		cout << "Discarded cards: ";
		while(baralho.size()>2){
			cout << baralho.top() << ", ";
			baralho.pop();
			aux = baralho.top();
			baralho.pop();
			push_back(&baralho,aux);
		}
		cout << baralho.top() << endl;
		baralho.pop();
		cout << "Remaining card: " << baralho.top() << endl;
		baralho.pop();
		baralho.pop();
		cin >> n;
	}
}
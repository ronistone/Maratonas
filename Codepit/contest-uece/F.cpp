#include <bits/stdc++.h>
using namespace std;


struct no{
	
	no* esq, *dir;
	int data;
	
	no(int n){
		data = n;
		esq = NULL;
		dir = NULL;
	}
	no(){}
	void insert(int n){
		if(n < data){
			if(esq){
				esq -> insert(n);
			}else{
				esq = new no(n);
			}
		}else{
			if(dir){
				dir -> insert(n);
			}else{
				dir = new no(n);
			}
		}
	}
};

no* arv;

void query(){


	queue<no*> q;
	
	q.push(arv);
	
	bool print = false;
	while(!q.empty()){
		no* aux = q.front();
		q.pop();
		
		if(print)
			cout << " ";
		cout << aux -> data;
		print = true;
		
		
		if(aux->esq)
			q.push(aux->esq);
		if(aux->dir)
			q.push(aux->dir);	
		
	}
	cout << endl;
}

main(){
	
	int z,a,n;
	
	cin >> z;
	
	
	for(int k=0;k<z;k++){
		arv = NULL;
		cin >> n;
		
		for(int i=0;i<n;i++){
			cin >> a;
			if(!arv){
				arv = new no(a);
			}else{
				arv -> insert(a);
			}
		}
		cout << "Case " << k+1 << ":" << endl;
		query();
		cout << endl;
	}

}

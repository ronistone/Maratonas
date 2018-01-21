#include <bits/stdc++.h>
using namespace std;


bool print;
struct no{
	int v;
	no *esq,*dir, *parent;
	
	no(int i){
		v = i;
		esq = NULL;
		dir = NULL;
		parent = NULL;
	}
	
	inline void insere(int i){
		if(i < v){
			if(esq)
				esq -> insere(i);
			else{
				esq = new no(i);
				esq->parent = this;
			}
		}
		else{
			if(dir)
				dir -> insere(i);
			else{
				dir = new no(i);
				dir->parent = this;
			}
		}
	}
	inline void infixa(){
		if(esq)
			esq->infixa();
		if(print) cout << " ";
		cout << v;
		print = true;
		if(dir)
			dir->infixa();
	}
	inline void prefixa(){
		if(print) cout << " ";
		cout << v;
		print = true;
		if(esq)
			esq->prefixa();
		if(dir)
			dir->prefixa();
	}
	inline void posfixa(){
		if(esq)
			esq->posfixa();
		if(dir)
			dir->posfixa();
		if(print) cout << " ";
		cout << v;
		print = true;
	}
	inline bool pesquisa(int i){
		if(v == i) return true;
		if(i < v and esq) return esq->pesquisa(i);
		if(i >= v and dir) return dir->pesquisa(i);
		return false;
	}
	inline void remove(int i){
		if(i < v and esq) return esq -> remove(i);
		else if(i >= v and dir) return dir -> remove(i);
		else if(i==v){
			no *aux = esq;
			while(aux -> dir){ aux = aux -> dir;}
		}
	}
};



main(){
	ios_base::sync_with_stdio(0);cin.tie(0);
	no* tree = NULL;
	string e;
	int x;
	while(cin >> e){
		if(e=="I"){
			cin >> x;
			if(tree)
				tree -> insere(x);
			else{
				tree = new no(x);
				tree -> parent = tree;
			}
			
		}
		else if(e=="INFIXA"){
			print =  false;
			tree -> infixa();
			cout << endl;
		}
		else if(e=="POSFIXA"){
			print =  false;
			tree -> posfixa();
			cout << endl;
		}
		else if(e=="PREFIXA"){
			print =  false;
			tree -> prefixa();
			cout << endl;
		}
		else if(e=="P"){
			cin >> x;
			cin.ignore();
			if(tree -> pesquisa(x))
				cout << x << " existe" << endl;
			else
				cout << x << " nao existe" << endl;
		}
		else if(e=="R"){
			cin >> x;
			cin.ignore();
			tree -> remove(x);
		}
	}
	
}

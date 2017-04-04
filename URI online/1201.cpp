#include <bits/stdc++.h>
using namespace std;

typedef struct No{
	No *esq,*dir;
	int data;
}No;

No* A;
void cria(){
	A = NULL;
}
bool ant;
void insere(No** arv,int n){
	if((*arv)==NULL){
		(*arv) = new No;
		(*arv)->data = n;
		(*arv)->esq = NULL;
		(*arv)->dir = NULL;
	}
	else if(n < (*arv)->data)
		insere(&(*arv)->esq,n);
	else if(n >= (*arv)->data)
		insere(&(*arv)->dir,n);
}
void pre(No* arv){
	if(arv!=NULL){
		if(ant)
			cout << " ";
		cout << arv->data;
		ant = true;
		pre(arv->esq);
		pre(arv->dir);
	}
}
void in(No* arv){
	if(arv!=NULL){
		in(arv->esq);
		if(ant)
			cout << " ";
		cout << arv->data;
		ant = true;
		in(arv->dir);
	}
}
void pos(No* arv){
	if(arv!=NULL){
		pos(arv->esq);
		pos(arv->dir);
		if(ant)
			cout << " ";
		cout << arv->data;
		ant = true;
	}
}

bool pesquisa(No* arv,int a){
	if(arv!=NULL){
		if(arv->data==a)
			return true;
		else if(a < arv->data)
			return pesquisa(arv->esq,a);
		else
			return pesquisa(arv->dir,a);
	}
	return false;
}
void remove(No** arv,int a){
	if(*arv){
		No* aux;
		if((*arv)->data==a){
			if((*arv)->esq and (*arv)->dir){
				aux = (*arv)->esq;
				while(aux->dir!=NULL) aux = aux->dir;
				(*arv)->data = aux->data;
				if(aux->esq){
					cout << "Achou " << aux-> data << endl;
					aux = aux->esq;
					//aux->esq  = aux->esq->esq;
					//delete aux->esq;
					//aux->esq = NULL;
				}
				else{
					delete aux;
					aux = NULL;
				}
				
			}
			else if((*arv)->esq){
				aux = (*arv)->esq;
				(*arv)->data = aux->data;
				(*arv)->esq = aux->esq;
				(*arv)->dir = aux->dir;
				delete aux;
				aux = NULL;
			}
			else if((*arv)->dir){
				aux = (*arv)->dir;
				(*arv)->data = aux->data;
				(*arv)->esq = aux->esq;
				(*arv)->dir = aux->dir;
				delete aux;
				aux = NULL;
			}
			else
				delete (*arv);
				(*arv) = NULL;
		}
		else if(a < (*arv)->data)
			remove(&(*arv)->esq,a);
		else
			remove(&(*arv)->dir,a);
	}
}
void clear(No** arv){
	if((*arv)->esq)
		clear(&(*arv)->esq);
	if((*arv)->dir)
		clear(&(*arv)->dir);
	delete *arv;
	*arv = NULL;
}
main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	string e;
	int a;
	int i,j,k,z;
	cria();
	
	while(cin >> e){
		//cin.ignore();
		ant = false;
		if(e=="I"){
			cin >> a;
			//cin.ignore();
			insere(&A,a);
		}
		else if(e=="INFIXA"){
			in(A);
			cout << endl;
		}
		else if(e=="PREFIXA"){
			pre(A);
			cout << endl;
		}
		else if(e=="POSFIXA"){
			pos(A);
			cout << endl;
		}
		else if(e=="P"){
			cin >> a;
			//cin.ignore();
			if(pesquisa(A,a))
				cout << a << " existe" << endl;
			else
				cout << a << " nao existe" << endl;
			
		}
		else if(e=="R"){
			cin >> a;
			remove(&A,a);
		}
	}
	clear(&A);
}

#include <bits/stdc++.h>
using namespace std;

const int N = 10004;
int p[N], sz=0, aux[N];
map<string, int> dic;
map<int, string> rdic;
string a, b;
int main()
{
	int n;
	
	for(int i=0; i<N; i++) {
		p[i] = -1;
		aux[i] = -1;
	}
	
	cin >> n;
	cin.ignore();
	
	int m = n;
	
	while(m--) {
			cin >> a >> b;
			
			if(!dic.count(a)) {rdic[sz] = a; dic[a] = sz++;}
			if(!dic.count(b)) {rdic[sz] = b; dic[b] = sz++;}
			
			p[dic[a]] = dic[b];
	}
	
	for(int i=0; i<sz; i++) aux[p[i]] = 1;
	for(int i=0; i<sz; i++) 
		if(aux[i] == -1) {
			m = i;
			break;
		}
		
	stack<int> pilha;
	while(m != -1) {
		pilha.push(m);
		m = p[m];
	}
	
	while(pilha.size()) {
		cout << rdic[pilha.top()] << endl;
		pilha.pop();
	}
}

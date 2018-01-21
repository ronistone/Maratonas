#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;

struct no{
	no *nxt[26];
	no *pai, *root;
	ll qtdNo,fim;
	char c;
	
	no(char k){
		for(int i=0;i<26;i++) nxt[i] = NULL;
		pai = root = this;
		qtdNo = fim = 0;
		c = k;
	}
	
	void insert(const string s, ll i){
		
		if(i == s.size()){
			fim = 1;
			return;
		}
		ll c = s[i] - 'a';
		if(!nxt[c]){
			nxt[c] = new no(s[i]);
			nxt[c] -> pai = this;
			nxt[c] -> root = root;
			root -> qtdNo++;
		}
		nxt[c] -> insert(s,i+1);
	}
	bool query(string s, ll i){
		
		if(i == s.size()) return false;
		
		ll c = s[i] - 'a';
		if(!nxt[c]) return false;
		
		if(nxt[c] -> fim) return true;
		else		return nxt[c] -> query(s,i+1);
	}
	
};



main(){

	ll n,qtd;
	string e;
	bool fail;
	no *trie = new no('*');
	while(cin >> n and n){
		cin.ignore();
		fail = false;
		for(int i=0;i<n;i++){
			getline(cin, e);
			
			if(!fail){
				fail = trie -> query(e,0);
				if(!fail){
					qtd = trie -> qtdNo;
					trie -> insert(e,0);
					if(qtd==trie -> qtdNo) fail = true;
				}
			}
		}
		if(!fail)
			cout << "Conjunto Bom" << endl;
		else
			cout << "Conjunto Ruim" << endl;
		trie = new no('*');
	}

}

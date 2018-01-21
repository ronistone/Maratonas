#include <bits/stdc++.h>
using namespace std;

typedef int ll;
ll at,ii;
struct no{
	no* nxt[26];
	no *root;
	ll fim,qtdNo;
	
	inline no(char k){
		for(ii=0;ii<26;ii++) nxt[ii] = NULL;
		root = this;
		fim = qtdNo = 0;
	}
	inline bool insert(const string s, ll i){
		if(i == s.size()){
			fim = 1;
			return false;
		}
		at = s[i] - 'a';
		if(!nxt[at]){
			nxt[at] = new no(s[i]);
			nxt[at] -> root = root;
			root -> qtdNo++;
		}
		else if(nxt[at] -> fim) return true;
		return nxt[at] -> insert(s,i+1);
	}
};


main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);	
	no* trie;
	bool fail;
	ll qtd,n,i;
	string e;
	while(cin >> n and n){
		trie = new no('*');
		cin.ignore();
		fail = false;
		
		for(i=0;i<n;i++){
			getline(cin, e);
			
			if(!fail){
				qtd = trie->qtdNo;
				fail = trie->insert(e,0);
				if(trie->qtdNo == qtd)
					fail = true;
			}
		}
		if(!fail)
			cout << "Conjunto Bom" << endl;
		else
			cout << "Conjunto Ruim" << endl;
	}
	
}

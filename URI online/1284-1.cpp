#include <bits/stdc++.h>
using namespace std;

typedef int ll;

struct no{
	no *nxt[26], *root;
	ll children;
	bool fim;
	
	inline no(char k){
		for(int i=0;i<26;i++) nxt[i] = NULL;
		root = this;
		children = 0;
		fim = false;
	}
	
	inline void insert(const string s, ll i){
		if(i == s.size()){
			fim = true;
			return;
		}
		ll c = s[i] - 'a';
		if(!nxt[c]){
			nxt[c] = new no(s[i]);
			nxt[c] -> root = root;
			this -> children++;
		}
		nxt[c] -> insert(s,i+1);
	}
	
	inline ll query(ll num){
		ll ans = 0LL;
		for(int i=0;i<26;i++){
			if(nxt[i]){
				ans += nxt[i] -> query(num+(children > 1 or fim? 1:0));
			}
		}
		return fim? ans+num: ans;
	}
	
};


main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	no *trie;
	ll n;
	string e;
	while(cin >> n){
		cin.ignore();
		trie = new no('*');
		for(int i=0;i<n;i++){
			getline(cin,e);
			trie -> insert(e,0);
		}
		cout << fixed << setprecision(2) << ((trie->query(0) + (trie->children==1?n:0)) / (double)n) << endl;
	}
}

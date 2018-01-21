#include <bits/stdc++.h>
using namespace std;

typedef int ll;


bool fail;
struct no{
	no *nxt[26], *pai, *root;
	char c;
	ll qtdNo,children;
	bool fim;
	
	no(char k){
		for(int i=0;i<26;i++) nxt[i] = NULL;
		pai = root = this;
		c = k;
		qtdNo = children = 0;
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
			nxt[c] -> pai = this;
			this -> children++;
			root -> qtdNo++;
		}
		nxt[c] -> insert(s,i+1);
	}
	
	inline ll query(string s, int i,ll num){
		if(i==s.size()) return num;
		
		ll c = s[i] - 'a';
		if(fim) return nxt[c] -> query(s,i+1,num+1LL);
		if(children > 1) return nxt[c] -> query(s,i+1,num+1LL);
		return nxt[c] -> query(s,i+1,num);
		
	}
	
};


main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	no *trie;
	vector<string> P;
	double ans,n;
	string e;
	while(cin >> n){
		cin.ignore();
		trie = new no('*');
		P.clear();
		ans = 0;
		for(int i=0;i<n;i++){
			getline(cin,e);
			trie -> insert(e,0);
			P.push_back(e);
		}
		for(int i=0;i<P.size();i++){
			ans += trie -> query(P[i],0,0);
		}
		cout << fixed << setprecision(2) << ((ans+(trie->children==1?n:0)) / n) << endl;
	}
}

#include <bits/stdc++.h>
using namespace std;

string e;
int ans;

struct Trie{
	
	Trie* child[26];
	bool end;
	
	Trie(){
		for(int i=0;i<26;i++){
			child[i] = NULL;
		}
		end = false;
	}
	
	void insert(int p, bool fi){
	
		if(p == e.size()) return;
		
		int posi = e[p] - 'a';
		
		if(child[posi] != NULL){
			child[posi] -> insert(p+1, fi);
		}else{
			if(!fi){
				ans = p+1;
			}
			child[posi] = new Trie();
			child[posi] -> insert(p+1, true);
		}
		if(p==e.size()-1){
			end = true;
			if(!fi)
				ans = p+1;
		}
	
	}
	
	void clear(){
		for(int i=0;i<26;i++){
			if(child[i]!= NULL){
				child[i] -> clear();
				delete child[i];
				child[i] = NULL;
			}
		}
		end = false;
	}
};





main(){

	int t, n, a;
	Trie trie;
	
	
	cin >> t;
	
	for(int i=0;i<t;i++){
		cin >> n;
		trie.clear();
		a = 0;
		for(int j=0;j<n;j++){
			cin >> e;
			trie.insert(0,false);
			a += ans;
			//cout << "ans: " << ans << endl;
		}
		cout << "Case #" << i+1 << ": " << a << endl;
	}

}

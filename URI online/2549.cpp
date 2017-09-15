#include <bits/stdc++.h>
using namespace std;


main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	unordered_map<string,bool> P;
	string nome,pre;
	int n,ano,ans;
	bool nxt;
	while(cin >> n >> ano){
		cin.ignore();
		ans = 0;
		for(int k=0;k<n;k++){
			getline(cin,nome);
			nxt = true;
			pre.clear();
			for(int i=0;i<nome.size();i++){
				if(nxt and nome[i]>='a' and nome[i]<='z'){
					pre += nome[i];
					nxt = false;
				}
				else if(nome[i]==' ')
					nxt = true;
			}
			if(P[pre])
				ans++;
			else
				P[pre] = true;
			nome.clear();
		}
		cout << ans << endl;
		P.clear();
	}
	
}

#include <bits/stdc++.h>
using namespace std;


main(){

	string ans;
	int n,aux,res;
	map<int,char> letras;
	for(int i=1;i<=26;i++){
		letras[i] = 'A'- 1 + i;
	}
	letras[0] = 'Z';

	cin >> n;

	for(int i=0;i<n;i++){
		cin >> aux;
		ans.clear();
		while(aux > 0){
			res = aux%26;
			ans = letras[res] + ans;
			aux /= 26;
			if(res==0)
				aux--;
		}
		cout << ans << endl;
	}

}

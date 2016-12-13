#include <bits/stdc++.h>
using namespace std;

int inverte(int n){
	char saida[20];
	int i = 0;
		while(n!=0){
			saida[i] = (char)(n%10)+48;
			n/=10;
			i++;
		}
	saida[i]= '\0';
	return atoi(saida);
}


int dfs(int n,int m,int cont){
		if(n==m)
			return cont;
		int c = cont+dfs(n+1,m,cont+1);
		int c2 = cont+dfs(inverte(n),m,cont+1);
		if(c>c2)
			return c2;
		else
			return c;
}

main(){
	int n,m;
	
	//cin >> n;
	//cout << inverte(n) << endl;
	
	while(cin >> n >> m){
			cout << dfs(n,m,0);
	}
}

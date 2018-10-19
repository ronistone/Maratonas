#include <bits/stdc++.h>
using namespace std;

char e[10][100];
int n,m;

void solve(){
	
	int a;
	for(int j=1;j<=m;j++){
		a = 0;
		for(int i=8;i>0;i--){
			if(e[i][j]=='\\'){
				a |= (1 << (i-1));
			}
		}
		cout << ((char)(a));
	}
	
}

main(){
	
	int i;
	
	scanf("%d", &n);
	
	while(n--){
		for(i=0;i<10;i++)
			scanf("%s", &e[i]);
			
		m = strlen(e[0]) - 2;
		solve();
		cout << endl;
	}
	
}

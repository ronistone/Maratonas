#include <bits/stdc++.h>
using namespace std;

main(){
	int n,m,a,b,i,j,k,l,count;

	while(cin >> n >> m and (n or m)){
		char entrada[n][m];
		for(i=0;i<n;i++){
				setbuf(stdin,NULL);
				scanf("%s",&entrada[i]);
				setbuf(stdin,NULL);
		}
		cin >> a >> b;
		char colunas[n][b];
		for(i=0;i<n;i++){
			for(j=0,l=0,count = 0;j<b;j++,count++){
				if(l==b)
					l = 0;
				colunas[i][j] = entrada[i][l];
				if(count==((b/n)-1)){
					l++;
					count = 0;
				}
			}
		}
		for(i=0;i<n;i++){
			for(j=0;j<b;j++){
				cout << colunas[i][j] << " ";
			}
			cout << endl;
		}
	}
}
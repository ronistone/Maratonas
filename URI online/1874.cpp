#include <bits/stdc++.h>

using namespace std;

main(){
	int h,p,f,i,j;

	while(cin >> h >> p >> f){
		if(h==0)
			break;
		int caixas[h][p],nova;
		for(i=0;i<h;i++){
			for(j=0;j<p;j++){
				cin >> caixas[i][j];
			}
		}
		int v;
		for(int x = 0;x < f;x++){
			cin >> nova;
			v = 0;
				for(j=p-1;j>=0,v==0;j--){
			for(i=h-1;i>=0;i--){
					if(caixas[i][j]==0){
						caixas[i][j]=nova;
						v = 1;
						break;
					}
				}
			}
		}
		for(i=0;i<h;i++){
			for(j=0;j<p;j++){
				cout << caixas[i][j];
				if(j!=p-1)
					cout << " ";
			}
			cout << endl;
		}
		
	}
}
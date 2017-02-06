#include <bits/stdc++.h>
using namespace std;

main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n,i,j,k,b,from,to;
	int esq[100005],dir[100005];
	
	while(cin >> n >> b and n and b){
		
		esq[1] = 0;
		dir[1] = 2;
		dir[n] = 0;
		esq[n] = n-1;
		for(i=2;i<n;i++){
			esq[i] = i-1;
			dir[i] = i+1;
		}
		for(i=0;i<b;i++){
			cin >> from >> to;
			if(esq[from]!=0)
				cout << esq[from] << ' ';
			else
				cout << "* ";
			if(dir[to]!=0)
				cout << dir[to] << endl;
			else
				cout << "*\n";
			dir[esq[from]] = dir[to];
			esq[dir[to]] = esq[from];
		}
		cout << "-\n";
	}
}

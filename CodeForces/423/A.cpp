#include <bits/stdc++.h>
using namespace std;

main(){
	int n,a,b,aux,ans=0;
	
	cin >> n >> a >> b;
	
	for(int i=0;i<n;i++){
		cin >> aux;
		if(aux == 1 and a)
			a--;
		else if(aux == 1 and b){
			b--;
			a++;
		}
		else if(aux==2 and b){
			b--;
		}
		else{
			ans += aux;
		}
	}
	cout << ans << endl;
}

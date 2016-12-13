#include <bits/stdc++.h>
using namespace std;

main(){
	int n,q,i,j,maior,menor;
	float media;

	cin >> n;
	for(i=0;i<n;i++){
		cin >> q;
		int idades[q];
		for(j=0;j<q;j++){
			cin >> idades[j];
		}
		if(idades[0]>idades[q-1]){
			if(q%2==0)
				media = (q/2)-1;
			else
				media = floor(q/2);
		}
		else{
			if(q%2==0)
				media = (q/2)+1;
			else
				media = floor(q/2);	
		}
			cout << media << endl;
			cout << "Case " << i+1 << ": " << idades[(int)media] << endl;
	}
}
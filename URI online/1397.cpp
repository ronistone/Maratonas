#include <bits/stdc++.h>

using namespace std;

main(){
	ios_base::sync_with_stdio(0);
	//cin.tie(0);

	int n, og,filho,a,b,i;

	while(true){
		cin >> n;
		if(n==0)
			break;
		og = filho =0;
		for(i=0;i<n;i++){
			cin >> a >> b;
			if(a>b)
				og++;
			else if(b>a)
				filho++;
		}
		cout << og <<" " << filho << endl;
	}
}
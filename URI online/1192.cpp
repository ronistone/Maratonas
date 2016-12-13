#include <bits/stdc++.h>

using namespace std;

main(){
	int a,b,n,i,r;
	char l;

	cin >> n;

	for(i=0;i<n;i++){
		cin >> a >> l >> b;
		if(a==b)
			r = a*b;
		else if(islower(l))
			r = a+b;
		else
			r = b-a;
		cout << r << endl;
	}

}
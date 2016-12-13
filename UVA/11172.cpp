#include <bits/stdc++.h>
using namespace std;


main(){
	long long a,b;
	int n;
	
	cin >> n;
	
	for(int i=0;i<n;i++){
		cin >> a >> b;
		
		if(a>b)
			cout << ">" << endl;
		else if(a<b)
			cout << "<" << endl;
		else
			cout << "=" << endl;
	}
}

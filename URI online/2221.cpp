#include <bits/stdc++.h>
using namespace std;

main(){
	int t,n,b,i,j,a,d,l,s1,s2;
	
	cin >> n;
	
	for(i=0;i<n;i++){
		cin >> b;
		cin >> a >> d >> l;
		s1 = (a+d)/2;
		if(l%2==0)
			s1+=b;
			
		cin >> a >> d >> l;
		
		s2 = (a+d)/2;
		if(l%2==0)
			s2+=b;
			
			if(s1>s2) cout << "Dabriel" << endl;
			else if(s1<s2) cout << "Guarte" << endl;
			else cout << "empate" << endl;
	}
}

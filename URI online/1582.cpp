#include <bits/stdc++.h>
using namespace std;

template <class T> T gcd(T x, T y){
	return (y!=0 ? gcd<T> (y,x%y) : x);
}

main(){

	int a,b,c;
	while(cin >> a >> b >> c){
		bool pitagoras = false;
		cout << "tripla";
		if(a > b and a > c)
			pitagoras = ((a*a)==(b*b)+(c*c));
		else if(b > a and b >c)
			pitagoras = ((b*b)==(a*a)+(c*c));
		else if(c > b and c > a)
			pitagoras = ((c*c)==(b*b)+(a*a));
		if(pitagoras){	
			cout << " pitagorica";
			if(gcd(a,gcd(b,c))==1)
				cout << " primitiva";
		}

		cout << endl;
	}
}
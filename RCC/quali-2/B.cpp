#include <bits/stdc++.h>
using namespace std;

template<class T> T gcd(T x, T y){
	return (y!=0 ? gcd<T>(y,x%y):x);
}
template<class T> T lcm(T x, T y){
	return (x / gcd<T> (x,y) * y);
}
typedef long long int ll;

main(){
	ll z,a,b,c,d;
	
	cin >> z;
	for(int k=0;k<z;k++){
		cin >> a >> b >> c >> d;
		ll x = lcm(a,c);
		ll y = gcd(b,d);
		cout << x << " " << y << endl;
	}

}

#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;

template<class T> T gcd (T x, T y){
	return (y!=0 ? gcd<T> (y,x%y):y);
}
vector<ll> v;
bool prime[100100];

void sieve(){
	ll i,j;
	memset(prime,true,sizeof(prime));
	v.clear();
	prime[1] = false;
	for(i=2;i<=100000;++i){
		if(prime[i]){
//			v.push_back(i);
			for(j=i*i;j<=100000;j+=i)
				prime[j] = false;
		}
	}
}
main(){
	//sieve();
	ll n,i,j;
	ll s,s1,c,c1;
	cin >> n;
	ll v[n];
	c = 1;
	c1= 1;
	s=-1;
	s1=-1;
	for(int i=0;i<n;i++){
		cin >> v[i];
		if(v[i]%2==0){
			if(s==-1)
				s = v[i];
			else{
				s = gcd(s,v[i]);
				c++;
			}
		}
		else{
			if(s1==-1)
				s1 = v[i];
			else{
				s1 = gcd(s1,v[i]);
				c1++;
			}
		}
	}
	if(max(s1,s)==s1 and s1!=1)
		cout << c1 << endl;
	else if(max(s1,s)==s and s!=1)
		cout << c << endl;
	else
		cout << max(c,c1) << endl;
}

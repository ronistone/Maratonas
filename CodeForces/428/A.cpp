#include <bits/stdc++.h>
using namespace std;

#define mp make_pair
#define pb push_back
#define F first
#define S second

typedef long long int ll;
typedef pair<ll,ll> ii;
typedef vector<ii> vii;
typedef vector<vii> vvii;
typedef vector<ll> vi;


main(){
	
	int n,k,aux,sum=0;
	bool ac=false;
	
	cin >> n >> k;
	
	for(int i=0;i<n;i++){
			cin >> aux;
			sum += aux;
			if(sum > 8){
				k-=8;
				sum-=8;
			}
			else{
				k -= sum;
				sum = 0;
			}
			if(k <= 0 and !ac){
				cout << i+1 << endl;
				ac = true;
			}
	}
	if(!ac)
		cout << -1 << endl;
	
}

#include <iostream>

using namespace std;

long long int fatorial(int x){
	if(x==0)
		return 1;
	else
		return x*fatorial(x-1);
}
int main(){
	unsigned long long int m,n;
	while(cin >> m >> n){
		m = fatorial(m);
		n = fatorial(n);
		m = m+n;
		cout << m << endl;
	}
return 0;
}
#include <iostream>
using namespace std;

int main(){
	int i,n,j;
	cin >> n;
	
	long long int f[n], fibo,p,s;
	for(i=0;i<n;i++){
		cin >> f[i];
		if(f[i]==0)
			cout << "Fib(0) = 0" << endl;
		else if(f[i]==1)
			cout << "Fib(1) = 1" << endl;
		else if(f[i]>1){
			p=0;
			s=1;
			for(j=2;j<=f[i];j++){
				fibo = p + s;
				p = s;
				s = fibo;
			}
			cout << "Fib(" << f[i] << ") = " << fibo << endl;
		}
	}
return 0;
}
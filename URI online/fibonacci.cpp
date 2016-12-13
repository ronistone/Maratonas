#include <iostream>

using namespace std;
unsigned long long memo[2000];

unsigned long long fib(long long n){
	unsigned long long f;
	if(memo[n])
		return memo[n];
		else{	
			if(n <= 2)
				f=1;
			else
				f = fib(n-1) + fib(n-2);
		}
		memo[n] = f;
		cout << f << " ";
		return f;

}
int main(){
	unsigned long long n;
	int i;
	while(n!=0){
		cout << "\nEntre com o valor fibonacci ";
		cin >> n;
		if(n==0)
			break;
		n = fib(n);
	//	cout << n;
	}
	for(i=1;i<=50;i++){
		cout << memo[i] << " ";
	}
	cout << endl;
return 0;
}
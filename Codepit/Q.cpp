#include <bits/stdc++.h>
using namespace std;

int main() {
	int n, fib[45];

	fib[0] = 1;
	fib[1] = 1;
	for( int i=2; i<=40; i++ )
		fib[i] = fib[i-1] + fib[i-2];
	
	while( scanf( "%d", &n ) && n )
		printf( "%d\n", fib[n] );

	return 0;
}
#include <iostream>

using namespace std;

int fatorial(int n){
	if(n<=1)
		return 1;
	else
		return n*fatorial(n-1);

}

int main(){
	int i,n,f;

	cin >> n;	

	f = fatorial(n);
	cout << f << endl;
return 0;
}
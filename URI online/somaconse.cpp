#include <iostream>

using namespace std;

int main(){
	int a,n,i,s=0;

	cin >> a >> n;
	while(n<=0)
		cin >> n;

	for(i=a;i<(a+n);i++){
		s+=i;
	}
	cout << s << endl;
return 0;
}
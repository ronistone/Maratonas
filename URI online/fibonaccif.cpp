#include <iostream>

using namespace std;

int main(){
	int i,n;

	cin >> n;
	int f[n];
	f[0]=0;
	f[1]=1;

	for(i=2;i<n;i++){
		f[i] = f[i-1]+f[i-2];
	}
	for(i=0;i<n;i++){
		cout << f[i];
		if(i!=n-1)
			cout << " ";
	}
	cout << endl;

return 0;
}

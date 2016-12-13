#include <iostream>

using namespace std;

int main(){
	int n,c,i;
	cin >> n;
	int a[n];
	for(i=0;i<n;i++)
		cin >> a[i];

	for(i=0;i<n;i++){
		if(2015-a[i]<1){
			a[i] = 2014 - a[i];
			a[i] *= -1;
			cout << a[i] << " A.C." << endl;
		}
		else{
			a[i] = 2015-a[i];
			cout << a[i] << " D.C." << endl;
		}
	}

return 0;
}
#include <iostream>

using namespace std;

int main(){
	int p,n,i,s=0,v;
	cin >> p
		>> n;
	for(i=0;i<n;i++){
		cin >> v;
		s+=v;
	}
	s/=p;
	cout << s << endl;
return 0;
}
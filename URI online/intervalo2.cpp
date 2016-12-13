#include <iostream>

using namespace std;

int main(){
	int n;
	cin >> n;
	int x[n],i,in=0,out=0;
	for(i=0;i<n;i++){
		cin >> x[i];
		if(x[i]>=10 && x[i]<=20)
			in++;
		else
			out++;
	}
	cout << in << " in\n" << out << " out" << endl;

return 0;
}
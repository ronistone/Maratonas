#include <iostream>

using namespace std;

int main(){
	int n;
	cin >> n;
	int x[n],i;
	for(i=0;i<n;i++){
		cin >> x[i];
	}
	for(i=0;i<n;i++){
		if(x[i]>0){
			if(x[i]%2==0)
				cout << "EVEN POSITIVE\n";
			else
				cout << "ODD POSITIVE\n";
		}
		else if(x[i]<0){
			if(x[i]%2==0)
				cout << "EVEN NEGATIVE\n";
			else
				cout << "ODD NEGATIVE\n";
		}
		else if(x[i]==0)
			cout << "NULL\n";
	}
return 0;
}
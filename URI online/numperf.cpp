#include <iostream>

using namespace std;

int main(){
	int x,n,i,j,s;

	cin >> n;
	for(i=0;i<n;i++){
		cin >> x;
		s=0;
		for(j=1;j<x;j++){
			if(x%j==0)
				s+=j;
		}
		if(s==x)
			cout << x << " eh perfeito" << endl;
		else
			cout << x << " nao eh perfeito" << endl;
	}
return 0;
}
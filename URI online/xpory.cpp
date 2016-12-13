#include <iostream>
#include <cstdio>

using namespace std;

int main(){
	int n,i;
	cin >> n;
	float x[n],y[n];

	for(i=0;i<n;i++){
		cin >> x[i] >> y[i];
		if(y[i]==0){
			cout << "divisao impossivel\n";
			continue;
		}
		x[i] /= y[i];
		printf("%.1f\n", x[i]);
	}
return 0;
}
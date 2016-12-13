#include <iostream>
#include <cstdio>

using namespace std;

int main(){
	int n,i,j;
	cin >> n;
	float x[n][3],m[n];
	for(i=0;i<n;i++){
		for(j=0;j<3;j++){
			cin >> x[i][j];
		}
		x[i][0] = x[i][0] * 2;
		x[i][1] = x[i][1] * 3;
		x[i][2] = x[i][2] * 5;
		m[i] = 0;
		for(j=0;j<3;j++)
			m[i] = m[i] + x[i][j];
		
		m[i] /= 10;
	}
	for(i=0;i<n;i++){
		printf("%.1f\n", m[i]);
	}
return 0;
}

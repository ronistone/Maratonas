#include <iostream>
using namespace std;

void organiza(int n[], int aux){
	int m[3],a,i,j;

	for(i=0;i<3;i++)
		m[i] = n[i];
	for(i=0;i<3;i++){
		for(j=0;j<3;j++){
			if(m[i] < m[j]){
				a = m[i];
				m[i] = m[j];
				m[j] = a;
			}
		}

	}
	for(i=0;i<3;i++)
		cout << m[i] <<"\n";
	cout << "\n";
	for(i=0;i<3;i++)
		cout << n[i] << "\n";
}
int main(){

	int n[3],i;
	for(i=0;i<3;i++){
		cin >> n[i];
	}
	organiza(n,3);

	return 0;
}
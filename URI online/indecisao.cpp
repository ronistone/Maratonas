#include <iostream>
#include <cstdio>

using namespace std;

int main(){
	int x,i;
	cin >> x;

	char curso[50];
	for(i=0;i<x;i++){	
		fgets(curso, 50, stdin);
		getchar();
	}
	cout << "Ciencia da Computacao" << endl;
return 0;
}
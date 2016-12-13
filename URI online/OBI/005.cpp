#include <iostream>
#include <string.h>

using namespace std;

int main(){
	int n,i;
	char p[100];
	cin >> n;
	for(i=0;i<n;i++){
		cin >> p;
		if(strlen(p)==3){
			if(p[0]=='O' && p[1]=='B')
				p[2]='I';
			else if(p[0]=='U' && p[1]=='R')
				p[2]='I';
		}
		if(i<n-1)
			cout << p <<" ";
		else
			cout << p << endl;
		}
return 0;
}
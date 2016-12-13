#include <bits/stdc++.h>
using namespace std;

main(){
	long double saida;
	int m;
	int n;
	char e;
	cin >> n;
	saida = 1;
	for(int i=0;i<n;i++){
		cin >> m >> e;
		cin.ignore();
		if(e=='*')
			saida *= m;
		else if(e=='/')
			saida /= m;
	}
	char s[1000];
	sprintf(s,"%llf",saida);
	for(int i=strlen(s)-1;i>=0;i--){
		if(s[i]=='0')
			s[i] = '\0';
		else if(s[i]=='.'){
			s[i]= '\0';
			break;
		}
		else if(s[i]!='0' and s[i]!='.')
			break;
	}
	cout << s << '\n';
}

#include <bits/stdc++.h>
using namespace std;

main(){
	string e;
	long long int n1,n2;
	int i;
	char a[20],b[20],x;
	getline(cin,e);
	
	for(i=0;i<e.size();i++){
		if(e[i]=='7')
			e[i] = '0';
	}
	i=0;
	int z = 0;
	while(e[i]!=' ')
		a[z++] = e[i++];
	a[z] = '\0';
	x = e[++i];
	i++;
	z =0;
	while(e[i]!='\0')
		b[z++] = e[i++];
	b[z] = '\0';
	n1 = atoi(a);
	n2 = atoi(b);
	if(x == '+')
		n1 = n1 +n2;
	else if(x=='x')
		n1 = n1*n2;
	e = to_string(n1);
	for(i=0;i<e.size();i++)
		if(e[i]=='7')
			e[i] = '0';
	n1 = atoi(e.c_str());
	cout << n1 << endl;
}

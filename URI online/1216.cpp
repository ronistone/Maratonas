#include <bits/stdc++.h>

using namespace std;

main(){
	string lixo;
	double dist,media=0;
	int i=0;
	while(getline(cin,lixo)){
		setbuf(stdin,NULL);
		cin >> dist;
		getchar();
		media +=dist;
		i++;
	}
	media /=i;
	cout <<fixed << setprecision(1) << media << endl;
}
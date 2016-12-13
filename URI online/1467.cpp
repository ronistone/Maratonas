#include <bits/stdc++.h>

using namespace std;

main(){
	ios_base::sync_with_stdio(0);
	//cin.tie(0);

	char a,b,c;
	int i;
	while(cin >> a >> b >> c){
		if(a==b && b==c){
			cout << "*" << endl;
		}
		else if(a==b && b!=c)
			cout << "C" << endl;
		else if(a!=b && b==c)
			cout << "A" << endl;
		else if(a==c && b!=c)
			cout << "B" << endl;
	}
}
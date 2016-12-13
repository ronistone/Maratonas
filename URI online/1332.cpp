#include <bits/stdc++.h>

using namespace std;

main(){
	int n;
	char num[10];
	cin >> n;
	for(int i=0;i<n;i++){
		cin >> num;
		
		if(strlen(num)== 5)
			cout << 3 << endl;
		else{
			if((num[0] == 'o' && num[1] == 'n') || (num[1] == 'n' && num[2]=='e') || (num[2] == 'e' && num[0]=='o'))
				cout << 1 << endl;
			else if((num[0] == 't' && num[1] == 'w') || (num[1] == 'w' && num[2]=='o') || (num[2] == 'o' && num[0]=='t'))
				cout << 2 << endl;
		}
	}
}
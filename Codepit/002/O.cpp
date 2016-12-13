#include <bits/stdc++.h>
using namespace std;

main(){
	int num,rua,count=0,saida;

	while(cin >> rua >> num and !(rua==num and rua == 0)){
		count++;
		if(rua == num)
			cout << "Case " << count << ": " << 0 << endl;
		else{
			rua = ceil(rua/ num);
			if(rua<=26)
				cout << "Case " << count << ": " << rua << endl;
			else
				cout << "Case " << count << ": " << "impossible" << endl;
		}
	}
}
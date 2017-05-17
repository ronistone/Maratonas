#include <bits/stdc++.h>
using namespace std;

main(){
	map<string,int> valores;
	valores["suco de laranja"] = 120;
	valores["morango fresco"] = 85;
	valores["mamao"] = 85;
	valores["goiaba vermelha"] = 70;
	valores["manga"] = 56;
	valores["laranja"] = 50;
	valores["brocolis"] = 34;
	
	
	int t,sum,n;
	string e;
	
	while(cin >> t and t){
		//cin.ignore();
		sum = 0;
		for(int i=0;i<t;i++){
			cin >> n;
			cin.ignore();
			getline(cin,e);
			//cout << e << endl;
			sum += n*valores[e];
		}
		if(sum > 130)		
			cout << "Menos " << sum - 130 << " mg" << endl;
		else if(sum < 110)
			cout << "Mais " << 110 - sum << " mg" << endl;
		else
			cout << sum << " mg" << endl;
		
	}

}

#include <bits/stdc++.h>
using namespace std;

main(){
	int n,i,j,a;
	string receita,cafe,almoco;
	string::iterator it;
	cin >> n;

	for(i=0;i<n;i++){
		setbuf(stdin,NULL);
		getline(cin,receita);
		setbuf(stdin,NULL);
		getline(cin,cafe);
		setbuf(stdin,NULL);
		getline(cin,almoco);
		setbuf(stdin,NULL);
		if(cafe.size()>0)
			cafe.append(almoco);
		else
			cafe = almoco;
		sort(receita.begin(),receita.end());
		sort(cafe.begin(),cafe.end());
		for(j=receita.size(), it = receita.end();j>=0 and cafe.size()>0;j--,it--){
			if(cafe.find(receita[j])!=string::npos){
				cafe.erase(cafe.find(receita[j]),1);
				receita.erase(it);
			}
		}
		if(cafe.size()==0)
			cout << receita << endl;
		else
			cout << "CHEATER" << endl;

		receita.clear();
		cafe.clear();
		almoco.clear();
	}
}
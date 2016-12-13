#include <bits/stdc++.h>
using namespace std;

main(){
	int n,i,j,c1,c2;
	cin >> n;

	string entrada, time1,time2;

	for(i=0;i<n;i++){
		setbuf(stdin,NULL);
		getline(cin,entrada);
		setbuf(stdin,NULL);
		getline(cin,time1);
		setbuf(stdin,NULL);
		getline(cin,time2);
		c1 = 0;
		c2 = 0;
		for(j=0;j<entrada.size();j++){
			if(time2[j]==entrada[j])
				c2++;
			if(time1[j]==entrada[j])
				c1++;
		}

		cout << "Instancia " << i+1 << endl;
		if(c1>c2)
			cout << "time 1" << endl;
		else if(c2>c1)
			cout << "time 2" << endl;
		else{
			int t = 0;
			for(j=0;j<entrada.size();j++){
				if(time2[j]==entrada[j] and time1[j]!=entrada[j]){
					t = 2;
					break;
				}
				else if(time1[j]==entrada[j] and time2[j]!=entrada[j]){
					t = 1 ;
					break;
				}
			}
			if(t==1)
				cout << "time 1" << endl;
			else if(t==2)
				cout << "time 2" << endl;
			else
				cout << "empate" << endl;
		}
		cout << endl;
		entrada.clear();
		time1.clear();
		time2.clear();
	}
}
#include <bits/stdc++.h>
using namespace std;

main(){
	map<string,int> m;
	map<string,double> saida;
	int i,j,n,total;
	string entrada;
	cin >> n;
	setbuf(stdin,NULL);
	for(i=0,total=0;i<n;i++,total = 0){
		getchar();
		while(getline(cin,entrada)){
//			cout << strlen(entrada) << endl;
			if(entrada.size()==0)
				break;
			total++;
			m[entrada]++;
			entrada.clear();
		}
		map<string,int>::iterator it;
		if(i!=0)
			cout << endl;
		for(it=m.begin();it!=m.end();it++){
			cout << fixed << setprecision(4) << it->first << " " << ((double)it->second/total)*100 << endl;
				
		}
		m.clear();
	}
	
}

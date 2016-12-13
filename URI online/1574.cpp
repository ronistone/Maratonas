#include <bits/stdc++.h>
using namespace std;
std::vector<string> v;

int verificao(string entrada,int posi = 0){
			int x,rear,i;
			//cout << entrada << endl;
			if(entrada.compare("LEFT")==0)
				return -1;
			else if(entrada.compare("RIGHT")==0)
				return 1;
			else if(entrada.size()>=6){
				rear = entrada.find("AS ")+3;
				//cout << "REAR: " << rear << endl;
				char instrucao[10];
				for(i=rear,x=0;i<entrada.size();i++,x++){
					instrucao[x] = entrada[i];
				}
				instrucao[i] = '\0';
				return verificao(v[atoi(instrucao)-1]);
			}
}

main(){
	int n,z,i,j;
	string entrada;
	int posi;

	cin >> n;

	for(i=0;i<n;i++){
		cin >> z;
		posi =0;
		for(j=0;j<z;j++){
			setbuf(stdin,NULL);
			getline(cin,entrada);
			v.push_back(entrada);
			posi += verificao(entrada); 
		}
		cout << posi << endl;
		entrada.clear();
		v.clear();
	}
}
#include <bits/stdc++.h>
using namespace std;

main(){
	string entrada;
	int gols;
	map<string,int> pontos;
	map<string,int>::iterator it;
	int i,j,x,n,maior;
	string time1,time2;
	char aux[100];
	while(cin >> n and n){
		for(i=0;i<n;i++){
			cin >> entrada >> gols;
			//cin.ignore();
			pontos[entrada] = gols;
		}
		for(i=0;i<floor(n/2);i++){
			cin >> time1;
			cin >> entrada;
			cin >> time2;
			for(j=0,x = 0;j<entrada.size();j++,x++){
				if(entrada[j] == '-'){
					aux[x] = '\0';
					gols = atoi(aux);
					x = -1;
				}
				else
					aux[x] = entrada[j];
			}
			aux[x] = '\0';
			pontos[time1]+= gols*3;
			pontos[time2]+= atoi(aux)*3;
			if(gols>atoi(aux))
				pontos[time1]+=5;
			else if(gols==atoi(aux)){
				pontos[time1]+=1;
				pontos[time2]+=1;
			}
			else
				pontos[time2]+=5;
		}
		for(it=pontos.begin(),maior = 0;it!=pontos.end();it++){
			if(it->second > maior){
				maior = it->second;
				time1 = it->first;			
			}
		}
		if(time1 == "Sport"){
			cout << "O Sport foi o campeao com " << maior <<" pontos :D" << endl;
		}
		else
			cout << "O Sport nao foi o campeao. O time campeao foi o " << time1 				 << " com " << maior << " pontos :(" << endl;
		pontos.clear();
		cout << endl;
	}

}

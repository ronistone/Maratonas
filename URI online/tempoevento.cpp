#include <iostream>
#include <cstdio>

using namespace std;

int main(){
	int hi,mi,si,hf,mf,sf,i,di,df,dia,hora,minuto,segundo;
	scanf("Dia %d", &di);
	getchar();
	scanf("%d : %d : %d", &hi,&mi,&si);
	getchar();
	scanf("Dia %d", &df);
	getchar();
	scanf("%d : %d : %d", &hf,&mf,&sf);
	getchar();
	dia = df - di;
	if(hora<0){
		hora =(hf - hi) + 24;
		dia--;
	}
	if(minuto<0){
		minuto = (mf - mi) + 60;
		hora--;
	}
	if(segundo<0){
		segundo = (sf - si) + 60;
		minuto--;
	}
	cout << dia << " dia(s)\n" << hora << " hora(s)\n" << minuto << " minuto(s)\n" << segundo << " segundo(s)\n";
return 0;
}
#include <bits/stdc++.h>
using namespace std;

typedef struct{
		int num;
		int cestas;
		int sofridas;
		int pontos;
}times;

bool ordena(times i,times j){
	double average,averagej;
	if(i.pontos>j.pontos)
		return true;
	else if(i.pontos==j.pontos){
			if(i.sofridas==0)
				average = i.cestas;
			else
				average = (double)i.cestas/i.sofridas;
			if(j.sofridas==0)
				averagej = j.cestas;
			else
				averagej = (double)j.cestas/j.sofridas;
			if(average>averagej)
				return true;
			else if(average==averagej){
					if(i.cestas>j.cestas)
						return true;
					else if(i.cestas==j.cestas){
								if(i.num>j.num)
									return true;
					}
			}
	}
	return false;
}

main(){
	int n,x,y,z,w,contador = 1;
	int jogos;
	int i,j,k;
	times aux;
	vector<times>T;
	while(cin >> n and n){
		if(contador!=1)
			cout << endl;
		jogos = (double)(n*(n-1))/2;
		for(i=0;i<n;i++){
				aux.cestas = 0;
				aux.sofridas = 0;
				aux.pontos = 0;
				aux.num = i+1;
				T.push_back(aux);
		}
		for(i=0;i<jogos;i++){
				cin >> x >> y >> z >> w;
				T[x-1].cestas+=y;
				T[x-1].sofridas+=w;
				T[z-1].cestas+=w;
				T[z-1].sofridas+=y;
				if(y>w){
					T[x-1].pontos+=2;
					T[z-1].pontos++;
				}
				else{
					T[z-1].pontos+=2;
					T[x-1].pontos++;
				}
		}
		sort(T.begin(),T.end(),ordena);
		
		cout << "Instancia " << contador << endl;
		for(i=0;i<T.size();i++){
			if(i!=0)
				cout << " ";
			cout << T[i].num;
		}
		cout << endl;
		contador++;
		T.clear();
	}
}

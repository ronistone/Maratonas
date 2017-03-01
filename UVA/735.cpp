#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;

main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	ll n;
	
	while(cin >> n and n > 0){
		ll perm = 0,comb=0;
		map<int,int> pcdontos;
		map<int,int>::iterator a,b,c;
		if(n <=180){
			for(int i=0;i<21;i++){
					pontos[i] = i;
					pontos[i*2] = i*2;
					pontos[i*3] = i*3;
			}
			pontos[61] = 50;
			for(a=pontos.begin();a!=pontos.end();a++){
				for(b=pontos.begin();b!=pontos.end();b++){
					for(c=pontos.begin();c!=pontos.end();c++){
						if(a->second+b->second+c->second==n){
							perm++;
							if(a->first <= b->first and b->first <= c->first)
								comb++;
						}
						
					}
				}
			}			
		}
		if(comb == 0)
			cout << "THE SCORE OF " << n << " CANNOT BE MADE WITH THREE DARTS.\n"
				 << "**********************************************************************\n";
		else
			cout << "NUMBER OF COMBINATIONS THAT SCORES " << n << " IS " << comb << ".\n"
				 << "NUMBER OF PERMUTATIONS THAT SCORES " << n << " IS " << perm << ".\n"
				 << "**********************************************************************\n";
	}
	cout << "END OF OUTPUT\n";
}

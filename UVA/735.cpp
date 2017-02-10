#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;

main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	ll n;
	
	while(cin >> n and n > 0){
		ll perm = 0,comb=0;
		int pontos[200];
		for(int i=0;i<62;i++){
				pontos[i] = i;
				pontos[i*2] = i*2;
				pontos[i*3] = i*3;
		}
		pontos[61] = 50;
		for(ll d1=0;d1<62;d1++){
			for(ll d2=0;d2<62;d2++){
				for(ll d3=0;d3<62;d3++){
					if(pontos[d1]+pontos[d2]+pontos[d3]==n){
						comb++;
						perm++;
					}
				}
			}
		}
		if(n <=180){
			
		}
		if(comb == 0)
			cout << "THE SCORE OF " << n << " CANNOT BE MADE WITH THREE DARTS.\n"
				 << "**********************************************************************\n";
		else
			cout << "NUMBER OF COMBINATIONS THAT SCORES " << n << " IS " << comb << ".\n"
				 << "NUMBER OF PERMUTATIONS THAT SCORES " << n << " IS " << perm << ".\n"
				 << "**********************************************************************\n";
	}
}

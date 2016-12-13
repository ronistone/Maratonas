#include <bits/stdc++.h>
using namespace std;

main(){
	int n,i,j,saida=1;
	cin >> n;
	std::vector<int> v;
	for(i=0;i<n;i++){
		cin >> j;
		v.push_back(j);
		if(v[i]==v[i-1] && i>0)
			saida = 0;
	}
	if(saida){
		for(i=0;i<n-1;i++){
			bool pico = false;
			if(v[i]>v[i+1])
				pico = true;
			if(n>i+2){
				if(!pico){
					if(v[i+1]>v[i+2])
						saida = 1;
					else{
						saida = 0;
						break;
					}
				}
				else if(v[i+1]<v[i+2] && pico){
					if(n>i+3){
						if(v[i+2]>v[i+3] && pico)
							saida = 1;
						else{
							saida =0;
							break;
						}
					}
					else
						saida = 1;
				}
				else{
					saida = 0;
					break;
				}
			}

		}
	}
	cout << saida << endl;
}
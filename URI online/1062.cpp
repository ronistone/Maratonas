#include <bits/stdc++.h>
using namespace std;

main(){
	int n,i,j,e;
	std::vector<int> entrada, saida,final;
	stack<int> estacao;
	cin >> n;
	while(n!=0){
		bool verifica = false;
		while(!verifica){
			int x = n;
			for(i=0;i<n;i++, x--){
					cin >> e;
					if(e==0){
						verifica = true;
						cout << endl;
						break;
					}
					entrada.push_back(x);
					final.push_back(e);
				}
				bool falha = false;
				int count =0;
				if(!verifica){
					while(!(entrada.size()==0 && estacao.empty())){
						count ++;
						if(entrada.size()==0 && (!estacao.empty() && estacao.top()!=final[saida.size()])){
							falha = true;
							break;
						}
						else if(entrada.size()==0 && estacao.empty())
							break;
						else if(estacao.size()!=0 && estacao.top()==final[saida.size()]){
							saida.push_back(estacao.top());
							estacao.pop();
						}
						else if(entrada.size()!=0 && entrada.back()==final[saida.size()]){
							saida.push_back(entrada.back());
							entrada.pop_back();
						}
						else if(entrada.size()!=0){
							estacao.push(entrada.back());
							entrada.pop_back();
						}
					}

					if(falha)
						cout << "No" << endl;
					else
						cout << "Yes" << endl;
				}
				while(!estacao.empty()){estacao.pop();}
				entrada.clear();
				saida.clear();
				final.clear();
		}

		cin >> n;
	}
}

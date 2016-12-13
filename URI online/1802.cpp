#include <bits/stdc++.h>
using namespace std;


main(){
		vector<int> p,m,f,q,b,s;
		int aux,k;
		int n,i,j;
		
		cin >> n;
		for(i=0;i<n;i++){
				cin >> aux;
				p.push_back(aux);
		}
		cin >> n;
		for(i=0;i<n;i++){
				cin >> aux;
				m.push_back(aux);
		}
		cin >> n;
		for(i=0;i<n;i++){
				cin >> aux;
				f.push_back(aux);
		}
		cin >> n;
		for(i=0;i<n;i++){
				cin >> aux;
				q.push_back(aux);
		}
		cin >> n;
		for(i=0;i<n;i++){
				cin >> aux;
				b.push_back(aux);
		}
		sort(p.begin(),p.end());
		sort(m.begin(),m.end());
		sort(f.begin(),f.end());
		sort(q.begin(),q.end());
		sort(b.begin(),b.end());
		int saida=0;
		cin >> k;
		for(i=0,j=0;i<k;i++,j++){
				if(j<p.size()){
					saida +=p[j];
						if(j!=0){
							saida-=p[j-1];
							continue;
						}
				}
				if(j<m.size()){
					saida +=m[j];
						if(j!=0){
							saida-=m[j-1];
							continue;
						}
				}
				if(j<f.size()){
					saida +=f[j];
						if(j!=0){
							saida-=f[j-1];
							continue;
						}
				}
				if(j<q.size()){
					saida +=q[j];
						if(j!=0){
							saida-=q[j-1];
							continue;
						}
				}
				if(j<b.size()){
					saida +=b[j];
						if(j!=0){
							saida-=b[j-1];
							continue;
						}
				}
		}
		cout << saida << endl;
}

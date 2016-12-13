#include <bits/stdc++.h>
using namespace std;

main(){
		int n;
		int z;
		int i,j,k,aux,q,contador,a,b,o;
		vector<map<int,bool> > v;
		map<int,bool> va;
		map<int,bool>::iterator it;
		scanf("%d",&n);

		for(i=0;i<n;i++){
			scanf("%d",&z);
			for(k=0;k<z;k++){
				scanf("%d",&q);
				for(j=0;j<q;j++){
					scanf("%d",&aux);
					va[aux] = true;
				}
				v.push_back(va);
				va.clear();
			}
			scanf("%d",&z);
			for(j=0;j<z;j++){
					contador = 0;
					scanf("%d %d %d", &o,&a,&b);
						for(it = v[a-1].begin();it!=v[a-1].end();it++){
							if(v[b-1].count(it->first))
								contador++;
						}
		//				cout << contador << endl;
		//				cout << v[a-1].size() << v[b-1].size() << endl;
					if(o==2)
						contador = v[a-1].size()+v[b-1].size() - contador;
					printf("%d\n",contador);
			}
			v.clear();
		}
}

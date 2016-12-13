#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> ii;
typedef vector<int> vi;

vi proibidos;
bool visitados[100001];

bool valid(int n){
	if(n<=0 or n>100000) return false;
	if(visitados[n]) return false;
	if(find(proibidos.begin(),proibidos.end(),n)!=proibidos.end()) return false;
	return true;
}

int bfs(int ini,int dest){
	queue<ii> q;
	memset(visitados,false,sizeof(visitados));
	q.push(make_pair(0,ini));
	
	while(!q.empty()){
		int custo = q.front().first;
		int num = q.front().second;
		q.pop();
		if(num==dest)
			return custo;
		if(valid(num+1))
			q.push(make_pair(custo+1,num+1)),visitados[num+1]=true;
			
		if(valid(num-1))
			q.push(make_pair(custo+1,num-1)),visitados[num-1]=true;
			
		if(valid(num*2))
			q.push(make_pair(custo+1,num*2)),visitados[num*2]=true;
			
		if(valid(num*3))
			q.push(make_pair(custo+1,num*3)),visitados[num*3]=true;
			
		if(num%2==0 and valid(num/2))
			q.push(make_pair(custo+1,num/2)),visitados[num/2]=true;
		
	}
	return -1;
}


main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int i,o,d,k,aux;
	
	while(cin >> o >> d >> k and (o or d or k)){
		proibidos.clear();
		for(i=0;i<k;i++){
			cin >> aux;
			proibidos.push_back(aux);
		}
		cout << bfs(o,d) << "\n";
	}
}

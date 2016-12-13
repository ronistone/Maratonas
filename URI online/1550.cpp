#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> ii;

int inverte(int num){
	int i,x;
	char entrada[100],saida[100];
	sprintf(entrada,"%i",num);
	for(i=strlen(entrada)-1,x=0;i>=0;i--,x++){
		saida[x]=entrada[i];
	}
	saida[x]='\0';
	
	return atoi(saida);	
}

int bfs(int ini,int dest){
	queue<ii> q;
	map<int,bool> visitados;
	q.push(make_pair(0,ini));
	while(!q.empty()){
		int custo = q.front().first;
		int num  = q.front().second;
		q.pop();
		if(num==dest)
			return custo;
		int inv = inverte(num);
		if(!visitados[num+1])
			q.push(make_pair(custo+1,num+1)),visitados[num+1]=true;
		if(!visitados[inv])
			q.push(make_pair(custo+1,inv)),visitados[inv]=true;
	}
}

main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n,i;
	int ini,dest;
	
	cin >> n;
	for(i=0;i<n;i++){
		cin >> ini >> dest;
		cout << bfs(ini,dest) << '\n';
	}
	
}

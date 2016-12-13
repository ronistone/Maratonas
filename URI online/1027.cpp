#include <bits/stdc++.h>
#define maxn (1<<16)

using namespace std;

vector<int> pontos[2*maxn+4];
set<int> ypos;
main()
{
		int n;
	while(scanf("%d", &n)!=EOF){
	
		for(int i=0;i<n;i++)
		{
			int x, y;
	
			scanf("%d %d", &x, &y);
	
			pontos[maxn + y + 1].push_back(x);
			ypos.insert(maxn + y + 1);
		}
	
		int maior = 0;
		for(set<int>::iterator it = ypos.begin(); it != ypos.end();it++)
		{
			int y = (*it);
			sort(pontos[y].begin(), pontos[y].end());
		
			int tam = 1;
			if(ypos.count(y+2))
			{
				sort(pontos[y+2].begin(), pontos[y+2].end());
		
				vector<int>::iterator i = pontos[y].begin(), j = pontos[y+2].begin();
	
				if(pontos[y][0] > pontos[y+2][0])
				{
					tam++;
					j++;
				}
	
				while(1)
				{
					j = lower_bound (j, pontos[y+2].end(), *i);
	
					if(j != pontos[y+2].end() && *j == *i)
						j++;
	
					if(j == pontos[y+2].end())
						break;
	
					tam++;
	
					i = lower_bound (i, pontos[y].end(), *j);
	
					if(i != pontos[y].end() && *i == *j)
						i++;
	
					if(i == pontos[y].end())
						break;
	
					tam++;
				}
			}
			if(tam > maior)
				maior = tam;
		}
		printf("%d\n", maior);
		ypos.clear();
		for(int x=0;x<2*maxn+4;x++)
			pontos[x].clear();
	}}
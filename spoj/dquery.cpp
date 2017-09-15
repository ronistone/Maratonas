#include <bits/stdc++.h>
using namespace std;

#define F first
#define S second


typedef long long int ll;
typedef pair<pair<int,int>, int> iii;

int A[30010],cont[1001000],n,q,ans[200010];
int current,BLOCK;
iii Q[200010];

bool cmp(iii  a, iii b){
	int x = a.F.F/BLOCK;
	int y = b.F.F/BLOCK;
	if(x!=y)
		return x < y;
	return a.F.S < b.F.S;
}

void add(int x){
	cont[x]++;
	if(cont[x]==1){
		current++;
	}
}
void remove(int x){
	cont[x]--;
	if(!cont[x])
		current--;
}

main(){
	int i;
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	scanf("%d",&n);
	for(i=1;i<=n;i++){
		scanf("%d",&A[i]);
	}
	BLOCK = sqrt(n);
	scanf("%d",&q);
	//memset(cont,0,sizeof cont);	
	for(i=0;i<q;i++){
		scanf("%d %d", &Q[i].F.F, &Q[i].F.S);
		Q[i].S = i;
	}
	sort(Q,Q+q,cmp);
	
	int R = 0, L=1,LL,RR;
	
	for(i=0;i<q;i++){
		RR = Q[i].F.S;
		LL = Q[i].F.F;
		while(R < RR){
			R++;
			add(A[R]);
		}
		while(R > RR){
			remove(A[R]);
			R--;
		}
		while(L < LL){
			remove(A[L]);
			L++;
		}
		while(L > LL){
			L--;
			add(A[L]);
		}
		ans[Q[i].S] = current;
	}
	for(i=0;i<q;i++){
		printf("%d\n",ans[i]);
	}

}

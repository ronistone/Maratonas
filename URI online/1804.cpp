#include <bits/stdc++.h>
using namespace std;

//typedef long long int ll;
int BIT[100100],ans;
int A[100100],n;
inline void update(int value,int index){
		
	for(;index<=n;index += index & (-index))
		BIT[index] += value;
}
inline int query(int index){
	ans = 0;

	for(;index > 0; index -= index&(-index))
		ans += BIT[index];
		
	return ans;
}

main(){
	char e;
	int from,aux,i;
	
	scanf("%d",&n);
	
		for(i=1;i<=n;i++){
			scanf("%d",&A[i]);
			update(A[i],i);
		}
		while(scanf("%c %d", &e, &from)!=EOF){
			if(e=='a'){
					update(-A[from],from);
			}
			else if(e=='?')
				printf("%d\n",query(from-1));
		}
}

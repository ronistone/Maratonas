#include <bits/stdc++.h>
using namespace std;

typedef struct
{
	int x,y,u,v;
}coord;

main(){
	int n,x,y,u,v;

	while(cin >> n and n!=0){
		coord a[n];

		for(i=0;i<n;i++){
			cin >> a[i].x >> a[i].y >> a[i].u >> a[i].v;
		}
		x = a[0].x;
		y = a[0].y;
		u = a[0].u;
		v = a[0].v;
		for(i=1;i<n;i++){
			if(x>=a[i].x and y>=a[i].y)
		}
	}
}
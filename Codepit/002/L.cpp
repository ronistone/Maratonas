#include <bits/stdc++.h>
using namespace std;

main(){
	long long int xmin,xmax,ymin,ymax;
	long long int n,b,count,x=1,y=1,direcao = 4;
	cin >> n >> b;
	xmin = ymin = 1;
	xmax = ymax = n;
	ymin--;
	for(;b!=0;){
		if(b-(xmax-(xmin-1))>=0){
			b-=xmax+(xmin-1);
			x = xmax;
			xmax--;
		}
		else{
			x+=b;
			b = 0;
		}
		if(b==0)
			break;
		if(b-(ymax-(ymin-1))>=0){
			b-=ymax+(ymin-1);
			y = ymax;
			ymax--;
		}
		else{
			y+=b;
			b = 0;
		}
		if(b==0)
			break;
		if(b-(xmax-(xmin-1))>=0){
			b-=(xmax-(xmin-1));
			x = xmin;
			xmin++;
		}
		else{
			x-=b;
			b =0;
		}
		if(b==0)
			break;
		if(b-(ymax-(ymin-1))>=0){
			b-=(ymax-(ymin-1));
			y = ymin;
			ymin++;
		}
		else{
			y-=b;
			b=0;
		}
		if(b==0)
			break;
	}
	cout << x << " " << y << endl;	
}
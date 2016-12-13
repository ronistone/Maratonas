#include <iostream>

using namespace std;

typedef struct{
	int x, y;
}posicao;

int main(){
	int n,i,xmin=1000000,ymin=1000000,xmax=-1000000,ymax=-1000000,j;
	posicao p[5]; 
	cin >> n;
	int v[n];
	for(i=0;i<n;i++){
		for(j=0;j<4;j++){
			cin >> p[j].x >> p[j].y;
			if(j==0){
				xmin = p[j].x;
				ymin = p[j].y;
			}
			if(j==2){
				xmax = p[j].x;
				ymax = p[j].y;
			}
		}
		cin >> p[4].x >>p[4].y;
		if(p[4].x>=xmin && p[4].x<=xmax && p[4].y>=ymin && p[4].y<=ymax)
			v[i] = 1;
		else
			v[i] = 0;		
	}
	for(i=0;i<n;i++)
		cout << v[i] << endl;

return 0;
}
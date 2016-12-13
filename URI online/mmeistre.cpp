#include <iostream>
#include <cstdio>

using namespace std;

int main(){
	int x,y,z=0,i=0,j=0;
	cin >> y >> x;
	char c[x][y];
	for(i=0;i<x;i++){
		for(j=0;j<y;j++){
			cin >> c[i][j];
		}
	}
	i=0;
	j=0;
	while(z!=-1){
		if(i<0 || i>x || j<0 || j>y || c[i][j]==0){
			printf("!\n");
			break;
		}
		else if(c[i][j]=='.'){
			if(z==1){
				c[i][j]=0;
				i--;
			}
			else if(z==2){
				c[i][j]=0;
				i++;
			}
			else if(z==3){
				c[i][j]=0;
				j--;
			}
			else if(z==4){
				c[i][j]=0;
				j++;
			}

		}
		else if(c[i][j]=='^'){
			z = 1;
			c[i][j]=0;
			i--;
		}
		else if(c[i][j]=='v'){
			z=2;
			c[i][j]=0;
			i++;
		}
		else if(c[i][j]=='<'){
			z=3;
			c[i][j]=0;
			j--;
		}
		else if(c[i][j]=='>'){
			z=4;
			c[i][j]=0;
			j++;
		}
		else if(c[i][j]=='*'){
			z=-1;
			printf("*\n");
			break;
		}
		else if(z==0){
			printf("!\n");
			break;
		}

	}
return 0;
}
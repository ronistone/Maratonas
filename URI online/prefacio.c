#include <stdio.h>
#include <stdlib.h>
int main(){
	int a,b;
	scanf("%d %d", &a, &b);
	int q=a/b;
	int r=a%b;
	if(a < 0 && b < 0){
		if(r<0 && q<=0){
			q++;
			r=-(b*q)+a;
		}
		else if(r<0 && q>0){
			q++;
			r=-(b*q)+a;
		}
	}
		else{
			if(r<0 && q<=0){
				q--;
				r=-(b*q)+a;
			}
			else if(r<0 && q>0){
				q++;
				r=-(b*q)+a;
			}
		}
	printf("%d %d\n", q, r);

return 0;
}
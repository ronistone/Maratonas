#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;


int main(){
	int abcde,fghij,tmp,used,n;
	bool achou,f=true;
	
	while(cin >> n and n){
		achou = false;
		if(!f)
		 cout << endl;
		for(fghij=1234;fghij <= 98765/n;fghij++){
			abcde = fghij*n;
			used = (fghij < 10000);
			tmp = abcde;
			while(tmp){
				used |= 1 << (tmp%10);
				tmp /= 10;
			}
			tmp = fghij;
			while(tmp){
				used |= 1 << (tmp%10);
				tmp /= 10;
			}
			if(used == (1<<10)-1){
				printf("%0.5d / %0.5d = %d\n",abcde,fghij,n);
				achou = true;
			}
		}
		if(!achou)
			printf("There are no solutions for %d.\n",n);
		f = false;
	}
	

return 0;
}

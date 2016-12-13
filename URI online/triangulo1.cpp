#include <iostream>
#include <cmath>

using namespace std;

int main(){
	int n[4],i,j,x,aux=0;

	for(i=0;i<4;i++)
		cin >> n[i];
	for(i=0;i<4;i++){
		for(j=0;j<4;j++){
			if(i!=j){
				if(i>j)
					x=
			}
		}
	}
	for(i=0;i<4;i++){
		for(j=0;j<4;j++){
			for(x=0;x<4;x++){
				if(i!=j && i!=x && j!=x){
					if((fdim(n[i],n[j])<n[x]) && (n[x]<n[i]+n[j]) || (fdim(n[x],n[j])<n[i] && n[i]<n[x]+n[j]) || (fdim(n[i],n[x])<n[j] && n[j]<n[i]+n[x])){
						aux=1;
					}
				}
			}
		}
	}
	cout << fdim(n[1],n[0]) << endl;
	if(aux==1)
		cout << "S" << endl;
	else
		cout << "N" << endl;


return 0;
}
#include <bits/stdc++.h>
using namespace std;

int main(){
	int t,n,x,saida,k=1,i,j;
	cin >> t;
	vector<int> A;
	while(t--){
	
		saida = 0;
		cin >> n;
		A.clear();
		
		for(i=0;i<n;i++){
			cin >> x;
			A.push_back(x);
		}
		sort(A.begin(),A.end());
		
		i=0; j=n-1;
		int sum = 0,cont=1;
		while(i<j){
			if(A[j]>=50){
				saida++;
				j--;
			}
			else{
				while((i<j) and A[j]*cont<50){
					cont++;
					i++;
				}
				if(A[j]*cont>=50){
					saida++;
					cont=1;
					j--;
				}
				else break;
			}
		}
		cout << "Case #" << k++ << ": " << saida << endl;
	}

}

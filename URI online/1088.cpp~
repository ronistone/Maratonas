#include <bits/stdc++.h>
using namespace std;

int ShellSort(int num[],int tam) {
     int i, temp, flag = 1, numLength = tam;
     int d = numLength,cont=0;
     while( flag || (d > 1)) {                    
          flag = 0;                               
          d = (d+1) / 2;
          for (i = 0; i < (numLength - d); i++) {
               if (num[i + d] > num[i]) {
                      temp = num[i + d];         
                      num[i + d] = num[i];
                      num[i] = temp;
                      flag = 1;
                      cont++;
               }
          }
     }
     return cont;
}

main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int n,i,j,aux;
	int v[100001];
	
	while(cin >> n and n){
		for(i=0;i<n;i++){
			cin >> v[i];
		}
		i=-1;
		int a = ShellSort(v,n);
			
		if((a+1)%2==0)
			cout << "Marcelo" << endl;
		else
			cout << "Carlos" << endl;
	}
}

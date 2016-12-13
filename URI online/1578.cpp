#include <bits/stdc++.h>
/*using namespace std;

main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n,m,i,j,x;
	cin >> n;
	for(x=4;x<n+4;x++){
		cin >> m;
		int matriz[m][m];
		for(i=0;i<m;i++){
			for(j=0;j<m;j++){
				cin >> matriz[i][j];
				matriz[i][j] *= matriz[i][j];
			}
		}
		cout << "Quadrado da matriz #" << x << ":" << endl;
		for(i=0;i<m;i++){
			cout << "\t";
			for(j=0;j<m;j++){
				cout << matriz[i][j];
				if(j!=m-1)
					cout << " ";
			}
			cout << endl;
		}
	}
}*/

//#include <stdio.h>
//#include <stdlib.h>
 
int main(){ 
    int n,m;
    int x =4;
    int i= 0,y=0,w=0;
    scanf("%d",&n);
    for(;i<n;i++){
       scanf("%d",&m);
       long long int matriz[m][m];
       long long int qua[m][m];
       for(y=0;y<m;y++){
           for(w=0;w<m;w++){
               scanf("%lld",&matriz[y][w]);                             
           }                             
       }
       for(y=0;y<m;y++){
           for(w=0;w<m;w++){
             qua[y][w] = matriz[y][w] * matriz[y][w];                             
           }             
       }
       printf("Quadrado da matriz #%d:\n",x);
       for(y=0;y<m;y++){
           for(w=0;w<m;w++){
             if(w== m-1){
                printf("%lld\n",qua[y][w]);           
             }
             else
                 printf("%lld ",qua[y][w]);                           
           }             
       }
       x++;
    }
    return 0;
}
#include <iostream>

using namespace std;

 int main(){
 	int n;
 	cin >> n;
 	int v[n-1],i,b[n+1];
 	for(i=1;i<=n;i++){
 		b[i]= -1;
 	}
 	for(i=0;i<n-1;i++){

 		cin >> v[i];
 		b[v[i]]=v[i];
 	}
 	for(i=1;i<=n;i++){
 		//cout << b[i] << endl;
 		if(b[i]==-1){
 			cout << i << endl;
 			return 0;
 		}
 	}
return 0;
 }
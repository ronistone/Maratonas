#include <bits/stdc++.h>
using namespace std;

main(){
	int n,i;

	cin >> n;

	while(n!=0){
		int a[n],count = 0;
		bool direcao = true;		// true == subindo      false == descendo
		for(i=0;i<n;i++){
			cin >> a[i];
		}
		for(i=0;i<n;i++){
				if(i==0){
					if(a[n-1]>=a[0] && a[0]<=a[1]){
						count++;
						direcao = true;
					}
					else{
						direcao = false;
					}
				}
			if(direcao){
				if(i!=0 && i<n && a[i-1]<a[i] && a[i]==a[i+1]){
					count++;
					direcao = false;
				}
				else if(i!=0 && a[i]<a[i-1]){
					direcao = false;
					count ++;
				}
			}
			else if(!direcao && i!=0 && a[i]>a[i-1]){
				direcao = true;
				count ++;
			}
			
		}
				if(direcao && a[n-1]>a[0] && a[0]<=a[1])
					count++;
				else if(!direcao && a[n-1]<a[0] && a[0]>a[1])
					count++;

		cout << count << endl;
		cin >> n;
	}
}
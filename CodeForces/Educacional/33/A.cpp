#include <bits/stdc++.h>
using namespace std;

int main(){
	
	int a=1,b=2,w,n,next=3,aux;
	cin >> n;
	
	for(int i=0;i<n;i++){
		cin >> w;
		if(w == next){
			cout << "NO" << endl;
			return 0;
		}
		if(w==a){
			swap(b,next);
		}
		else if(w ==b){
			swap(a,next);
		}
	}
	cout << "YES" << endl;

}

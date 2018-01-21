#include <bits/stdc++.h>
using namespace std;

main(){
	int ant=-1,at=0,ans = 0, M=0;
	cin >> n >> d;
	bool zero = false;
	for(int i=0;i<n;i++){
		cin >> a;
		if(a!=0 and and ant==-1){
			at += a;
		}
		else if(a == 0){
			if(((M + at) < M) and ((M + abs(at)) <=d)){
				at = M+abs(at);
				at = 0;
				M = 0;
				ans++;
			}
			if(abs(at) <= d){
				ant = abs(at);
			}else{
				ans = -1;
				break;
			}
		}
	}
}

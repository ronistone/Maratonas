#include <bits/stdc++.h>
using namespace std;

char m[3][3];
typedef long long int ll;

main(){
	while(cin >> m[0][0]){
		for(int i=0;i<3;i++){
			for(int j=0;j<3;j++){
				if(not (i==j and i==0)){
					cin >> m[i][j];
				}
			}
			cin.ignore();
		}
		bool ans = false;
		for(int i=0;i<3;i++){
			ll c=0,l=0;
			for(int j=0;j<3;j++){
				if(m[i][j]=='1')
					l++;
				if(m[j][i]=='1')
					c++;
			}
			if(l==2 or c==2){
				ans = true;
				break;
			}
		}
		ll p = 0,s=0;
		if(m[0][0]=='1')
			p++;
		if(m[1][1]=='1'){
			p++;
			s++;
		}
		if(m[2][2]=='1'){
			p++;
		}
		if(m[0][2]=='1'){
			s++;
		}
		if(m[2][0]=='1'){
			s++;
		}
		if(s==2 or p==2){
			ans = true;
		}
			
			
		if(ans)
			cout << "SIM\n";
		else
			cout << "NAO\n";
		
	}
}

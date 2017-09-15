#include <bits/stdc++.h>
using namespace std;


int A[10];

void add(int i){
	for(int j=i;j<10;j++){
		A[j]++;
	}
}
void remove(int i){
	for(int j=i;j<10;j++){
		A[j]--;
	}
}


main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n,d;
	string e;
	
	while(cin >> n >> d and (n or d)){
		
		memset(A,0,sizeof A);
		
		cin >> e;
		
		for(int i=0;i<e.size();i++){
			A[(e[i]-'0')]++;
		}
		for(int i=1;i<10;i++)
			A[i] = A[i]+A[i-1];
		
		int i = 0;
		while(d){
			if(e[i]!= 'a' and A[(e[i]-'0')] <= d or ((e[i]-'0') == 0 and A[(e[i]-'0')] > 0) or (A[(e[i]-'0')-1]==0 and A[(e[i]-'0')]>0)){
				remove((e[i]-'0'));
				e[i] = 'a';
				d--;
				i = 0;
			}
			else{
				i++;
				if(i >= e.size()){
					i = 0;
				}
			}
		}
		for(i=0;i<e.size();i++){
			if(e[i]!='a')
				cout << e[i];
		}
		cout << endl;
	}

}

#include <bits/stdc++.h>
using namespace std;


main(){
	string M,S,Maux,Saux;
	int n,m=0,s=0;
	
	cin >> n;
	cin >> S;
	cin >> M;
	
	Maux = M;
	Saux = S;
	
	sort(Maux.begin(),Maux.end());
	sort(Saux.begin(),Saux.end());
	bool usou[n][2];
	memset(usou,false,sizeof(usou));
	for(int i=0;i<n;i++){
		for(int j=i;j<n;j++){
			if(!usou[j][1] and Maux[j] >= Saux[i]){
				m++;
				//cout << Maux[j] << "  " << Saux[i] << "  ----  " << j << "  " << i << endl;
				usou[j][1] = true;
				break;
			}
			
		}
	}
	memset(usou,false,sizeof(usou));
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			if(!usou[j][0] and Maux[j] > S[i]){
				s++;
				usou[j][0] = true;
				break;
			}
			
		}
	}
	cout << n-m << endl << s << endl;
	
	
}

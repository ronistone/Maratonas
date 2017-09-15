#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define F first
#define S second
typedef pair<int,int> ii;

main(){
	
	int c,s,cont=1,aux;
	double am,b;
	vector<ii> A;
	vector<pair<ii,ii> > ans;
	
	while(cin >> c >> s){
		am = 0;
		for(int i=0;i<s;i++){
			cin >> aux;
			A.pb(mp(aux,i));
			am+=aux;
		}
		am /= c;
		for(int i=s;i<2*c;i++){
			A.pb(mp(0,20));
		}
		sort(A.begin(),A.end());
		b = 0;
		cout << "Set #" << cont++ << endl;
		for(int i=0;i<c;i++){
			b += abs(A[i].F+A[(2*c)-1-i].F - am);
			if(A[i].S < A[(2*c)-1-i].S)
				ans.pb(mp(mp(A[i].S,A[i].F),mp(A[(2*c)-1-i].S,A[(2*c)-1-i].F)));
			else
				ans.pb(mp(mp(A[(2*c)-1-i].S,A[(2*c)-1-i].F),mp(A[i].S,A[i].F)));
		}
		sort(ans.begin(),ans.end());
		for(int i=0;i<c;i++){
			cout << " " << i << ":";
			if(i < ans.size()){
				if(ans[i].F.S!=0 and ans[i].S.S!=0)
					cout << " " << ans[i].F.S << " " << ans[i].S.S << endl;
				else if(ans[i].F.S==0 and ans[i].S.S!=0)
					cout << " " << ans[i].S.S << endl;
				else if(ans[i].S.S==0 and ans[i].F.S!=0)
					cout << " " << ans[i].F.S << endl;
				else
					cout << endl;
			}
		}
		cout << fixed << setprecision(5) << "IMBALANCE = " << b << endl;
		cout << endl;
		A.clear();
		ans.clear();
	}

}

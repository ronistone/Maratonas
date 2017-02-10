#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;

main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	ll a,b,c,x,y,z,n;
	
	cin >> n;
	for(int i=0;i<n;i++){
		cin >> a >> b >> c;
		ll l = sqrt(c);
		bool parar = false;
			for(x=-l;x<=l;x++){
				for(y=-l;y<=l;y++){
					for(z=-l;z<=l;z++){
						if((x+y+z==a) and (x*y*z==b) and ((x*x)+(y*y)+(z*z))==c and x!=y and x!=z and y!=z){
							cout << x << " " << y << " " << z << endl;
							parar = true;
							break;
						}
					}
					if(parar)
						break;
				}
				if(parar)
					break;
			}
		if(!parar)
			cout << "No solution.\n";
	}
}

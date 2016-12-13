#include <bits/stdc++.h>
using namespace std;

main(){
	double x,y,x1,y1,v,r1,r2;
	double saida;
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	while(cin >> x >> y >> x1 >> y1 >> v >> r1 >> r2){
		if((sqrt(((x-x1)*(x-x1))+((y-y1)*(y-y1)))+(v*1.5)<=r1+r2))
			cout << "Y" << endl;
		else
			cout << "N" << endl;
	}
}

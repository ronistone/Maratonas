#include <bits/stdc++.h>

using namespace std;

main(){
	string a,b,c;
	int n,i;

	cin >> n;

	for(i=0;i<n;i++){
		cin >> a >> b;
		while(a.size()!=0 && b.size()!=0){
			c.push_back(a[0]);
			c.push_back(b[0]);
			a.erase(a.begin());
			b.erase(b.begin());
		}
		if(a.size()>0)
			c.append(a);
		else
			c.append(b);
		cout << c << endl;
		c.clear();
		a.clear();
		b.clear();
	}
}
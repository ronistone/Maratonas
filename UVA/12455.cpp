#include <bits/stdc++.h>
using namespace std;




main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n,z,x;
	int num[21];
	cin >> n;
	for(int k=0;k<n;k++){
			cin >> x >> z;
			for(int i=0;i<z;i++){
				cin >> num[i];	
			}
			bool ans = false;
			for(int i=0;i< (1<<z);i++){
					int sum = 0;
					for(int j=0;j<z;j++)
							if(i & (1 << j))
								sum +=num[j];
					if(sum == x) {ans = true;break;}
			}
			if(ans)
				cout << "YES\n";
			else
				cout << "NO\n";
	}
}

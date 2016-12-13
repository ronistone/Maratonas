#include <bits/stdc++.h>

using namespace std;

main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int i,j,n,k,feed;

	cin >> n;

	for(i=0;i<n;i++){
		cin >> k;
		for(j=0;j<k;j++){
			cin >> feed;
			switch(feed){
				case 1:
					cout << "Rolien" << endl;
					break;
				case 2:
					cout << "Naej" << endl;
					break;
				case 3:
					cout << "Elehcim" << endl;
					break;
				case 4:
					cout << "Odranoel" << endl;
					break;
			}
		}
	}
}
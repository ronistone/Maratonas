#include <bits/stdc++.h>
using namespace std;

main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int i,j,F,R;
	double front[1000],rear[1000];
	vector<double> drive;
	
	while(cin >> F and F){
		cin >> R;
		for(i=0;i<F;i++)
			cin >> front[i];
			
		for(i=0;i<R;i++)
			cin >> rear[i];
			
		for(i=0;i<F;i++)
			for(j=0;j<R;j++)
				drive.push_back(rear[j]/front[i]);
				
		sort(drive.begin(),drive.end());
		double ratio = 0;
		
		for(i=1;i<drive.size();i++)
			ratio = max(ratio,drive[i]/drive[i-1]);
			
		cout << fixed << setprecision(2) << ratio << endl;
		drive.clear();
	}
}

#include <bits/stdc++.h>
using namespace std;

typedef pair<int,int> ii;

bool sortByDifficult(ii a, ii b){
	if(a.first > b.first) return true;
	if(a.first == b.first) return a.second < b.second;
	return false;
}

bool sortByPosition(ii a, ii b){
	
	if(a.second < b.second) return true;
	if(a.second == b.second) return a.first > b.first;
	return false;
}


main(){
	
	int n, k, a;
	vector<ii> problems, ans;
	cin >> n >> k;
	
	
	for(int i=1;i<=n;i++){
		cin >> a;
		problems.push_back(make_pair(a,i));
	}
	
	sort(problems.begin(), problems.end(), sortByDifficult);
	
	int ansSum = 0;
	for(int i=0;i<k;i++){
		ans.push_back(problems[i]);
		ansSum += problems[i].first;
	}
	sort(ans.begin(), ans.end(), sortByPosition);
	
	cout << ansSum << endl;
	int size = 0;
	int ant = 0, at;
	for(int i=0;i<ans.size();i++){
		if(i!=0) cout << " ";
		if( i == ans.size()-1 )
			at = n;
		else
			at = ans[i].second;
		cout << at - ant;
		ant = ans[i].second;
	}
	
	//cout << " " << n-1 - ant;
	cout << endl;
}

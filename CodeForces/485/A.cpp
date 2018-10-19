 #include <bits/stdc++.h>
 using namespace std;
 
 main(){
	string e;
	unordered_map<string,bool> gems;
	map<string,string> val;
	unordered_map<string,bool>::iterator it;
	
	gems["purple"] = false;
	gems["green"] = false;
	gems["blue"] = false;
	gems["orange"] = false;
	gems["red"] = false;
	gems["yellow"] = false;
	
	val["purple"] = "Power";
	val["green"] = "Time";
	val["blue"] = "Space";
	val["orange"] = "Soul";
	val["red"] = "Reality";
	val["yellow"] = "Mind";
	
	int t;
	
	cin >> t;
	
	vector<string> ans;
	while(t--){
		cin >> e;
		gems[e] = true;
		
	}
	for(it=gems.begin();it!=gems.end();it++){
			if(!it->second){
				ans.push_back(val[it->first]);
			}
		}
		cout << ans.size() << endl;
		for(int i=0;i<ans.size();i++){
			cout << ans[i] << endl;
		}
 
 }

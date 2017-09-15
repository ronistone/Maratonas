#include <bits/stdc++.h>
using namespace std;

string l,e,q;
map<char,bool> good;
int n;


bool back(int i, int j){
	
	if(i==e.size() and j==q.size()) return true;
	if(j==q.size() and e[i]!='*') return false;
	
	if(e[i]!='*' and e[i]!='?' and e[i]==q[j]) return back(i+1,j+1);
	else if(e[i]=='?' and good[q[j]]) return back(i+1,j+1);
	else if(e[i]=='*'){
		int k=j;
		bool success = false;
		if(j==q.size()){
			return back(i+1,j);
		}
		for(k=j;k<q.size();k++){
			if(!good[q[j]]){
				success = (success or back(i+1,j+1));
			}
			else{
				break;
			}
			//else if(j<q.size()){
//				success = (back(i,j+1) or back(i+1,j+1));
	//		}
		}
		return success;
	}
	return false;
}




main(){
	cin >> l;
	cin.ignore();
	for(int i=0;i<l.size();i++)
		good[l[i]] = true;
	cin >> e;
	cin.ignore();
	cin >> n;
	cin.ignore();
	bool ans;
	for(int k=0;k<n;k++){
		getline(cin,q);
		ans = back(0,0);
		if(ans)		
			cout << "YES" << endl;
		else
			cout << "NO" << endl;
	}
	
}

#include <bits/stdc++.h>
using namespace std;

string pre,in;

int indice;
void pos(int L,int R){
	if(L<=R){
		indice++;
		int i = in.find(pre[indice]);
		pos(L,i-1);
		pos(i+1,R);
		cout << in[i];
	}
	
}

main(){	
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	while(cin >> pre  >> in){
		cin.ignore();
		indice = -1;
		pos(0,pre.size()-1);
		cout << endl;
	}
	

}

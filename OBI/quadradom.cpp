#include <iostream>

using namespace std;


int main(){
	int n;
	cin >> n;
	int v[n][n],i,j;

	for(i=0;i<n;i++){
		for(j=0;j<n;j++){
			cin >> v[i][j];
		}
	}
	int s,u,d=0;
	for(i=0;i<n;i++){
		s=0;
		u=0;
		for(j=0;j<n;j++){
			s+=v[i][j];
			u+=v[j][i];
			if(i==j)
				d+=v[j][j];
		}
		if(s!=u){
			cout << "-1" << endl;
			return 0;
		}
	}
	if(s!=d || u!=d){
		cout << "-1" << endl;
		return 0;
	}
	i=0;
	j=n-1;
	int w,y=0;
	for(w=0;w<n;w++){
		y+=v[i][j];
		i++;
		j--;
	}
	if(y!=s || y!= d || y!=u){
		cout << "-1" << endl;
		return 0;
	}
		cout << u << endl;
return 0;
}
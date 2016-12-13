#include <iostream>

using namespace std;

int main(){
	int n,s,i,j=1;

	cin >> s >> n;
	
	int a[n];

	for(i=0;i<n;i++)
		cin >> a[i];

	for(i=0;i<n-1;i++){
		if(a[i]<a[j]){
			if(a[j]-a[i]>s){
				cout <<"GAME OVER" << endl;
				return 0;
			}
		}
		if(a[i]>a[j]){
			if(a[i]-a[j]>s){
				cout <<"GAME OVER" << endl;
				return 0;
			}
		}
		j++;
	}

	cout << "YOU WIN" << endl;

return 0;
}
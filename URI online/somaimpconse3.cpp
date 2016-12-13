#include <iostream>

using namespace std;

int main(){
	int n,x,y,i,j,s,count;

	cin >> n;

	for(i=0;i<n;i++){
		cin >> x >> y;
		s=0;
		count=0;
		for(j=x;count<y;j++){
			if(j%2!=0){
				s+=j;
				count++;
			}
		}
		cout << s << endl;
	}
return 0;
}
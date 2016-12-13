#include <iostream>

using namespace std;

int main(){
	int x,y,i,s=0;
	cin >> x >> y;
	if(y>x){
		s=y;
		y=x;
		x=s;
		s=0;
	}
	for(i=y+1;i<x;i++){
		if(i%2!=0){
			s += i;
		}
	}
	cout << s << endl;

return 0;
}
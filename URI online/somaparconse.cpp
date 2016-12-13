#include <iostream>

using namespace std;

int main(){
	int n,x,y,i,j,s,count;

	for(i=0;;i++){
		cin >> x;
		if(x==0)
			break;
		s=0;
		count=0;
		for(j=x;count<5;j++){
			if(j%2==0){
				s+=j;
				count++;
			}
		}
		cout << s << endl;
	}
return 0;
}
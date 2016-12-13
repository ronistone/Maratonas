#include <iostream>

using namespace std;

int main(){
	int x, y,i,count=1;

	cin >> x >> y;

	for(i=1;i<=y;i++){
		if(count==x){
			cout << i << endl;
			count=1;
		}
		else{
			cout << i << " ";
			count++;
		}
	}
return 0;
}
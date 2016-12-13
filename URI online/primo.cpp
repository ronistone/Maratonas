#include <iostream>

using namespace std;

int main(){
	int n, num,i,j,v;

	cin >> n;

	for(i=0;i<n;i++){
		cin >> num;
		if(num==2){
					v=1;
				}
		if(num==1){
			v=0;
		}
			for(j=2;j<num;j++){
				if(num%j==0){
					v=0;
					break;
				}
				else
					v=1;
			}
			if(v==0)
				cout << num << " nao eh primo" << endl;
			else if(v==1)
				cout << num << " eh primo" << endl;
	}
return 0;
}
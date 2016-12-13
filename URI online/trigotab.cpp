#include <iostream>

using namespace std;

int main(){
	unsigned long long r;
	int n,i,j,x;
	cin >> n;
	
	for(i=0;i<n;i++){
		cin >> x;
		r = 1;
		
		if(x!=64){
			for(j=0;j<x;j++){
				r *= 2;
			}
			r /= 12000;

			cout << r << " kg" << endl;
		}
		else{
			cout << "1537228672809129 kg" << endl;
		}
	}
return 0;
}
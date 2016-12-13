#include <iostream>

using namespace std;

int main(){
	long long int n,x[1000000],y[1000000],i,a=0,r=0,v,s=0;
	cin >> n;

	for(i=0;i<n;i++){
		cin >> x[i];
		y[i]=0;
	}
	i=0;
	for(;;){
		if(i<0 || i>=n)
			break;
		if(x[i]%2==0)
			v = 0;
		else if(x[i]%2!=0)
			v = 1;
		if(x[i]>0){
			x[i]--;
			y[i] = 1;
		}
		if(v==0)
			i--;
		else if(v==1)
			i++;
	}
	for(i=0;i<n;i++){
		r += x[i];
		s += y[i];
	}
	cout << s << " " << r << endl;

return 0;
}
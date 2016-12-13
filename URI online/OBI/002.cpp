#include <iostream>

using namespace std;

int main(){
	int n,i,m2=0,m3=0,m4=0,m5=0;
	cin >> n;
	int a;
	for(i=0;i<n;i++){	
		cin >> a;
		if(a%2==0)
			m2++;
		if(a%3==0)
			m3++;
		if(a%4==0)
			m4++;
		if(a%5==0)
			m5++;
	}
	cout << m2 <<" Multiplo(s) de 2\n" << m3 << " Multiplo(s) de 3\n" << m4 << " Multiplo(s) de 4\n" << m5 << " Multiplo(s) de 5\n";
return 0;
}
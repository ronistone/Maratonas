#include <bits/stdc++.h>
using namespace std;
#define PI 3.14159265

bool calc(int p,int x, int y){
	double raio = sqrt(((x-50)*(x-50))+((y-50)*(y-50)));
	
	if(raio > 50) return false;
	double x1 = x-50;
	double y1 = y-50;
	double x2 = 0;
	double y2 = 50;
	
	double pr = (x2*x1)+(y1*y2);
	double d = sqrt((x1*x1)+(y1*y1))*sqrt((x2*x2)+(y2*y2));
	d = acos(pr/d) * (180.0/PI);
	d = x < 50 ? 360 - d: d;
	if(d <= ((double)p/100)*360) return true;
	else return false;
	
}


main(){
	int n;
	int x,y,p;
	cin >> n;
	
	for(int i=0;i<n;i++){
		cin >> p >> x >> y;
		cout << "Case #" << i+1 << ": ";
		if(calc(p,x,y))
			cout << "black\n";
		else
			cout << "white\n";	
	}
}

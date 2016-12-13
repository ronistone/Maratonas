#include <iostream>

using namespace std;

int main(){
	int x0,y0,x1,y1;
	int x2,y2,x3,y3;
	int xm,ym,xn,yn;
	cin >> x0 >> y0 >> x1 >> y1;
	cin >> x2 >> y2 >> x3 >> y3;

	if(x0>x1){
		xm = x0;
		xn = x1;
	}
	else{
		xm = x1;
		xn = x0;
	}
	if(y0>y1){
		ym = y0;
		yn = y1;
	}
	else{
		ym = y1;
		yn = y0;
	}
	if(x2>=xn && x3<xm && y2>=xn)


return 0;
}
#include <iostream>

using  namespace std;

int main(){
	int i,j,x1,y1,x2,y2,aux,auy,m;

	while(cin >> x1 >> y1 >> x2 >> y2){
		if(x1==0 && y1==0 && x2==0 && y2==0)
			break;
		m =0;
		aux = x2 - x1;
		auy = y2 - y1;

		if(!((aux==0 && auy!=0) || (aux!=0 && auy==0) || (aux==auy) || (aux== (-auy)))){
			m+=2;
		}
		else if(aux==0 && auy==0)
			m=0;
		else
			m++;
		cout << m << endl;
	}

return 0;
}
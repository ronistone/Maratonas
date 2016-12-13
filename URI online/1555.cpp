	#include <bits/stdc++.h>

	using namespace std;

	int rafael(int x, int y){return pow(3*x,2)+ (y*y);}
	int beto(int x, int y){return (2*pow(x,2))+pow(5*y,2);}
	int carlos(int x, int y){return (-100*x)+pow(y,3);}

	main(){
		int n,i,x,y;

		cin >> n;

		for(i=0;i<n;i++){
			cin >> x >> y;
			if(rafael(x,y)>beto(x,y) && rafael(x,y) > carlos(x,y))
				cout << "Rafael ganhou" << endl;
			else if(beto(x,y)>rafael(x,y) && beto(x,y)>carlos(x,y))
				cout << "Beto ganhou" << endl;
			else if(carlos(x,y)>rafael(x,y) && carlos(x,y)>beto(x,y))
				cout << "Carlos ganhou" << endl;
		}
	}
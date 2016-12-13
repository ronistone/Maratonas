#include <bits/stdc++.h>

using namespace std;

main(){
	int n,g,Bgol,Ggol,Rgol;
	char r,s;

	cin >> n;

	for(int i=0;i<n;i++){
		cin >> g;
		Bgol = 0;
		Ggol = 0;
		Rgol = 0;
		for(int j=0;j<g;j++){
			cin >> r >> s;
			if(r=='B' && s=='G')
				Bgol++;
			else if(r=='R' && s=='B')
				Rgol++;
			else if(r=='G' && s=='R')
				Ggol++;
			else if(r=='B' && s=='R')
				Bgol+=2;
			else if(r=='R' && s=='G')
				Rgol+=2;
			else if(r=='G' && s=='B')
				Ggol+=2;
		}
		if(Bgol==Ggol && Bgol==Rgol)
			cout << "trempate" << endl;
		else if((Bgol==Ggol && Ggol>Rgol) || (Bgol==Rgol && Rgol>Ggol) || (Ggol==Rgol && Rgol>Bgol))
			cout << "empate" << endl;
		else if(Bgol>Ggol && Bgol>Rgol)
			cout << "blue" << endl;
		else if(Ggol>Bgol && Ggol>Rgol)
			cout << "green" << endl;
		else if(Rgol>Bgol && Rgol>Ggol)
			cout << "red" << endl;
	}
}


/*
1		2
B G && B R
R B && R G
G R && G B
*/
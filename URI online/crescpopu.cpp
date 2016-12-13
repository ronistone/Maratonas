#include <iostream>

using namespace std;

int main(){
	int i,pa,pb,anos,n,dif,cresa,cresb,j;
	float ga,gb;

	cin >> n;

	for(i=0;i<n;i++){
		cin >> pa >> pb >> ga >> gb;
		j=1;
		for(;;j++){
			pa =pa + (pa*((ga/100)));
			pb =pb + (pb*((gb/100)));
			if(pa>pb || j==101)
				break;
		}
		if(j>100)
			cout << "Mais de 1 seculo." << endl;
		else
			cout << j << " anos." << endl;
	}
return 0;
}
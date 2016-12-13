#include <iostream>
#include <string.h>

using namespace std;

int main(){
	int n,i,tam,j,led;
	char num[100000];

	cin >> n;

	for(i=0;i<n;i++){
		cin >> num;
		led = 0;
		tam = strlen(num);
		for(j=0;j<tam;j++){
			if(num[j]=='1')
				led +=2;
			else if(num[j]=='7')
				led +=3;
			else if(num[j]=='4')
				led +=4;
			else if(num[j]=='2' || num[j]=='3' || num[j]=='5')
				led +=5;
			else if(num[j]=='6' || num[j]=='9' || num[j]=='0')
				led +=6;
			else if(num[j]=='8')
				led +=7;
		}
		cout << led << " leds" << endl;

	}


return 0;
}
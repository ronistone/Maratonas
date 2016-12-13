#include <bits/stdc++.h>
using namespace std;

void conv(char* buffer){
	int i,x = strlen(buffer)-1;
	long long int final=0;
	for(i=0;i<strlen(buffer);i++,x--){
		if(buffer[i]=='A' || buffer[i]=='a'){
			final += 10*pow(16,x);
		}
		else if(buffer[i]=='B' || buffer[i]=='b'){
			final += 11*pow(16,x);
		}
		else if(buffer[i]=='C' || buffer[i]=='c'){
			final += 12*pow(16,x);
		}
		else if(buffer[i]=='D' || buffer[i]=='d'){
			final += 13*pow(16,x);
		}
		else if(buffer[i]=='E' || buffer[i]=='e'){
			final += 14*pow(16,x);
		}
		else if(buffer[i]=='F' || buffer[i]=='f'){
			final += 15*pow(16,x);
		}
		else{
			final += (buffer[i]-48)*pow(16,x);
		}
	}
	if(final<0)
		final*=-1;
	cout << final << endl;
}

main(){

	int i,num,x;
	char n[50],aux[50];
	cin >> n;
	while(true){

		if(strlen(n)==2){	
			int a = atoi(n);
			if(a<0){	
			break;
			}
		}
		if(n[0]=='0' && n[1]=='x'){
			for(i=2,x = 0;i<strlen(n)+1;i++,x++)
				aux[x] = n[i];
			//num = atoi(aux);
			//itoa()
			conv(aux);
			//sprintf(n,"%d",num);
			//cout << aux << endl;
		}
		else{	
			num = atoi(n);
			cout << "0x";
			printf("%X\n", num);
		}
		cin >> n;
	}

}
 
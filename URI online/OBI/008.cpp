#include <iostream>
#include <string.h>
#include <math.h>
#include <sstream>
#include <cstdlib>

using namespace std;

void str_reverse(char* str)
{
  char caracter;
  int a, b;

  for(a = 0, b = strlen(str) - 1;  a < b;  ++a, b--)
  {
    caracter = str[a];
    str[a] = str[b];
    str[b] = caracter;
  }
}

int main(){
	int n,resultado[20];
	unsigned long long v,v1,i,ve,cont=0;
	cin >> n;
	v = pow(1,n);
	v1 = v*10;
	for(i=v;i<v1;i++){
		stringstream ss;
		ss << i;
		ss >> resultado; // or s = ss.str();
		str_reverse(resultado);
		ve = atoll(resultado);
		if(i < ve)
			cont++;
	}

	cout << cont << endl;
return 0;
}
#include <iostream>
#include <cstdio>

using namespace std;

int main(){
	float idade,soma=0,i;

	for(i=0;;i++){
		cin >> idade;
		if(idade<0)
			break;
		else
			soma+=idade;
	}
	soma /= i;
	printf("%.2f\n", soma);
return 0;
}
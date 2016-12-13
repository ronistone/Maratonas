#include <bits/stdc++.h>

using namespace std;

long long int sum(int n,long long int num){
	int aux,soma=0,i;
	for(i=0;i<n;i++){
		soma += num%10;
		num /=10;
	}
	return soma;
}

main(){
	long long int num,soma;
	int n;
	
	while(cin >> n >> num){
		soma = sum(n,num);
		cout << soma << " ";
		if(soma%3==0)
			cout << "sim" << endl;
		else
			cout << "nao" << endl;
	}


}
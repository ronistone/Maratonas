#include <bits/stdc++.h>

using namespace std;

int resposta[40][2];
int rep;
int fibo(int num){
	if(num<=rep)
		return 0;
	else{
		fibo(num-1);
		fibo(num-2);
		resposta[num][0] = resposta[num-1][0] + resposta[num-2][0];
		resposta[num][1] = resposta[num-1][1] + resposta[num-2][1] + 2;
		rep++;
	}

}

main(){
	int n, num,i;
	resposta[0][0] = 0;
	resposta[0][1] = 0;
	resposta[1][0] = 1;
	resposta[1][1] = 0;
	rep = 1;
	cin >> n;
	for(i=0;i<n;i++){
		cin >> num;
		fibo(num);
		cout << "fib(" << num << ") = " << resposta[num][1] << " calls = " << resposta[num][0] << endl;
	}
}
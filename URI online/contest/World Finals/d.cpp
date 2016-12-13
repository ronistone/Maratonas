#include <bits/stdc++.h>
using namespace std;

std::vector<string> v;


string fibo(int n){
	string a = "", b = "";
	if(v.size()>=n)
		return v[n];
	else if(n == 0){
		return v[0]; 
	}
	else if(n == 1){
		return v[1];
	}
	else{
		if(v.size()<n-2){	
			if(v.size()<n-1){	
				a += fibo(n-1);
				v.push_back(a);
			}
			b += fibo(n-2);
			v.push_back(b);
			a += b;
		}
		else{
			a+=v[n-1];
			a+=v[n-2];
		}
		return a;
	}
}


main(){
	int n,count;
	string padrao;
	v.push_back("0");
	v.push_back("1");
	while(cin >> n){
		cin >> padrao;
		count = 0;
		string a = fibo(n);
		cout << a << endl;
		int rear = a.find(padrao);
		while(rear!=string::npos){
			count++;
			a.erase(0,rear+padrao.size());
			rear = a.find(padrao);
		}
		cout << count << endl;
	}
}
#include <bits/stdc++.h>
using namespace std;


int ans;
string e;
int A[30];

int sum(char a){
	if(a=='X' or a=='/')
		return 10;
	else
		return a - '0';
}

int sum(char a,int p){
	if(a=='X')
		return 10;
	else if(a=='/'){
		return 10-(e[p-1] -'0');
	}
	else
		return a - '0';
}

void spare(int p){
	if(p+1 < e.size()){
		ans += sum(e[p+1],p+1);
	}
}
void strike(int p){
	spare(p);
	if(p+2 < e.size()){
		ans += sum(e[p+2],p+2);
	}
}


main(){
	
	stringstream ss;
	string z;
	ans = 0;
	getline(cin,e);
	
	ss << e;
	string a;
	for(int i=0;i<e.size();i++){
		A[i] = 0;
		if(e[i]!=' ')
			a+= e[i];
	}
	for(int i=0;i<10;i++)
		ss >> z;
		
	e = a;
	int i=e.size()-1;
	if(z.size()==3)
		i-=3;
	for(;i>=0;i--){
		
		if(e[i]==' ') continue;
		
		else if(e[i]=='/'){
			 spare(i);
			 ans+=10;
			 i--;
		}
		else if(e[i]=='X'){
			strike(i);
			ans += 10;
		}
		else{
			ans += sum(e[i],i);
		}
		
	}
	i = e.size();
	if(z.size()==3 and z[0]=='X'){
		ans +=10;
		if(z[1] =='x'){
			ans += 10+sum(z[2]);
		}else{
			ans += sum(z[1])+ (z[2]=='/'?10-sum(z[1]):sum(z[2]));
		}
	}else if(z.size()==3){
		ans += 10 + sum(z[2]);
	}
	
	cout << ans << endl;

}

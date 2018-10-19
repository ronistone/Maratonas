#include<bits/stdc++.h>
using namespace std;

string str;


bool dp(int ini, int fim, int tam){
	if(fim < ini) return true;
	
	if(fim-ini+1 == tam) return true;
	
	string sa="", sb="";
	
	for(int i=0; i < tam; i++)
		sa.push_back(str[ini+i]);
	
	for(int i=tam; i>0; i--)
		sb.push_back(str[fim-i+1]);
		
	if(sa!=sb) return false;
	if(sa==sb) return dp(ini+tam, fim-tam, tam);
} 


int main(){
	
	cin >> str;
	
	int S = str.size();
	
	for(int i=1; i <=S; i++){
		
		if(S%i==0){
			if(dp(0, S-1, i)){
				cout << S/i << endl;
				return 0;
			}
		}
		
	}
	
}

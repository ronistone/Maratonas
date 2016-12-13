#include <bits/stdc++.h>

using namespace std;

bool verifica(int i,int j){return i<j;}

int binary(vector<int> v,int q){
	int first,meio,last,i=0;
	first = 0;
	last = v.size();

	while(first<=last){
		meio = (first+last)/2;
		if(v[meio]==q){
			while(v[meio-i]==q)
				i++;
			return meio-i+2;
		}	
		if(v[meio]<q) first = meio+1;
		else last = meio-1;
	}
	return -1;

}

main(){

	int n ,q,i;

	cin >> n >> q;
	int count = 0;
	while(n!=0 && q!=0){
		count++;
		cout << "CASE# " << count << ":" << endl;
		std::vector<int> v;
		int b,aux;
		for(i=0;i<n;i++){
			cin >> aux;
			v.push_back(aux);
		}
		sort(v.begin(),v.end(),verifica);
		for(i=0;i<q;i++){
			cin >> b;
			int achou = binary(v,b);
			if(achou!=-1){
				cout << b << " found at " << achou << endl;
			}
			else
				cout << b << " not found" << endl;
		}


		v.clear();
		cin >> n >> q;
	}

	int v[n];
}

/*
CASE# 1:
5 found at 4
CASE# 2:
2 not found
3 found at 3
*/


/*1
2 -->first -->meio
3 -->meio 
5*/
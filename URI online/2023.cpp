/*#include <bits/stdc++.h>
using namespace std;

main(){
	vector<string> v,a;
	string entrada;
	int i,count=0;

	while(getline(cin,entrada)){
		a.push_back(entrada);
		for(i=0;i<entrada.size();i++){
			if(entrada[i]>='a' and entrada[i]<='z')
				entrada[i]-= 'a'-'A';
		}
		entrada.insert(entrada.end(),count+48);
		v.push_back(entrada);
		count++;
	}
	sort(v.begin(),v.end());
	string aux = v.back();
	int fim = aux.size();
	cout << "saida: "<< a[(int)(aux[fim-1]) - 48] << endl;
}*/

#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

typedef struct p {
	string name;
	string modi;
}p;

p names[1001];

bool cmp(p s1, p s2) {
	string a = s1.modi;
	string b = s2.modi;
	int i = 0;

	while (a[i] == b[i])
		i++;
	if (a[i] < b[i]) return true;
	else return false;
}

int main(int argc, char const *argv[]) {
	int z = 0;
	string name;

	int i = 0;
	while (getline(cin, name)) {
		names[i].name = name;
		transform(name.begin(), name.end(), name.begin(), ::tolower);
		names[i].modi = name;
		i++;
	}

	sort(names, names + i, cmp);

	cout << names[i - 1].name << endl;
	return 0;
}
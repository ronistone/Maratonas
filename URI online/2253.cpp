#include <bits/stdc++.h>
using namespace std;

main(){
	string e;
	int i,j,k;
	bool falha;
	while(getline(cin,e)){
		falha = false;
		if(e.size()<6 or e.size()>32){
			falha = true;
		}
		bool  mini=false, mai=false,num=false;
		for(i=0;i<e.size();i++){
			if((e[i]<'a' or e[i]>'z') and
			 (e[i]<'A' or e[i]>'Z') and
			 (e[i]<'0' or e[i]>'9')){
				falha = true;
				break;
			}
			if(e[i]>='a' and e[i]<='z')
				mini = true;
			if(e[i]>='A' and e[i]<='Z')
				mai = true;
			if(e[i]>='0' and e[i]<='9')
				num = true;
		}

		if(falha)
			cout << "Senha invalida." << endl;
		else if(mai and mini and num)
			cout << "Senha valida." << endl;
		else
			cout << "Senha invalida." << endl;
	}

}

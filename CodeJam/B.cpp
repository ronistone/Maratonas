#include <bits/stdc++.h>
using namespace std;

main(){
	string in;
	int n;
	
	cin >> n;
	cin.ignore();
	for(int k=0;k<n;k++){
		cin >> in;
		cin.ignore();
		int i=0;
		while(i < in.size() - 1)
		{
			if(in[i] > in[i+1])
			{
				in[i]--;
				for (int j = i+1; j < in.size(); j++)
				{
					in[j] = '9';
				}
				i = 0;
			}else i++;
		}
		i=0;
		while(i<in.size()){
			if(in[i]=='0')
				i++;
			else
				break;
		}
		in = string(in.begin()+i,in.end());
		cout << "Case #" << k+1 << ": " << in << endl;
	}
	
}
/*#include <bits/stdc++.h>
using namespace std;

main(){
	string in;
	int n,i;
	
	cin >> n;
	cin.ignore();
	for(int k=0;k<n;k++){
		cin >> in;
		cin.ignore();
		bool quebrou = false;
		for(int l=0;l<in.size();l++){
			for(i=0;i<in.size()-1;i++){
				if(in[i] > in[i+1]){
					in[i]--;
					for(int j=i+1;j<in.size();j++)
						in[j] = '9';
					//cout << in << endl;
				}
			}
		}
		i=0;
		while(i<in.size()){
			if(in[i]=='0')
				i++;
			else
				break;
		}
		in = string(in.begin()+i,in.end());
		cout << "Case #" << k+1 << ": " << in << endl;
	}
	
}*/

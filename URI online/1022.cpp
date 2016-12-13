#include <bits/stdc++.h>
using namespace std;

template<class T> T gcd (T x, T y){
	return (y != 0 ? gcd<T> (y,x%y) : x);
}

template<class T> T lcm(T x,T y){
	return (x/gcd<T> (x,y) * y);
}

main(){
	int n,i;

	cin >> n;
	int n1,d1,n2,d2,nf,df;
	char c1,c2,c3;
	for(i=0;i<n;i++){
		int j;
		cin >> n1 >> c1 >> d1 >> c2 >> n2 >> c3 >> d2;
		if(c2=='+'){	
			nf = (n1*d2 + n2*d1);
			df = (d1*d2);
			cout << nf << "/" << df << " = ";
			//df = lcm(d1,d2);
			//nf = ((df/d1)*n1) + ((df/d2)*n2);
			if(nf<df){j = nf;}
			else{j = df;}
			if(j>0){
				while(j>0){
					if(nf%j==0 && df%j==0){
						cout << nf/j << "/" << df/j << endl;
						break;
					}
					j--;
				}
			}
			else{
				while(j<0){
					if(nf%j==0 && df%j==0){
						cout << nf/j << "/" << df/j << endl;
						break;
					}
					j++;
				}
			}

		}
		else if(c2=='-'){
			nf = (n1*d2 - n2*d1);
			df = (d1*d2);
			cout << nf << "/" << df << " = ";
			//df = lcm(d1,d2);
			//nf = ((df/d1)*n1) - ((df/d2)*n2);
			if(nf<df){j = nf;}
			else{j = df;}
			if(j>0){
				while(j>0){
					if(nf%j==0 && df%j==0){
						if(df/j<0){
							df*=-1;
							nf*=-1;
						}
						cout << nf/j << "/" << df/j << endl;
						break;
					}
					j--;
				}
			}
			else{
				while(j<0){
					if(nf%j==0 && df%j==0){
						if(df/j<0){
							df*=-1;
							nf*=-1;
						}
						cout << nf/j << "/" << df/j << endl;
						break;
					}
					j++;
				}
			}
		}
		else if(c2=='*'){
			nf = (n1*n2);
			df = (d1*d2);
			cout << nf << "/" << df << " = ";
			if(nf<df){j = nf;}
			else{j = df;}
			while(j>0){
				if(nf%j==0 && df%j==0){
					if(df/j<0){
							df*=-1;
							nf*=-1;
						}
					cout << nf/j << "/" << df/j << endl;
					break;
				}
				j--;
			}

		}
		else if(c2=='/'){
			 nf = (n1*d2);
			 df = (n2*d1);
			 cout << nf << "/" << df << " = ";
			if(nf<df){j = nf;}
			else{j = df;}
			while(j>0){
				if(nf%j==0 && df%j==0){
					if(df/j<0){
							df*=-1;
							nf*=-1;
						}
					cout << nf/j << "/" << df/j << endl;
					break;
				}
				j--;
			}
		}

	}
}
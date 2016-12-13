#include <iostream>

using namespace std;

int f(int n, int k){
    if(n==1) return 1;
    return (((f(n-1, k) + k-1)%n)+1);   
}

int main(){
    unsigned int n,k,i,ns;
    cin >> ns;
    for(i=0;i<ns;i++){
    	cin >> n >> k;
    	cout << "Case " << i+1 <<": " << f(n, k) << endl;
    }
 return 0;
}
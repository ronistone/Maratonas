#include <bits/stdc++.h>
using namespace std;

#define mp make_pair
#define pb push_back
#define F first
#define S second

typedef long long int ll;
typedef pair<ll,ll> ii;
typedef vector<ii> vii;
typedef vector<vii> vvii;
typedef vector<ll> vi;


main(){
	
	int n,k,mid,left,right,res1=0,res2=0;
	int A[105],sum,mod;
	cin >> n >> k;
	
	for(int i=0;i<k;i++){
		cin >> A[i];
	}
	sort(A,A+k);
	mid = n*4;
	left = right = n*2;
	bool ac = true;
	for(int i=k-1;i>=0;i--){
		if(mid > 0 and A[i] > 0){
			if(A[i] < mid){
				if(A[i]==1){
					mid -= 4;
					right+=2;
					A[i] = 0;
				}
				else if(A[i]==2){
					mid -= 4;
					res1++;
					A[i] = 0;
				}
				else{
					mid -= A[i]+(A[i]%4);//(A[i]%4!=0 ? (4*((A[i]/4)+1)):A[i]);
					A[i] = 0;
				}
			}
			else{
				A[i] -= mid;
				mid = 0;
			}
			//sort(A,A+k);
		}
		if(left >0 and A[i] > 0){
			if(A[i] < left){
				left -= A[i]+(A[i]%2);//(A[i]%2!=0? (2*((A[i]/2)+1)):A[i]);
				A[i] = 0;
			}
			else{
				A[i] -= left;
				left = 0;
			}
			//sort(A,A+k);
		}
		if(right > 0 and A[i] > 0){
			if(A[i] < right){
				right -= A[i]+(A[i]%2);//(A[i]%2!=0? (2*((A[i]/2)+1)):A[i]);
				A[i] = 0;
			}
			else{
				A[i] -= right;
				right = 0;
			}
			//sort(A,A+k);
		}
		if(A[i] <= res1){
			res1 -= A[i];
			A[i] = 0;
		}
		if(A[i]>0){
			ac = false;
			break;
		}
	}
	
	/*sum = 8*n;
	for(int i=k-1;i>=0;i--){
		sum -= A[i];
		mod = sum%n;
		if(mod>=0 and mod<=1){
			sum -= 1 - mod;
		}
		else if(mod>=2 and mod<=5){
			sum -= 5 - mod;
		}
		else if(mod>=6 and mod<=7){
			sum -= 7 - mod;
		}
	}
	/*int ini = 0,fim = k-1;
	for(int i=0;i<n;i++){
		if(A[ini] >=2){
			A[ini]-=2;
			sum -= 2;
		}
		if(A[fim] >= 4)
			
	}
	*/
	if(!ac)
		cout << "NO" << endl;
	else
		cout << "YES" << endl;
}

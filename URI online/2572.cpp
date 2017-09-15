#include <bits/stdc++.h>
using namespace std;

#define MAX 200100
#define S second
#define F first
#define pb push_back
#define mp make_pair

typedef long long int ll;
typedef vector<int> vi;
int A[MAX];
vi st[MAX << 2];
int k;
vi merge(vi a,vi b){
	/*vi temp(a);
	temp.insert(temp.end(),b.begin(),b.end());
	sort(temp.rbegin(),temp.rend());
	vi ans(temp.begin(),temp.begin()+min(k,temp.size())), e;
	if(k and temp.size())
		return ans;
	else
		return e;*/
	vi ans;
	int i=0,j=0;
	while(ans.size()<k and (i<a.size() or j<b.size())){
		if(i<a.size() and j<b.size()){
			if(a[i]>b[j]){
				ans.push_back(a[i]);
				i++;	
			}
			else{
				ans.push_back(b[j]);
				j++;
			}
		}
		else if(i<a.size()){
			ans.push_back(a[i]);
			i++;
		}
		else if(j<b.size()){
			ans.push_back(b[j]);
			j++;
		}
	}
	return ans;
}

void build(int P, int L,int R){
	
	if(L==R){
		if(k){
			st[P].pb(A[L]);
		}
	}
	else{
		int nxt = P << 1;
		int mid = (L+R) >> 1;
		build(nxt,L,mid);
		build(nxt+1,mid+1,R);
		st[P] = merge(st[nxt],st[nxt+1]);
	}
}
vi query(int P, int L, int R, int i, int j){
	
	vi a;
	// no overlap
	if(i>R or j<L) return a;
	
	//total overlap
	if(i<=L and j>=R) return st[P];
	
	int nxt = P << 1;
	int mid = (L+R) >> 1;
	vi q1 = query(nxt,L,mid,i,j);
	vi q2 = query(nxt+1,mid+1,R,i,j);
	if(!q1.size()) return q2;
	if(!q2.size()) return q1;
	vi ans = merge(q1,q2);
	return ans;
}


main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n,q,from,to,i,j;
	vi temp;
	ll ans;
	cin >> n >> k >> q;
	
	for(i=1;i<=n;i++)
		cin >> A[i];
	
	build(1,1,n);
	
	for(i=0;i<q;i++){
		cin >> from >> to;
		temp = query(1,1,n,from,to);
		if(!temp.size() or temp[0]==0)
			ans = 0;
		else{
			ans = 1;
			for(j=0;j<temp.size();j++){
				ans *= temp[j];
				ans = ans%(1000000007);
			}
		}
		cout << ans << endl;
	}

}

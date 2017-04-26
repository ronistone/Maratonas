#include <bits/stdc++.h>
using namespace std;
#define INF 10101010
int A[105][105], P[105][105], dp[105][105];
char e[105][105];
int n,m,q;
inline void scanint(int *x)
{
	register char c = getchar_unlocked();
	*x = 0;
	for(; (c<48)||(c>57);c = getchar_unlocked());
	for(; (c>47)&&(c<58);c = getchar_unlocked())
		*x = (int)((((*x)<<1) + ((*x)<<3)) + c - 48);
}
inline void printint(int n)
{
	if(n == 0)
	{
		putchar_unlocked('0');
		putchar_unlocked('\n');
	}
	else if(n == -1)
	{
		putchar_unlocked('-');
		putchar_unlocked('1');
		putchar_unlocked('\n');
	}
	else
	{
		char buf[11];
		buf[10] = '\n';
		int i = 9;
		while(n)
		{
			buf[i--] = n % 10 + '0';
			n /= 10;
		}
		while(buf[i] != '\n')
			putchar_unlocked(buf[++i]);
	}
}

int solve(int LC,int IC){
	if(LC == n) return 0;
	if(dp[LC][IC]!=-INF) return dp[LC][IC];
	int ans = -INF;
	bool falha;	
	for(int i=1;i<=q;i++){
			falha = false;
			for(int j=0;j<m;j++){
				if(((e[i][j]!='.') and (e[IC][j]!='.') and (e[IC][j]==e[i][j]))){
					falha = true;
					break;
				}
			}
			if(falha)
				continue;
			else{
				ans = max(solve(LC+1,i)+P[LC][i],ans);
			}
	}
	return dp[LC][IC] = ans;
}

main(){
	strcpy(e[0],"......................................................................................................");
	while(true){
		scanint(&n);scanint(&m);
		if(!m or !n)
			break;
		for(int i=0;i<n;i++){
			for(int j=0;j<m;j++){
				scanint(&A[i][j]);
			}
		}
		scanint(&q);
		memset(P,0,sizeof P);
		for(int l=1;l<=q;l++){
			scanf("%s",e[l]);
			for(int i=0;i<n;i++){
				for(int j=0;j<m;j++){
					if(e[l][j]=='+')
						P[i][l] += A[i][j];
					else if(e[l][j]=='-')
						P[i][l] -= A[i][j];
				}
			}
		}
		for(int i=0;i<=n;i++)
			for(int j=0;j<=q;j++)
				dp[i][j] = -INF;
		//memset(dp,-1,sizeof dp);
		printf("%d\n",solve(0,0));
	}
}









/*






#include <bits/stdc++.h>
using namespace std;
const int N = 1e2 + 10;
const int INF = 1e9 + 10;

int n, m, k;
char v[N][N];
vector<int> g[N];
int dp[N][N], value[N][N];

bool valid (const int &a, const int &b) {
	for (int i = 0; i < m; ++i)
		if (v[a][i] != '.' and v[a][i] == v[b][i])
			return false;
	return true;
}

void build () {
	for (int i = 0; i <= k; ++i)
		g[i].clear();
	for (int i = 0; i < k; ++i) {
		for (int j = i; j < k; ++j) {
			if (valid(i, j)) {
				g[i].push_back(j);
				if (i != j)
					g[j].push_back(i);
			}
		}
	}
	for (int i = 0; i < k; ++i)
		g[k].push_back(i);
}

int get_sum (const int &line, const int ¤t) {
	int ans = 0;
	for (int i = 0; i < m; ++i) {
		if (v[current][i] == '+')
			ans += value[line][i];
		else if (v[current][i] == '-')
			ans -= value[line][i];
	}
	return ans;
}

int solve (const int &line, const int &before) {
	if (line == n)
		return 0;
	if (dp[line][before] != -INF)
		return dp[line][before];
	int ans = -INF + 10;
	for (auto i : g[before])
		ans = max(ans, get_sum(line, i) + solve(line + 1, i));
	return dp[line][before] = ans;
}

int main () {
	while (scanf("%d %d", &n, &m) != EOF) {
		if (!n and !m)
			break;
		for (int i = 0; i < n; ++i)
			for (int j = 0; j < m; ++j)
				scanf("%d", &value[i][j]);
		scanf("%d", &k);
		for (int i = 0; i < k; ++i) {
			while (getchar() != '\n');
			for (int j = 0; j < m; ++j)
				scanf("%c", &v[i][j]);
		}
		build();
		for (int i = 0; i <= n; ++i)
			for (int j = 0; j <= k; ++j)
				dp[i][j] = -INF;
		printf("%d\n", solve(0, k));
	}
	return 0;
}*
*/

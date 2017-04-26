#include <bits/stdc++.h>

#ifndef LOCAL
#define cerr dolor_sit_amet
#endif

#define mp make_pair
#define sz(x) ((int)((x).size()))
#define X first
#define Y second

using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef pair < int , int > ipair;
typedef pair < ll , ll > lpair;
const int IINF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;
const double DINF = numeric_limits<double>::infinity();
const ll MOD = 1000000007;
const double EPS = 1e-9;
const int DX[] = { 1,  0, -1,  0,  1, -1,  1, -1};
const int DY[] = { 0,  1,  0, -1,  1, -1, -1,  1};
ll gcd(ll a, ll b) { return b ? gcd(b, a % b) : a; }
ll sqr(ll x) { return x*x; } ll sqr(int x) { return (ll)x*x; }
double sqr(double x) { return x*x; } ld sqr(ld x) { return x*x; }

// ========================================================================= //

const int N = 500179;
const int D = 41;

int n;
int vvl[N];
int vvr[N];
int db[N][D], dr[N][D];

int main()
{
    ios::sync_with_stdio(false);
	scanf("%d", &n);
	for (int i = 0; i < n; ++i)
	{
		scanf("%d%d", vvl + i, vvr + i);
		--vvl[i];
		--vvr[i];
	}

	for (int v = n - 1; v >= 0; --v)
	{
		int vl = vvl[v];
		int vr = vvr[v];
		if (vl == -1)
			swap(vl, vr);
		if (vl == -1 && vr == -1)
			db[v][1] = dr[v][0] = 1;
		else if (vr == -1)
			db[v][1] = dr[vl][0];
		else
		{
			for (int i = 0; i < D; ++i)
				dr[v][i] = (1LL * db[vl][i] * db[vr][i]) % MOD;
			for (int i = 1; i < D; ++i)
				db[v][i] = (1LL * (db[vl][i-1] + dr[vl][i-1]) * (db[vr][i-1] + dr[vr][i-1])) % MOD;
		}
	}

	int ans = 0;
	for (int i = 0; i < D; ++i)
		ans = (ans + db[0][i]) % MOD;
	cout << ans << "\n";

    return 0;
}

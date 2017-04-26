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

const int N = 1000179;

void solve()
{
	int n;
	static int a[N], a1[N];
	scanf("%d", &n);
	memset(a1, -1, sizeof(int)*n);
	for (int i = 0; i < n; ++i)
	{
		scanf("%d", &a[i]);
		--a[i];
		if (a[i] != -1)
			a1[a[i]] = i;
	}

	vector < ipair > w;
	for (int i = 0; i < n; ++i)
		if (a[i] == -1)
		{
			int j = i;
			while (a1[j] != -1)
				j = a1[j];
			w.emplace_back(i, j);
		}
	if (!w.empty())
	{
		for (int i = 0; i < sz(w) - 1; ++i)
		{
			a[w[i].X] = w[i+1].Y;
			a1[a[w[i].X]] = w[i].X;
		}
		a[w.back().X] = w[0].Y;
		a1[a[w.back().X]] = w.back().X;
	}

	static int b[N];
	memcpy(b, a, sizeof(int) * n);
	int ans = 0;
	for (int i = 0; i < n; ++i)
		if (a1[i] != i)
		{
			++ans;
			swap(a1[i], a1[a[i]]);
			swap(a[a1[i]], a[a1[a[i]]]);
		}
	cout << ans << "\n";
	for (int i = 0; i < n; ++i)
		cout << b[i] + 1 << " ";
	cout << "\n";
}

int main()
{
    ios::sync_with_stdio(false);
	int t;
	scanf("%d", &t);
	while (t--)
		solve();

    return 0;
}

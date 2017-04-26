#include "bits/stdc++.h"
#define puba push_back
#define ff first
#define ss second
#define bend(_x) begin(_x), end(_x)
#define szof(_x) ((int) (_x).size())
#define cmpby(_x) [](const auto& a, const auto& b) {return (a _x) < (b _x);}
#define TASK_NAME ""

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
const int INF = 1e9 + 7;
const double PI = atan2(0, -1);
const int MAXN = 5e5 + 5, SZ = 20;
const ll MOD = 1e9 + 7;

ll d[2][SZ][MAXN];
vector<int> graph[MAXN];

int dfs(int v) {
    if (v == 0) {
        return 0;
    }
    for (int to : graph[v]) {
        dfs(to);
    }
    for (int i = 0; i < SZ; ++i) {
        if (i) {
            d[0][i][v] = (d[0][i - 1][graph[v][0]] + d[1][i - 1][graph[v][0]]) * (d[0][i - 1][graph[v][1]] + d[1][i - 1][graph[v][1]]) % MOD;
        }
        d[1][i][v] = d[0][i][graph[v][0]] * d[0][i][graph[v][1]] % MOD;
    }
    return 0;
}

int main() {
    //freopen(TASK_NAME ".in", "r", stdin);
    //freopen(TASK_NAME ".out", "w", stdout);

    int n;
    scanf("%d", &n);

    for (int i = 0; i < n; ++i) {
        int l, r;
        scanf("%d%d", &l, &r);
        graph[i + 1].puba(l);
        graph[i + 1].puba(r);
    }

    d[0][1][0] = 1;

    dfs(1);

    ll ans = 0;
    for (int i = 0; i < SZ; ++i) {
        ans = (ans + d[0][i][1]) % MOD;
    }

    cout << ans << "\n";

    #ifdef LOCAL
        cerr << "time: " << clock() << endl;
    #endif
    return 0;
}
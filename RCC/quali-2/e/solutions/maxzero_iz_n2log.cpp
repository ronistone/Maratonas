#include <bits/stdc++.h>
using namespace std;
typedef long long ll;



int main() {
#ifdef _MSC_VER
	freopen("input.txt", "r", stdin);
#endif
	
	int T;
	scanf("%d", &T);
	while (T--) {
		int n;
		scanf("%d", &n);
		vector<int> a(n);
		for (int i = 0; i < n; i++) scanf("%d", &a[i]);
		int q;
		scanf("%d", &q);
		vector<int> l(q), r(q);
		for (int i = 0; i < q; i++) scanf("%d%d", &l[i], &r[i]), l[i]--;

		vector<ll> s(n + 1);
		for (int i = 0; i < n; i++) s[i + 1] = s[i] + a[i];
		vector<ll> vct;
		for (int i = 0; i <= n; i++) vct.push_back(s[i]);
		sort(vct.begin(), vct.end());
		vct.resize(unique(vct.begin(), vct.end()) - vct.begin());
		int k = vct.size();
		for (int i = 0; i <= n; i++) s[i] = lower_bound(vct.begin(), vct.end(), s[i]) - vct.begin();

		vector<vector<int> > pos(k);
		for (int i = 0; i <= n; i++) pos[s[i]].push_back(i);
		auto combine = [&](pair<int, int> a, pair<int, int> b) {
			return make_pair(min(a.first, b.first), max(a.second, b.second));
		};
		int N = 1;
		while (N <= n + 1) N <<= 1;
		vector<pair<int, int>> t(N * 2);
		for (int i = 0; i <= n; i++) t[N + i] = pos[s[i]].size() > 1 ? make_pair((int)s[i], (int)s[i]) : make_pair(n + 1, -1);
		for (int i = N - 1; i >= 1; i--) t[i] = combine(t[i * 2], t[i * 2 + 1]);
		auto get = [&](int l, int r) {
			l += N;
			r += N;
			pair<int, int> res = make_pair(n + 1, -1);
			while (l <= r) {
				if ((l & 1) == 1) {
					res = combine(res, t[l]);
				}
				if ((r & 1) == 0) {
					res = combine(res, t[r]);
				}
				l = (l + 1) >> 1;
				r = (r - 1) >> 1;
			}
			return res;
		};
		ll ans = 0;
		for (int i = 0; i < q; i++) {
			int cans = 0;
			auto o = get(l[i], r[i]);
			for (int j = o.first; j <= o.second; j++) {
				int id1 = lower_bound(pos[j].begin(), pos[j].end(), l[i]) - pos[j].begin();
				int id2 = lower_bound(pos[j].begin(), pos[j].end(), r[i] + 1) - pos[j].begin() - 1;
				if (id1 <= id2 && id1 < (int)pos[j].size()) cans = max(cans, pos[j][id2] - pos[j][id1]);
			}
			ans += cans;
		}
		cout << ans << endl;
	}

	return 0;
}
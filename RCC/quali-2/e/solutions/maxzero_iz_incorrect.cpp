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
		ll ans = 0;
		for (int i = 0; i < q; i++) {
			int cans = 0;
			const int T = 100;
			if (k > 400) {
				for (int j = l[i]; j <= r[i] && j - l[i] <= T; j++) {
					cans = max(cans, pos[s[j]][lower_bound(pos[s[j]].begin(), pos[s[j]].end(), r[i] + 1) - pos[s[j]].begin() - 1] - j);
				}
				for (int j = max(l[i] + T + 1, r[i] - T); j <= r[i]; j++) {
					cans = max(cans, pos[s[j]][lower_bound(pos[s[j]].begin(), pos[s[j]].end(), r[i] + 1) - pos[s[j]].begin() - 1] - j);
				}
				for (int j = 0; j < k && j <= T; j++) {
					int id1 = lower_bound(pos[j].begin(), pos[j].end(), l[i]) - pos[j].begin();
					int id2 = lower_bound(pos[j].begin(), pos[j].end(), r[i] + 1) - pos[j].begin() - 1;
					if (id1 <= id2 && id1 < (int)pos[j].size()) cans = max(cans, pos[j][id2] - pos[j][id1]);
				}
				for (int j = k - 1; j >= k - T && j > T; j--) {
					int id1 = lower_bound(pos[j].begin(), pos[j].end(), l[i]) - pos[j].begin();
					int id2 = lower_bound(pos[j].begin(), pos[j].end(), r[i] + 1) - pos[j].begin() - 1;
					if (id1 <= id2 && id1 < (int)pos[j].size()) cans = max(cans, pos[j][id2] - pos[j][id1]);
				}
			}
			else {
				for (int j = 0; j < k; j++) {
					int id1 = lower_bound(pos[j].begin(), pos[j].end(), l[i]) - pos[j].begin();
					int id2 = lower_bound(pos[j].begin(), pos[j].end(), r[i] + 1) - pos[j].begin() - 1;
					if (id1 <= id2 && id1 < (int)pos[j].size()) cans = max(cans, pos[j][id2] - pos[j][id1]);
				}
			}
			ans += cans;
		}
		cout << ans << endl;
	}

	return 0;
}
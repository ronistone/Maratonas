#include <bits/stdc++.h>

int main() {
  int tests;
  scanf("%d", &tests);
  while (tests--) {
    int n;
    scanf("%d", &n);
    std::vector<int> a(n);
    for (int i = 0; i < n; i++) {
      scanf("%d", &a[i]);
    }
    std::vector<int> pref(n + 1);
    std::vector<int> prefs_set;
    pref[0] = 0;
    prefs_set.push_back(n);
    for (int i = 0; i < n; i++) {
      pref[i + 1] = pref[i] + a[i];
      prefs_set.push_back(pref[i + 1] + n);
    }
    std::sort(prefs_set.begin(), prefs_set.end());
    prefs_set.erase(std::unique(prefs_set.begin(), prefs_set.end()), prefs_set.end());

    std::vector<std::vector<int>> prefs(2 * n + 1);
    for (int i = 0; i <= n; i++) {
      prefs[pref[i] + n].push_back(i);
    }
    
    std::vector<int> ps;
    for (int p : prefs_set) {
        if (prefs[p].size() > 1) {
            ps.push_back(p);
        }
    }

    auto solve = [&](int l, int r) {
      int ans = 0;
      for (int p : ps) {
        auto upper = std::upper_bound(prefs[p].begin(), prefs[p].end(), r) - prefs[p].begin();
        auto lower = std::lower_bound(prefs[p].begin(), prefs[p].end(), l - 1) - prefs[p].begin();
        int cnt = upper - lower;
        if (cnt >= 2) {
          ans = std::max(ans, prefs[p][upper - 1] - prefs[p][lower]);
        }
      }
      return ans;
    };

    int q;
    scanf("%d", &q);
    long long sum = 0;
    for (int i = 0; i < q; i++) {
      int l, r;
      scanf("%d%d", &l, &r);
      sum += solve(l, r);
    }
    printf("%lld\n", sum);
  }
}

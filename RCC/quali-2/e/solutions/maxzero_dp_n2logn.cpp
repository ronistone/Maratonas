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
    std::vector<int> pref(n);
    pref[0] = a[0];
    for (int i = 1; i < n; i++) {
      pref[i] = pref[i - 1] + a[i];
    }
    std::vector<std::vector<int>> prefs(2 * n + 1);
    prefs[n].push_back(-1);
    for (int i = 0; i < n; i++) {
      prefs[pref[i] + n].push_back(i);
    }
    
    auto solve = [&](int l, int r) {
      int ans = 0;
      for (int p = 0; p <= 2 * n; p++) {
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
      sum += solve(l - 1, r - 1);
    }
    printf("%lld\n", sum);
  }
}

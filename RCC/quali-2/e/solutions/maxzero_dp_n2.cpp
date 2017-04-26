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
    pref[0] = 0;
    for (int i = 0; i < n; i++) {
      pref[i + 1] = pref[i] + a[i];
    }
    std::vector<std::vector<int>> prefs(2 * n + 1);
    prefs.resize(2 * n + 1);
    for (int i = 0; i <= n; i++) {
      prefs[pref[i] + n].push_back(i);
    }
    std::vector<std::vector<int>> firstGE(2 * n + 1);
    for (int i = 0; i <= 2 * n; i++) {
      firstGE[i].resize(n + 2);
      int size = static_cast<int>(prefs[i].size());
      firstGE[i][n + 1] = size;
      int p = size - 1;
      for (int j = n; j >= 0; j--) {
        if (p >= 0 && prefs[i][p] == j) {
          firstGE[i][j] = p--;
        } else {
          firstGE[i][j] = firstGE[i][j + 1];
        }
      }
    }

    auto solve = [&](int l, int r) {
      int ans = 0;
      for (int p = 0; p <= 2 * n; p++) {
        int upper = firstGE[p][r + 1];
        int lower = firstGE[p][l - 1];
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

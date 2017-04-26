#include <bits/stdc++.h>

int solve(const std::vector<int> &pref, int l, int r) {
  for (int len = r - l + 1; len >= 1; len--) {
    for (int i = l; i <= r - len + 1; i++) {
      int j = i + len - 1;
      if (pref[j] - (i == 0 ? 0 : pref[i - 1]) == 0) {
        return len;
      }
    }
  }
  return 0;
}

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
    int q;
    scanf("%d", &q);
    long long sum = 0;
    for (int i = 0; i < q; i++) {
      int l, r;
      scanf("%d%d", &l, &r);
      sum += solve(pref, l - 1, r - 1);
    }
    printf("%lld\n", sum);
  }
}

#include <bits/stdc++.h>

const int K = 350;
const int maxn = (int)1e5 + 10;

int a[maxn];
int pref[maxn];
int mostRight[2 * maxn + 1];
int mostLeft[2 * maxn + 1];
int next[maxn];
int prev[maxn];
int answer;
int cnt;

bool is_less(const std::pair<int, int> &a, const std::pair<int, int> &b) {
  if (a.first / K != b.first / K) {
    return a.first < b.first;
  }
  return a.second < b.second;
}

void update(int x) {
  if (answer == x) {
    cnt++;
    return;
  }
  if (answer < x) {
    answer = x;
    cnt = 1;
  }
}

void recalc(int a, int b) {
  answer = 0;
  for (int i = b; i >= a; i--) {
    mostLeft[pref[i]] = i;
  }
  for (int i = a; i <= b; i++) {
    mostRight[pref[i]] = i;
    update(i - mostLeft[pref[i]]);
  }
}

void add(int x) {
  int p = pref[x];
  int &l = mostLeft[p];
  int &r = mostRight[p];
  if (r == -1) {
    r = x;
    return;
  }
  if (l == -1) {
    l = r;
  }
  l = std::min(l, x);
  r = std::max(r, x);
  update(r - l);
}

void delLeft(int a, int b) {
  int p = pref[a];
  int &l = mostLeft[p];
  int &r = mostRight[p];
  if (l == -1) {
    r = -1;
    return;
  }
  int old = r - l;
  l = next[a];
  if (answer == old) {
    if (--cnt == 0) {
      recalc(a + 1, b);
    }
  }
}

void delRight(int a, int b) {
  int p = pref[a];
  int &l = mostLeft[p];
  int &r = mostRight[p];
  if (l == -1) {
    r = -1;
    return;
  }
  int old = r - l;
  r = prev[a];
  if (answer == old) {
    if (--cnt == 0) {
      recalc(a, b - 1);
    }
  }
}

int main() {
  int tests;
  scanf("%d", &tests);
  while (tests--) {
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
      scanf("%d", &a[i]);
    }

    pref[0] = 0;
    for (int i = 0; i < n; i++) {
        pref[i + 1] = pref[i] + a[i];
    }
    std::vector<std::vector<int>> prefs(2 * n + 1);
    for (int i = 0; i <= n; i++) {
      pref[i] += n;
      prefs[pref[i]].push_back(i);
    }
    for (int i = 0; i <= 2 * n; i++) {
      int j;
      for (j = 0; j + 1 < (int)prefs[i].size(); j++) {
        next[prefs[i][j]] = prefs[i][j + 1];
      }
      if (prefs[i].size() > 0) {
        next[prefs[i][j]] = -1;
        prev[prefs[i][0]] = -1;
      }
      for (int j = 1; j < (int)prefs[i].size(); j++) {
        prev[prefs[i][j]] = prefs[i][j - 1];
      }
    }

    int q;
    scanf("%d", &q);
    std::vector<std::pair<int, int>> queries;
    answer = 0;
    cnt = 0;
    for (int i = 0; i < q; i++) {
      int l, r;
      scanf("%d%d", &l, &r);
      queries.emplace_back(l - 1, r);
    }
    long long sum = 0;
    std::sort(queries.begin(), queries.end(), is_less);
    memset(mostLeft, -1, sizeof(mostLeft));
    memset(mostRight, -1, sizeof(mostRight));
    int a = 0;
    int b = -1;
    for (int i = 0; i < q; i++) {
      while (a > queries[i].first) {
        add(--a);
      }
      while (b < queries[i].second) {
        add(++b);
      }
      while (a < queries[i].first) {
        delLeft(a++, b);
      }
      while (b > queries[i].second) {
        delRight(a, b--);
      }
      sum += answer;
    }
    printf("%lld\n", sum);
  }
}

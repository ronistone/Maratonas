#include <bits/stdc++.h>

const int K = 350;
const int maxn = (int)1e5 + 10;

int a[maxn];
int pref[maxn];
int mostRight[2 * maxn + 1];
int mostLeft[2 * maxn + 1];

bool is_less(const std::pair<int, int> &a, const std::pair<int, int> &b) {
  if (a.first / K != b.first / K) {
    return a.first < b.first;
  }
  return a.second < b.second;
}

int query(int L, int l, int r) {
  int answer = 0;
  for (int i = std::min(L, r); i >= l; i--) {
    int p = mostRight[pref[i]];
    answer = std::max(answer, p - i);
  }
  return answer;
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
    for (int i = 0; i <= n; i++) {
      pref[i] += n;
    }

    int q;
    scanf("%d", &q);
    std::vector<std::pair<int, int>> queries;
    for (int i = 0; i < q; i++) {
      int l, r;
      scanf("%d%d", &l, &r);
      queries.emplace_back(l - 1, r);
    }
    long long sum = 0;
    std::sort(queries.begin(), queries.end(), is_less);
    for (int i = 0; i < q;) {
      int i0 = i;
      while (i < q && queries[i].first / K == queries[i0].first / K) {
        i++;
      }
      memset(mostRight, -1, sizeof(mostRight));
      memset(mostLeft, -1, sizeof(mostLeft));
      int L = queries[i0].first / K * K;
      int R = std::min(L + K - 1, n);
      for (int i = L; i <= std::min(queries[i0].second, R); i++) {
        mostRight[pref[i]] = i;
      }
      int answer = 0;
      int last = R;
      for (int j = i0; j < i; j++) {
        int ql = queries[j].first;
        int qr = queries[j].second;
        for (int c = last + 1; c <= qr; c++) {
          int p = pref[c];
          mostRight[p] = c;
          if (c > R) {
            if (mostLeft[p] == -1) {
              mostLeft[p] = c;
            } else {
              answer = std::max(answer, c - mostLeft[p]);
            }
          }
        }
        last = qr;
        sum += std::max(answer, query(R, ql, qr));
      }
    }
    printf("%lld\n", sum);
  }
}

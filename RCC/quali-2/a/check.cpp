#include "testlib.h"
#include <vector>
#include <iostream>

using namespace std;


template<typename T>
string to_string(const T& x) 
{
    stringstream ss;
    ss << x;
    return ss.str();
}

template<typename T>
string check(T &ouf, int n, int m, int x, vector<int> &a) 
{
    int k = n * m;
    map<int, int> cnt;
    for (int i = 0; i < k; i++)
        cnt[a[i]]++;
    vector<vector<int>> out(n, vector<int>(m));
    vector<pair<int, int>> q;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
        {
            out[i][j] = ouf.readInt();
            cnt[out[i][j]]--;
            if (cnt[out[i][j]] < 0)
                return "value " + to_string(out[i][j]) + " used more than two times";
            q.push_back({i + abs(j - x), out[i][j]});
        }
    sort(q.begin(), q.end());
    int prev_min = 1e9;
    int cur_min = 1e9;
    int level = -1;
    for (int i = 0; i < (int)q.size(); i++)
    {
        if (level != q[i].first)
        {
            level++;
            prev_min = cur_min;
            cur_min = 1e9;
        }
        if (prev_min < q[i].second)
            return "not optimal placement on level " + to_string(level);
        cur_min = min(cur_min, q[i].second);
    }
    return "ok";
}
int main(int argc, char* argv[])
{
    registerTestlibCmd(argc, argv);
    
    
    int t = inf.readInt();
    int cnt = 0;
    while (cnt < t)
    {
        cnt++;
        int n = inf.readInt();
        int m = inf.readInt();
        int x = 0;
        int k = n * m;
        vector<int> a(k);
        for (int i = 0; i < k; i++)
            a[i] = i + 1;
        sort(a.begin(), a.end());
        reverse(a.begin(), a.end());


        string cans = check(ouf, n, m, x, a);
        string jans = check(ans, n, m, x, a);
        quitif(cans != "ok", _wa, "In %d test %s", cnt, cans.c_str());
        quitif(jans != "ok", _fail, "In %d test %s", cnt, jans.c_str());
    }
    quitf(_ok, "%d tests", t);
    return 0;
}
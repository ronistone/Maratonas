#include <bits\stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--) 
    {
        int n, m, k, x;
        cin >> n >> m;
        //x--;
        x = 0;
        k = n * m;
        vector<int> a(k);
        for (int i = 0; i < k; i++)
            a[i] = i + 1;
            //cin >> a[i];
        sort(a.begin(), a.end());
        reverse(a.begin(), a.end());
        vector<vector<int>> ans(n, vector<int>(m, 0));
        vector<int> p;
        for (int i = 0; i < n; i++)
            for (int j = 0; j + x < m; j++)
            {    
                ans[i][j + x] = i + j;
                p.push_back(i + j);
            }
        for (int i = 0; i < n; i++)
            for (int j = 1; j <= x; j++)
            {
                ans[i][x - j] = i + j;
                p.push_back(i + j); 
            }
        sort(p.begin(), p.end());
        vector<vector<int>> places(k);
        for (int i = 0; i < k; i++)
            places[p[i]].push_back(a[i]);
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                int tmp = ans[i][j];
                assert(places[tmp].size() != 0);
                ans[i][j] = places[tmp].back();
                places[tmp].pop_back();
            }
        }
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
                cout << ans[i][j] << ' ';
            cout << endl;
        }
    }
    return 0;
}
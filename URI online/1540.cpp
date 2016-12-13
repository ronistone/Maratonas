#include <bits/stdc++.h>

using namespace std;

main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

   int cases;
   cin >> cases;
   while (cases-- > 0) {
      double y1, v1, y2, v2;
      cin >> y1 >> v1 >> y2 >> v2;
      double res = (v2-v1)/(y2-y1);
      long long copy = res;
      long long remaining = (res-copy)*100;
    if(remaining<10)
        printf("%lld,0%lld\n", copy, remaining);
    else
      printf("%lld,%lld\n", copy, remaining);
   }
}
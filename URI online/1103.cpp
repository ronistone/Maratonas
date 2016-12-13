#include <bits/stdc++.h>

using namespace std;



main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int h1,m1,h2,m2;

    cin >> h1 >> m1 >> h2 >> m2;
    while(h1!=0 || m1!=0 || h2!=0 || m2!=0){
        int minutos1=(60*h1 + m1);
        int minutos2=(60*h2 + m2);

        if(minutos2>minutos1){
             cout << minutos2-minutos1 << endl;
        }else if(minutos1>minutos2){
              cout << 1440-minutos1+minutos2 << endl;
        }else{
              cout << 0 << endl;
        }
        cin >> h1 >> m1 >> h2 >> m2;
    }
    return 0;
}

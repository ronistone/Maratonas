#include <bits/stdc++.h>

using namespace std;

main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    int i,maior,posim,segundo,j;
    while(cin >> n){
        if(n==0)
            break;
        int v[n];
        for(i=0;i<n;i++){
            cin >> v[i];
        }
        maior = v[0];
        posim = 0;
        for(i=0;i<n;i++){
            if(v[i]>maior){
                maior = v[i];
                posim = i;
            }
        }
        segundo = 0;
        int posis=0;
        for(i=0;i<n;i++){
            if(i!= posim && v[i]> segundo){
                segundo = v[i];
                posis = i;
            }
        }

        cout << posis+1 << endl;
    }
}
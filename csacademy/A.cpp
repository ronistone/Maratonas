#include <bits/stdc++.h>
using namespace std;

using namespace std;

int main() {
    int n;
    int coin[15];
    map<int,bool> m;
    
    cin >> n;
    
    for(int i=0;i<n;i++){
        cin >> coin[i];
    }
    
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(i!=j)
                m[coin[i]+coin[j]] = true;
        }
    }
    cout << m.size() << endl;
    
}

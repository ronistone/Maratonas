#include <bits/stdc++.h>
 
using namespace std;
 
int main() {
    string e;
    map<string,bool> M;
    while(getline(cin,e)){
        M[e] = true;
    }
    cout << M.size() << endl;
    return 0;
}

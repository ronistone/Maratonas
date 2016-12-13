#include <bits/stdc++.h>

using namespace std;

main(){
    //ios_base::sync_with_stdio(0);
    //cin.tie(0);

    int n;
    int p1j1,p1j2,p2j1,p2j2,i,s1,s2;
    cin >> n;
    for(i=0;i<n;i++){
        scanf("%d x %d", &p1j1,&p1j2);
        scanf("%d x %d", &p2j1,&p2j2);
        s1 = p1j1+p2j2;
        s2 = p1j2+p2j1;
        if(s1>s2)
            cout << "Time 1" << endl;
        else if(s1<s2)
            cout << "Time 2" << endl;
        else{
            if(p1j2>p2j2)
                cout << "Time 2" << endl;
            else if(p1j2<p2j2)
                cout << "Time 1" << endl;
            else
                cout << "Penaltis" << endl;
        }
    }

}
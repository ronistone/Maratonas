#include <bits/stdc++.h>

using namespace std;

main(){
        int k,x,y,i,xo,yo;

    while(1){
        cin >> k;
        if(k==0)
            break;
            cin >> x >> y;
        for(i=0;i<k;i++){
            cin >> xo >> yo;
            if(xo==x || yo == y)
                cout << "divisa" << endl;
            else if(xo>x){
                if(yo<y)
                    cout << "SE" << endl;
                else if(yo>y)
                    cout << "NE" << endl;
            }
            else if(xo<x){
                if(yo<y)
                    cout << "SO" << endl;
                else if(yo>y)
                    cout << "NO" << endl;
            }
        }
    }
return 0;
}
#include <bits/stdc++.h>

using namespace std;

main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int q,d,p,pag;
    double re;
    for(;;){
        cin >> q;
        if(q==0)
            break;
        cin >> d >> p;
        re = (double)(q*d)/-(q-p);
        pag = (re+d)*q;
        if(pag!=1 && pag != -1)
            cout << pag << " paginas" << endl;
        else
            cout << pag << " pagina" << endl;
    }
}
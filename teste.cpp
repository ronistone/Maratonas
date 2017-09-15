#include <bits/stdc++.h>
using namespace std;

main(){
    int n;
    string e;
    bool fail;
    stack<char> q;
    cin >> n;
    cin.ignore();
    
    for(int i=0;i<n;i++){
        getline(cin,e);
        fail = false;
        for(int j=0;j<e.size();j++){
            if(e[j]=='(' or e[j]=='{' or e[j]=='[')
                q.push(e[j]);
            else if(q.empty() or (e[j]==']' and q.top()!='[')){
                fail = true;
                break;
            }
            else if(q.empty() or (e[j]==')' and q.top()!='(')){
                fail = true;
                break;
            }
            else if(q.empty() or (e[j]=='}' and q.top()!='{')){
                fail = true;
                break;
            }
            else{
                q.pop();
            }
        }
        if(fail or !q.empty())
            cout << "N" << endl;
        else
            cout << "S" << endl;
        while(!q.empty()) q.pop();
    }
    
}

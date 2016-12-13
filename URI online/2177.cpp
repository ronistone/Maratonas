#include <bits/stdc++.h>
using namespace std;

main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);

	double x,y,t;
	double x1,y1,t1;
	int i,j,k;

	cin >> x >> y >> t;
	bool achou = false;
	for(i=0;i<t;i++){
		cin >> x1 >> y1 >> t1;
		double hf = sqrt(pow(x-x1, 2) + pow(y-y1, 2));
		if(hf < t1){
			if(achou)
				cout << " ";
			cout << i+1;
			achou = true;
		}
	}
	if(!achou)
		cout << -1;
	cout << endl;
}

#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    vector<int>vet;
    double dist;
    double x, y, n, x1, y1, n1;

    cin >> x >> y >> n;

    for(int i = 1; i <= n; i++)
    {
        cin >> x1 >> y1 >> n1;

        dist = sqrt(pow(x-x1, 2) + pow(y-y1, 2));

        if (dist < n1)
            vet.push_back(i);
    }
    sort(vet.begin(), vet.end());

    if (vet.empty())
        cout << -1 << endl;
    else
    {
        for(int i = 0; i < vet.size(); i++)
        {
            if (i != 0)
                cout << " ";
            cout << vet[i];
        }
        cout << endl;
    }
    return 0;
}
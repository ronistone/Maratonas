#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;

ll A[2010100];
vector<int> zeros;

int binary_search(int posi){
	int first = 0;
	int last = zeros.size()-1;
	int mid;
	int at = (first+last)/2;
	while(first<=last){
		mid = (first+last)/2;
		if(abs(zeros[mid] - posi)==0)
			return zeros[mid];
		else if(posi < zeros[mid])
			last = mid-1;
		else
			first = mid+1;
		if(abs(zeros[at] - posi) < abs(zeros[mid]-posi))
			return zeros[at];
		at = mid;
	}
	return zeros[mid];
}

main(){
	int n;
	while(cin >> n){
		zeros.clear();
		for(int i=0;i<n;i++){
			cin >> A[i];
			if(A[i]==0)
				zeros.push_back(i);
		}
		for(int i=0;i<n;i++){
			if(i!=0)
				cout << " ";
			cout << abs(binary_search(i) - i);
		}
		cout << endl;

	}
}

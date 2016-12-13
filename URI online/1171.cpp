#include <bits/stdc++.h>

using namespace std;

int compareint (const void * a, const void * b)
{
  if ( *(int*)a <  *(int*)b ) return -1;
  if ( *(int*)a == *(int*)b ) return 0;
  if ( *(int*)a >  *(int*)b ) return 1;
}

main(){
	int i,j,vezes,n,temp;

	cin >> n;

	int v[n];
	for(i=0;i<n;i++)
		cin >> v[i];

	qsort(v,n,sizeof(int),compareint);
	i = 0;
	while(i<n){
		for(vezes = 1;i<n;i++){
			if(v[i]==v[i+1])
				vezes++;
			else{
				i++;
				break;
			}
		}
		cout << v[i-1] << " aparece " << vezes << " vez(es)" << endl;
	}
}
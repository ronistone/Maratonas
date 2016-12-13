#include <bits/stdc++.h>

using namespace std;
int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
   long long int a,b,c,d;
   scanf("%lld %lld %lld %lld", &a, &b, &c, &d);
   long long int i=a;
	do{
      if(i%b!=0 && c%i==0 && d%i!=0){
         printf("%lld\n",i);
         return 0;
         }
         i+=a;
   }while(i<sqrt(c)*a);
   printf("-1\n");
   return 0;
}

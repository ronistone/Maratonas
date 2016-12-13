#include <bits/stdc++.h>
using namespace std;

int main(){

   double temp = 2;
   int repeticoes;
   scanf("%d", &repeticoes);
   if (repeticoes == 0){
      printf("1.0000000000\n");
   }
   else{
      for (int i = 1; i < repeticoes; i++){
         temp = 2 + 1.0 / temp;
      }

      printf("%10.10lf\n", 1+ 1 / temp);
   }
   return 0;
}
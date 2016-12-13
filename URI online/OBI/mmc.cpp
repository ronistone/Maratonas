#include <cstdio>
#include <cstdlib>
#include <iostream>

int mdc2(int a,int b);

int mmc2(int a,int b);

int main()
{
    int a,b;
    char op;
    do{
        system("title MMC"); system("color 9a");
        printf("Informe dois numeros inteiros: ");
        scanf("%i%i",&a,&b);
        printf("m.m.c => %i\n",mmc2(a,b));
        printf("\nDeseja calcular outro m.m.c (S/N)? ");
        scanf("%s",&op);
      }while((op=='s')||(op=='S'));    
return 0;
}
int mdc2(int a,int b)
{
    if(b == 0) return a;
    else
    return mdc2(b,a%b);
}
int mmc2(int a,int b)
{
    int div;
    if(b == 0) return a;
    else
     div = (a*b)/(mdc2(a,b));
    return (div); 
}  
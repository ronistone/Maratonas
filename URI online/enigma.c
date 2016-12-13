        #include <stdio.h>
        #include <string.h>

        int main()
        {
           
            char num[64];
            int i, tam, aux[64];
            scanf("%s", num);
            tam=strlen(num);
            for (i=0;i<tam;i++)
                aux[i]=((int)(num[tam-i-1]))-48;
            for (i=0;i<tam;i++)
                printf("%d",aux[i]);
            printf("\n");

            return 0;

        }



#include <stdio.h>
#include <stdlib.h>

int main()
{
    int N, M, P[1001], i, j, k, troca, aux;
    scanf("%i", &N);
    for (i = 0; i < N; i++)
    {
        troca = 0;
        scanf("%i", &M);
        for (j = 0; j < M; j++)
            scanf("%i", &P[j]);
        for (j = 0; j < M; j++)
        {
            for (k = (j+1); k < M; k++)
            {
                aux = 0;
                if (P[j] < P[k])
                {
                    aux = P[j];
                    P[j] = P[k];
                    P[k] = aux;
                    troca = (troca+2);
                }
            }
        }
       troca = (M-troca);
       if(troca<0)
        troca*=-1;
        printf("%i\n", troca);
    }
    return 0;
}
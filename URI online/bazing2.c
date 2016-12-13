#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct ops {
    char X[50];
    char Z[50];
};
typedef struct ops Ops;
 
int main()
{
 
    Ops ops[11];
    strcpy(ops[0].X,"tesoura");
    strcpy(ops[0].Z , "papel");
    strcpy(ops[1].X , "papel");
    strcpy(ops[1].Z , "pedra");
    strcpy(ops[2].X , "pedra");
    strcpy(ops[2].Z , "lagarto");
    strcpy(ops[3].X , "lagarto");
    strcpy(ops[3].Z , "Spock;");
    strcpy(ops[4].X , "Spock");
    strcpy(ops[4].Z , "tesoura");
    strcpy(ops[5].X , "tesoura");
    strcpy(ops[5].Z , "lagarto");
    strcpy(ops[6].X , "lagarto");
    strcpy(ops[6].Z , "papel");
    strcpy(ops[7].X , "papel");
    strcpy(ops[7].Z , "Spock");
    strcpy(ops[8].X , "Spock");
    strcpy(ops[8].Z , "pedra");
    strcpy(ops[9].X , "pedra");
    strcpy(ops[9].Z, "tesoura");
 
    int i;
    int j;
 
    int tam;
    scanf("%d",&tam);
    char raj[50], sheldon[50];
 
    for(i = 0; i < tam; i++) {
        setbuf(stdin,NULL);
        scanf("%s %s", sheldon, raj);
        setbuf(stdin,NULL);
        for(j=0;j<10;j++) {
            if(!strcmp(ops[j].X, raj) && !strcmp(ops[j].Z, sheldon)) {
                printf("Caso #%d: Raj trapaceou!\n", i+1);
                break;
            }
            else if(!strcmp(ops[j].X, sheldon) && !strcmp(ops[j].Z, raj)) {
                printf("Caso #%d: Bazinga!\n", i+1);
                break;
            }
            else if(!strcmp(sheldon, raj)) {
                printf("Caso #%d: De novo!\n", i+1);
                break;
            }

        }
    }
    return 0;
}
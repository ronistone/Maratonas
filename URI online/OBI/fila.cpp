 #define SIZE 5            /* Size of Queue */
int f=0,r=-1;       /* Global declarations */
typedef struct PRQ
{
    int ele;
    int pr;
} PriorityQ;

PriorityQ PQ[SIZE];

PQinsert(int elem, int pre)
{
    int i;       /* Function for Insert operation */
    if( Qfull()) printf("\n\n Overflow!!!!\n\n");
    else
    {
        i=r;
        ++r;
        while(PQ[i].pr >= pre && i >= 0) /* Find location for new elem */
        {
            PQ[i+1]=PQ[i];
            i--;
        }
        PQ[i+1].ele=elem;
        PQ[i+1].pr=pre;
    }
}

PriorityQ PQdelete()
{
    /* Function for Delete operation */
    PriorityQ p;
    if(Qempty())
    {
        printf("\n\nUnderflow!!!!\n\n");
        p.ele=-1;
        p.pr=-1;
        return(p);
    }
    else
    {
        p=PQ[f];
        f=f+1;
0        return(p);
    }
}

int Qfull()
{
    /* Function to Check Queue Full */
    if(r==SIZE-1) return 1;
    return 0;
}

int Qempty()
{
    /* Function to Check Queue Empty */
    if(f > r) return 1;
    return 0;
}

display()
{
    /* Function to display status of Queue */
    int i;
    if(Qempty()) printf(" \n Empty Queue\n");
    else
    {
        printf("Front->");
        for(i=f; i<=r; i++)
            printf("[%d,%d] ",PQ[i].ele,PQ[i].pr);
        printf("<-Rear");
    }
}

main()
{
    /* Main Program */
    int opn;
    PriorityQ p;
    do
    {
        printf("\n ### Priority Queue Operations(DSC order) ### \n\n");
        printf("\n Press 1-Insert, 2-Delete,3-Display,4-Exit\n");
        printf("\n Your option ? ");
        scanf("%d",&opn);
        switch(opn)
        {
        case 1:
            printf("\n\nRead the element and its Priority?");
            scanf("%d%d",&p.ele,&p.pr);
            PQinsert(p.ele,p.pr);
            break;
        case 2:
            p=PQdelete();
            if( p.ele != -1)
                printf("\n\nDeleted Element is %d \n",p.ele);
            break;
        case 3:
            printf("\n\nStatus of Queue\n\n");
            display();
            break;
        case 4:
            printf("\n\n Terminating \n\n");
            break;
        default:
            printf("\n\nInvalid Option !!! Try Again !! \n\n");
            break;
        }
        printf("\n\n\n\n  Press a Key to Continue . . . ");
        getch();
    }
    while(opn != 4);
}
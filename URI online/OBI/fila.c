/*#include <stdio.h>
#include <stdlib.h>
#define SIZE 5     
int f=0,r=-1;      
typedef struct PRQ
{
    int ele;
    int pr;
} PriorityQ;

PriorityQ PQ[SIZE];

int Qfull()
{
    if(r==SIZE-1) return 1;
    return 0;
}

int Qempty()
{
    if(f > r) return 1;
    return 0;
}

void PQinsert(int elem, int pre)
{
    int i;       
    if( Qfull()) printf("\n\n Overflow!!!!\n\n");
    else
    {
        i=r;
        ++r;
        while(PQ[i].pr >= pre && i >= 0) 
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
        return(p);
    }
}


void display()
{
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

void main()
{
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
        //getch();
    }
    while(opn != 4);
}*/


     /*Program of priority queue using linked list*/

#include <stdio.h>
#include <stdlib.h>

struct node
{
    int priority;
    int info;
    struct node *link;
}*queue1=NULL;

void enqueue(struct node **front, int item, int item_priority);
int del(struct node **front);
void display(struct node *front);
int isEmpty(struct node *front);

void main()
{
    int choice,item,item_priority;
    while(1)
    {
        printf("1.Enqueue\n");
        printf("2.Dequeue\n");
        printf("3.Display\n");
        printf("4.Quit\n");
        printf("Enter your choice : ");
        scanf("%d", &choice);

        switch(choice)
        {
        case 1:
            printf("Input the item to be enqueued : ");
            scanf("%d",&item);
            printf("Enter its priority : ");
            scanf("%d",&item_priority);
            enqueue(&queue1, item, item_priority);
            break;
        case 2:
            printf("Dequeued item is %d\n",del(&queue1));
            break;
        case 3:
            display(queue1);
            break;
        case 4:
            exit(1);
        default :
            printf("Wrong choice\n");
        }/*End of switch*/
    }/*End of while*/
}/*End of main()*/

void enqueue(struct node **front, int item,int item_priority)
{
    struct node *tmp,*p;

    tmp=(struct node *)malloc(sizeof(struct node));
    if(tmp==NULL)
    {
        printf("Memory not available\n");
        return;
    }
    tmp->info=item;
    tmp->priority=item_priority;
    /*Queue is empty or item to be added has priority more than first element*/
    if( isEmpty(*front) || item_priority < (*front)->priority )
    {
        tmp->link=*front;
        *front=tmp;
    }
    else
    {
        p = *front;
        while( p->link!=NULL && p->link->priority<=item_priority )
            p=p->link;
        tmp->link=p->link;
        p->link=tmp;
    }
}/*End of enqueue()*/

int del(struct node **front)
{
    struct node *tmp;
    int item;
    if( isEmpty(*front) )
    {
        printf("Queue Underflow\n");
        exit(1);
    }
    else
    {
        tmp=*front;
        item=tmp->info;
        *front=(*front)->link;
        free(tmp);
    }
    return item;
}/*End of del()*/

int isEmpty(struct node *front)
{
    if( front == NULL )
        return 1;
    else
        return 0;

}/*End of isEmpty()*/

void display(struct node *front)
{
    struct node *ptr;
    ptr=front;
    if( isEmpty(front) )
        printf("Queue is empty\n");
    else
    {
        printf("Queue is :\n");
        printf("Priority       Item\n");
        while(ptr!=NULL)
        {
            printf("%5d        %5d\n",ptr->priority,ptr->info);
            ptr=ptr->link;
        }
    }
}
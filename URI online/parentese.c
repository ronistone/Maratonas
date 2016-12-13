#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct ListElmt_ {

void               *data;
struct ListElmt_   *next;

} ListElmt;

typedef struct List_ {

int                size;

int                (*match)(const void *key1, const void *key2);
void               (*destroy)(void *data);

ListElmt           *head;
ListElmt           *tail;

} List;
void list_init(List *list, void (*destroy)(void *data));

void list_destroy(List *list);

int list_ins_next(List *list, ListElmt *element, const void *data);

int list_rem_next(List *list, ListElmt *element, void **data);

#define list_size(list) ((list)->size)

#define list_head(list) ((list)->head)

#define list_tail(list) ((list)->tail)

#define list_is_head(list, element) ((element) == (list)->head ? 1 : 0)

#define list_is_tail(element) ((element)->next == NULL ? 1 : 0)

#define list_data(element) ((element)->data)

#define list_next(element) ((element)->next)

//#endif

void list_init(List *list, void (*destroy)(void *data)) {
list->size = 0;
list->destroy = destroy;
list->head = NULL;
list->tail = NULL;
return;
}
void list_destroy(List *list) {
void               *data;
while (list_size(list) > 0) {
   if (list_rem_next(list, NULL, (void **)&data) == 0 && list->destroy !=
      NULL) {
      list->destroy(data);
   }
}
memset(list, 0, sizeof(List));
return;
}
int list_ins_next(List *list, ListElmt *element, const void *data) {
ListElmt           *new_element;
if ((new_element = (ListElmt *)malloc(sizeof(ListElmt))) == NULL)
   return -1;
new_element->data = (void *)data;
if (element == NULL) {
   if (list_size(list) == 0)
      list->tail = new_element;
   new_element->next = list->head;
   list->head = new_element;
   }
else {
   if (element->next == NULL)
      list->tail = new_element;
   new_element->next = element->next;
   element->next = new_element;
}
list->size++;
return 0;
}
int list_rem_next(List *list, ListElmt *element, void **data) {
ListElmt           *old_element;
if (list_size(list) == 0)
   return -1;
if (element == NULL) {
   *data = list->head->data;
   old_element = list->head;
   list->head = list->head->next;
   if (list_size(list) == 1)
      list->tail = NULL;
   }
else {
   if (element->next == NULL)
      return -1;
   *data = element->next->data;
   old_element = element->next;
   element->next = element->next->next;

   if (element->next == NULL)
      list->tail = element;
}
free(old_element);

list->size--;

return 0;

}
typedef List Stack;

#define stack_init list_init

#define stack_destroy list_destroy

int stack_push(Stack *stack, const void *data);

int stack_pop(Stack *stack, void **data);

#define stack_peek(stack) ((stack)->head == NULL ? NULL : (stack)->head->data)

#define stack_size list_size

//#endif

int stack_push(Stack *stack, const void *data) {

return list_ins_next(stack, NULL, data);
}

int stack_pop(Stack *stack, void **data) {

return list_rem_next(stack, NULL, data);

}

int main()
{
    int i, contA=0, contB=0, total=0, achou=0;
    float ter;
    char equacao[2000];
    char *aux = malloc(sizeof(char));
    while(scanf("%[^\n]s", equacao)!=EOF){
        getchar();
    Stack postfix;
    stack_init(&postfix, free);
    if(equacao[0]==')' || equacao[strlen(equacao)-1]=='('){
      printf("incorrect\n");
      continue;

    }
    for(i = 0; i < strlen(equacao); i++)
    {
        *aux = equacao[i];
        if(equacao[i] == '(')
        {
            stack_push(&postfix, (void*)aux);
            contA++;
            total++;
        }
        else if (equacao[i] == ')')
        {
            if (stack_size(&postfix) != 0)
            {
                stack_pop(&postfix, (void**)aux);
                achou++;
            }
            else{
                //printf("incorrect\n");
                achou+=400;
            }
            contB++;
            total++;
        }
    }

    ter = (int)total/2;

     if (ter == achou )
    {
        printf("correct\n");
    }
    else
        printf("incorrect\n");   
    }
    return 0;
}

#include<stdio.h>
#include<stdlib.h>

typedef int ElemType;
 
typedef struct DNode
{
    ElemType data;
    struct DNode *prior, *next;
}DNode, *Dlink;

//create double linear from head
Dlink create_head_insert_Dlink(Dlink L)
{
     int x;
     DNode *s;
     L = (Dlink)malloc(sizeof(DNode));
     L->prior = NULL;
     L->next = NULL;
     scanf("%d", &x);
     while(x != -1)
          { 
            s = (Dlink)malloc(sizeof(DNode));
            s->data = x;
            s->next = L->next;
            if(L->next != NULL)
                L->next->prior = s;
            s->prior = L;
            L->next = s;
            scanf("%d", &x);
            
            }
      return L;
}


//insert from tail
Dlink create_tail_insert(Dlink DL)
{
      int x;
      DNode *r, *s;
      DL = (Dlink)malloc(sizeof(DNode));
      DL->next = NULL;
      DL->prior = NULL;
      r = DL;
      scanf("%d", &x);
      while(x != -1)
         {
            s = (Dlink)malloc(sizeof(DNode));
            s->data = x;
            r->next = s;
            s->prior = r;
            r = s;
            scanf("%d", &x);
           }
        r->next = NULL;
     return DL;
}
//find the position of i
DNode *findN(Dlink DL, int i)
{
     int j = 1;
     DNode *p;
     p = DL->next;
     while(p && j < i)
          {
            p = p->next;
            j++;
            }
     return p;
}

//insert a number in the position i
int insert_i(Dlink DL, int i, ElemType e)
{
     DNode *p, *s;
     if(i < 0)
        return 0;
     p = findN(DL, i-1);
     if( p == NULL)
         return 0;
     s = (Dlink)malloc(sizeof(DNode));
     s->data = e;
     s->next = p->next;
     s->prior = p;
     s->next->prior = s;
     p->next = s;
     return 1;
}

//delete the number in the positiion i
int Delete_DL(Dlink DL, int i)
{
     DNode *p, *q;
     p = findN(DL, i -1 );
     if(p == NULL)
           return 0;
     q = p->next;
     p->next = q->next;
     q->next->prior = p;
     free(q);
     return 1;
}

//display the double list
void display(Dlink L)
{
    DNode *p;
    p = L->next;
    while(p)
       {
         printf("%4d", p->data);
         p = p->next;
          }
      printf("\n");
}

int main()
{
    int flag;
    Dlink DL;
    DNode *search;
   // DL = create_head_insert_Dlink(DL);
    DL =  create_tail_insert(DL);  // input 1 2 3 4 5 6 -1
    display(DL);
    printf("the number 4's prior number and next\n");
    search = findN(DL, 4);
    if(search != NULL)
           printf("It's prior number is %d and next is %d\n", search->prior->data, search->next->data);
   else
       printf("Not find\n");
   flag = insert_i(DL, 4, 66);
   if(flag)
       display(DL);
   else
        printf("Failure\n");
    printf("delete the number 66\n");
    flag = Delete_DL(DL, 4);
    if(flag)
         {
          printf("Delete successfully!\n");
          display(DL);
           }
   else
         printf("failure\n");
    return 0;
    
}

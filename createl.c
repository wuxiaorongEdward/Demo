#include<stdio.h>
#include<stdlib.h>
#define N 10

int a[N] = {10, 9, 8, 7, 6, 5, 4, 3, 2, 1};

typedef struct LNode
{
        int data;
        struct LNode *next;
}LNode;

LNode * create(LNode *head,  int array[],  int n)
{
      int i;
      LNode *s, *r;
      head = (LNode *)malloc(sizeof(LNode));
      head->next = NULL;
       r = head;
       for(i = 0; i < n; i++)
         {
            s = (LNode *)malloc(sizeof(LNode));
            s->data = array[i];
            r->next = s;
            r = s;
}
            r->next = NULL;
            return head;
} 

LNode *create1(LNode *head, int a[], int n)
{
    int i;
     LNode *s;
     head = (LNode *)malloc(sizeof(LNode));
     head->next = NULL;
    for(i = 0; i < n; i++)
      {
        s = (LNode *)malloc(sizeof(LNode));
        s->data = a[i];
        s->next = head->next;
        head->next = s;
}
    return head;
}
int main()
{
     LNode *s, *p;
   // s =  create(s,a, N );
    s =  create1(s,a, N );
     p = s->next;
     while(p)
         {
       printf("%d\t", p->data);
       p = p->next;
}
     printf("\n");        
     return 0;
}

#include<stdio.h>
#include<stdlib.h>

typedef struct Node
{
   int value;
   struct Node *next;
}Node;

Node *Create(Node *L)
{
     int n;
     Node *s, *r;
     L = (Node *)malloc(sizeof(Node));
     L->next = NULL;
     r = L;
     scanf("%d", &n);
     while(n != -1)
          {
           s = (Node *)malloc(sizeof(Node));
           s->value = n;
           r->next = s;
           r = s;
     scanf("%d", &n);
              }
      s->next = NULL;
     return L;     
}

void ReverseList(Node *L)
{
     Node *p, *q, *r;
     p = L->next;
     q = p->next;
     p->next = NULL;
     r = q->next;
     while(r != NULL)
         {
           q->next = p;
           p = q;
           q = r; 
           r = q->next;
          }
      q->next = p;
      L->next = q;
}

Node *Reverse(Node *L)
{
    Node *s, *head, *p;
    p = L->next;
    head = (Node *)malloc(sizeof(Node));
    head->next = NULL;
    while(p)
       {
         s = (Node *)malloc(sizeof(Node));
         s->value = p->value;
         s->next = head->next;
         head->next = s;
         p = p->next;
           }
     return head;
    
}
void PintList(Node *h)
{
     Node *p;
     p = h->next;
     while(p)
        {
         printf("%d\t", p->value);
         p = p->next;
          }
        printf("\n");
}
int main()
{
        Node *h;
        h = Create(h);
        PintList(h);
        ReverseList(h);
        PintList(h);
        h = Reverse(h);
        PintList(h);
       return 0;
}






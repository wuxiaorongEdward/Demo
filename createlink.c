#include<stdio.h>
#include<stdlib.h>
#define OK 1
#define ERROR 0
typedef int Elem;

typedef struct LNode{
      Elem data;
     struct LNode *next;
}LNode;

LNode * CreateFromTrail(LNode *head)
{
      int n;
      LNode *r, *s;
      head = (LNode *)malloc(sizeof(LNode));
      head->next = NULL;
      r = head;
      printf("please input positive number <-1 to exit>\n");
      scanf("%d", &n);
      while(n != -1)
          {
            s = (LNode * )malloc(sizeof(LNode));
            s->data = n;
            r->next = s;
            r = s;
            scanf("%d", &n);
          }
        r->next = NULL;
        return head;
}

LNode *CreateFromHead(LNode *head)
{
      int n;
     LNode *p;
     head = (LNode *)malloc(sizeof(LNode));
     head->next = NULL;
     printf("please input positive number <-1 to exit>\n");
     scanf("%d", &n);
     while(n != -1)
          {
           p = (LNode *)malloc(sizeof(LNode));
           p->data = n;
           p->next = head->next;
           head->next = p;
           scanf("%d", &n);
            }
        return head;
}

void displayLink(LNode *head)
{
    LNode *p;
    p = head->next;
    while(p)
          {
           printf("%d\t", p->data);
           p = p->next;
           }
         printf("\n");
}

int main()
{
    LNode *head;
   // head = CreateFromTrail(head);
    head = CreateFromHead(head);
    displayLink(head);
    return 0;
}
